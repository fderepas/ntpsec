/*
 * Copyright (C) 2008  Johannes Maximilian K�hn
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM
 * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL
 * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
 * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "networking.h"

char adr_buf[INET6_ADDRSTRLEN];


/* resolve_hosts consumes an arry of hostnames/addresses and its length, stores a pointer
 * to the array with the resolved hosts in res and returns the size of the array res.
 * pref_family enforces IPv4 or IPv6 depending on commandline options and system 
 * capability. If pref_family is NULL or PF_UNSPEC any compatible family will be accepted.
 * Check here: Probably getaddrinfo() can do without ISC's IPv6 availability check? 
 */
int 
resolve_hosts (
		char **hosts, 
		int hostc, 
		struct addrinfo **res,
		int pref_family
		) 
{
	register unsigned int a, b;
	unsigned int entryc = 0; 

	if(hostc < 1) 
		return 0;
	
	struct addrinfo ***tres = (struct addrinfo ***) malloc(sizeof(struct addrinfo **) * hostc);

	for(a=0; a<hostc; a++) {
		tres[a] = (struct addrinfo **) malloc(sizeof(struct addrinfo));

#ifdef DEBUG
		printf("sntp resolve_hosts: Starting host resolution for %s...\n", hosts[a]); 
#endif

		struct addrinfo hints, *dres;
		int error;

		memset(&hints, 0, sizeof(hints));

		if(pref_family == 0)
			hints.ai_family = PF_UNSPEC;
		else 
			hints.ai_family = pref_family;
		
		hints.ai_socktype = SOCK_DGRAM;

		error = getaddrinfo(hosts[a], "123", &hints, tres[a]);

		if(error) {
			size_t msg_length = strlen(hosts[a]) + 21;
			char *logmsg = (char *) malloc(sizeof(char) * msg_length);

			snprintf(logmsg, msg_length, "Error looking up %s", hosts[a]);
#ifdef DEBUG
			printf("%s\n", logmsg);
#endif

			log_msg(logmsg, 1);
			res[a] = 0;
		}
		else {
			for(dres=*tres[a]; dres; dres=dres->ai_next) {
				entryc++;
#ifdef DEBUG	
				getnameinfo(dres->ai_addr, dres->ai_addrlen, adr_buf, INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);
				STDLINE
				printf("Resolv No.: %i Result of getaddrinfo for %s:\n", entryc, hosts[a]);
				printf("socktype: %i ", dres->ai_socktype); 
				printf("protocol: %i ", dres->ai_protocol);
				printf("Prefered socktype: %i IP: %s\n", dres->ai_socktype, adr_buf);
				STDLINE
#endif
			}
		}
	}

#ifdef DEBUG
	printf("Retrieved %i DNS entries, continuing...\n", entryc);
#endif

	/* Make a list of the addrinfo list entries, start by counting them */
	struct addrinfo **result = (struct addrinfo **) malloc(sizeof(struct addrinfo**) * entryc);

	for(a=0, b=0; a<hostc; a++) {
		struct addrinfo *cur = *tres[a];

		if(cur->ai_next == NULL) {
			result[b] = *tres[a];
		}
		else {
			struct addrinfo *seek = *tres[a];

			for(; b<entryc && seek; b++) {
				result[b] = seek;
				seek = seek->ai_next;
			}
		}
	}

#ifdef DEBUG
	for(a=0; a<entryc; a++)
		getnameinfo(result[a]->ai_addr, result[a]->ai_addrlen, adr_buf, INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);

		printf("%x: IP %s\n", (unsigned int) result[a], adr_buf); 
#endif

	*res = (struct addrinfo *) malloc(sizeof(struct addrinfo *) * entryc);

	for(a=0; a<entryc; a++)
		res[a] = result[a];

	return entryc;
}

/* Creates a socket and returns. */
void 
create_socket (
		SOCKET *rsock,
		struct sockaddr_storage *dest
		)
{
	*rsock = socket(dest->ss_family, SOCK_DGRAM, 0);

	if(*rsock == -1)
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("Failed to create UDP socket with family %i\n", dest->ss_family);

}

/* If there's nothing more to do here we might need this function 
 * Originally I thought about doing some broad-/multicast related
 * cleaning up here. 
 */
void 
close_socket (
		SOCKET rsock
		)
{
	close(rsock);
}

/* Send a packet */
void
sendpkt (
	SOCKET rsock,
	struct sockaddr_storage *dest,
	struct pkt *pkt,
	int len
	)
{
#ifdef DEBUG
	printf("sntp sendpkt: Packet data:\n");
	pkt_output(pkt, len, stdout);
#endif

	if(ENABLED_OPT(NORMALVERBOSE)) {
		getnameinfo((struct sockaddr *) dest, SOCKLEN(dest), adr_buf, INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);

		printf("sntp sendpkt: Sending packet to %s... ", adr_buf);
	}

	int cc = sendto(rsock, (char *)pkt, len, 0, (struct sockaddr *)dest, SOCKLEN(dest));

	if (cc == SOCKET_ERROR) {
#ifdef DEBUG
		printf("\n sntp sendpkt: Socket error: %i. Couldn't send packet!\n", cc);
#endif

		if (errno != EWOULDBLOCK && errno != ENOBUFS) {

		}
	}
	else {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("Packet sent.\n");
	}
}

/* Receive raw data */
int
recvdata (
		SOCKET rsock,
		struct sockaddr_storage *sender,
		char *rdata,
		int rdata_length
	 )
{
	GETSOCKNAME_SOCKLEN_TYPE slen = SOCKLEN(&rsock);

#ifdef DEBUG
	printf("sntp recvdata: Trying to receive data from...\n");
#endif

	int recvc = recvfrom(rsock, rdata, rdata_length, 0, 
			(struct sockaddr *) sender, &slen);
#ifdef DEBUG
	printf("sntp recvdata: recvfrom returned...\n");
#endif

#ifdef DEBUG

	if(recvc > 0) {
		getnameinfo((struct sockaddr *)sender, SOCKLEN(sender), adr_buf, INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);

		printf("Received %i bytes from %s:\n", recvc, adr_buf);

		pkt_output((struct pkt *) rdata, recvc, stdout);
	}
	else {
		printf("Failure, recvc: %i\n", recvc);
	}
#endif

	return recvc;
}

/* Receive data from broadcast. Couldn't finish that. Need to do some digging
 * here, especially for protocol independence and IPv6 multicast */
int 
recv_bcst_data (
		SOCKET rsock,
		char *rdata,
		int rdata_len,
		struct sockaddr_storage *sas,
		struct sockaddr_storage *ras
	 )
{
	struct timeval timeout_tv;
	fd_set bcst_fd;
	char *buf;
	int btrue = 1;
	int recv_bytes = 0;

	 
	setsockopt(rsock, SOL_SOCKET, SO_REUSEADDR, &btrue, sizeof(btrue));

	if(sas->ss_family == AF_INET) {
		struct ip_mreq mdevadr;
	
		if(bind(rsock, (struct sockaddr *) sas, SOCKLEN(sas)) < 0) {}


		if(setsockopt(rsock, IPPROTO_IP, IP_MULTICAST_LOOP, &btrue, sizeof(btrue)) < 0) {
			/* some error message regarding setting up multicast loop */
			return BROADCAST_FAILED;
		}

		buf = ss_to_str(sas);

		mdevadr.imr_multiaddr.s_addr = inet_addr(buf); 
		mdevadr.imr_interface.s_addr = htonl(INADDR_ANY);

		if(mdevadr.imr_multiaddr.s_addr == -1) {
			if(ENABLED_OPT(NORMALVERBOSE)) {
				printf("sntp recv_bcst_data: %s is not a broad-/multicast address, aborting...\n", buf);
			}
			
			return BROADCAST_FAILED;
		}

		free(buf);

		if (setsockopt(rsock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mdevadr, sizeof(mdevadr)) < 0) {
			if(ENABLED_OPT(NORMALVERBOSE)) {
				buf = ss_to_str(sas);

				printf("sntp recv_bcst_data: Couldn't add IP membership for %s\n", buf);
				
				free(buf);

				return BROADCAST_FAILED;
			}
		}
	}
	else if(sas->ss_family == AF_INET6) {
		struct ipv6_mreq mdevadr;

		if(bind(rsock, (struct sockaddr *) sas, sizeof(sas)) < 0) {
			if(ENABLED_OPT(NORMALVERBOSE))
				printf("sntp recv_bcst_data: Couldn't bind() address.\n");
		}

		if(setsockopt(rsock, IPPROTO_IPV6, IPV6_MULTICAST_LOOP, &btrue, sizeof (btrue)) < 0) {
			/* some error message regarding setting up multicast loop */
			return BROADCAST_FAILED;
	    }

		mdevadr.ipv6mr_multiaddr = *((struct in6_addr *) sas);
		/* FIXME    hat value for ipv6mr_interface?  Use utilities for sock to char op*/
		/* mdevadr.ipv6mr_interface = in6addr_any; */ 
														 
		if(!IN6_IS_ADDR_MULTICAST((struct in6_addr *) &mdevadr.ipv6mr_multiaddr)) {
			if(ENABLED_OPT(NORMALVERBOSE)) {
				buf = ss_to_str(sas); 

				printf("sntp recv_bcst_data: %s is not a broad-/multicast address, aborting...\n", buf);
				
				free(buf);
			}
			
			return BROADCAST_FAILED;
		}

		if (setsockopt(rsock, IPPROTO_IPV6, IPV6_JOIN_GROUP, &mdevadr, sizeof(mdevadr)) < 0) {
			if(ENABLED_OPT(NORMALVERBOSE)) {
				buf = ss_to_str(sas); 

				printf("sntp recv_bcst_data: Couldn't join group for %s\n", buf);
				
				free(buf);

				return BROADCAST_FAILED;
			}
		}
	}
	
	FD_ZERO(&bcst_fd);
	FD_SET(rsock, &bcst_fd);

	if(ENABLED_OPT(TIMEOUT)) 
		timeout_tv.tv_sec = (int) OPT_ARG(TIMEOUT);
	else 
		timeout_tv.tv_sec = 60;
	
	switch(select(rsock + 1, &bcst_fd, 0, 0, &timeout_tv)) {
		FD_CLR(rsock, &bcst_fd);
		
		case -1: 
			if(ENABLED_OPT(NORMALVERBOSE)) 
				printf("sntp recv_bcst_data: select() returned -1, an error occured, aborting.\n");

			return BROADCAST_FAILED;
			break;

		case 0:
			if(ENABLED_OPT(NORMALVERBOSE))
				printf("sntp recv_bcst_data: select() reached timeout (%li sec), aborting.\n", timeout_tv.tv_sec);

			return BROADCAST_FAILED;
			break;

/*		default: */
			GETSOCKNAME_SOCKLEN_TYPE ss_len = SOCKLEN(ras);

			recv_bytes = recvfrom(rsock, rdata, rdata_len, 0, (struct sockaddr *) ras, (GETSOCKNAME_SOCKLEN_TYPE *) &ss_len);
	}

	if(recv_bytes == -1) {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("sntp recv_bcst_data: Failed to receive from broad-/multicast\n");

		return BROADCAST_FAILED;
	}

	if(sas->ss_family == AF_INET) 
		setsockopt(rsock, IPPROTO_IP, IP_DROP_MEMBERSHIP, &btrue, sizeof(btrue));
	else if(sas->ss_family == AF_INET6)
		setsockopt(rsock, IPPROTO_IPV6, IPV6_LEAVE_GROUP, &btrue, sizeof(btrue));
		
	return recv_bytes;
}

int 
recv_bcst_pkt (
		SOCKET rsock,
		struct pkt *rpkt,
		struct sockaddr_storage *sas
		)
{
	struct sockaddr_storage sender;
	register int a;
	int is_authentic, has_mac = 0, orig_pkt_len;

	char *rdata = (char *) malloc(sizeof(char) * 256);

	int pkt_len = recv_bcst_data(rsock, rdata, 256, sas, &sender);


	if(pkt_len < 0)
		return BROADCAST_FAILED;

	/* No MAC, no authentication */
	if(pkt_len == LEN_PKT_NOMAC)
		has_mac = 0;

	/* If there's more than just the NTP packet it should be a MAC */	
	else if(pkt_len > LEN_PKT_NOMAC) 
		has_mac = pkt_len - LEN_PKT_NOMAC;
	else
		if(ENABLED_OPT(NORMALVERBOSE)) {
			printf("sntp recv_bcst_pkt: Funny packet length: %i. Discarding package.\n", pkt_len);
			return PACKET_UNUSEABLE;
		}

	/* Packet too big */
	if(pkt_len > LEN_PKT_NOMAC + MAX_MAC_LEN) {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("sntp recv_bcst_pkt: Received packet is too big (%i bytes), trying again to get a useable packet\n", 
					pkt_len);

		return PACKET_UNUSEABLE;
	}
	
	orig_pkt_len = pkt_len;
	pkt_len = min(pkt_len, sizeof(struct pkt));

	/* Let's copy the received data to the packet structure */
	for(a=0; a<pkt_len; a++) 
		if(a < orig_pkt_len)
			((char *)rpkt)[a] = rdata[a];
		else
			((char *)rpkt)[a] = 0;

	free(rdata);

	/* MAC could be useable for us */
	if(has_mac) {
		/* Two more things that the MAC must conform to */
		if(has_mac > MAX_MAC_LEN || has_mac % 4 != 0) {
			is_authentic = 0; /* Or should we discard this packet? */
		}
		else  {
			if(has_mac == MAX_MAC_LEN) {
				struct key *pkt_key = NULL;

				/* Look for the key used by the server in the specified keyfile
				 * and if existent, fetch it or else leave the pointer untouched */
				get_key(rpkt->mac[0], &pkt_key);

				/* Seems like we've got a key with matching keyid */
				if(pkt_key != NULL) {
					/* Generate a md5sum of the packet with the key from our keyfile
					 * and compare those md5sums */
					if(!auth_md5((char *) rpkt, has_mac, pkt_key)) {
						if(ENABLED_OPT(AUTHENTICATION)) {
							/* We want a authenticated packet */
							if(ENABLED_OPT(NORMALVERBOSE)) {
								char *hostname = ss_to_str(sas);
								printf("sntp recv_bcst_pkt: Broadcast packet received from %s is not authentic. Will discard this packet.\n", 
										hostname);

								free(hostname);
							}
							return SERVER_AUTH_FAIL;
						}
						else {
							/* We don't know if the user wanted authentication so let's 
							 * use it anyways */
							if(ENABLED_OPT(NORMALVERBOSE)) {
								char *hostname = ss_to_str(sas);
								printf("sntp recv_bcst_pkt: Broadcast packet received from %s is not authentic. Authentication not enforced.\n", 
										hostname);

								free(hostname);
							}

							is_authentic = 0;
						}
					}
					else {
						/* Yay! Things worked out! */
						if(ENABLED_OPT(NORMALVERBOSE)) {
							char *hostname = ss_to_str(sas);
							printf("sntp recv_bcst_pkt: Broadcast packet received from %s successfully authenticated using key id %i.\n", 
									hostname, rpkt->mac[0]);

							free(hostname);
						}

						is_authentic = 1;
					}
				}
			}
		}
	}

	/* Check for server's ntp version */
	if(PKT_VERSION(rpkt->li_vn_mode) < NTP_OLDVERSION ||
		PKT_VERSION(rpkt->li_vn_mode) > NTP_VERSION) {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("sntp recv_bcst_pkt: Packet shows wrong version (%i)\n", 
					PKT_VERSION(rpkt->li_vn_mode));

		return SERVER_UNUSEABLE;
	} 

	/* We want a server to sync with */
	if(PKT_MODE(rpkt->li_vn_mode) != MODE_BROADCAST
		 && PKT_MODE(rpkt->li_vn_mode) != MODE_PASSIVE) {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("sntp recv_bcst_pkt: mode %d stratum %i\n",
			   PKT_MODE(rpkt->li_vn_mode), rpkt->stratum);

		return SERVER_UNUSEABLE;
	}

	if(rpkt->stratum == STRATUM_PKT_UNSPEC) {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("sntp recv_bcst_pkt: Stratum unspecified, going to check for KOD (stratum: %i)\n", rpkt->stratum);

		char *ref_char = (char *) &rpkt->refid;
		
		/* If it's a KOD packet we'll just use the KOD information */
		if(ref_char[0] != 'X') {
			if(strncmp(ref_char, "DENY", 4))
				return KOD_DEMOBILIZE;

			if(strncmp(ref_char, "RSTR", 4))
				return KOD_DEMOBILIZE;

			if(strncmp(ref_char, "RATE", 4))
				return KOD_RATE;

			/* There are other interesting kiss codes which might be interesting for authentication */
		}
	}

	/* If the server is not synced it's not really useable for us */
	if(PKT_LEAP(rpkt->li_vn_mode) == LEAP_NOTINSYNC) {
		if(ENABLED_OPT(NORMALVERBOSE)) 
			printf("recv_bcst_pkt: Server not in sync, skipping this server\n");

		return SERVER_UNUSEABLE;
	}

	return pkt_len;
}



/* Fetch data, check if it's data for us and whether it's useable or not. If not, return 
 * a failure code so we can delete this server from our list and continue with another one. 
 */
int 
recvpkt (
		SOCKET rsock,
		struct pkt *rpkt,
		struct pkt *spkt
	)
{
	struct sockaddr_storage sender;
	char *rdata, done;

	register int a;
	int has_mac, is_authentic, orig_pkt_len;


	/* Much space, just to be sure */
	rdata = (char *) malloc(sizeof(char) * 256);

	int pkt_len = recvdata(rsock, &sender, rdata, 256);

	if(!done) {
		/* Do something about it, first check for a maximum length of ntp packets,
		 * probably that's something we can avoid 
		 */
	}
	
	/* Some checks to see if that packet is intended for us */

	/* No MAC, no authentication */
	if(pkt_len == LEN_PKT_NOMAC)
		has_mac = 0;

	/* If there's more than just the NTP packet it should be a MAC */	
	else if(pkt_len > LEN_PKT_NOMAC) 
		has_mac = pkt_len - LEN_PKT_NOMAC;
	
	else {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("sntp recvpkt: Funny packet length: %i. Discarding package.\n", pkt_len);

			return PACKET_UNUSEABLE;
	}

	/* Packet too big */
	if(pkt_len > LEN_PKT_MAC) {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("sntp recvpkt: Received packet is too big (%i bytes), trying again to get a useable packet\n", 
					pkt_len);

		return PACKET_UNUSEABLE;
	}

	orig_pkt_len = pkt_len;
	pkt_len = min(pkt_len, sizeof(struct pkt));
	
	for(a=0; a<pkt_len; a++) 
		/* FIXME! */
		if(a < orig_pkt_len)
			((char *) rpkt)[a] = rdata[a];
		else
			((char *) rpkt)[a] = 0;

	/* MAC could be useable for us */
	if(has_mac) {
		/* Two more things that the MAC must conform to */
		if(has_mac > MAX_MAC_LEN || has_mac % 4 != 0) {
			is_authentic = 0; /* Or should we discard this packet? */
		}
		else  {
			if(has_mac == MAX_MAC_LEN) {
				struct key *pkt_key = NULL;
				
				/*
				 * Look for the key used by the server in the specified keyfile
				 * and if existent, fetch it or else leave the pointer untouched 
				 */
				get_key(rpkt->mac[0], &pkt_key);

				/* Seems like we've got a key with matching keyid */
				if(pkt_key != NULL) {
					/*
					 * Generate a md5sum of the packet with the key from our keyfile
					 * and compare those md5sums 
					 */
					if(!auth_md5((char *) rpkt, has_mac, pkt_key)) {
						if(ENABLED_OPT(AUTHENTICATION)) {
							/* We want a authenticated packet */
							if(ENABLED_OPT(NORMALVERBOSE)) {
								char *hostname = ss_to_str(&sender);
								printf("sntp recvpkt: Broadcast packet received from %s is not authentic. Will discard this packet.\n", 
										hostname);

								free(hostname);
							}
							return SERVER_AUTH_FAIL;
						}
						else {
							/* 
							 * We don't know if the user wanted authentication so let's 
							 * use it anyways 
							 */
							if(ENABLED_OPT(NORMALVERBOSE)) {
								char *hostname = ss_to_str(&sender);
								printf("sntp recvpkt: Broadcast packet received from %s is not authentic. Authentication not enforced.\n", 
										hostname);

								free(hostname);
							}

							is_authentic = 0;
						}
					}
					else {
						/* Yay! Things worked out! */
						if(ENABLED_OPT(NORMALVERBOSE)) {
							char *hostname = ss_to_str(&sender);
							printf("sntp recvpkt: Broadcast packet received from %s successfully authenticated using key id %i.\n", 
									hostname, rpkt->mac[0]);

							free(hostname);
						}

						is_authentic = 1;
					}
				}
			}
		}
	}

	/* Check for server's ntp version */
	if(PKT_VERSION(rpkt->li_vn_mode) < NTP_OLDVERSION ||
		PKT_VERSION(rpkt->li_vn_mode) > NTP_VERSION) {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("sntp recvpkt: Packet got wrong version (%i)\n", PKT_VERSION(rpkt->li_vn_mode));

		return SERVER_UNUSEABLE;
	} 

	/* We want a server to sync with */
	if(PKT_MODE(rpkt->li_vn_mode) != MODE_SERVER
		 && PKT_MODE(rpkt->li_vn_mode) != MODE_PASSIVE) {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("sntp recvpkt: mode %d stratum %i\n",
			   PKT_MODE(rpkt->li_vn_mode), rpkt->stratum);

		return SERVER_UNUSEABLE;
	}

	/* Stratum is unspecified (0) check what's going on */
	if(rpkt->stratum == STRATUM_PKT_UNSPEC) {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("sntp recvpkt: Stratum unspecified, going to check for KOD (stratum: %i)\n", rpkt->stratum);


		char *ref_char = (char *) &rpkt->refid;

		if(ENABLED_OPT(NORMALVERBOSE)) 
			printf("sntp recvpkt: Packet refid: %c%c%c%c\n", ref_char[0], ref_char[1], ref_char[2], ref_char[3]);
		
		/* If it's a KOD packet we'll just use the KOD information */
		if(ref_char[0] != 'X') {
			if(!strncmp(ref_char, "DENY", 4))
				return KOD_DEMOBILIZE;

			if(!strncmp(ref_char, "RSTR", 4))
				return KOD_DEMOBILIZE;

			if(!strncmp(ref_char, "RATE", 4))
				return KOD_RATE;

			/* There are other interesting kiss codes which might be interesting for authentication */
		}
	}

	/* If the server is not synced it's not really useable for us */
	if(PKT_LEAP(rpkt->li_vn_mode) == LEAP_NOTINSYNC) {
		if(ENABLED_OPT(NORMALVERBOSE)) 
			printf("sntp recvpkt: Server not in sync, skipping this server\n");

		return SERVER_UNUSEABLE;
	}

	/*
	 * Decode the org timestamp and make sure we're getting a response
	 * to our last request. 
	 */

#ifdef DEBUG
	printf("rpkt->org:\n");
	l_fp_output(&rpkt->org, stdout);
	printf("spkt->xmt:\n");
	l_fp_output(&spkt->xmt, stdout);
#endif
	
	if (!L_ISEQU(&rpkt->org, &spkt->xmt)) {
		if(ENABLED_OPT(NORMALVERBOSE))
			printf("sntp recvpkt: pkt.org and peer.xmt differ\n");
		
		return PACKET_UNUSEABLE;
	}

	return pkt_len;
}

/*
 * is_reachable - check to see if we have a route to given destination
 */
int
is_reachable (
		struct addrinfo *dst
		)
{
	SOCKET sockfd;

	sockfd = socket(dst->ai_family, SOCK_DGRAM, 0);

	if (sockfd == -1) {
#ifdef DEBUG
		printf("is_reachable: Couldn't create socket\n");
#endif
		return 0;
	}

	if(connect(sockfd, dst->ai_addr, SOCKLEN(dst->ai_addr))) {
		closesocket(sockfd);
		return 0;
	}

	closesocket(sockfd);
	return 1;
}
