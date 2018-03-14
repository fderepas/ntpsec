/* WARNING! All changes made to this file will be lost! */

#ifndef W_CONFIG_H_WAF
#define W_CONFIG_H_WAF

#define NTPSEC_VERSION_STRING "1.0.1-1e3fee3"
#define HAS_f_stack_protector_all 1
#define HAS_PIC 1
#define HAS_PIE 1
/* #undef HAS_unused */
#define HAS_w_cast_qual 1
#define HAS_w_disabled_optimization 1
#define HAS_w_float_equal 1
#define HAS_w_format 1
#define HAS_w_format_security 1
#define HAS_w_format_signedness 1
#define HAS_w_implicit_function_declaration 1
#define HAS_w_init_self 1
#define HAS_w_invalid_pch 1
#define HAS_w_missing_declarations 1
#define HAS_w_multichar 1
#define HAS_w_packed 1
#define HAS_w_pointer_arith 1
#define HAS_w_shadow 1
#define HAS_w_suggest_attribute_noreturn 1
#define HAS_w_write_strings 1
#define HAS_LTO 1
#define HAS_z_now 1
#define HAS_stripall 1
#define HAS_relro 1
/* #undef HAVE_STRUCT_IF_LADDRCONF */
/* #undef HAVE_STRUCT_IF_LADDRREQ */
#define HAVE_STRUCT_TIMEX 1
#define HAVE_STRUCT_NTPTIMEVAL 1
/* #undef HAVE_STRUCT_TIMEX_TIME_TICK */
#define HAVE_STRUCT_TIMEX_MODES 1
/* #undef HAVE_STRUCT_NTPTIMEVAL_TIME_TV_NSEC */
#define HAVE_STRUCT_NTPTIMEVAL_TAI 1
#define NTP_SIZEOF_LONG 8 /* Size of long from <None> */
#define NTP_SIZEOF_TIME_T 8 /* Size of time_t from <time.h> */
#define OPEN_BCAST_SOCKET 1 /* Whether to open a broadcast socket */
#define HAVE__UNWIND_BACKTRACE 1 /* Whether _Unwind_Backtrace() exists */
#define HAVE_ADJTIMEX 1 /* Whether adjtimex() exists */
#define HAVE_BACKTRACE_SYMBOLS_FD 1 /* Whether backtrace_symbols_fd() exists */
/* #undef HAVE_CLOSEFROM */
#define HAVE_CLOCK_GETTIME 1 /* Whether clock_gettime() exists */
#define HAVE_CLOCK_SETTIME 1 /* Whether clock_settime() exists */
#define HAVE_NTP_ADJTIME 1 /* Whether ntp_adjtime() exists */
#define HAVE_NTP_GETTIME 1 /* Whether ntp_gettime() exists */
#define HAVE_RES_INIT 1 /* Whether res_init() exists */
#define HAVE_SCHED_SETSCHEDULER 1 /* Whether sched_setscheduler() exists */
/* #undef HAVE_STRLCPY */
/* #undef HAVE_STRLCAT */
/* #undef HAVE_TIMER_CREATE */
#define HAVE_STDBOOL_H 1 /* Sanity check. */
#define HAVE_ALLOCA_H 1 /* <alloca.h> header */
#define HAVE_ARPA_NAMESER_H 1 /* <arpa/nameser.h> header */
#define HAVE_DNS_SD_H 1
/* #undef HAVE_BSD_STRING_H */
#define HAVE_IFADDRS_H 1 /* <ifaddrs.h> header */
#define HAVE_LINUX_IF_ADDR_H 1 /* <linux/if_addr.h> header */
#define HAVE_LINUX_RTNETLINK_H 1 /* <linux/rtnetlink.h> header */
#define HAVE_LINUX_SERIAL_H 1 /* <linux/serial.h> header */
/* #undef HAVE_NET_IF6_H */
#define HAVE_NET_ROUTE_H 1 /* <net/route.h> header */
/* #undef HAVE_NETINFO_NI_H */
/* #undef HAVE_PRIV_H */
#define HAVE_SEMAPHORE_H 1 /* <semaphore.h> header */
#define HAVE_STDATOMIC_H 1 /* <stdatomic.h> header */
/* #undef HAVE_SYS_CLOCKCTL_H */
#define HAVE_SYS_IOCTL_H 1 /* <sys/ioctl.h> header */
/* #undef HAVE_SYS_MODEM_H */
/* #undef HAVE_SYS_SOCKIO_H */
#define HAVE_SYS_SYSCTL_H 1 /* <sys/sysctl.h> header */
/* #undef HAVE_TIMEPPS_H */
#define HAVE_SYS_TIMEPPS_H 1 /* <sys/timepps.h> header */
#define HAVE_SYS_TIMEX_H 1 /* <sys/timex.h> header */
#define HAVE_PPSAPI 1 /* Enable the PPS API */
/* #undef ISC_PLATFORM_HAVESALEN */
/* #undef HAVE_LIBSCF_H */
#define ENABLE_DROPROOT 1 /* Drop root after initialising */
#define ENABLE_DNS_LOOKUP 1 /* Enable DNS lookup of hostnames */
#define HAVE_WORKING_FORK 1 /* Whether a working fork() exists */
#define NEED_REUSEADDR_FOR_IFADDRBIND 1 /* Whether SO_REUSEADDR is needed to open same sockets on alternate interfaces, required by Linux at least */
#define VSNPRINTF_PERCENT_M 1 /* %m expanding to strerror(error) in glibc style */
#define DIR_SEP '/' /* Directory separator used */
#define HAVE_IFLIST_SYSCTL 1 /* Whether sysctl interface exists */
#define HAVE_SYS_PRCTL_H 1
#define HAVE_SYS_CAPABILITY_H 1
#define HAVE_LINUX_CAPABILITY 1
#define HAVE_PTHREAD_H 1 /* pthread header */
#define HAVE_PTHREAD 1 /* pthread support */
#define HAVE_MDNS 1 /* Multicast DNS support */
#define ENABLE_MDNS_REGISTRATION 1 /* Multicast DNS support */
/* #undef ENABLE_CLASSIC_MODE */
/* #undef ENABLE_DEBUG_TIMING */
#define BUILD_EPOCH 1521036402 /* Using default */

#endif /* W_CONFIG_H_WAF */
