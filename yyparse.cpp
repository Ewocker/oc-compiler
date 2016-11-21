/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

    // Dummy parser for scanner project.
    
    #include <cassert>
    #include <assert.h> 
    #include "lyutils.h"
    #include "astree.h"
    
    
/* Line 371 of yacc.c  */
#line 78 "yyparse.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.h".  */
#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ROOT = 258,
     IDENT = 259,
     NUMBER = 260,
     TOK_VOID = 261,
     TOK_BOOL = 262,
     TOK_CHAR = 263,
     TOK_INT = 264,
     TOK_STRING = 265,
     TOK_IF = 266,
     TOK_ELSE = 267,
     TOK_WHILE = 268,
     TOK_RETURN = 269,
     TOK_STRUCT = 270,
     TOK_FALSE = 271,
     TOK_TRUE = 272,
     TOK_NULL = 273,
     TOK_NEW = 274,
     TOK_ORD = 275,
     TOK_CHR = 276,
     TOK_EQ = 277,
     TOK_NE = 278,
     TOK_LE = 279,
     TOK_GE = 280,
     TOK_ARRAY = 281,
     TOK_IDENT = 282,
     TOK_INTCON = 283,
     TOK_CHARCON = 284,
     TOK_STRINGCON = 285,
     TOK_ROOT = 286,
     TOK_BLOCK = 287,
     TOK_PARAMLIST = 288,
     TOK_DECLID = 289,
     TOK_FUNCTION = 290,
     TOK_TYPEID = 291,
     TOK_FIELD = 292,
     TOK_VARDECL = 293,
     TOK_IFELSE = 294,
     TOK_RETURNVOID = 295,
     TOK_NEWSTRING = 296,
     TOK_NEWARRAY = 297,
     TOK_INDEX = 298,
     TOK_PROTOTYPE = 299,
     TOK_CALL = 300,
     TOK_POS = 301,
     TOK_NEG = 302,
     TOK_GT = 303,
     TOK_LT = 304,
     NEG = 305,
     POS = 306
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 195 "yyparse.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   532

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,     2,     2,    55,     2,     2,
      62,    66,    53,    51,    67,    52,    61,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    64,
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    68,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,    63,     2,     2,     2,     2,
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
      45,    46,    47,    49,    50,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    16,    20,    21,    24,
      28,    32,    35,    39,    41,    43,    45,    47,    52,    57,
      62,    67,    71,    74,    77,    81,    84,    86,    89,    92,
      94,    96,    98,   100,   102,   104,   107,   112,   118,   124,
     132,   136,   139,   143,   146,   148,   150,   154,   156,   158,
     160,   162,   164,   166,   168,   170,   172,   174,   176,   178,
     180,   182,   184,   186,   188,   190,   192,   194,   196,   198,
     200,   205,   209,   211,   213,   215,   217,   219,   221,   226,
     232,   238,   242,   245,   249
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    70,    71,    -1,    70,    75,    -1,    70,
      80,    -1,    70,     1,    63,    -1,    70,     1,    64,    -1,
      -1,    72,    63,    -1,    72,    73,    64,    -1,    15,    27,
      65,    -1,    74,    27,    -1,    74,    26,    27,    -1,     6,
      -1,     9,    -1,    10,    -1,    27,    -1,    77,    76,    66,
      78,    -1,    77,    76,    66,    64,    -1,    77,    62,    66,
      78,    -1,    77,    62,    66,    64,    -1,    76,    67,    77,
      -1,    62,    77,    -1,    74,    27,    -1,    74,    26,    27,
      -1,    79,    63,    -1,    64,    -1,    79,    80,    -1,    65,
      80,    -1,    65,    -1,    78,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    64,    -1,    77,    48,    85,
      64,    -1,    13,    62,    85,    66,    80,    -1,    11,    62,
      85,    66,    80,    -1,    11,    62,    85,    66,    80,    12,
      80,    -1,    14,    85,    64,    -1,    14,    64,    -1,    85,
      86,    85,    -1,    87,    85,    -1,    90,    -1,    91,    -1,
      62,    85,    66,    -1,    88,    -1,    89,    -1,     4,    -1,
       5,    -1,    22,    -1,    23,    -1,    50,    -1,    24,    -1,
      49,    -1,    25,    -1,    51,    -1,    52,    -1,    53,    -1,
      54,    -1,    48,    -1,    56,    -1,    46,    -1,    47,    -1,
      59,    -1,    19,    -1,    20,    -1,    21,    -1,    27,    -1,
      85,    60,    85,    68,    -1,    85,    61,    27,    -1,    28,
      -1,    29,    -1,    30,    -1,    16,    -1,    17,    -1,    18,
      -1,    19,    27,    62,    66,    -1,    19,    10,    62,    85,
      66,    -1,    19,    74,    60,    85,    68,    -1,    27,    62,
      66,    -1,    92,    66,    -1,    27,    62,    85,    -1,    92,
      67,    85,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    58,    59,    60,    61,    62,    66,    69,
      71,    75,    77,    81,    82,    83,    84,    87,    90,    93,
      96,   101,   102,   106,   108,   112,   113,   116,   117,   119,
     122,   123,   124,   125,   126,   127,   130,   134,   138,   140,
     145,   146,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   175,   176,   177,   178,   179,   180,   183,
     184,   186,   190,   191,   192,   193,   194,   195,   198,   200,
     202,   206,   208,   211,   212
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ROOT", "IDENT", "NUMBER", "TOK_VOID",
  "TOK_BOOL", "TOK_CHAR", "TOK_INT", "TOK_STRING", "TOK_IF", "TOK_ELSE",
  "TOK_WHILE", "TOK_RETURN", "TOK_STRUCT", "TOK_FALSE", "TOK_TRUE",
  "TOK_NULL", "TOK_NEW", "TOK_ORD", "TOK_CHR", "TOK_EQ", "TOK_NE",
  "TOK_LE", "TOK_GE", "TOK_ARRAY", "TOK_IDENT", "TOK_INTCON",
  "TOK_CHARCON", "TOK_STRINGCON", "TOK_ROOT", "TOK_BLOCK", "TOK_PARAMLIST",
  "TOK_DECLID", "TOK_FUNCTION", "TOK_TYPEID", "TOK_FIELD", "TOK_VARDECL",
  "TOK_IFELSE", "TOK_RETURNVOID", "TOK_NEWSTRING", "TOK_NEWARRAY",
  "TOK_INDEX", "TOK_PROTOTYPE", "TOK_CALL", "TOK_POS", "TOK_NEG", "'='",
  "TOK_GT", "TOK_LT", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "NEG",
  "POS", "'!'", "'['", "'.'", "'('", "'}'", "';'", "'{'", "')'", "','",
  "']'", "$accept", "program", "structdef", "structcont", "fielddecl",
  "basetype", "function", "funcargs", "identdecl", "block", "blockbody",
  "statement", "vardecl", "while", "ifelse", "return", "expr", "binop",
  "unop", "variable", "constant", "allocator", "call", "exprs", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    61,   303,
     304,    43,    45,    42,    47,    37,    94,   305,   306,    33,
      91,    46,    40,   125,    59,   123,    41,    44,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    75,    75,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    79,
      80,    80,    80,    80,    80,    80,    81,    82,    83,    83,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    88,
      88,    88,    89,    89,    89,    89,    89,    89,    90,    90,
      90,    91,    91,    92,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     3,     3,     0,     2,     3,
       3,     2,     3,     1,     1,     1,     1,     4,     4,     4,
       4,     3,     2,     2,     3,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     4,     5,     5,     7,
       3,     2,     3,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     1,     1,     1,     1,     1,     4,     5,
       5,     3,     2,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     1,     0,    49,    50,    13,    14,    15,     0,
       0,     0,     0,    75,    76,    77,    66,    67,    68,    69,
      72,    73,    74,    63,    64,    65,     0,    26,    29,     2,
       0,     0,     3,     0,    30,     0,     4,    31,    32,    33,
      34,     0,     0,    47,    48,    44,    45,     0,     5,     6,
       0,     0,    69,    41,     0,     0,    15,    16,     0,     0,
       0,     0,    28,    16,     8,     0,     0,     0,    23,     0,
       0,     0,    25,    27,    51,    52,    54,    56,    61,    55,
      53,    57,    58,    59,    60,    62,     0,     0,    35,     0,
      43,    82,     0,     0,     0,    40,    10,     0,     0,     0,
      81,    83,    46,     9,     0,    11,    24,     0,     0,    22,
       0,     0,     0,    71,    42,    84,     0,     0,     0,    78,
       0,    12,    36,    20,    19,    18,    17,    21,    70,    38,
      37,    79,    80,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    29,    30,    65,    31,    32,    71,    61,    34,
      35,    36,    37,    38,    39,    40,    41,    89,    42,    43,
      44,    45,    46,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -107
static const yytype_int16 yypact[] =
{
    -107,    12,  -107,   -49,  -107,  -107,  -107,  -107,  -107,   -53,
     -43,   237,    21,  -107,  -107,  -107,    41,  -107,  -107,   -16,
    -107,  -107,  -107,  -107,  -107,  -107,   286,  -107,   216,  -107,
      -3,    40,  -107,   -13,  -107,   154,  -107,  -107,  -107,  -107,
    -107,   392,   286,  -107,  -107,  -107,  -107,     6,  -107,  -107,
     286,   286,   -10,  -107,   411,   -11,     0,     8,    -4,    95,
     312,    33,  -107,  -107,  -107,    11,    52,    65,  -107,   286,
      28,    18,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,   286,    70,  -107,   286,
     471,  -107,   286,   331,   352,  -107,  -107,   286,    32,   286,
    -107,   471,  -107,  -107,    78,  -107,  -107,   454,    23,  -107,
      31,    55,    79,  -107,   471,   471,   216,   216,   371,  -107,
     270,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,    96,
    -107,  -107,  -107,   216,  -107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -107,  -107,  -107,  -107,  -107,    27,  -107,  -107,    -1,  -106,
    -107,   -27,  -107,  -107,  -107,  -107,    -6,  -107,  -107,  -107,
    -107,  -107,  -107,  -107
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -17
static const yytype_int16 yytable[] =
{
      33,    62,   124,     6,   126,    54,     7,     8,    73,    50,
     -16,   -16,     2,     3,    48,    49,     4,     5,     6,    51,
      60,     7,     8,     9,    63,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     6,    69,    90,     7,     8,    19,
      20,    21,    22,    58,    93,    94,    59,     6,    55,    70,
       7,    56,    59,   101,    96,    63,    99,    66,    23,    24,
      64,     6,    97,   107,     7,     8,    67,    68,    57,   109,
      98,    25,    91,    92,    26,   103,    27,    28,   104,   105,
     112,    69,    63,   114,   110,   111,   115,   123,    28,   129,
     130,   118,   106,   120,   108,   125,    28,   113,   119,     4,
       5,    74,    75,    76,    77,   121,   134,     0,   133,     0,
     127,    13,    14,    15,    16,    17,    18,     0,     0,     0,
       0,     0,    52,    20,    21,    22,     0,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,     0,     0,    86,
      87,    23,    24,     0,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,    25,     0,     0,    26,     4,     5,
       6,   100,     0,     7,     8,     9,     0,    10,    11,     0,
      13,    14,    15,    16,    17,    18,     0,     0,     0,     0,
       0,    19,    20,    21,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,    26,    72,    27,    28,
       4,     5,     6,     0,     0,     7,     8,     9,     0,    10,
      11,     0,    13,    14,    15,    16,    17,    18,     0,     0,
       0,     4,     5,    19,    20,    21,    22,     0,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,     0,
       0,     0,    23,    24,    52,    20,    21,    22,     0,     0,
       0,     0,     0,     0,     0,    25,     0,     0,    26,     0,
      27,    28,     0,    23,    24,     0,     0,     0,     0,     0,
       4,     5,    74,    75,    76,    77,    25,     0,     0,    26,
       0,    53,    13,    14,    15,    16,    17,    18,     0,     0,
       0,     0,     0,    52,    20,    21,    22,     0,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,     0,     0,
      86,    87,    23,    24,    74,    75,    76,    77,   132,     0,
       0,     0,     0,     0,     0,    25,     0,     0,    26,     0,
       0,     0,     0,    74,    75,    76,    77,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
       0,     0,    86,    87,    74,    75,    76,    77,   102,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,     0,
       0,    86,    87,    74,    75,    76,    77,   116,     0,     0,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
       0,     0,    86,    87,    74,    75,    76,    77,   117,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,     0,
       0,    86,    87,    74,    75,    76,    77,   131,     0,     0,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
       0,     0,    86,    87,     0,     0,    88,     0,     0,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,     0,
       0,    86,    87,     0,     0,    95,    74,    75,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,     0,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,     0,     0,    86,    87,     0,     0,   122,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,     0,
       0,    86,    87
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,    28,   108,     6,   110,    11,     9,    10,    35,    62,
      26,    27,     0,     1,    63,    64,     4,     5,     6,    62,
      26,     9,    10,    11,    27,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     6,    48,    42,     9,    10,    27,
      28,    29,    30,    16,    50,    51,    62,     6,    27,    62,
       9,    10,    62,    59,    65,    27,    60,    30,    46,    47,
      63,     6,    62,    69,     9,    10,    26,    27,    27,    70,
      62,    59,    66,    67,    62,    64,    64,    65,    26,    27,
      86,    48,    27,    89,    66,    67,    92,    64,    65,   116,
     117,    97,    27,    99,    66,    64,    65,    27,    66,     4,
       5,    22,    23,    24,    25,    27,   133,    -1,    12,    -1,
     111,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    -1,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,    60,
      61,    46,    47,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    62,     4,     5,
       6,    66,    -1,     9,    10,    11,    -1,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    62,    63,    64,    65,
       4,     5,     6,    -1,    -1,     9,    10,    11,    -1,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,     4,     5,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    46,    47,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    62,    -1,
      64,    65,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,
       4,     5,    22,    23,    24,    25,    59,    -1,    -1,    62,
      -1,    64,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      60,    61,    46,    47,    22,    23,    24,    25,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    -1,
      -1,    -1,    60,    61,    22,    23,    24,    25,    66,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    -1,
      -1,    60,    61,    22,    23,    24,    25,    66,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    -1,
      -1,    -1,    60,    61,    22,    23,    24,    25,    66,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    -1,
      -1,    60,    61,    22,    23,    24,    25,    66,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    -1,
      -1,    60,    61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,     0,     1,     4,     5,     6,     9,    10,    11,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    27,
      28,    29,    30,    46,    47,    59,    62,    64,    65,    71,
      72,    74,    75,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    87,    88,    89,    90,    91,    92,    63,    64,
      62,    62,    27,    64,    85,    27,    10,    27,    74,    62,
      85,    77,    80,    27,    63,    73,    74,    26,    27,    48,
      62,    76,    63,    80,    22,    23,    24,    25,    48,    49,
      50,    51,    52,    53,    54,    56,    60,    61,    64,    86,
      85,    66,    67,    85,    85,    64,    65,    62,    62,    60,
      66,    85,    66,    64,    26,    27,    27,    85,    66,    77,
      66,    67,    85,    27,    85,    85,    66,    66,    85,    66,
      85,    27,    64,    64,    78,    64,    78,    77,    68,    80,
      80,    66,    68,    12,    80
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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

/* User initialization code.  */
/* Line 1575 of yacc.c  */
#line 17 "parser.y"
{
   parser::root = new astree (ROOT, {0, 0, 0}, "<<ROOT>>");
}
/* Line 1575 of yacc.c  */
#line 1428 "yyparse.cpp"
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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 57 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 58 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 59 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 60 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 61 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 62 "parser.y"
    { (yyval) = parser::root 
 = new astree(TOK_ROOT, {0,0,0},""); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 66 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 70 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)])); destroy((yyvsp[(3) - (3)])); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 72 "parser.y"
    { (yyvsp[(2) - (3)])->symbol = TOK_TYPEID; (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)])); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 76 "parser.y"
    { (yyvsp[(2) - (2)])->symbol = TOK_FIELD; (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 78 "parser.y"
    { (yyvsp[(3) - (3)])->symbol = TOK_FIELD; (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 81 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 82 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 83 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 84 "parser.y"
    { (yyvsp[(1) - (1)])->symbol = TOK_TYPEID; (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 88 "parser.y"
    { (yyval) = (new astree(TOK_FUNCTION, (yyvsp[(1) - (4)])->lloc, ""))
->adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); destroy((yyvsp[(3) - (4)])); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 91 "parser.y"
    { (yyval) = (new astree(TOK_PROTOTYPE, (yyvsp[(1) - (4)])->lloc, ""))
->adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    { (yyvsp[(2) - (4)])->symbol = TOK_PARAMLIST;
 (yyval) = (new astree(TOK_FUNCTION, (yyvsp[(1) - (4)])->lloc, ""))
->adopt((yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)])); destroy((yyvsp[(3) - (4)])); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 96 "parser.y"
    { (yyvsp[(2) - (4)])->symbol = TOK_PARAMLIST;
 (yyval) = (new astree(TOK_PROTOTYPE, (yyvsp[(1) - (4)])->lloc, ""))
->adopt((yyvsp[(1) - (4)]),(yyvsp[(2) - (4)])); destroy((yyvsp[(3) - (4)]),(yyvsp[(4) - (4)])); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 101 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(3) - (3)])); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 103 "parser.y"
    { (yyvsp[(1) - (2)])->symbol = TOK_PARAMLIST; (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 107 "parser.y"
    { (yyvsp[(2) - (2)])->symbol = TOK_DECLID; (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 109 "parser.y"
    { (yyvsp[(3) - (3)])->symbol = TOK_DECLID; (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 112 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 113 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 118 "parser.y"
    { (yyvsp[(1) - (2)])->symbol = TOK_BLOCK; (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 119 "parser.y"
    { (yyvsp[(1) - (1)])->symbol = TOK_BLOCK; (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 122 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 124 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 125 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 126 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 127 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 131 "parser.y"
    { (yyvsp[(2) - (4)])->symbol = TOK_VARDECL; (yyval) = (yyvsp[(2) - (4)])->adopt((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); destroy((yyvsp[(4) - (4)])); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    { (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); destroy((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)])); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 139 "parser.y"
    { (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); destroy((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]));}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
    { (yyval) = (yyvsp[(1) - (7)])->adopt((yyvsp[(3) - (7)]),(yyvsp[(5) - (7)])); (yyvsp[(7) - (7)])->symbol
 = TOK_IFELSE; (yyvsp[(1) - (7)])->adopt((yyvsp[(7) - (7)])); destroy((yyvsp[(2) - (7)]),(yyvsp[(4) - (7)])); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 145 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)])); destroy((yyvsp[(3) - (3)])); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 147 "parser.y"
    { (yyvsp[(1) - (2)])->symbol = TOK_RETURNVOID; (yyval) = (yyvsp[(1) - (2)]); destroy((yyvsp[(2) - (2)])); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 150 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 151 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 152 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 153 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 154 "parser.y"
    { destroy ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 155 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 158 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 163 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 164 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 165 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 166 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 167 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 168 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 169 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 170 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 171 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 172 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 177 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 178 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 179 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 185 "parser.y"
    { destroy((yyvsp[(4) - (4)])); (yyvsp[(2) - (4)])->symbol = TOK_INDEX; (yyval) = (yyvsp[(2) - (4)])->adopt((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)])); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 187 "parser.y"
    { (yyvsp[(3) - (3)])->symbol = TOK_FIELD; (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 191 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 192 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 193 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 194 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 195 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 199 "parser.y"
    { (yyvsp[(2) - (4)])->symbol = TOK_TYPEID; (yyval) = (yyvsp[(1) - (4)])->adopt((yyvsp[(2) - (4)])); destroy((yyvsp[(3) - (4)]),(yyvsp[(4) - (4)])); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 201 "parser.y"
    { (yyvsp[(1) - (5)])->symbol = TOK_NEWSTRING; (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(4) - (5)])); destroy((yyvsp[(3) - (5)]),(yyvsp[(5) - (5)])); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 203 "parser.y"
    { (yyvsp[(1) - (5)])->symbol = TOK_NEWARRAY; (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)])); destroy((yyvsp[(3) - (5)]),(yyvsp[(5) - (5)])); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 207 "parser.y"
    { (yyvsp[(2) - (3)])->symbol = TOK_CALL; (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)])); }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 208 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 211 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(3) - (3)])); }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 213 "parser.y"
    { (yyvsp[(2) - (3)])->symbol = TOK_CALL; (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); }
    break;


/* Line 1792 of yacc.c  */
#line 2115 "yyparse.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 216 "parser.y"



const char *parser::get_tname (int symbol) {
    return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
    return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

/*
 static void* yycalloc (size_t size) {
 void* result = calloc (1, size);
 assert (result != nullptr);
 return result;
 }

 %destructor { destroy ($$); } <>
%printer { astree::dump (yyoutput, $$); } <>
 */

