/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 13 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:339  */

  #include "config.h"

  #include "ntp.h"
  #include "ntpd.h"
  #include "ntp_machine.h"
  #include "ntp_stdlib.h"
  #include "ntp_filegen.h"
  #include "ntp_scanner.h"
  #include "ntp_config.h"

  #define YYMALLOC	emalloc
  #define YYFREE	free
  #define YYERROR_VERBOSE
  #define YYMAXDEPTH	1000	/* stop the madness sooner */
  void yyerror(const char *msg);

#line 84 "ntp_parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "ntp_parser.tab.h".  */
#ifndef YY_YY_NTP_PARSER_TAB_H_INCLUDED
# define YY_YY_NTP_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_Age = 258,
    T_All = 259,
    T_Allan = 260,
    T_Allpeers = 261,
    T_Auth = 262,
    T_Average = 263,
    T_Baud = 264,
    T_Bias = 265,
    T_Burst = 266,
    T_Calibrate = 267,
    T_Ceiling = 268,
    T_Clock = 269,
    T_Clockstats = 270,
    T_Cohort = 271,
    T_ControlKey = 272,
    T_Ctl = 273,
    T_Day = 274,
    T_Default = 275,
    T_Disable = 276,
    T_Discard = 277,
    T_Dispersion = 278,
    T_Double = 279,
    T_Driftfile = 280,
    T_Drop = 281,
    T_Dscp = 282,
    T_Ellipsis = 283,
    T_Enable = 284,
    T_End = 285,
    T_False = 286,
    T_File = 287,
    T_Filegen = 288,
    T_Filenum = 289,
    T_Flag1 = 290,
    T_Flag2 = 291,
    T_Flag3 = 292,
    T_Flag4 = 293,
    T_Flake = 294,
    T_Floor = 295,
    T_Freq = 296,
    T_Fudge = 297,
    T_Holdover = 298,
    T_Huffpuff = 299,
    T_Iburst = 300,
    T_Ignore = 301,
    T_Incalloc = 302,
    T_Incmem = 303,
    T_Initalloc = 304,
    T_Initmem = 305,
    T_Includefile = 306,
    T_Integer = 307,
    T_Interface = 308,
    T_Intrange = 309,
    T_Io = 310,
    T_Ipv4 = 311,
    T_Ipv4_flag = 312,
    T_Ipv6 = 313,
    T_Ipv6_flag = 314,
    T_Kernel = 315,
    T_Key = 316,
    T_Keys = 317,
    T_Kod = 318,
    T_Mssntp = 319,
    T_Leapfile = 320,
    T_Leapsmearinterval = 321,
    T_Limited = 322,
    T_Link = 323,
    T_Listen = 324,
    T_Logconfig = 325,
    T_Logfile = 326,
    T_Loopstats = 327,
    T_Mask = 328,
    T_Maxage = 329,
    T_Maxclock = 330,
    T_Maxdepth = 331,
    T_Maxdisp = 332,
    T_Maxdist = 333,
    T_Maxmem = 334,
    T_Maxpoll = 335,
    T_Mdnstries = 336,
    T_Mem = 337,
    T_Memlock = 338,
    T_Minage = 339,
    T_Minclock = 340,
    T_Mindepth = 341,
    T_Mindist = 342,
    T_Minimum = 343,
    T_Minpoll = 344,
    T_Minsane = 345,
    T_Mode = 346,
    T_Monitor = 347,
    T_Month = 348,
    T_Mru = 349,
    T_Nic = 350,
    T_Nolink = 351,
    T_Nomodify = 352,
    T_Nomrulist = 353,
    T_None = 354,
    T_Nonvolatile = 355,
    T_Nopeer = 356,
    T_Noquery = 357,
    T_Noselect = 358,
    T_Noserve = 359,
    T_Notrap = 360,
    T_Notrust = 361,
    T_Ntp = 362,
    T_Ntpport = 363,
    T_NtpSignDsocket = 364,
    T_Orphan = 365,
    T_Orphanwait = 366,
    T_Panic = 367,
    T_Path = 368,
    T_Peer = 369,
    T_Peerstats = 370,
    T_Phone = 371,
    T_Pid = 372,
    T_Pidfile = 373,
    T_Pool = 374,
    T_Ppspath = 375,
    T_Port = 376,
    T_Prefer = 377,
    T_Protostats = 378,
    T_Rawstats = 379,
    T_Refclock = 380,
    T_Refid = 381,
    T_Requestkey = 382,
    T_Reset = 383,
    T_Restrict = 384,
    T_Rlimit = 385,
    T_Saveconfigdir = 386,
    T_Server = 387,
    T_Setvar = 388,
    T_Source = 389,
    T_Stacksize = 390,
    T_Statistics = 391,
    T_Stats = 392,
    T_Statsdir = 393,
    T_Step = 394,
    T_Stepback = 395,
    T_Stepfwd = 396,
    T_Stepout = 397,
    T_Stratum = 398,
    T_Subtype = 399,
    T_String = 400,
    T_Sys = 401,
    T_Sysstats = 402,
    T_Tick = 403,
    T_Time1 = 404,
    T_Time2 = 405,
    T_Timer = 406,
    T_Timingstats = 407,
    T_Tinker = 408,
    T_Tos = 409,
    T_Trap = 410,
    T_True = 411,
    T_Trustedkey = 412,
    T_Type = 413,
    T_U_int = 414,
    T_Unit = 415,
    T_Unconfig = 416,
    T_Unpeer = 417,
    T_Unrestrict = 418,
    T_Usestats = 419,
    T_Version = 420,
    T_WanderThreshold = 421,
    T_Week = 422,
    T_Wildcard = 423,
    T_Year = 424,
    T_Flag = 425,
    T_EOC = 426
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:355  */

	char *			String;
	double			Double;
	int			Integer;
	unsigned		U_int;
	gen_fifo *		Generic_fifo;
	attr_val *		Attr_val;
	attr_val_fifo *		Attr_val_fifo;
	int_fifo *		Int_fifo;
	string_fifo *		String_fifo;
	address_node *		Address_node;
	address_fifo *		Address_fifo;
	setvar_node *		Set_var;

#line 311 "ntp_parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_NTP_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 328 "ntp_parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  181
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   541

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  175
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  274
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  352

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   426

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     173,   174,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   172,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   305,   305,   309,   310,   311,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     347,   357,   358,   359,   363,   364,   369,   374,   376,   382,
     383,   391,   392,   393,   394,   395,   399,   404,   405,   406,
     407,   408,   412,   414,   416,   428,   429,   430,   431,   432,
     433,   434,   435,   439,   444,   449,   451,   453,   458,   459,
     460,   464,   465,   466,   467,   476,   484,   498,   499,   509,
     520,   522,   524,   530,   532,   542,   547,   552,   560,   562,
     564,   569,   570,   571,   572,   573,   577,   578,   579,   580,
     581,   590,   592,   601,   611,   616,   624,   625,   626,   627,
     628,   629,   630,   631,   636,   637,   645,   655,   664,   679,
     684,   685,   689,   690,   694,   695,   696,   697,   698,   699,
     700,   709,   710,   714,   718,   722,   730,   738,   746,   761,
     776,   789,   790,   798,   799,   800,   801,   802,   803,   804,
     805,   806,   807,   808,   809,   810,   811,   815,   820,   828,
     833,   834,   835,   839,   844,   852,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   873,   883,   888,   896,   898,
     900,   909,   914,   915,   919,   920,   921,   922,   930,   942,
     944,   954,   959,   964,   972,   977,   978,   979,   988,   990,
     995,  1000,  1008,  1010,  1027,  1028,  1029,  1030,  1034,  1042,
    1047,  1052,  1060,  1065,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,  1073,  1074,  1083,  1084,  1085,  1092,  1099,  1106,  1122,
    1141,  1143,  1145,  1147,  1149,  1154,  1155,  1159,  1163,  1172,
    1176,  1177,  1178,  1182,  1193,  1203,  1212,  1217,  1219,  1223,
    1228,  1236,  1261,  1268,  1278,  1279,  1283,  1284,  1285,  1286,
    1290,  1291,  1292,  1296,  1301,  1306,  1314,  1315,  1316,  1317,
    1318,  1319,  1320,  1330,  1335,  1343,  1345,  1349,  1354,  1359,
    1367,  1376,  1377,  1381,  1382
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Age", "T_All", "T_Allan",
  "T_Allpeers", "T_Auth", "T_Average", "T_Baud", "T_Bias", "T_Burst",
  "T_Calibrate", "T_Ceiling", "T_Clock", "T_Clockstats", "T_Cohort",
  "T_ControlKey", "T_Ctl", "T_Day", "T_Default", "T_Disable", "T_Discard",
  "T_Dispersion", "T_Double", "T_Driftfile", "T_Drop", "T_Dscp",
  "T_Ellipsis", "T_Enable", "T_End", "T_False", "T_File", "T_Filegen",
  "T_Filenum", "T_Flag1", "T_Flag2", "T_Flag3", "T_Flag4", "T_Flake",
  "T_Floor", "T_Freq", "T_Fudge", "T_Holdover", "T_Huffpuff", "T_Iburst",
  "T_Ignore", "T_Incalloc", "T_Incmem", "T_Initalloc", "T_Initmem",
  "T_Includefile", "T_Integer", "T_Interface", "T_Intrange", "T_Io",
  "T_Ipv4", "T_Ipv4_flag", "T_Ipv6", "T_Ipv6_flag", "T_Kernel", "T_Key",
  "T_Keys", "T_Kod", "T_Mssntp", "T_Leapfile", "T_Leapsmearinterval",
  "T_Limited", "T_Link", "T_Listen", "T_Logconfig", "T_Logfile",
  "T_Loopstats", "T_Mask", "T_Maxage", "T_Maxclock", "T_Maxdepth",
  "T_Maxdisp", "T_Maxdist", "T_Maxmem", "T_Maxpoll", "T_Mdnstries",
  "T_Mem", "T_Memlock", "T_Minage", "T_Minclock", "T_Mindepth",
  "T_Mindist", "T_Minimum", "T_Minpoll", "T_Minsane", "T_Mode",
  "T_Monitor", "T_Month", "T_Mru", "T_Nic", "T_Nolink", "T_Nomodify",
  "T_Nomrulist", "T_None", "T_Nonvolatile", "T_Nopeer", "T_Noquery",
  "T_Noselect", "T_Noserve", "T_Notrap", "T_Notrust", "T_Ntp", "T_Ntpport",
  "T_NtpSignDsocket", "T_Orphan", "T_Orphanwait", "T_Panic", "T_Path",
  "T_Peer", "T_Peerstats", "T_Phone", "T_Pid", "T_Pidfile", "T_Pool",
  "T_Ppspath", "T_Port", "T_Prefer", "T_Protostats", "T_Rawstats",
  "T_Refclock", "T_Refid", "T_Requestkey", "T_Reset", "T_Restrict",
  "T_Rlimit", "T_Saveconfigdir", "T_Server", "T_Setvar", "T_Source",
  "T_Stacksize", "T_Statistics", "T_Stats", "T_Statsdir", "T_Step",
  "T_Stepback", "T_Stepfwd", "T_Stepout", "T_Stratum", "T_Subtype",
  "T_String", "T_Sys", "T_Sysstats", "T_Tick", "T_Time1", "T_Time2",
  "T_Timer", "T_Timingstats", "T_Tinker", "T_Tos", "T_Trap", "T_True",
  "T_Trustedkey", "T_Type", "T_U_int", "T_Unit", "T_Unconfig", "T_Unpeer",
  "T_Unrestrict", "T_Usestats", "T_Version", "T_WanderThreshold", "T_Week",
  "T_Wildcard", "T_Year", "T_Flag", "T_EOC", "'='", "'('", "')'",
  "$accept", "configuration", "command_list", "command", "server_command",
  "client_type", "address", "ip_address", "address_fam", "option_list",
  "option", "option_flag", "option_flag_keyword", "option_int",
  "option_int_keyword", "option_double", "option_boolean", "option_string",
  "option_double_keyword", "option_bool_keyword", "unpeer_command",
  "unpeer_keyword", "other_mode_command", "authentication_command",
  "orphan_mode_command", "tos_option_list", "tos_option",
  "tos_option_int_keyword", "tos_option_dbl_keyword", "monitoring_command",
  "stats_list", "stat", "filegen_option_list", "filegen_option",
  "link_nolink", "enable_disable", "filegen_type", "restrict_prefix",
  "access_control_command", "ac_flag_list", "access_control_flag",
  "discard_option_list", "discard_option", "discard_option_keyword",
  "mru_option_list", "mru_option", "mru_option_keyword", "fudge_command",
  "fudge_factor_list", "fudge_factor", "fudge_factor_dbl_keyword",
  "fudge_factor_bool_keyword", "refclock_command", "optional_unit",
  "rlimit_command", "rlimit_option_list", "rlimit_option",
  "rlimit_option_keyword", "system_option_command", "system_option_list",
  "system_option", "system_option_flag_keyword",
  "system_option_local_flag_keyword", "tinker_command",
  "tinker_option_list", "tinker_option", "tinker_option_keyword",
  "miscellaneous_command", "misc_cmd_dbl_keyword", "misc_cmd_int_keyword",
  "misc_cmd_str_keyword", "misc_cmd_str_lcl_keyword", "drift_parm",
  "variable_assign", "t_default_or_zero", "log_config_list",
  "log_config_command", "interface_command", "interface_nic",
  "nic_rule_class", "nic_rule_action", "reset_command", "counter_set_list",
  "counter_set_keyword", "integer_list_range", "integer_list_range_elt",
  "integer_range", "string_list", "boolean", "number", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,    61,    40,    41
};
# endif

#define YYPACT_NINF -210

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-210)))

#define YYTABLE_NINF -7

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,  -162,   -37,    66,    -4,  -127,  -210,    66,  -210,   -12,
     -21,  -117,  -210,  -114,  -210,  -210,  -111,  -210,   -13,   165,
    -210,  -210,  -100,  -210,   -99,  -210,  -210,   -96,     3,    41,
    -210,   -15,  -210,  -210,   -87,   -12,   -84,  -210,    69,   430,
     -39,  -210,  -210,  -210,    67,   246,   -98,  -210,   -21,  -210,
      23,  -210,  -210,  -210,  -210,    82,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,    -8,    24,   -70,   -68,  -210,   121,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,    66,  -210,  -210,
    -210,  -210,  -210,  -210,    -4,  -210,    31,    61,  -210,    66,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,   199,  -210,   -59,   368,  -210,  -210,  -111,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
     165,  -210,    35,  -210,  -210,   -56,   -69,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,    41,  -210,  -210,  -210,  -210,
     -15,  -210,    38,   -79,  -210,   -12,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,    69,  -210,
      -8,  -210,   -11,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,   430,  -210,    45,    -8,  -210,    47,   -39,  -210,
    -210,  -210,   -66,  -210,  -210,   -30,  -210,  -210,    86,    88,
    -210,  -210,    64,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,    -2,  -210,  -210,  -210,  -210,    11,  -210,  -210,
    -210,  -210,    -3,    94,  -210,  -210,   199,  -210,    -8,   -11,
    -210,  -210,  -210,  -210,  -210,  -210,   103,  -210,  -210,  -210,
    -210,    14,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,   128,  -210,  -210,   140,   -69,   231,  -210,  -210,
     231,   231,    19,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,    20,  -210,  -210,     5,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,   140,   150,   127,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,    37,    39,  -210,    43,   134,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,   -38,  -210,  -210,  -210,    -8,
     -11,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,   231,   231,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,     6,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
     231,  -210
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,   235,   227,     0,   220,     0,
       0,     0,   244,     0,   229,   228,     0,   230,     0,     0,
     245,   225,     0,    23,     0,   231,    22,     0,     0,     0,
     121,     0,   232,    21,     0,     0,     0,   226,     0,     0,
       0,    67,    68,   122,     0,     2,     0,     7,     0,     8,
       0,     9,    10,    13,    11,     0,    12,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,   213,     0,   214,
       5,    70,   194,   195,   196,   197,   198,   189,   191,   192,
     193,   150,   151,   152,   123,   148,     0,   233,   221,   188,
      96,    97,    98,   101,    99,   100,   102,   103,   104,    27,
      28,    26,     0,    24,     0,     6,    71,   241,   222,   240,
      69,   156,   157,   158,   159,   160,   162,   163,   161,   164,
     124,   154,     0,    74,   269,   223,   179,    72,   256,   257,
     258,   259,   260,   261,   262,   253,   255,   187,   185,   186,
     181,   183,     0,     0,   224,    91,    95,    92,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   199,   201,
       0,    81,     0,    82,    90,    87,    88,    89,    86,    85,
      83,    84,    75,    77,     0,     0,   265,     0,    73,   264,
     266,     1,     0,     4,    29,     0,    65,   131,    27,    28,
     131,   131,    24,   274,   273,   215,   216,   217,   218,   252,
     251,   250,     0,   190,   147,   149,   234,    93,   174,   175,
     176,   177,     0,     0,   172,   173,   165,   167,     0,     0,
      25,   219,   239,   153,   155,   268,     0,    29,   254,   182,
     184,     0,    94,   200,   202,   272,   270,   271,    80,    76,
      78,    79,     0,   263,     3,    20,   179,   127,   131,   131,
     130,   125,     0,   246,   247,   248,   243,   249,   242,   113,
     112,     0,   110,   111,     0,   105,   108,   109,   171,   170,
     166,   168,   169,   180,   178,   238,     0,    51,    58,    37,
      61,    62,    63,    64,    52,    38,    45,    47,    46,    48,
      39,     0,     0,    40,     0,     0,    49,    59,    60,    41,
      50,    30,    31,    36,    32,     0,    33,    35,    34,     0,
       0,    66,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   132,   128,   129,   131,
     106,   120,   116,   118,   114,   115,   117,   119,   107,   237,
     236,     0,    56,    57,    55,    44,    42,    43,    53,    54,
     126,   267
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,  -210,  -210,   -33,  -210,  -210,     2,   -55,  -210,   -36,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,    17,  -210,  -210,  -210,
    -210,   -28,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -185,
    -210,  -210,   109,  -210,  -210,    74,  -210,  -210,  -210,   -20,
    -210,  -210,  -210,   -51,  -210,  -210,    58,  -210,  -210,   192,
     -54,  -210,  -210,  -210,  -210,    42,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,    96,  -210,  -210,  -210,
    -210,  -210,  -210,    70,  -210,    28,  -210,  -210,  -209,  -149
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    44,    45,    46,    47,    48,   102,   103,   104,   245,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
      49,    50,    51,    52,    53,   172,   173,   174,   175,    54,
     145,    98,   207,   265,   266,   267,   338,    55,    56,   247,
     326,    84,    85,    86,   120,   121,   122,    57,   216,   217,
     218,   219,    58,   227,    59,   140,   141,   142,    60,    77,
      78,    79,    80,    61,   158,   159,   160,    62,    63,    64,
      65,    66,    88,   144,   340,   108,   109,    67,    68,   258,
     202,    69,   135,   136,   178,   179,   180,   125,   238,   195
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     192,     1,   253,    90,    81,   250,   251,   146,   331,    70,
     272,   234,   182,   176,   346,    71,   193,     2,    87,   137,
     235,     3,     4,   203,   332,     5,   241,     6,   105,     7,
       8,   106,   259,     9,   107,   203,    99,   185,   100,   110,
     260,   236,    10,   261,   194,   123,   124,   128,   129,   126,
     184,    11,   186,    12,   254,   127,   255,   191,   143,   130,
      91,   147,    13,   327,   328,    14,    15,   181,   138,   271,
      16,    17,   221,   183,   148,   197,   196,   198,    72,   262,
      99,    18,   100,   205,    82,   206,   220,   224,    83,   225,
     230,   226,   149,   231,    19,    20,   131,   240,   333,   242,
      21,   349,   187,    92,   334,   244,   248,   263,   249,    22,
     150,    93,    94,   151,    23,   246,    24,   232,    25,    26,
     139,   347,   335,   132,   101,    27,    73,    28,    29,    30,
      31,    32,    33,    34,   177,    95,    35,   252,    36,   188,
      96,   189,   268,   256,   350,   237,   269,   199,    37,   277,
     278,   279,    97,    38,    39,   273,   276,    40,    74,   275,
     348,    41,    42,    43,   101,   330,   257,   200,   101,   264,
     339,    -6,   336,    75,   337,   280,   281,   282,   283,   341,
     351,   152,   342,   284,   343,   285,   345,   133,   344,   239,
     201,   274,   134,   204,   223,   311,   270,   329,   229,    89,
     233,   286,     0,    76,   222,   228,   243,     0,   153,   154,
     155,   156,   111,   112,   113,   114,   190,   157,     0,     0,
     287,     0,     0,     0,     0,     0,     0,   101,     0,   288,
       0,   289,     0,     0,   208,   209,   210,   211,     0,   115,
       0,   116,     0,   290,   117,     0,     0,     0,     0,   118,
       0,   119,     0,   291,     0,     0,     0,     0,     0,     0,
     292,     0,   293,     2,     0,     0,   294,     3,     4,     0,
     312,     5,     0,     6,     0,     7,     8,   313,     0,     9,
       0,     0,     0,   295,   296,     0,     0,     0,    10,   297,
     298,     0,     0,     0,   314,   315,   299,    11,   316,    12,
       0,     0,     0,     0,     0,   300,     0,     0,    13,     0,
       0,    14,    15,     0,     0,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,   212,     0,    18,   317,   318,
       0,     0,   319,   320,     0,   321,   322,   323,     0,   324,
      19,    20,   213,     0,     0,     0,    21,     0,   214,   215,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
      23,     0,    24,     0,    25,    26,     0,     0,     0,     0,
       0,    27,     0,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,     0,    36,     2,     0,     0,     0,     3,
       4,     0,     0,     5,    37,     6,   325,     7,     8,    38,
      39,     9,     0,    40,     0,     0,     0,    41,    42,    43,
      10,     0,     0,     0,     0,     0,     0,    -6,     0,    11,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,    14,    15,     0,     0,     0,    16,    17,
       0,     0,     0,   161,     0,     0,   162,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,     0,     0,    21,     0,
     163,     0,     0,     0,     0,     0,     0,    22,     0,     0,
       0,     0,    23,     0,    24,     0,    25,    26,     0,     0,
       0,     0,     0,    27,     0,    28,    29,    30,    31,    32,
      33,    34,     0,     0,    35,   164,    36,   165,   166,     0,
       0,     0,     0,     0,     0,   167,    37,   168,     0,     0,
     169,    38,    39,     0,     0,    40,     0,     0,     0,    41,
      42,    43,     0,     0,     0,     0,     0,     0,     0,     0,
     170,   171
};

static const yytype_int16 yycheck[] =
{
      55,     1,     4,    15,     8,   190,   191,    35,     3,   171,
     219,   160,    45,    52,    52,    52,    24,    17,   145,    34,
      31,    21,    22,    77,    19,    25,   175,    27,   145,    29,
      30,   145,    21,    33,   145,    89,    57,    14,    59,    52,
      29,    52,    42,    32,    52,   145,   145,     6,     7,   145,
      48,    51,    50,    53,    56,    52,    58,    55,   145,    18,
      72,   145,    62,   248,   249,    65,    66,     0,    83,   218,
      70,    71,   105,   171,     5,   145,    52,   145,    12,    68,
      57,    81,    59,    52,    88,    24,   145,    52,    92,   145,
      52,   160,    23,   172,    94,    95,    55,    52,    93,    52,
     100,   310,    20,   115,    99,   171,    20,    96,    20,   109,
      41,   123,   124,    44,   114,   145,   116,   145,   118,   119,
     135,   159,   117,    82,   145,   125,    60,   127,   128,   129,
     130,   131,   132,   133,   173,   147,   136,    73,   138,    57,
     152,    59,   145,   145,   329,   156,    52,    26,   148,     9,
      10,    11,   164,   153,   154,    52,    28,   157,    92,   145,
     309,   161,   162,   163,   145,   145,   168,    46,   145,   158,
      20,   171,   167,   107,   169,    35,    36,    37,    38,    52,
     174,   112,   145,    43,   145,    45,    52,   146,   145,   172,
      69,   227,   151,    84,   120,   246,   216,   252,   140,     7,
     158,    61,    -1,   137,   108,   135,   178,    -1,   139,   140,
     141,   142,    47,    48,    49,    50,   134,   148,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    89,
      -1,    91,    -1,    -1,    35,    36,    37,    38,    -1,    74,
      -1,    76,    -1,   103,    79,    -1,    -1,    -1,    -1,    84,
      -1,    86,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,   122,    17,    -1,    -1,   126,    21,    22,    -1,
      39,    25,    -1,    27,    -1,    29,    30,    46,    -1,    33,
      -1,    -1,    -1,   143,   144,    -1,    -1,    -1,    42,   149,
     150,    -1,    -1,    -1,    63,    64,   156,    51,    67,    53,
      -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    62,    -1,
      -1,    65,    66,    -1,    -1,    -1,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,    81,    97,    98,
      -1,    -1,   101,   102,    -1,   104,   105,   106,    -1,   108,
      94,    95,   143,    -1,    -1,    -1,   100,    -1,   149,   150,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,   119,    -1,    -1,    -1,    -1,
      -1,   125,    -1,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,    -1,   138,    17,    -1,    -1,    -1,    21,
      22,    -1,    -1,    25,   148,    27,   165,    29,    30,   153,
     154,    33,    -1,   157,    -1,    -1,    -1,   161,   162,   163,
      42,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,    51,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    65,    66,    -1,    -1,    -1,    70,    71,
      -1,    -1,    -1,    13,    -1,    -1,    16,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,   100,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,   114,    -1,   116,    -1,   118,   119,    -1,    -1,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,    75,   138,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    85,   148,    87,    -1,    -1,
      90,   153,   154,    -1,    -1,   157,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    17,    21,    22,    25,    27,    29,    30,    33,
      42,    51,    53,    62,    65,    66,    70,    71,    81,    94,
      95,   100,   109,   114,   116,   118,   119,   125,   127,   128,
     129,   130,   131,   132,   133,   136,   138,   148,   153,   154,
     157,   161,   162,   163,   176,   177,   178,   179,   180,   195,
     196,   197,   198,   199,   204,   212,   213,   222,   227,   229,
     233,   238,   242,   243,   244,   245,   246,   252,   253,   256,
     171,    52,    12,    60,    92,   107,   137,   234,   235,   236,
     237,     8,    88,    92,   216,   217,   218,   145,   247,   234,
      15,    72,   115,   123,   124,   147,   152,   164,   206,    57,
      59,   145,   181,   182,   183,   145,   145,   145,   250,   251,
      52,    47,    48,    49,    50,    74,    76,    79,    84,    86,
     219,   220,   221,   145,   145,   262,   145,    52,     6,     7,
      18,    55,    82,   146,   151,   257,   258,    34,    83,   135,
     230,   231,   232,   145,   248,   205,   206,   145,     5,    23,
      41,    44,   112,   139,   140,   141,   142,   148,   239,   240,
     241,    13,    16,    40,    75,    77,    78,    85,    87,    90,
     110,   111,   200,   201,   202,   203,    52,   173,   259,   260,
     261,     0,   178,   171,   181,    14,   181,    20,    57,    59,
     134,   181,   182,    24,    52,   264,    52,   145,   145,    26,
      46,    69,   255,   235,   217,    52,    24,   207,    35,    36,
      37,    38,   126,   143,   149,   150,   223,   224,   225,   226,
     145,   178,   251,   220,    52,   145,   160,   228,   258,   231,
      52,   172,   206,   240,   264,    31,    52,   156,   263,   201,
      52,   264,    52,   260,   171,   184,   145,   214,    20,    20,
     214,   214,    73,     4,    56,    58,   145,   168,   254,    21,
      29,    32,    68,    96,   158,   208,   209,   210,   145,    52,
     224,   264,   263,    52,   184,   145,    28,     9,    10,    11,
      35,    36,    37,    38,    43,    45,    61,    80,    89,    91,
     103,   113,   120,   122,   126,   143,   144,   149,   150,   156,
     165,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   228,    39,    46,    63,    64,    67,    97,    98,   101,
     102,   104,   105,   106,   108,   165,   215,   214,   214,   182,
     145,     3,    19,    93,    99,   117,   167,   169,   211,    20,
     249,    52,   145,   145,   145,    52,    52,   159,   264,   263,
     214,   174
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   175,   176,   177,   177,   177,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     179,   180,   180,   180,   181,   181,   182,   183,   183,   184,
     184,   185,   185,   185,   185,   185,   186,   187,   187,   187,
     187,   187,   188,   188,   188,   189,   189,   189,   189,   189,
     189,   189,   189,   190,   191,   192,   192,   192,   193,   193,
     193,   194,   194,   194,   194,   195,   195,   196,   196,   197,
     198,   198,   198,   198,   198,   199,   200,   200,   201,   201,
     201,   202,   202,   202,   202,   202,   203,   203,   203,   203,
     203,   204,   204,   204,   205,   205,   206,   206,   206,   206,
     206,   206,   206,   206,   207,   207,   208,   208,   208,   208,
     209,   209,   210,   210,   211,   211,   211,   211,   211,   211,
     211,   212,   212,   213,   213,   213,   213,   213,   213,   213,
     213,   214,   214,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   216,   216,   217,
     218,   218,   218,   219,   219,   220,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   222,   223,   223,   224,   224,
     224,   224,   225,   225,   226,   226,   226,   226,   227,   228,
     228,   229,   230,   230,   231,   232,   232,   232,   233,   233,
     234,   234,   235,   235,   236,   236,   236,   236,   237,   238,
     239,   239,   240,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   243,   243,   244,   244,   245,
     246,   246,   246,   247,   247,   247,   248,   249,   249,   250,
     250,   251,   252,   252,   253,   253,   254,   254,   254,   254,
     255,   255,   255,   256,   257,   257,   258,   258,   258,   258,
     258,   258,   258,   259,   259,   260,   260,   261,   262,   262,
     263,   263,   263,   264,   264
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     5,     3,     4,     4,
       3,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     4,     0,
       2,     2,     2,     1,     2,     1,     1,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     3,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     4,     1,     0,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     5,     2,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 312 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			/* I will need to incorporate much more fine grained
			 * error messages. The following should suffice for
			 * the time being.
			 */
			struct FILE_INFO * ip_ctx = lex_current();
			msyslog(LOG_ERR, 
				"CONFIG: syntax error in %s line %d, column %d",
				ip_ctx->fname,
				ip_ctx->errpos.nline,
				ip_ctx->errpos.ncol);
		}
#line 1805 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 348 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			peer_node *my_node;

			my_node = create_peer_node((yyvsp[-2].Integer), (yyvsp[-1].Address_node), (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.peers, my_node);
		}
#line 1816 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 365 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Address_node) = create_address_node((yyvsp[0].String), (yyvsp[-1].Integer)); }
#line 1822 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 370 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Address_node) = create_address_node((yyvsp[0].String), AF_UNSPEC); }
#line 1828 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 375 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = AF_INET; }
#line 1834 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 377 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = AF_INET6; }
#line 1840 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 382 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val_fifo) = NULL; }
#line 1846 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 384 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 1855 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 400 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer)); }
#line 1861 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 413 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 1867 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 415 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_uval((yyvsp[-1].Integer), (unsigned int)(yyvsp[0].Integer)); }
#line 1873 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 417 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].Integer) >= 0 && (yyvsp[0].Integer) <= STRATUM_UNSPEC) {
				(yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			} else {
				(yyval.Attr_val) = NULL;
				yyerror("fudge factor: stratum value out of bounds, ignored");
			}
		}
#line 1886 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 440 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double)); }
#line 1892 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 445 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 1898 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 450 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 1904 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 452 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 1910 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 454 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 1916 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 477 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			unpeer_node *my_node;

			my_node = create_unpeer_node((yyvsp[0].Address_node));
			if (my_node)
				APPEND_G_FIFO(cfgt.unpeers, my_node);
		}
#line 1928 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 485 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
#ifdef REFCLOCK
			unpeer_node *my_node;

			my_node = create_unpeer_node(addr_from_typeunit((yyvsp[-1].String), (yyvsp[0].Integer)));
			if (my_node)
				APPEND_G_FIFO(cfgt.unpeers, my_node);
#else
			yyerror("no refclock support was compiled in.");
#endif /* REFCLOCK */
		}
#line 1944 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 510 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.mdnstries = (yyvsp[0].Integer); }
#line 1950 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 521 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.control_key = (yyvsp[0].Integer); }
#line 1956 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 523 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.keys = (yyvsp[0].String); }
#line 1962 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 525 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			    msyslog(LOG_WARNING,
				    "CONFIG: requestkey is a no-op because "
				    "ntpdc has been removed.");
			}
#line 1972 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 531 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.auth.trusted_key_list, (yyvsp[0].Attr_val_fifo)); }
#line 1978 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 533 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { cfgt.auth.ntp_signd_socket = (yyvsp[0].String); }
#line 1984 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 543 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.orphan_cmds, (yyvsp[0].Attr_val_fifo)); }
#line 1990 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 548 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 1999 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 553 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {	
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2008 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 561 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (double)(yyvsp[0].Integer)); }
#line 2014 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 563 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double)); }
#line 2020 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 565 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (double)(yyvsp[0].Integer)); }
#line 2026 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 591 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.stats_list, (yyvsp[0].Int_fifo)); }
#line 2032 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 593 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				cfgt.stats_dir = (yyvsp[0].String);
			} else {
				YYFREE((yyvsp[0].String));
				yyerror("statsdir remote configuration ignored");
			}
		}
#line 2045 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 602 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			filegen_node *fgn;
			
			fgn = create_filegen_node((yyvsp[-1].Integer), (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.filegen_opts, fgn);
		}
#line 2056 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 612 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = (yyvsp[-1].Int_fifo);
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 2065 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 617 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = NULL;
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 2074 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 636 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val_fifo) = NULL; }
#line 2080 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 638 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2089 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 646 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				(yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String));
			} else {
				(yyval.Attr_val) = NULL;
				YYFREE((yyvsp[0].String));
				yyerror("filegen file remote config ignored");
			}
		}
#line 2103 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 656 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				(yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			} else {
				(yyval.Attr_val) = NULL;
				yyerror("filegen type remote config ignored");
			}
		}
#line 2116 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 665 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			const char *err;
			
			if (lex_from_file()) {
				(yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer));
			} else {
				(yyval.Attr_val) = NULL;
				if (T_Link == (yyvsp[0].Integer))
					err = "filegen link remote config ignored";
				else
					err = "filegen nolink remote config ignored";
				yyerror(err);
			}
		}
#line 2135 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 680 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer)); }
#line 2141 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 715 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			CONCAT_G_FIFOS(cfgt.discard_opts, (yyvsp[0].Attr_val_fifo));
		}
#line 2149 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 719 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			CONCAT_G_FIFOS(cfgt.mru_opts, (yyvsp[0].Attr_val_fifo));
		}
#line 2157 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 723 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node((yyvsp[-2].Integer), (yyvsp[-1].Address_node), NULL, (yyvsp[0].Int_fifo),
						  lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2169 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 731 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node((yyvsp[-4].Integer), (yyvsp[-3].Address_node), (yyvsp[-1].Address_node), (yyvsp[0].Int_fifo),
						  lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2181 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 739 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node((yyvsp[-2].Integer), NULL, NULL, (yyvsp[0].Int_fifo),
						  lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2193 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 747 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;

			rn = create_restrict_node((yyvsp[-3].Integer),
				create_address_node(
					estrdup("0.0.0.0"), 
					AF_INET),
				create_address_node(
					estrdup("0.0.0.0"), 
					AF_INET),
				(yyvsp[0].Int_fifo), 
				lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2212 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 762 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *rn;
			
			rn = create_restrict_node((yyvsp[-3].Integer),
				create_address_node(
					estrdup("::"), 
					AF_INET6),
				create_address_node(
					estrdup("::"), 
					AF_INET6),
				(yyvsp[0].Int_fifo), 
				lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2231 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 777 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			restrict_node *	rn;

			APPEND_G_FIFO((yyvsp[0].Int_fifo), create_int_node((yyvsp[-1].Integer)));
			rn = create_restrict_node(
				(yyvsp[-2].Integer), NULL, NULL, (yyvsp[0].Int_fifo), lex_current()->curpos.nline);
			APPEND_G_FIFO(cfgt.restrict_opts, rn);
		}
#line 2244 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 789 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Int_fifo) = NULL; }
#line 2250 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 791 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = (yyvsp[-1].Int_fifo);
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 2259 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 816 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2268 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 821 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2277 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 829 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2283 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 840 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2292 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 845 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2301 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 853 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2307 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 874 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			addr_opts_node *aon;
			
			aon = create_addr_opts_node((yyvsp[-1].Address_node), (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.fudge, aon);
		}
#line 2318 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 884 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2327 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 889 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2336 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 897 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double)); }
#line 2342 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 899 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2348 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 901 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].Integer) >= 0 && (yyvsp[0].Integer) <= 16) {
				(yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			} else {
				(yyval.Attr_val) = NULL;
				yyerror("fudge factor: stratum value not in [0..16], ignored");
			}
		}
#line 2361 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 910 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String)); }
#line 2367 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 931 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
#ifdef REFCLOCK
			address_node *fakeaddr = addr_from_typeunit((yyvsp[-2].String), (yyvsp[-1].Integer));
			peer_node *my_node = create_peer_node(T_Server, fakeaddr, (yyvsp[0].Attr_val_fifo));
			APPEND_G_FIFO(cfgt.peers, my_node);
#endif /* REFCLOCK */
		}
#line 2379 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 942 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {(yyval.Integer) = 0;}
#line 2385 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 945 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {(yyval.Integer) = (yyvsp[0].Integer);}
#line 2391 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 955 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.rlimit, (yyvsp[0].Attr_val_fifo)); }
#line 2397 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 960 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2406 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 965 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2415 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 973 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer)); }
#line 2421 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 989 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.enable_opts, (yyvsp[0].Attr_val_fifo)); }
#line 2427 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 991 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.disable_opts, (yyvsp[0].Attr_val_fifo)); }
#line 2433 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 996 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2442 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1001 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2451 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1009 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer)); }
#line 2457 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1011 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { 
			if (lex_from_file()) {
				(yyval.Attr_val) = create_attr_ival(T_Flag, (yyvsp[0].Integer));
			} else {
				char err_str[128];
				
				(yyval.Attr_val) = NULL;
				snprintf(err_str, sizeof(err_str),
					 "enable/disable %s remote configuration ignored",
					 keyword((yyvsp[0].Integer)));
				yyerror(err_str);
			}
		}
#line 2475 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1043 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.tinker, (yyvsp[0].Attr_val_fifo)); }
#line 2481 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1048 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2490 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1053 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2499 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1061 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double)); }
#line 2505 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1086 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *av;
			
			av = create_attr_dval((yyvsp[-1].Integer), (yyvsp[0].Double));
			APPEND_G_FIFO(cfgt.vars, av);
		}
#line 2516 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1093 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *av;
			
			av = create_attr_ival((yyvsp[-1].Integer), (yyvsp[0].Integer));
			APPEND_G_FIFO(cfgt.vars, av);
		}
#line 2527 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1100 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *av;

			av = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String));
			APPEND_G_FIFO(cfgt.vars, av);
		}
#line 2538 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1107 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			char error_text[64];
			attr_val *av;

			if (lex_from_file()) {
				av = create_attr_sval((yyvsp[-1].Integer), (yyvsp[0].String));
				APPEND_G_FIFO(cfgt.vars, av);
			} else {
				YYFREE((yyvsp[0].String));
				snprintf(error_text, sizeof(error_text),
					 "%s remote config ignored",
					 keyword((yyvsp[-1].Integer)));
				yyerror(error_text);
			}
		}
#line 2558 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1123 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (!lex_from_file()) {
				YYFREE((yyvsp[-1].String)); /* avoid leak */
				yyerror("remote includefile ignored");
				break;
			}
			if (lex_level() > MAXINCLUDELEVEL) {
				fprintf(stderr, "getconfig(): Maximum include file level exceeded.\n");
				msyslog(LOG_ERR, "CONFIG: Maximum include file level exceeded.");
			} else {
				const char * path = (yyvsp[-1].String);
				if (!lex_push_file(path)) {
					fprintf(stderr, "getconfig(): Couldn't open <%s>\n", path);
					msyslog(LOG_ERR, "CONFIG: Couldn't open <%s>", path);
				}
			}
			YYFREE((yyvsp[-1].String)); /* avoid leak */
		}
#line 2581 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1142 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { lex_flush_stack(); }
#line 2587 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1144 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { /* see drift_parm below for actions */ }
#line 2593 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1146 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.logconfig, (yyvsp[0].Attr_val_fifo)); }
#line 2599 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1148 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.phone, (yyvsp[0].String_fifo)); }
#line 2605 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1150 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { APPEND_G_FIFO(cfgt.setvar, (yyvsp[0].Set_var)); }
#line 2611 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1164 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
#ifndef ENABLE_LEAP_SMEAR
			yyerror("Built without LEAP_SMEAR support.");
#endif
		}
#line 2621 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1183 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if (lex_from_file()) {
				attr_val *av;
				av = create_attr_sval(T_Driftfile, (yyvsp[0].String));
				APPEND_G_FIFO(cfgt.vars, av);
			} else {
				YYFREE((yyvsp[0].String));
				yyerror("driftfile remote configuration ignored");
			}
		}
#line 2636 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1194 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *av;
			
			av = create_attr_sval(T_Driftfile, (yyvsp[-1].String));
			APPEND_G_FIFO(cfgt.vars, av);
			av = create_attr_dval(T_WanderThreshold, (yyvsp[0].Double));
			APPEND_G_FIFO(cfgt.vars, av);
		}
#line 2649 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1203 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			attr_val *av;
			
			av = create_attr_sval(T_Driftfile, estrdup(""));
			APPEND_G_FIFO(cfgt.vars, av);
		}
#line 2660 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1213 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Set_var) = create_setvar_node((yyvsp[-3].String), (yyvsp[-1].String), (yyvsp[0].Integer)); }
#line 2666 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1219 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = 0; }
#line 2672 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1224 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2681 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1229 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2690 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1237 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			char	prefix;
			char *	type;
			
			switch ((yyvsp[0].String)[0]) {
			
			case '+':
			case '-':
			case '=':
				prefix = (yyvsp[0].String)[0];
				type = (yyvsp[0].String) + 1;
				break;
				
			default:
				prefix = '=';
				type = (yyvsp[0].String);
			}	
			
			(yyval.Attr_val) = create_attr_sval(prefix, estrdup(type));
			YYFREE((yyvsp[0].String));
		}
#line 2716 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1262 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			nic_rule_node *nrn;
			
			nrn = create_nic_rule_node((yyvsp[0].Integer), NULL, (yyvsp[-1].Integer));
			APPEND_G_FIFO(cfgt.nic_rules, nrn);
		}
#line 2727 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1269 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			nic_rule_node *nrn;
			
			nrn = create_nic_rule_node(0, (yyvsp[0].String), (yyvsp[-1].Integer));
			APPEND_G_FIFO(cfgt.nic_rules, nrn);
		}
#line 2738 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1297 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { CONCAT_G_FIFOS(cfgt.reset_counters, (yyvsp[0].Int_fifo)); }
#line 2744 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1302 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = (yyvsp[-1].Int_fifo);
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 2753 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1307 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Int_fifo) = NULL;
			APPEND_G_FIFO((yyval.Int_fifo), create_int_node((yyvsp[0].Integer)));
		}
#line 2762 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1331 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = (yyvsp[-1].Attr_val_fifo);
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2771 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1336 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.Attr_val_fifo) = NULL;
			APPEND_G_FIFO((yyval.Attr_val_fifo), (yyvsp[0].Attr_val));
		}
#line 2780 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1344 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_ival('i', (yyvsp[0].Integer)); }
#line 2786 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1350 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Attr_val) = create_attr_rangeval('-', (yyvsp[-3].Integer), (yyvsp[-1].Integer)); }
#line 2792 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1355 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.String_fifo) = (yyvsp[-1].String_fifo);
			APPEND_G_FIFO((yyval.String_fifo), create_string_node((yyvsp[0].String)));
		}
#line 2801 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1360 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			(yyval.String_fifo) = NULL;
			APPEND_G_FIFO((yyval.String_fifo), create_string_node((yyvsp[0].String)));
		}
#line 2810 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1368 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].Integer) != 0 && (yyvsp[0].Integer) != 1) {
				yyerror("Integer value is not boolean (0 or 1). Assuming 1");
				(yyval.Integer) = 1;
			} else {
				(yyval.Integer) = (yyvsp[0].Integer);
			}
		}
#line 2823 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1376 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = 1; }
#line 2829 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1377 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Integer) = 0; }
#line 2835 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1381 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1646  */
    { (yyval.Double) = (double)(yyvsp[0].Integer); }
#line 2841 "ntp_parser.tab.c" /* yacc.c:1646  */
    break;


#line 2845 "ntp_parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1386 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1906  */


#ifdef REFCLOCK
address_node *
addr_from_typeunit(char *type, int unit)
{
	char addrbuf[1025];	/* NI_MAXHOSTS on Linux */
	int dtype;

	for (dtype = 1; dtype < (int)num_refclock_conf; dtype++)
	    if (refclock_conf[dtype]->basename != NULL && strcasecmp(refclock_conf[dtype]->basename, type) == 0)
		goto foundit;
	 msyslog(LOG_ERR, "CONFIG: Unknown driver name %s", type);
	 exit(1);
foundit:
	snprintf(addrbuf, sizeof(addrbuf), "127.127.%d.%d", dtype, unit);
	return create_address_node(estrdup(addrbuf), AF_INET);
}
#endif /* REFCLOCK */

void 
yyerror(
	const char *msg
	)
{
	int retval;
	struct FILE_INFO * ip_ctx;

	ip_ctx = lex_current();
	ip_ctx->errpos = ip_ctx->tokpos;
	
	msyslog(LOG_ERR, "CONFIG: line %d column %d %s", 
		ip_ctx->errpos.nline, ip_ctx->errpos.ncol, msg);
	if (!lex_from_file()) {
		/* Save the error message in the correct buffer */
		retval = snprintf(remote_config.err_msg + remote_config.err_pos,
				  (size_t)(MAXLINE - remote_config.err_pos),
				  "column %d %s",
				  ip_ctx->errpos.ncol, msg);

		/* Increment the value of err_pos */
		if (retval > 0)
			remote_config.err_pos += retval;

		/* Increment the number of errors */
		++remote_config.no_errors;
	}
}


/*
 * token_name - convert T_ token integers to text
 *		example: token_name(T_Server) returns "T_Server"
 */
const char *
token_name(
	int token
	)
{
	return yytname[YYTRANSLATE(token)];
}


/* Initial Testing function -- ignore */
#if 0
int main(int argc, char *argv[])
{
	ip_file = FOPEN(argv[1], "r");
	if (!ip_file)
		fprintf(stderr, "ERROR!! Could not open file: %s\n", argv[1]);
	yyparse();
	return 0;
}
#endif

