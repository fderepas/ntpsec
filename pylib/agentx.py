#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, division

import select
import time

try:
    import ntp.util
    import ntp.agentx_packet
    ax = ntp.agentx_packet
except ImportError as e:
    sys.stderr.write(
        "AgentX: can't find Python AgentX Packet library.\n")
    sys.stderr.write("%s\n" % e)
    sys.exit(1)


defaultTimeout = 30


class MIBControl:
    def __init__(self):
        # The undo system is only for the last operation
        self.inSetP = False  # Are we currently in the set procedure?
        self.setVarbinds = []  # Varbind of the current set operation
        self.setHandlers = []  # Handlers for commit/undo/cleanup of set
        self.setUndoData = []  # Previous values for undoing
        self.mibRoot = ()

    def rootOID(self):
        return self.mibRoot

    def rangeSubid(self):
        return 0

    def upperBound(self):
        return None

    def context(self):
        return None

    def getOID_core(self, nextP, searchoid, returnGenerator=False):
        gen = ax.walkMIBTree(self.oidTree, self.mibRoot)
        while True:
            try:
                oid, reader, writer = gen.next()
                if nextP is True:  # GetNext
                    # For getnext any OID greater than the start qualifies
                    oidhit = (oid > searchoid)
                else:  # Get
                    # For get we need a *specific* OID
                    oidhit = (oid.subids == searchoid.subids)
                if oidhit and (reader is not None):
                    # We only return OIDs that have a minimal implementation
                    # walkMIBTree handles the generation of dynamic trees
                    if returnGenerator is True:
                        return oid, reader, writer, gen
                    else:
                        return oid, reader, writer
            except StopIteration:  # Couldn't find anything in the tree
                if returnGenerator is True:
                    return None, None, None, None
                else:
                    return None, None, None

    # These exist instead of just using getOID_core so semantics are clearer
    def getOID(self, searchoid, returnGenerator=False):
        "Get the requested OID"
        return self.getOID_core(False, searchoid, returnGenerator)

    def getNextOID(self, searchoid, returnGenerator=False):
        "Get the next lexicographical OID"
        return self.getOID_core(True, searchoid, returnGenerator)

    def getOIDsInRange(self, oidrange, firstOnly=False):
        "Get a list of every (optionally the first) OID in a range"
        oids = []
        gen = ax.walkMIBTree(self.oidTree, self.mibRoot)
        # Find the first OID
        while True:
            try:
                oid, reader, writer = gen.next()
                if reader is None:
                    continue  # skip unimplemented OIDs
                elif oid.subids == oidrange.start.subids:
                    # ok, found the start, do we need to skip it?
                    if oidrange.start.include is True:
                        oids.append((oid, reader, writer))
                        break
                    else:
                        continue
                elif oid > oidrange.start:
                    # If we are here it means we hit the start but skipped
                    oids.append((oid, reader, writer))
                    break
            except StopIteration:
                # Couldn't find *anything*
                return []
        if firstOnly is True:
            return oids
        # Start filling in the rest of the range
        while True:
            try:
                oid, reader = gen.next()
                if reader is None:
                    continue  # skip unimplemented OIDs
                elif (oidrange.end is not None) and (oid >= oidrange.end):
                    break  # past the end of a bounded range
                else:
                    oids.append((oid, reader, writer))
            except StopIteration:
                break  # We have run off the end of the MIB
        return oids


class PacketControl:
    def __init__(self, sock, dbase, spinGap=0.001, timeout=defaultTimeout,
                 logfp=None, debugThreshold=0):
        self.log = (lambda txt, dbg : ntp.util.dolog(logfp, txt, dbg,
                                                     debugThreshold))
        # take a pre-made socket instead of making our own so that
        # PacketControl doesn't have to know or care about implementation
        self.socket = sock
        self.spinGap = spinGap  # sleep() time on each loop
        # indexed on: (session_id, transaction_id, packet_id)
        # contains: (timeout, packet class)
        self.packetLog = {}  # Sent packets kept until response is received
        self.loopCallback = None  # called each loop in runforever mode
        self.database = dbase  # class for handling data requests
        self.recievedData = ""  # buffer for data from incomplete packets
        self.recievedPackets = []  # use as FIFO
        self.timeout = timeout
        self.sessionID = None  # need this for all packets
        self.highestTransactionID = 0  # used for exchanges we start
        # indexed on pdu code
        self.pduHandlers = {ax.PDU_GET: self.handle_GetPDU,
                            ax.PDU_GET_NEXT: self.handle_GetNextPDU,
                            ax.PDU_GET_BULK: self.handle_GetBulkPDU,
                            ax.PDU_TEST_SET: self.handle_TestSetPDU,
                            ax.PDU_COMMIT_SET: self.handle_CommitSetPDU,
                            ax.PDU_UNDO_SET: self.handle_UndoSetPDU,
                            ax.PDU_CLEANUP_SET: self.handle_CleanupSetPDU}

    def mainloop(self, runforever):
        if runforever:
            while True:
                self._doloop()
                if self.loopCallback is not None:
                    self.loopCallback(self)
                time.sleep(self.spinGap)
        else:
            self._doloop()

    def _doloop(self):
        # loop body split out to separate the one-shot/run-forever switches
        # from the actual logic
        self.packetEater()
        while len(self.recievedPackets) > 0:
            packet = self.recievedPackets.pop(0)
            if packet.sessionID != self.sessionID:
                resp = ax.ResponsePDU(True, packet.sessionID,
                                      packet.transactioID, packet.packetID,
                                      0, ax.REPERR_NOT_OPEN, 0)
                self.sendPacket(resp, False)
                continue
            # TODO: Need to check for expected responses
            ptype = packet.pduType
            if ptype in self.pduHandlers:
                self.pduHandlers[ptype](packet)
            else:
                self.log("dropping packet type %i, not implemented\n" % ptype,
                         1)

    def initNewSession(self): # WORKING
        self.log("init new session...\n", 1)
        # We already have a connection, need to open a session.
        openpkt = ax.OpenPDU(True, 23, 0, 0, self.timeout, (),
                             "NTPsec SNMP subagent")
        self.sendPacket(openpkt, False)
        self.log("Sent open packet\n", 1)
        response = self.waitForResponse(openpkt, True)
        self.sessionID = response.sessionID
        # Register the tree
        register = ax.RegisterPDU(True, self.sessionID, 1, 1, self.timeout, 1,
                                  self.database.rootOID(),
                                  self.database.rangeSubid(),
                                  self.database.upperBound(),
                                  self.database.context())
        self.sendPacket(register, False)
        self.log("Sent registration\n", 1)
        response = self.waitForResponse(register, True)

    def waitForResponse(self, opkt, ignoreSID=False):
        "Wait for a response to a specific packet, dropping everything else"
        while True:
            self.packetEater()
            while len(self.recievedPackets) > 0:
                packet = self.recievedPackets.pop(0)
                self.log("Waiting, got packet: " + repr(packet) + "\n\n", 3)
                if packet.__class__ != ax.ResponsePDU:
                    continue
                haveit = (opkt.transactionID == packet.transactionID) and \
                         (opkt.packetID == packet.packetID)
                if ignoreSID is False:
                    haveit = haveit and (opkt.sessionID == packet.sessionID)
                if haveit is True:
                    return packet
            time.sleep(self.spinGap)

    def packetEater(self):
        "Slurps data from the input buffer and tries to parse packets from it"
        self.pollSocket()
        while True:
            datalen = len(self.recievedData)
            if datalen < 20:
                return None  # We don't even have a packet header, bail
            try:
                pkt, extraData = ax.decode_packet(self.recievedData)
                self.recievedData = extraData
                self.recievedPackets.append(pkt)
                if pkt.transactionID > self.highestTransactionID:
                    self.highestTransactionID = pkt.transactionID
                self.log("\npacketEater got a full packet: %s\n" % repr(pkt), 3)
            except ax.ParseDataLengthError:
                return None  # this happens if we don't have all of a packet
            except (ax.ParseVersionError, ax.ParsePDUTypeError,
                    ax.ParseError) as e:
                if e.header["type"] != ax.PDU_RESPONSE:
                    # Response errors are silently dropped, per RFC
                    # Everything else sends an error response
                    self.sendErrorResponse(e.header, ax.RSPERR_PARSE_ERROR, 0)
                # *Hopefully* the packet length was correct.....
                #  if not, all packets will be scrambled. Maybe dump the
                #  whole buffer if too many failures in a row?
                self.receivedData = e.remainingData

    def sendPacket(self, packet, expectsReply):
        encoded = packet.encode()
        self.log("\nsending packet: %s\n%s \n" % (repr(packet), repr(encoded)),
                 4)
        self.socket.sendall(encoded)
        if expectsReply is True:
            index = (packet.sessionID,
                     packet.transactionID,
                     packet.packetID)
            self.packetLog[index] = packet

    def sendNotify(self, varbinds, context=None):
        # DUMMY packetID, does this need to change? or does the pktID only
        # count relative to a given transaction ID?
        tid = self.highestTransactionID + 5  # +5 to avoid collisions
        self.highestTransactionID = tid
        pkt = ax.NotifyPDU(True, self.sessionID, tid, 1, varbinds, context)
        self.sendPacket(pkt, True)

    def sendErrorResponse(self, errorHeader, errorType, errorIndex):
        err = ax.ResponsePDU(errorHeader["flags"]["bigEndian"],
                             errorHeader["session_id"],
                             errorHeader["transaction_id"],
                             errorHeader["packet_id"],
                             0, errorType, errorIndex)
        self.sendPacket(err, False)

    def pollSocket(self):
        "Reads all currently available data from the socket, non-blocking"
        data = ""
        while True:
            tmp = select.select([self.socket], [], [], 0)[0]
            if len(tmp) == 0:  # No socket, means no data available
                break
            tmp = tmp[0]
            newdata = tmp.recv(4096)  # Arbitrary value
            if len(newdata) > 0:
                self.log("Received data: " + repr(newdata) + "\n", 4)
                data += newdata
            else:
                break
        self.recievedData += data

    # ==========================
    # Packet handlers start here
    # ==========================

    def handle_GetPDU(self, packet):
        binds = []
        for oidr in packet.oidranges:
            target = oidr.start
            oid, reader, _ = self.database.getOID(target)
            if (oid != target) or (reader is None):
                # This OID must not be implemented yet.
                binds.append(ax.Varbind(ax.VALUE_NO_SUCH_OBJECT, target))
            else:
                vbind = reader(oid)
                if vbind is None:  # No data avaliable.
                    # I am not certain that this is the correct response
                    # when no data is available. snmpwalk appears to stop
                    # calling a particular sub-agent when it gets to a NULL.
                    binds.append(ax.Varbind(ax.VALUE_NULL, target))
                else:
                    binds.append(vbind)
            # There should also be a situation that leads to noSuchInstance
            #  but I do not understand the requirements for that
        # TODO: Need to implement genError
        resp = ax.ResponsePDU(True, self.sessionID, packet.transactionID,
                              packet.packetID, 0, ax.ERR_NOERROR, 0, binds)
        self.sendPacket(resp, False)

    def handle_GetNextPDU(self, packet):
        binds = []
        for oidr in packet.oidranges:
            while True:
                oids = self.database.getOIDsInRange(oidr, True)
                if len(oids) == 0:  # Nothing found
                    binds.append(ax.Varbind(ax.VALUE_END_OF_MIB_VIEW,
                                            oidr.start))
                    break
                else:
                    oid, reader, _ = oids[0]
                    vbind = reader(oid)
                    if vbind is None:  # No data available
                        # Start next search from the current location
                        oidr = ax.SearchRange(oid, oidr.end, False)
                        continue
                    else:
                        binds.append(vbind)
                        break
        # TODO: Need to implement genError
        resp = ax.ResponsePDU(True, self.sessionID, packet.transactionID,
                              packet.packetID, 0, ax.ERR_NOERROR, 0, binds)
        self.sendPacket(resp, False)

    def handle_GetBulkPDU(self, packet):
        binds = []
        nonreps = packet.oidranges[:packet.nonReps]
        repeats = packet.oidranges[packet.nonReps:]
        # Handle non-repeats
        for oidr in nonreps:
            oids = self.database.getOIDsInRange(oidr, True)
            if len(oids) == 0:  # Nothing found
                binds.append(ax.Varbind(ax.VALUE_END_OF_MIB_VIEW, oidr.start))
            else:
                oid, reader, _ = oids[0]
                binds.append(reader(oid))
        # Handle repeaters
        for oidr in repeats:
            oids = self.database.getOIDsInRange(oidr)
            if len(oids) == 0:  # Nothing found
                binds.append(ax.Varbind(ax.VALUE_END_OF_MIB_VIEW, oidr.start))
            else:
                for oid, reader, _ in oids[:packet.maxReps]:
                    binds.append(reader(oid))
        resp = ax.ResponsePDU(True, self.sessionID, packet.transactionID,
                              packet.packetID, 0, ax.ERR_NOERROR, 0, binds)
        self.sendPacket(resp, False)

    def handle_TestSetPDU(self, packet):  # WIP / TODO
        # Be advised: MOST OF THE VALIDATION IS DUMMY CODE OR DOESN'T EXIST
        # According to the RFC this is one of the most demanding parts and
        #  *has* to be gotten right
        if self.database.inSetP is True:
            pass  # Is this an error?
        # if (inSetP is True) is an error these will go in an else block
        self.database.inSetP = True
        self.database.setVarbinds = []
        self.database.setHandlers = []
        self.database.setUndoData = []
        error = None
        for bindIndex in range(len(packet.varbinds)):
            varbind = packet.varbinds[bindIndex]
            # Find an OID, then validate it
            oid, reader, writer = self.database.getOID(varbind.oid)
            if oid is None:  # doesn't exist, can we create it?
                # DUMMY, assume we can't create anything
                error = ax.ERR_NO_ACCESS
                break
            elif writer is None:  # exists, writing not implemented
                error = ax.ERR_NOT_WRITABLE
                break
            # Ok, we have an existing or new OID, assemble the orders
            # If we created a new bind undoData is None, must delete it
            undoData = reader(oid)
            error = writer("test", varbind)
            if error != ax.ERR_NOERROR:
                break
            self.database.setVarbinds.append(varbind)
            self.database.setHandlers.append(writer)
            self.database.setUndoData.append(undoData)
        if error != ax.ERR_NOERROR:
            resp = ax.ResponsePDU(True, self.sessionID, packet.transactionID,
                                  packet.packetID, 0, error, bindIndex)
            self.sendPacket(resp, False)
            for i in range(bindIndex):
                # Errored out, clear the successful ones
                self.database.setHandlers[i]("clear",
                                             self.database.setVarbinds[i])
            self.database.inSetP = False
        else:
            resp = ax.ResponsePDU(True, self.sessionID, packet.transactionID,
                                  packet.packetID, 0, ax.ERR_NOERROR, 0)
            self.sendPacket(resp, False)

    def handle_CommitSetPDU(self, packet):
        if self.database.inSetP is False:
            pass  # how to handle this?
        varbinds = self.database.setVarbinds
        handlers = self.database.setHandlers
        for i in range(len(varbinds)):
            error = handlers[i]("commit", varbinds[i])
            if error != ax.ERR_NOERROR:
                break
        if error != ax.ERR_NOERROR:
            resp = ax.ResponsePDU(True, self.sessionID, packet.transactionID,
                                  packet.packetID, 0, error, i)
        else:
            resp = ax.ResponsePDU(True, self.sessionID, packet.transactionID,
                                  packet.packetID, 0, ax.ERR_NOERROR, 0)
        self.sendPacket(resp, False)

    def handle_UndoSetPDU(self, packet):
        varbinds = self.database.setVarbinds
        handlers = self.database.setHandlers
        undoData = self.database.setUndoData
        for i in range(len(varbinds)):
            error = handlers[i]("undo", varbinds[i], undoData[i])
            if error != ax.ERR_NOERROR:
                break
        if error != ax.ERR_NOERROR:
            resp = ax.ResponsePDU(True, self.sessionID, packet.transactionID,
                                  packet.packetID, 0, error, i)
        else:
            resp = ax.ResponsePDU(True, self.sessionID, packet.transactionID,
                                  packet.packetID, 0, ax.ERR_NOERROR, 0)
        self.sendPacket(resp, False)

    def handle_CleanupSetPDU(self, packet):
        varbinds = self.database.setVarbinds
        handlers = self.database.setHandlers
        for i in range(len(varbinds)):
            handlers[i]("clean", varbinds[i])
        self.database.inSetP = False
