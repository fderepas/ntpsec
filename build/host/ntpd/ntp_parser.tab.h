/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 37 "/home/fabrice/src/ntpsec/ntpd/ntp_parser.y" /* yacc.c:1909  */

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

#line 241 "ntp_parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_NTP_PARSER_TAB_H_INCLUDED  */
