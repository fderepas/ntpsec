#include "ntpdtest.h"

extern "C" {
#include "ntp.h"
#include "ntp_calendar.h"
#include "ntp_leapsec.h"
}

#include <string>
#include <sstream>

static const char leap1 [] =
    "#\n"
    "#@ 	3610569600\n"
    "#\n"
    "2272060800 10	# 1 Jan 1972\n"
    "2287785600	11	# 1 Jul 1972\n"
    "2303683200	12	# 1 Jan 1973\n"
    "2335219200	13	# 1 Jan 1974\n"
    "2366755200	14	# 1 Jan 1975\n"
    "2398291200	15	# 1 Jan 1976\n"
    "2429913600	16	# 1 Jan 1977\n"
    "2461449600	17	# 1 Jan 1978\n"
    "2492985600	18	# 1 Jan 1979\n"
    "2524521600	19	# 1 Jan 1980\n"
    "   \t  \n"
    "2571782400	20	# 1 Jul 1981\n"
    "2603318400	21	# 1 Jul 1982\n"
    "2634854400	22	# 1 Jul 1983\n"
    "2698012800	23	# 1 Jul 1985\n"
    "2776982400	24	# 1 Jan 1988\n"
    "2840140800	25	# 1 Jan 1990\n"
    "2871676800	26	# 1 Jan 1991\n"
    "2918937600	27	# 1 Jul 1992\n"
    "2950473600	28	# 1 Jul 1993\n"
    "2982009600	29	# 1 Jul 1994\n"
    "3029443200	30	# 1 Jan 1996\n"
    "3076704000	31	# 1 Jul 1997\n"
    "3124137600	32	# 1 Jan 1999\n"
    "3345062400	33	# 1 Jan 2006\n"
    "3439756800	34	# 1 Jan 2009\n"
    "3550089600	35	# 1 Jul 2012\n"
    "#\n"
    "#h	dc2e6b0b 5aade95d a0587abd 4e0dacb4 e4d5049e\n"
    "#\n";

static const char leap2 [] =
    "#\n"
    "#@ 	2950473700\n"
    "#\n"
    "2272060800 10	# 1 Jan 1972\n"
    "2287785600	11	# 1 Jul 1972\n"
    "2303683200	12	# 1 Jan 1973\n"
    "2335219200	13	# 1 Jan 1974\n"
    "2366755200	14	# 1 Jan 1975\n"
    "2398291200	15	# 1 Jan 1976\n"
    "2429913600	16	# 1 Jan 1977\n"
    "2461449600	17	# 1 Jan 1978\n"
    "2492985600	18	# 1 Jan 1979\n"
    "2524521600	19	# 1 Jan 1980\n"
    "2571782400	20	# 1 Jul 1981\n"
    "2603318400	21	# 1 Jul 1982\n"
    "2634854400	22	# 1 Jul 1983\n"
    "2698012800	23	# 1 Jul 1985\n"
    "2776982400	24	# 1 Jan 1988\n"
    "2840140800	25	# 1 Jan 1990\n"
    "2871676800	26	# 1 Jan 1991\n"
    "2918937600	27	# 1 Jul 1992\n"
    "2950473600	28	# 1 Jul 1993\n"
    "#\n";

static u_int32 lsec2009 = 3439756800u; // 1 Jan 2009, 00:00:00 utc
static u_int32 lsec2012 = 3550089600u; // 1 Jul 2012, 00:00:00 utc

int stringreader(void* farg)
{
	const char ** cpp = (const char**)farg;
	if (**cpp)
		return *(*cpp)++;
	else
		return EOF;
}

static int/*BOOL*/
setup_load_table(
	const char * cp,
	int          blim=FALSE)
{
	int            rc;
	leap_table_t * pt = leapsec_get_table(0);
	rc = (pt != NULL) && leapsec_load(pt, stringreader, &cp, blim);
	rc = rc && leapsec_set_table(pt);
	return rc;
}

static int/*BOOL*/
setup_clear_table()
{
	int            rc;
	leap_table_t * pt = leapsec_get_table(0);
	if (pt)
		leapsec_clear(pt);
	rc = leapsec_set_table(pt);
	return rc;
}


class leapsecTest : public ntpdtest {
protected:
	virtual void SetUp();
	virtual void TearDown();

	std::string CalendarToString(const calendar &cal) {
		std::ostringstream ss;
		ss << cal.year << "-" << (u_int)cal.month << "-" << (u_int)cal.monthday
		   << " (" << cal.yearday << ") " << (u_int)cal.hour << ":"
		   << (u_int)cal.minute << ":" << (u_int)cal.second;
		return ss.str();
	}

	::testing::AssertionResult IsEqual(const calendar &expected, const calendar &actual) {
		if (expected.year == actual.year &&
			(expected.yearday == actual.yearday ||
			 (expected.month == actual.month &&
			  expected.monthday == actual.monthday)) &&
			expected.hour == actual.hour &&
			expected.minute == actual.minute &&
			expected.second == actual.second) {
			return ::testing::AssertionSuccess();
		} else {
			return ::testing::AssertionFailure()
				<< "expected: " << CalendarToString(expected) << " but was "
				<< CalendarToString(actual);
		}
	}
	::testing::AssertionResult IsEqual(const vint64 &expected, const vint64 &actual) {
		if (0 == memcmp(&expected, &actual, sizeof(vint64))) {
			return ::testing::AssertionSuccess();
		} else {
			return ::testing::AssertionFailure()
			    << "expected: "
			    << std::hex << expected.D_s.hi << '.'
			    << std::hex << expected.D_s.lo
			    << " but was "
			    << std::hex << actual.D_s.hi << '.'
			    << std::hex << actual.D_s.lo;
		}
	}
};

void leapsecTest::SetUp()
{
    ntpcal_set_timefunc(timefunc);
    settime(1970, 1, 1, 0, 0, 0);
    leapsec_electric(1);
}

void leapsecTest::TearDown()
{
    ntpcal_set_timefunc(NULL);
}

TEST_F(leapsecTest, ParseVUI64) {
	vint64 act, exp;
	const char *sp;
	char       *ep;

	sp         = "1234x";
	exp.D_s.hi = 0;
	exp.D_s.lo = 1234;
	act        = strtouv64(sp, &ep, 0);
	EXPECT_TRUE(IsEqual(exp, act));
	EXPECT_EQ(*ep, 'x');

	sp         = "-1234x";
	exp.D_s.hi = ~0;
	exp.D_s.lo = -1234;
	act        = strtouv64(sp, &ep, 0);
	EXPECT_TRUE(IsEqual(exp, act));
	EXPECT_EQ(*ep, 'x');

	sp         = "0123456789AbCdEf";
	exp.D_s.hi = 0x01234567;
	exp.D_s.lo = 0x89ABCDEF;
	act        = strtouv64(sp, &ep, 16);
	EXPECT_TRUE(IsEqual(exp, act));
	EXPECT_EQ(*ep, '\0');
}

TEST_F(leapsecTest, tableSelect) {
	leap_table_t *pt1, *pt2, *pt3, *pt4;

	pt1 = leapsec_get_table(0);
	pt2 = leapsec_get_table(0);
	EXPECT_EQ(pt1, pt2);

	pt1 = leapsec_get_table(1);
	pt2 = leapsec_get_table(1);
	EXPECT_EQ(pt1, pt2);

	pt1 = leapsec_get_table(1);
	pt2 = leapsec_get_table(0);
	EXPECT_NE(pt1, pt2);

	pt1 = leapsec_get_table(0);
	pt2 = leapsec_get_table(1);
	EXPECT_NE(pt1, pt2);

	leapsec_set_table(pt1);
	pt2 = leapsec_get_table(0);
	pt3 = leapsec_get_table(1);
	EXPECT_EQ(pt1, pt2);
	EXPECT_NE(pt2, pt3);

	pt1 = pt3;
	leapsec_set_table(pt1);
	pt2 = leapsec_get_table(0);
	pt3 = leapsec_get_table(1);
	EXPECT_EQ(pt1, pt2);
	EXPECT_NE(pt2, pt3);
}

TEST_F(leapsecTest, loadFileOk) {
	const char *cp = leap1;
	int rc;
	leap_table_t * pt = leapsec_get_table(0);

	rc =   leapsec_load(pt, stringreader, &cp, FALSE)
	    && leapsec_set_table(pt);
	EXPECT_EQ(1, rc);
	rc = leapsec_expired(3439756800, NULL);
	EXPECT_EQ(0, rc);
	//leapsec_dump(pt, (leapsec_dumper)fprintf, stdout);
}

TEST_F(leapsecTest, loadFileExpire) {
	const char *cp = leap1;
	int rc;
	leap_table_t * pt = leapsec_get_table(0);

	rc =   leapsec_load(pt, stringreader, &cp, FALSE)
	    && leapsec_set_table(pt);
	EXPECT_EQ(1, rc);
	rc = leapsec_expired(3610569601, NULL);
	EXPECT_EQ(1, rc);
}

/* test handling of the leap second at 2009.01.01 */
TEST_F(leapsecTest, ls2009faraway) {
	int            rc;
	leap_result_t  qr;

	rc = setup_load_table(leap1);
	EXPECT_EQ(1, rc);

	// test 60 days before leap. Nothing scheduled or indicated.
	rc = leapsec_query(&qr, lsec2009 - 60*SECSPERDAY, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(33, qr.tai_offs);
	EXPECT_EQ(0,  qr.tai_diff);
	EXPECT_EQ(0,  qr.dist);
	EXPECT_EQ(LSPROX_NOWARN, qr.proximity);
}

/* test handling of the leap second at 2009.01.01 */
TEST_F(leapsecTest, ls2009weekaway) {
	int            rc;
	leap_result_t  qr;

	rc = setup_load_table(leap1);
	EXPECT_EQ(1, rc);

	// test 7 days before leap. Leap scheduled, but not yet indicated.
	rc = leapsec_query(&qr, lsec2009 - 7*SECSPERDAY, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(33, qr.tai_offs);
	EXPECT_EQ(1,  qr.tai_diff);
	EXPECT_EQ(7*SECSPERDAY,  qr.dist);
	EXPECT_EQ(LSPROX_SCHEDULE, qr.proximity);
}

/* test handling of the leap second at 2009.01.01 */
TEST_F(leapsecTest, ls2009houraway) {
	int            rc;
	leap_result_t  qr;

	rc = setup_load_table(leap1);
	EXPECT_EQ(1, rc);

	// test 1 hour before leap. 61 true seconds to go.
	rc = leapsec_query(&qr, lsec2009 - SECSPERHR, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(33, qr.tai_offs);
	EXPECT_EQ(1,  qr.tai_diff);
	EXPECT_EQ(SECSPERHR,  qr.dist);
	EXPECT_EQ(LSPROX_ANNOUNCE, qr.proximity);
}

/* test handling of the leap second at 2009.01.01 */
TEST_F(leapsecTest, ls2009secaway) {
	int            rc;
	leap_result_t  qr;

	rc = setup_load_table(leap1);
	EXPECT_EQ(1, rc);

	// test 1 second before leap (last boundary...) 2 true seconds to go.
	rc = leapsec_query(&qr, lsec2009 - 1, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(33, qr.tai_offs);
	EXPECT_EQ(1,  qr.tai_diff);
	EXPECT_EQ(1,  qr.dist);
	EXPECT_EQ(LSPROX_ALERT, qr.proximity);
}

/* test handling of the leap second at 2009.01.01 */
TEST_F(leapsecTest, ls2009onspot) {
	int            rc;
	leap_result_t  qr;

	rc = setup_load_table(leap1);
	EXPECT_EQ(1, rc);

	// test on-spot: treat leap second as already gone.
	rc = leapsec_query(&qr, lsec2009, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(34, qr.tai_offs);
	EXPECT_EQ(0,  qr.tai_diff);
	EXPECT_EQ(0,  qr.dist);
	EXPECT_EQ(LSPROX_NOWARN, qr.proximity);
}

/* test handling of the leap second at 2009.01.01 */
TEST_F(leapsecTest, ls2009sequenceElectric) {
	int            rc;
	leap_result_t  qr;

	rc = setup_load_table(leap1);
	EXPECT_EQ(1, rc);

	rc = leapsec_query(&qr, lsec2009 - 60*SECSPERDAY, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,             qr.warped   );
	EXPECT_EQ(LSPROX_NOWARN, qr.proximity);

	rc = leapsec_query(&qr, lsec2009 - 7*SECSPERDAY, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,               qr.warped   );
	EXPECT_EQ(LSPROX_SCHEDULE, qr.proximity);

	rc = leapsec_query(&qr, lsec2009 - SECSPERHR, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,               qr.warped   );
	EXPECT_EQ(LSPROX_ANNOUNCE, qr.proximity);

	rc = leapsec_query(&qr, lsec2009 - 1, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,               qr.warped   );
	EXPECT_EQ(LSPROX_ALERT,    qr.proximity);

	rc = leapsec_query(&qr, lsec2009, NULL);
	EXPECT_EQ(TRUE, rc);
	EXPECT_EQ(0,             qr.warped   );
	EXPECT_EQ(LSPROX_NOWARN, qr.proximity);

	// second call, same time frame: no trigger!
	rc = leapsec_query(&qr, lsec2009, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,             qr.warped   );
	EXPECT_EQ(LSPROX_NOWARN, qr.proximity);
}

/* test handling of the leap second at 2009.01.01 */
TEST_F(leapsecTest, ls2009nodata) {
	int            rc;
	leap_result_t  qr;

	rc = setup_clear_table();
	EXPECT_EQ(1, rc);

	// test on-spot with empty table
	rc = leapsec_query(&qr, lsec2009, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,  qr.tai_offs);
	EXPECT_EQ(0,  qr.tai_diff);
	EXPECT_EQ(0,  qr.dist);
}

/* test handling of the leap second at 2009.01.01 */
TEST_F(leapsecTest, ls2009limdata) {
	int            rc;
	leap_result_t  qr;

	rc = setup_load_table(leap1, TRUE);
	EXPECT_EQ(1, rc);

	// test on-spot with limted table - does not work if build before 2013!
	rc = leapsec_query(&qr, lsec2009, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(35, qr.tai_offs);
	EXPECT_EQ(0,  qr.tai_diff);
	EXPECT_EQ(0,  qr.dist);
}

TEST_F(leapsecTest, addManual) {
	int            rc;
	leap_result_t  qr;

	static const u_int32 insns[] = {
		2982009600,	//	29	# 1 Jul 1994
		3029443200,	//	30	# 1 Jan 1996
		3076704000,	//	31	# 1 Jul 1997
		3124137600,	//	32	# 1 Jan 1999
		3345062400,	//	33	# 1 Jan 2006
		3439756800,	//	34	# 1 Jan 2009
		3550089600,	//	35	# 1 Jul 2012
		0 // sentinel
	};

	rc = setup_load_table(leap2, FALSE);
	EXPECT_EQ(1, rc);

	leap_table_t * pt = leapsec_get_table(0);
	for (int idx=1; insns[idx]; ++idx) {
	    rc = leapsec_add_dyn(insns[idx] - 20*SECSPERDAY - 100, 1, NULL);
		EXPECT_EQ(TRUE, rc);
	}
	// try to slip in a previous entry
	rc = leapsec_add_dyn(insns[0] - 20*SECSPERDAY - 100, 1, NULL);
	EXPECT_EQ(FALSE, rc);
	//leapsec_dump(pt, (leapsec_dumper)fprintf, stdout);
}

TEST_F(leapsecTest, addFixed) {
	int            rc;
	leap_result_t  qr;

	static const struct { u_int32 tt; int of; } insns[] = {
		{2982009600, 29},//	# 1 Jul 1994
		{3029443200, 30},//	# 1 Jan 1996
		{3076704000, 31},//	# 1 Jul 1997
		{3124137600, 32},//	# 1 Jan 1999
		{3345062400, 33},//	# 1 Jan 2006
		{3439756800, 34},//	# 1 Jan 2009
		{3550089600, 35},//	# 1 Jul 2012
		{0,0} // sentinel
	};

	rc = setup_load_table(leap2, FALSE);
	EXPECT_EQ(1, rc);

	leap_table_t * pt = leapsec_get_table(0);
	// try to get in BAD time stamps...
	for (int idx=0; insns[idx].tt; ++idx) {
	    rc = leapsec_add_fix(insns[idx].tt - 20*SECSPERDAY - 100,
				 insns[idx].tt + SECSPERDAY,
				 insns[idx].of,
				 NULL);
		EXPECT_EQ(FALSE, rc);
	}
	// no do it right
	for (int idx=0; insns[idx].tt; ++idx) {
		rc = leapsec_add_fix(insns[idx].tt,
				 insns[idx].tt + SECSPERDAY,
				 insns[idx].of,
				 NULL);
		EXPECT_EQ(TRUE, rc);
	}
	// try to slip in a previous entry
	rc = leapsec_add_fix(insns[0].tt,
			     insns[0].tt + SECSPERDAY,
			     insns[0].of,
			     NULL);
	EXPECT_EQ(FALSE, rc);
	//leapsec_dump(pt, (leapsec_dumper)fprintf, stdout);
}

/* test handling of the leap second at 2012.07.01 */
TEST_F(leapsecTest, ls2012sequenceElectric) {
	int            rc;
	leap_result_t  qr;

	rc = setup_load_table(leap1);
	EXPECT_EQ(1, rc);

	rc = leapsec_query(&qr, lsec2012 - 60*SECSPERDAY, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,             qr.warped   );
	EXPECT_EQ(LSPROX_NOWARN, qr.proximity);

	rc = leapsec_query(&qr, lsec2012 - 7*SECSPERDAY, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,               qr.warped   );
	EXPECT_EQ(LSPROX_SCHEDULE, qr.proximity);

	rc = leapsec_query(&qr, lsec2012 - SECSPERHR, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,               qr.warped   );
	EXPECT_EQ(LSPROX_ANNOUNCE, qr.proximity);

	rc = leapsec_query(&qr, lsec2012 - 1, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,               qr.warped   );
	EXPECT_EQ(LSPROX_ALERT,    qr.proximity);

	rc = leapsec_query(&qr, lsec2012, NULL);
	EXPECT_EQ(TRUE, rc);
	EXPECT_EQ(0,            qr.warped   );
	EXPECT_EQ(LSPROX_NOWARN, qr.proximity);

	// second call, same time frame: no trigger!
	rc = leapsec_query(&qr, lsec2012, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,             qr.warped   );
	EXPECT_EQ(LSPROX_NOWARN, qr.proximity);
}

/* test handling of the leap second at 2012.07.01 */
TEST_F(leapsecTest, ls2012sequenceDumb) {
	int            rc;
	leap_result_t  qr;

	leapsec_electric(0);
	EXPECT_EQ(0, leapsec_electric(-1));
	EXPECT_EQ(0, leapsec_electric(-1));

	rc = setup_load_table(leap1);
	EXPECT_EQ(1, rc);

	rc = leapsec_query(&qr, lsec2012 - 60*SECSPERDAY, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,             qr.warped   );
	EXPECT_EQ(LSPROX_NOWARN, qr.proximity);

	rc = leapsec_query(&qr, lsec2012 - 7*SECSPERDAY, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,               qr.warped   );
	EXPECT_EQ(LSPROX_SCHEDULE, qr.proximity);

	rc = leapsec_query(&qr, lsec2012 - SECSPERHR, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,               qr.warped   );
	EXPECT_EQ(LSPROX_ANNOUNCE, qr.proximity);

	rc = leapsec_query(&qr, lsec2012 - 1, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,               qr.warped   );
	EXPECT_EQ(LSPROX_ALERT,    qr.proximity);

	// This is just 1 sec before transition!
	rc = leapsec_query(&qr, lsec2012, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,            qr.warped   );
	EXPECT_EQ(LSPROX_ALERT, qr.proximity);

	// NOW the insert/backwarp must happen
	rc = leapsec_query(&qr, lsec2012+1, NULL);
	EXPECT_EQ(TRUE, rc);
	EXPECT_EQ(-1,            qr.warped   );
	EXPECT_EQ(LSPROX_NOWARN, qr.proximity);

	// second call with transition time: no trigger!
	rc = leapsec_query(&qr, lsec2012, NULL);
	EXPECT_EQ(FALSE, rc);
	EXPECT_EQ(0,             qr.warped   );
	EXPECT_EQ(LSPROX_NOWARN, qr.proximity);
}

