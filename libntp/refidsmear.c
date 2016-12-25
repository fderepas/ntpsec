#include <config.h>

#include <ntp.h>
#include <ntp_fp.h>
#include <refidsmear.h>

/*
 * we want to test a refid format of:
 * 254.x.y.x
 *
 * where x.y.z are 24 bits containing 2 (signed) integer bits
 * and 22 fractional bits.
 *
 */


l_fp
convertRefIDToLFP(uint32_t r)
{
	l_fp temp;

	r = ntohl(r);

	// printf("%03d %08x: ", (r >> 24) & 0xFF, (r & 0x00FFFFFF) );

	setlfpfrac(temp, r << 10);	/* 22 fractional bits */

	r = (r >> 22) & 0x3;
	r |= ~(r & 2) + 1;
	setlfpuint(temp, r);

	return temp;
}


uint32_t
convertLFPToRefID(l_fp num)
{
	uint32_t temp;

	/* round the input with the highest bit to shift out from the
	 * fraction, then keep just two bits from the integral part.
	 *
	 * TODO: check for overflows; should we clamp/saturate or just
	 * complain?
	 */
	setlfpfrac(num, lfpfrac(num) + 0x200);

	/* combine integral and fractional part to 24 bits */
	temp  = ((lfpuint(num) & 3) << 22) | (lfpfrac(num) >> 10);

	/* put in the leading 254.0.0.0 */
	temp |= UINT32_C(0xFE000000);

	// printf("%03d %08x: ", (temp >> 24) & 0xFF, (temp & 0x00FFFFFF) );

	return htonl(temp);
}
