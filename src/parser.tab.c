/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include<bits/stdc++.h>
using namespace std;
int yylex();
void yyerror(const char *s);
extern int yylineno;
extern FILE *yyin;
extern char * yytext;

// parser for python 3.6

int root=-1;
int line=0;

uint countnode=0;
map<int, pair<string, vector<int> > > tree;
map<int, int> parent;



int makenode(string name){
    countnode++;
    vector<int>childs;
    tree[countnode].first=name;
    tree[countnode].second=childs;
    return countnode;
}

void addChild(int p, int c){
    tree[p].second.push_back(c);
    parent[c] = p;
}

void writeDotFile(const std::map<int, std::pair<std::string, std::vector<int>>> &tree, const std::string &filename) {
    std::ofstream dotFile(filename);
    if (!dotFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    dotFile << "digraph Tree {\n";
    
    for (const auto &node : tree) {
        int nodeId = node.first;
        std::string label = node.second.first;
        std::vector<int> children = node.second.second;

        // set<string> BytePrefix = {"b" | "B" | "br" | "Br" | "bR" | "BR" | "rb" | "rB" | "Rb" | "RB"}
        set<string> BytePrefix = {"b", "B", "br", "Br", "bR", "BR", "rb", "rB", "Rb", "RB"};
        // Write node
        if (label[label.size() - 1] == '\"') {
            // remove last character and prefix upto "
            label = label.substr(0, label.size() - 2);
            int i = 0;
            while (i < label.size() && label[i] != '\"') {
                i++;
                
            }
            label = label.substr(0,i) + "\\\"" + label.substr(i + 1, label.size()) + "\\\"";
        }

        dotFile << "    " << nodeId << " [label=\"" << label << "\"];\n";

        // Write edges
        for (int child : children) {
            if(child != -1) dotFile << "    " << nodeId << " -> " << child << ";\n";
        }
    }

    dotFile << "}\n";
    
    dotFile.close();
}



#line 147 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LITERAL_FLOAT = 258,
    LITERAL_INT = 259,
    KEY_FALS = 260,
    KEY_NONE = 261,
    KEY_TRU = 262,
    KEY_AS = 263,
    KEY_ASSERT = 264,
    KEY_ASYNC = 265,
    KEY_AWAIT = 266,
    KEY_BREAK = 267,
    KEY_CLASS = 268,
    KEY_CONTINUE = 269,
    KEY_DEF = 270,
    KEY_DEL = 271,
    KEY_ELIF = 272,
    KEY_ELSE = 273,
    KEY_EXCEPT = 274,
    KEY_FINALLY = 275,
    KEY_FOR = 276,
    KEY_FROM = 277,
    KEY_GLOBAL = 278,
    KEY_IF = 279,
    KEY_IMPORT = 280,
    KEY_IN = 281,
    KEY_IS = 282,
    KEY_LAMBDA = 283,
    KEY_NONLOCAL = 284,
    KEY_PASS = 285,
    KEY_RAISE = 286,
    KEY_RETURN = 287,
    KEY_TRY = 288,
    KEY_WHILE = 289,
    KEY_WITH = 290,
    KEY_YIELD = 291,
    IDENTIFIER = 292,
    RES_ID_SELF = 293,
    RES_ID_INIT = 294,
    RES_ID_MAIN = 295,
    KEY_INT = 296,
    KEY_FLOAT = 297,
    KEY_STR = 298,
    KEY_BOOL = 299,
    OP_PLUS = 300,
    OP_MINUS = 301,
    OP_TIMES = 302,
    OP_DIVIDE = 303,
    OP_FLOOR = 304,
    OP_MOD = 305,
    OP_EXP = 306,
    OP_LSHIFT = 307,
    OP_RSHIFT = 308,
    OP_BITWISE_AND = 309,
    OP_BITWISE_OR = 310,
    OP_BITWISE_XOR = 311,
    OP_BITWISE_NOT = 312,
    OP_WALRUS = 313,
    OP_LESS = 314,
    OP_GREATER = 315,
    OP_LESS_EQ = 316,
    OP_GREATER_EQ = 317,
    OP_EQ = 318,
    OP_NOT_EQ = 319,
    OP_LOGICAL_NOT = 320,
    OP_LOGICAL_OR = 321,
    OP_LOGICAL_AND = 322,
    NEWLINE = 323,
    STRING = 324,
    BYTESTRING = 325,
    KEY_LIST = 326,
    STMT_PRINT = 327,
    STMT_RANGE = 328,
    DELIM_LPAR = 329,
    DELIM_RPAR = 330,
    DELIM_LBRACKET = 331,
    DELIM_RBRACKET = 332,
    DELIM_LBRACE = 333,
    DELIM_RBRACE = 334,
    DELIM_COMMA = 335,
    DELIM_COLON = 336,
    DELIM_DOT = 337,
    DELIM_SEMICOLON = 338,
    DELIM_ARROW = 339,
    DELIM_OP_AT = 340,
    DELIM_ASSIGN = 341,
    DELIM_PLUS_EQ = 342,
    DELIM_MINUS_EQ = 343,
    DELIM_TIMES_EQ = 344,
    DELIM_DIVIDE_EQ = 345,
    DELIM_FLOOR_EQ = 346,
    DELIM_MOD_EQ = 347,
    DELIM_MATMUL_EQ = 348,
    DELIM_AND_EQ = 349,
    DELIM_OR_EQ = 350,
    DELIM_XOR_EQ = 351,
    DELIM_RSHIFT_EQ = 352,
    DELIM_LSHIFT_EQ = 353,
    DELIM_EXP_EQ = 354,
    OP_BITWSIE_NOT = 355,
    ENDMARKER = 356,
    INDENT = 357,
    DEDENT = 358
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 82 "parser.y"

    
    char * sval;
    int id;
    // for int num
    int intNumber;
    // for float num also
    float fltNumber;

#line 313 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  97
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   566

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  277

#define YYUNDEFTOK  2
#define YYMAXUTOK   358


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101,   102,   103
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   191,   191,   201,   211,   212,   217,   223,   235,   239,
     249,   254,   258,   263,   267,   271,   275,   279,   283,   287,
     291,   301,   316,   327,   334,   342,   348,   356,   365,   377,
     378,   384,   390,   396,   402,   408,   414,   420,   426,   432,
     438,   444,   450,   459,   466,   476,   480,   491,   502,   518,
     528,   536,   544,   556,   560,   564,   569,   573,   581,   585,
     594,   607,   614,   618,   627,   634,   638,   648,   652,   662,
     666,   676,   680,   690,   694,   704,   708,   715,   722,   729,
     736,   743,   753,   757,   764,   771,   778,   788,   789,   796,
     806,   810,   817,   827,   831,   838,   845,   852,   862,   866,
     876,   880,   886,   892,   898,   908,   912,   916,   920,   925,
     929,   933,   937,   941,   945,   950,   961,   969,   977,   989,
     993,  1000,  1010,  1014,  1018,  1022,  1026,  1035,  1046,  1055,
    1064,  1075,  1079,  1090,  1101,  1114,  1123,  1137,  1146,  1157,
    1168,  1172,  1176,  1190,  1202,  1218,  1222,  1229,  1233,  1239,
    1244,  1250,  1254,  1263,  1271,  1286,  1289,  1292,  1295
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LITERAL_FLOAT", "LITERAL_INT",
  "KEY_FALS", "KEY_NONE", "KEY_TRU", "KEY_AS", "KEY_ASSERT", "KEY_ASYNC",
  "KEY_AWAIT", "KEY_BREAK", "KEY_CLASS", "KEY_CONTINUE", "KEY_DEF",
  "KEY_DEL", "KEY_ELIF", "KEY_ELSE", "KEY_EXCEPT", "KEY_FINALLY",
  "KEY_FOR", "KEY_FROM", "KEY_GLOBAL", "KEY_IF", "KEY_IMPORT", "KEY_IN",
  "KEY_IS", "KEY_LAMBDA", "KEY_NONLOCAL", "KEY_PASS", "KEY_RAISE",
  "KEY_RETURN", "KEY_TRY", "KEY_WHILE", "KEY_WITH", "KEY_YIELD",
  "IDENTIFIER", "RES_ID_SELF", "RES_ID_INIT", "RES_ID_MAIN", "KEY_INT",
  "KEY_FLOAT", "KEY_STR", "KEY_BOOL", "OP_PLUS", "OP_MINUS", "OP_TIMES",
  "OP_DIVIDE", "OP_FLOOR", "OP_MOD", "OP_EXP", "OP_LSHIFT", "OP_RSHIFT",
  "OP_BITWISE_AND", "OP_BITWISE_OR", "OP_BITWISE_XOR", "OP_BITWISE_NOT",
  "OP_WALRUS", "OP_LESS", "OP_GREATER", "OP_LESS_EQ", "OP_GREATER_EQ",
  "OP_EQ", "OP_NOT_EQ", "OP_LOGICAL_NOT", "OP_LOGICAL_OR",
  "OP_LOGICAL_AND", "NEWLINE", "STRING", "BYTESTRING", "KEY_LIST",
  "STMT_PRINT", "STMT_RANGE", "DELIM_LPAR", "DELIM_RPAR", "DELIM_LBRACKET",
  "DELIM_RBRACKET", "DELIM_LBRACE", "DELIM_RBRACE", "DELIM_COMMA",
  "DELIM_COLON", "DELIM_DOT", "DELIM_SEMICOLON", "DELIM_ARROW",
  "DELIM_OP_AT", "DELIM_ASSIGN", "DELIM_PLUS_EQ", "DELIM_MINUS_EQ",
  "DELIM_TIMES_EQ", "DELIM_DIVIDE_EQ", "DELIM_FLOOR_EQ", "DELIM_MOD_EQ",
  "DELIM_MATMUL_EQ", "DELIM_AND_EQ", "DELIM_OR_EQ", "DELIM_XOR_EQ",
  "DELIM_RSHIFT_EQ", "DELIM_LSHIFT_EQ", "DELIM_EXP_EQ", "OP_BITWSIE_NOT",
  "ENDMARKER", "INDENT", "DEDENT", "$accept", "input", "END", "statements",
  "statement", "simplestatement", "expressionstatement", "delstatement",
  "returnstatement", "raisestatement", "globalstatement",
  "nonlocalstatement", "assign_statement", "assignments", "Ids",
  "Variable_Declaration", "Type_Declaration", "Primitive_Type",
  "NumericType", "List_Type", "List_expression", "expression",
  "logical_or_expression", "logical_and_expression",
  "bitwise_or_expression", "bitwise_xor_expression",
  "bitwise_and_expression", "equality_expression", "relational_expression",
  "shift_expression", "additive_expression", "multiplicative_expression",
  "exponentiation_expression", "negated_expression", "primary_expression",
  "funccall", "arguments", "compoundstatement", "ifstatement",
  "elifblocks", "elifblock", "elseblock", "whilestatement", "forstatement",
  "for_expression", "ForList", "funcdef", "params", "Return_Type", "Suite",
  "classdef", "Names", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
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
     355,   356,   357,   358
};
# endif

#define YYPACT_NINF (-222)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-157)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     368,  -222,  -222,  -222,  -222,  -222,  -222,    85,  -222,    85,
      17,    85,    85,    17,    85,  -222,    17,    17,    17,   -67,
     -53,  -222,  -222,    17,    17,    17,    17,   -41,  -222,  -222,
      17,    17,  -222,    53,  -222,   368,  -222,    15,  -222,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,   112,  -222,   -25,  -222,
       3,     8,    37,    45,    49,    32,    73,    28,    63,    89,
    -222,    77,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
      -8,  -222,  -222,   -43,    66,    59,  -222,  -222,    24,    65,
     122,  -222,    71,  -222,  -222,  -222,    72,   153,   186,  -222,
    -222,  -222,  -222,  -222,    79,    95,    91,  -222,  -222,  -222,
    -222,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,   190,    17,    17,    17,    17,   147,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,   144,    17,   490,   196,   153,   490,    67,   490,
     490,  -222,  -222,  -222,  -222,  -222,  -222,  -222,    17,  -222,
     110,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,     8,    37,    45,    49,
      32,    93,   131,  -222,   138,    73,    73,    73,    73,   190,
      28,    28,    28,    28,    63,    63,    89,    89,  -222,  -222,
    -222,  -222,  -222,   137,   141,   143,  -222,  -222,  -222,  -222,
     142,  -222,  -222,  -222,  -222,   146,   140,   170,  -222,    33,
    -222,    14,   171,   235,    17,  -222,  -222,  -222,    94,   235,
    -222,   190,   190,  -222,    17,  -222,  -222,   144,   178,   442,
    -222,   207,   -56,   207,   187,  -222,   193,    17,    94,  -222,
    -222,  -222,  -222,   194,   490,   293,   185,   490,     7,  -222,
     490,  -222,   191,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,   195,  -222,   490,   490,  -222,  -222
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   107,   106,   111,   112,   110,    12,     0,    13,     0,
       0,     0,     0,     0,     0,    14,    26,    24,     0,   155,
     156,   157,   158,     0,     0,     0,     0,     0,   108,   109,
       0,    63,     5,     0,     3,     0,     6,     0,    10,    11,
      18,    20,    15,    16,    17,    29,   105,    21,    50,    19,
      64,    65,    67,    69,    71,    73,    75,    82,    87,    90,
      93,    98,   100,   113,     9,   122,   123,   124,   125,   126,
      45,   155,   156,     0,     0,   156,   105,    22,    45,     0,
       0,    27,     0,    28,    25,    23,     0,     0,     0,   104,
     101,   103,   102,     4,     0,     0,    62,     1,     2,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,   121,     0,   148,     0,     0,     0,     0,
       0,    48,   117,    47,    52,   118,   114,   115,    63,    43,
     105,    44,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    49,    66,    68,    70,    72,
      74,   155,   156,    80,    45,    79,    78,    76,    77,     0,
      83,    84,    85,    86,    88,    89,    91,    92,    94,    95,
      96,    97,    99,   119,     0,     0,    58,    59,    54,    55,
       0,    51,    53,    56,    57,     0,     0,     0,   153,   147,
     145,     0,     0,   138,    63,   141,   140,   139,   130,   136,
      61,     0,     0,    81,   121,   116,    46,     0,     0,     0,
     151,     0,     0,     0,     0,   137,     0,     0,   128,   131,
     129,   135,   120,     0,     0,     0,   156,     0,     0,   146,
       0,   142,     0,   132,   127,    60,   154,   152,   144,   150,
     149,     0,   134,     0,     0,   133,   143
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -222,  -222,    -1,    36,   -33,     1,  -222,  -222,  -222,  -222,
    -222,  -222,  -222,   176,    30,  -141,   -71,  -221,  -222,  -222,
    -148,    54,  -222,   167,   169,   173,   174,   172,   126,   136,
     -12,    -7,   -96,   256,  -222,   -69,  -135,  -222,  -222,  -222,
      41,  -196,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -144,
    -222,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    33,    34,    35,    36,   217,    38,    39,    40,    41,
      42,    43,    44,    45,    76,    47,    48,   211,   212,   213,
      95,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,   204,    64,    65,   248,
     249,   245,    66,    67,    79,   227,    68,   221,   271,   218,
      69,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    37,    99,   223,   220,   228,   229,    73,   215,    74,
     230,    80,    81,   269,    83,    87,   253,   154,   152,   155,
       1,     2,     3,     4,     5,   257,    93,    27,   258,    88,
      46,   143,   250,   251,    98,    70,    37,   270,   144,   198,
     199,   200,   201,   202,    71,    72,    21,    22,   206,   207,
     208,   209,   264,    97,    19,    75,    21,    22,   121,   122,
      32,   115,    23,    24,    77,    46,   140,    82,   141,   116,
      84,    85,    86,   142,    25,   117,   246,   155,   210,   226,
     131,   132,    26,   100,    94,    96,    28,    29,    70,   242,
     123,    30,   118,    31,   243,   124,   125,   126,   140,   252,
     141,   119,   259,   120,    19,    75,    21,    22,   133,   134,
     266,   247,   244,   268,  -156,   241,   272,   151,   153,   194,
     195,   184,    71,    72,    21,    22,   196,   197,   139,   275,
     276,   160,   127,   128,   129,   130,   135,   136,   137,   138,
     145,   146,   214,   224,    70,   222,   147,    70,   148,    70,
      70,   183,   149,   150,   156,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     154,   158,   157,   189,    46,   231,   153,    46,   225,    46,
      46,    71,    72,    21,    22,   206,   207,   208,   209,   184,
      19,    75,    21,    22,   203,   205,   101,   203,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    96,   232,   141,   210,   235,   234,   237,   233,
     236,   238,    99,    19,    20,    21,    22,   181,   182,    21,
      22,   184,   184,    71,   219,    21,    22,   214,   240,    70,
      37,   222,   239,   222,    71,   256,    21,    22,   185,   186,
     187,   188,   142,   244,    70,    70,    37,    70,   214,   254,
      70,   151,   153,   190,   191,   192,   193,   241,   260,    46,
     261,   265,   273,    70,    70,   255,   274,   159,    96,    89,
      90,    91,    92,   176,    46,    46,   177,    46,   203,   263,
      46,   178,   180,   179,     0,     0,     1,     2,     3,     4,
       5,   262,     0,    46,    46,     6,     7,     8,     9,    10,
       0,     0,     0,     0,    11,     0,    12,    13,     0,     0,
       0,     0,    14,    15,    16,    17,     0,    18,     0,     0,
      19,    20,    21,    22,     0,     0,     0,     0,    23,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,    28,    29,     0,     0,     0,    30,     0,    31,
       0,     1,     2,     3,     4,     5,     0,     0,     0,     0,
       6,     7,     8,     9,    10,     0,     0,     0,     0,    11,
       0,    12,    13,     0,     0,     0,   267,    14,    15,    16,
      17,     0,    18,     0,     0,    19,    20,    21,    22,     0,
       0,     0,     0,    23,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,    27,    28,    29,     0,
       0,     0,    30,     0,    31,     1,     2,     3,     4,     5,
       0,     0,     0,     0,     6,     7,     8,     9,    10,     0,
       0,     0,     0,    11,     0,    12,    13,     0,     0,    32,
       0,    14,    15,    16,    17,     0,    18,     0,     0,    19,
      20,    21,    22,     0,     0,     0,     0,    23,    24,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     0,    25,
       0,     0,     6,     0,     8,     0,    10,    26,     0,     0,
       0,    28,    29,    12,     0,     0,    30,     0,    31,    14,
      15,    16,    17,     0,     0,     0,     0,    19,    20,    21,
      22,     0,     0,     0,     0,    23,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,   216,    28,
      29,     0,     0,     0,    30,     0,    31
};

static const yytype_int16 yycheck[] =
{
       0,     0,    35,   147,   145,   149,   150,     7,   143,     9,
     158,    11,    12,     6,    14,    82,   237,    88,    87,    88,
       3,     4,     5,     6,     7,    81,    27,    68,    84,    82,
       0,    74,   228,   229,    35,    35,    35,   258,    81,   135,
     136,   137,   138,   139,    37,    38,    39,    40,    41,    42,
      43,    44,   248,     0,    37,    38,    39,    40,    26,    27,
     101,    86,    45,    46,    10,    35,    74,    13,    76,    66,
      16,    17,    18,    81,    57,    67,   224,   146,    71,   148,
      52,    53,    65,    68,    30,    31,    69,    70,    88,    75,
      58,    74,    55,    76,    80,    63,    64,    65,    74,   234,
      76,    56,   243,    54,    37,    38,    39,    40,    45,    46,
     254,    17,    18,   257,    81,    82,   260,    87,    88,   131,
     132,   121,    37,    38,    39,    40,   133,   134,    51,   273,
     274,   101,    59,    60,    61,    62,    47,    48,    49,    50,
      74,    82,   142,    76,   144,   145,    81,   147,    26,   149,
     150,   121,    81,    81,    75,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     241,    80,    77,    26,   144,    82,   146,   147,   148,   149,
     150,    37,    38,    39,    40,    41,    42,    43,    44,   189,
      37,    38,    39,    40,   140,   141,    86,   143,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   158,    82,    76,    71,    75,    80,    76,   189,
      77,    75,   255,    37,    38,    39,    40,    37,    38,    39,
      40,   231,   232,    37,    38,    39,    40,   237,    68,   239,
     239,   241,   102,   243,    37,    38,    39,    40,   122,   123,
     124,   125,    81,    18,   254,   255,   255,   257,   258,    81,
     260,   231,   232,   127,   128,   129,   130,    82,    81,   239,
      77,    77,    81,   273,   274,   239,    81,   101,   224,    23,
      24,    25,    26,   116,   254,   255,   117,   257,   234,   248,
     260,   118,   120,   119,    -1,    -1,     3,     4,     5,     6,
       7,   247,    -1,   273,   274,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    21,    -1,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    69,    70,    -1,    -1,    -1,    74,    -1,    76,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
      -1,    23,    24,    -1,    -1,    -1,   103,    29,    30,    31,
      32,    -1,    34,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    74,    -1,    76,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    21,    -1,    23,    24,    -1,    -1,   101,
      -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    57,
      -1,    -1,    12,    -1,    14,    -1,    16,    65,    -1,    -1,
      -1,    69,    70,    23,    -1,    -1,    74,    -1,    76,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    74,    -1,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    12,    13,    14,    15,
      16,    21,    23,    24,    29,    30,    31,    32,    34,    37,
      38,    39,    40,    45,    46,    57,    65,    68,    69,    70,
      74,    76,   101,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   141,   142,   146,   147,   150,   154,
     155,    37,    38,   155,   155,    38,   118,   125,   155,   148,
     155,   155,   125,   155,   125,   125,   125,    82,    82,   137,
     137,   137,   137,   106,   125,   124,   125,     0,   106,   108,
      68,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    86,    66,    67,    55,    56,
      54,    26,    27,    58,    63,    64,    65,    59,    60,    61,
      62,    52,    53,    45,    46,    47,    48,    49,    50,    51,
      74,    76,    81,    74,    81,    74,    82,    81,    26,    81,
      81,   118,   139,   118,   120,   139,    75,    77,    80,   117,
     118,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   127,   128,   129,   130,
     131,    37,    38,   118,   155,   132,   132,   132,   132,    26,
     133,   133,   133,   133,   134,   134,   135,   135,   136,   136,
     136,   136,   136,   125,   140,   125,    41,    42,    43,    44,
      71,   121,   122,   123,   155,   140,    68,   109,   153,    38,
     119,   151,   155,   153,    76,   118,   139,   149,   153,   153,
     124,    82,    82,   118,    80,    75,    77,    76,    75,   102,
      68,    82,    75,    80,    18,   145,   124,    17,   143,   144,
     145,   145,   140,   121,    81,   107,    38,    81,    84,   119,
      81,    77,   125,   144,   145,    77,   153,   103,   153,     6,
     121,   152,   153,    81,    81,   153,   153
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   110,   111,   112,   112,   113,   113,   114,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   118,   118,   118,   118,   119,
     119,   120,   120,   121,   121,   121,   121,   121,   122,   122,
     123,   124,   124,   124,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   132,   132,   132,   133,   133,   133,
     134,   134,   134,   135,   135,   135,   135,   135,   136,   136,
     137,   137,   137,   137,   137,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   139,   139,   139,   140,
     140,   140,   141,   141,   141,   141,   141,   142,   142,   142,
     142,   143,   143,   144,   145,   146,   146,   147,   147,   148,
     149,   149,   149,   150,   150,   151,   151,   151,   151,   152,
     152,   153,   153,   154,   154,   155,   155,   155,   155
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     1,     2,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     4,     3,     3,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     0,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     4,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     3,     3,     1,
       3,     0,     1,     1,     1,     1,     1,     6,     5,     5,
       4,     1,     2,     4,     3,     5,     4,     5,     4,     3,
       1,     1,     3,     9,     7,     1,     3,     1,     0,     1,
       1,     2,     4,     4,     7,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2:
#line 191 "parser.y"
                          {
            cout << "input" << endl;
            int uid = makenode("input");
            addChild(uid, (yyvsp[-1].id));
            int child = makenode("ENDMARKER");
            addChild(uid, child);
            root = uid;
            (yyval.id) = uid;

            }
#line 1786 "parser.tab.c"
    break;

  case 3:
#line 201 "parser.y"
               {
            cout << "input" << endl;
            int uid = makenode("input");
            int child = makenode("ENDMARKER");
            addChild(uid, child);
            root = uid;
            (yyval.id) = uid;}
#line 1798 "parser.tab.c"
    break;

  case 4:
#line 211 "parser.y"
                       { cout << "end newline" << endl;}
#line 1804 "parser.tab.c"
    break;

  case 5:
#line 212 "parser.y"
                    { cout << "end" << endl; }
#line 1810 "parser.tab.c"
    break;

  case 6:
#line 217 "parser.y"
                    { 
            cout << "statements" << endl;
            (yyval.id) = (yyvsp[0].id);
            

        }
#line 1821 "parser.tab.c"
    break;

  case 7:
#line 223 "parser.y"
                               { 
            cout << "statements" << endl;
            int uid = makenode("statements");
            addChild(uid, (yyvsp[-1].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 1833 "parser.tab.c"
    break;

  case 8:
#line 235 "parser.y"
                                 {
            cout << "statement" << endl;
            (yyval.id) = (yyvsp[-1].id);
        }
#line 1842 "parser.tab.c"
    break;

  case 9:
#line 239 "parser.y"
                             { 
            cout << "statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 1851 "parser.tab.c"
    break;

  case 10:
#line 249 "parser.y"
                                     { 
            cout << "simple statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 1860 "parser.tab.c"
    break;

  case 11:
#line 254 "parser.y"
                                    { 
            cout << "simple statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 1869 "parser.tab.c"
    break;

  case 12:
#line 258 "parser.y"
                              {
            cout << "simple break statement" << endl;
            (yyval.id) = makenode("break");

        }
#line 1879 "parser.tab.c"
    break;

  case 13:
#line 263 "parser.y"
                               { 
            cout << "simple continue statement" << endl;
            (yyval.id) = makenode("continue");
        }
#line 1888 "parser.tab.c"
    break;

  case 14:
#line 267 "parser.y"
                    {
            cout << "simple pass statement" << endl;
            (yyval.id) = makenode("pass");
        }
#line 1897 "parser.tab.c"
    break;

  case 15:
#line 271 "parser.y"
                                  { 
            cout << "simple statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 1906 "parser.tab.c"
    break;

  case 16:
#line 275 "parser.y"
                                 { 
            cout << "simple statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 1915 "parser.tab.c"
    break;

  case 17:
#line 279 "parser.y"
                                  { 
            cout << "simple statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 1924 "parser.tab.c"
    break;

  case 18:
#line 283 "parser.y"
                                  { 
            cout << "simple statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 1933 "parser.tab.c"
    break;

  case 19:
#line 287 "parser.y"
                                     { 
            cout << "simple expression" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 1942 "parser.tab.c"
    break;

  case 20:
#line 291 "parser.y"
                                   { 
            cout << "simple statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 1951 "parser.tab.c"
    break;

  case 21:
#line 301 "parser.y"
                                { 
            cout << "expression statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 1960 "parser.tab.c"
    break;

  case 22:
#line 316 "parser.y"
                             { 
            cout << "del statement" << endl;
            int uid = makenode("del");
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
            

        }
#line 1973 "parser.tab.c"
    break;

  case 23:
#line 327 "parser.y"
                                { 
            cout << "return statement" << endl;
            int uid = makenode("return");
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;

        }
#line 1985 "parser.tab.c"
    break;

  case 24:
#line 334 "parser.y"
                      { 
            cout << "return statement" << endl;
            (yyval.id) = makenode("return");

        }
#line 1995 "parser.tab.c"
    break;

  case 25:
#line 342 "parser.y"
                               { 
            cout << "raise statement" << endl;
            int uid = makenode("raise");
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2006 "parser.tab.c"
    break;

  case 26:
#line 348 "parser.y"
                     { 
            cout << "raise statement" << endl;
            (yyval.id) = makenode("raise");
        }
#line 2015 "parser.tab.c"
    break;

  case 27:
#line 356 "parser.y"
                             { 
            cout << "global statement" << endl;
            int uid = makenode("global");
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2026 "parser.tab.c"
    break;

  case 28:
#line 365 "parser.y"
                             { 
            cout << "nonlocal statement" << endl;
            int uid = makenode("nonlocal");
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2037 "parser.tab.c"
    break;

  case 30:
#line 378 "parser.y"
                                        {
            int uid = makenode("+=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2048 "parser.tab.c"
    break;

  case 31:
#line 384 "parser.y"
                                         {
            int uid = makenode("-=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2059 "parser.tab.c"
    break;

  case 32:
#line 390 "parser.y"
                                         { 
            int uid = makenode("*=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2070 "parser.tab.c"
    break;

  case 33:
#line 396 "parser.y"
                                          {
            int uid = makenode("/=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2081 "parser.tab.c"
    break;

  case 34:
#line 402 "parser.y"
                                         {
            int uid = makenode("//=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2092 "parser.tab.c"
    break;

  case 35:
#line 408 "parser.y"
                                       { 
            int uid = makenode("%=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2103 "parser.tab.c"
    break;

  case 36:
#line 414 "parser.y"
                                          { 
            int uid = makenode("@=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2114 "parser.tab.c"
    break;

  case 37:
#line 420 "parser.y"
                                       {
            int uid = makenode("&=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2125 "parser.tab.c"
    break;

  case 38:
#line 426 "parser.y"
                                      { 
            int uid = makenode("|=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2136 "parser.tab.c"
    break;

  case 39:
#line 432 "parser.y"
                                       { 
            int uid = makenode("^=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2147 "parser.tab.c"
    break;

  case 40:
#line 438 "parser.y"
                                          {
            int uid = makenode(">>=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2158 "parser.tab.c"
    break;

  case 41:
#line 444 "parser.y"
                                          { 
            int uid = makenode("<<=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2169 "parser.tab.c"
    break;

  case 42:
#line 450 "parser.y"
                                       { 
            int uid = makenode("**=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2180 "parser.tab.c"
    break;

  case 43:
#line 459 "parser.y"
                                     { 
            cout << "assignments" << endl;
            int uid = makenode("=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2192 "parser.tab.c"
    break;

  case 44:
#line 466 "parser.y"
                                       {
            cout << "assignments" << endl;
            int uid = makenode("=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2204 "parser.tab.c"
    break;

  case 45:
#line 476 "parser.y"
              {
            cout << "ids" << endl;
            (yyval.id) = (yyvsp[0].id);
         }
#line 2213 "parser.tab.c"
    break;

  case 46:
#line 480 "parser.y"
                                                         {
            cout << "ids" << endl;
            int uid = makenode("atom_expr");

            addChild(uid, (yyvsp[-3].id));
            int child= makenode("[]");
            addChild(uid, child);
            addChild(child, (yyvsp[-1].id));

            (yyval.id) = uid;
        }
#line 2229 "parser.tab.c"
    break;

  case 47:
#line 491 "parser.y"
                                    {
            cout << "ids" << endl;
            int uid = makenode("atomic_expr");
            addChild(uid, makenode("self"));
            int dot = makenode(".");
            addChild(uid, dot);
            addChild(dot, (yyvsp[0].id));

            // addChild(uid, $3);
            (yyval.id) = uid;
        }
#line 2245 "parser.tab.c"
    break;

  case 48:
#line 502 "parser.y"
                                   {
            // cout << "ids" << endl;
            int uid = makenode("atomic_expr");
            addChild(uid, makenode((yyvsp[-2].sval)));
            int dot = makenode(".");
            addChild(uid, dot);
            addChild(dot, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2259 "parser.tab.c"
    break;

  case 49:
#line 518 "parser.y"
                                                 { 
            cout << "variable" << endl;
            int uid = makenode("=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
            

        }
#line 2273 "parser.tab.c"
    break;

  case 50:
#line 528 "parser.y"
                           {
            cout << "variable" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2282 "parser.tab.c"
    break;

  case 51:
#line 536 "parser.y"
                                          {
            int uid = makenode(":");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2293 "parser.tab.c"
    break;

  case 52:
#line 544 "parser.y"
                                                 { 
            int uid = makenode("atomic_expr");
            addChild(uid, makenode("self"));
            int dot = makenode(".");
            addChild(uid, dot);
            addChild(dot, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2306 "parser.tab.c"
    break;

  case 53:
#line 556 "parser.y"
                      { 
            cout << "numeric" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2315 "parser.tab.c"
    break;

  case 54:
#line 560 "parser.y"
                      { 
            cout << "string" << endl;
            (yyval.id) = makenode("str");
        }
#line 2324 "parser.tab.c"
    break;

  case 55:
#line 564 "parser.y"
                      {
             cout << "bool" << endl;
                (yyval.id) = makenode("bool"); 

        }
#line 2334 "parser.tab.c"
    break;

  case 56:
#line 569 "parser.y"
                      {
             cout << "list" << endl;
                (yyval.id) = (yyvsp[0].id);
        }
#line 2343 "parser.tab.c"
    break;

  case 57:
#line 573 "parser.y"
                      {
            cout << "primitive" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2352 "parser.tab.c"
    break;

  case 58:
#line 581 "parser.y"
                      { 
            cout << "int" << endl;
            (yyval.id) = makenode("int");
        }
#line 2361 "parser.tab.c"
    break;

  case 59:
#line 585 "parser.y"
                      {
            cout << "float" << endl;
            (yyval.id) = makenode("float");
        }
#line 2370 "parser.tab.c"
    break;

  case 60:
#line 594 "parser.y"
                                                              { 
            cout << "list_type" << endl;
            int uid = makenode("atom_expr");
            addChild(uid, makenode("list"));
            int child = makenode("[]");
            addChild(child, (yyvsp[-1].id));
            addChild(uid, child);
            (yyval.id) = uid;
        }
#line 2384 "parser.tab.c"
    break;

  case 61:
#line 607 "parser.y"
                                                { 
            cout << "list" << endl;
            int uid = makenode(",");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2396 "parser.tab.c"
    break;

  case 62:
#line 614 "parser.y"
                     { 
            cout << "list" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2405 "parser.tab.c"
    break;

  case 63:
#line 618 "parser.y"
                 {
            (yyval.id) = -1;
        }
#line 2413 "parser.tab.c"
    break;

  case 64:
#line 627 "parser.y"
                            { 
        cout << "expression" << endl;
        (yyval.id) = (yyvsp[0].id);
    }
#line 2422 "parser.tab.c"
    break;

  case 65:
#line 634 "parser.y"
                                    {
            cout << "logical or" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2431 "parser.tab.c"
    break;

  case 66:
#line 638 "parser.y"
                                                                     { 
            cout << "logical or" << endl;
            int uid = makenode("or");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2443 "parser.tab.c"
    break;

  case 67:
#line 648 "parser.y"
                                 { 
            cout << "logical and" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2452 "parser.tab.c"
    break;

  case 68:
#line 652 "parser.y"
                                                                      { 
            cout << "logical and" << endl;
            int uid = makenode("and");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2464 "parser.tab.c"
    break;

  case 69:
#line 662 "parser.y"
                                   { 
            cout << "bitwise or" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2473 "parser.tab.c"
    break;

  case 70:
#line 666 "parser.y"
                                                                     { 
            cout << "bitwise or" << endl;
            int uid = makenode("|");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2485 "parser.tab.c"
    break;

  case 71:
#line 676 "parser.y"
                                   { 
            cout << "bitwise xor" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2494 "parser.tab.c"
    break;

  case 72:
#line 680 "parser.y"
                                                                       { 
            cout << "bitwise xor" << endl;
            int uid = makenode("^");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2506 "parser.tab.c"
    break;

  case 73:
#line 690 "parser.y"
                                 { 
            cout << "bitwise and" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2515 "parser.tab.c"
    break;

  case 74:
#line 694 "parser.y"
                                                                    { 
            cout << "bitwise and" << endl;
            int uid = makenode("&");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2527 "parser.tab.c"
    break;

  case 75:
#line 704 "parser.y"
                                 { 
            cout << "equality expression" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2536 "parser.tab.c"
    break;

  case 76:
#line 708 "parser.y"
                                                          {  
            cout << "equality expression" << endl;
            int uid = makenode("==");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2548 "parser.tab.c"
    break;

  case 77:
#line 715 "parser.y"
                                                              {
            cout << "equality expression" << endl;
            int uid = makenode("!=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2560 "parser.tab.c"
    break;

  case 78:
#line 722 "parser.y"
                                                              {
            cout << "equality expression" << endl;
            int uid = makenode(":=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2572 "parser.tab.c"
    break;

  case 79:
#line 729 "parser.y"
                                                           {
            cout << "equality expression" << endl;
            int uid = makenode("=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2584 "parser.tab.c"
    break;

  case 80:
#line 736 "parser.y"
                                         {
            cout << "equality expression" << endl;
            int uid = makenode("in");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2596 "parser.tab.c"
    break;

  case 81:
#line 743 "parser.y"
                                                        {
            cout << "equality expression" << endl;
            int uid = makenode("!=");
            addChild(uid, (yyvsp[-3].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2608 "parser.tab.c"
    break;

  case 82:
#line 753 "parser.y"
                            { 
            cout << "relational expression" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2617 "parser.tab.c"
    break;

  case 83:
#line 757 "parser.y"
                                                         { 
            cout << "relational expression" << endl;
            int uid = makenode("<");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2629 "parser.tab.c"
    break;

  case 84:
#line 764 "parser.y"
                                                            { 
            cout << "relational expression" << endl;
            int uid = makenode(">");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2641 "parser.tab.c"
    break;

  case 85:
#line 771 "parser.y"
                                                            {
            cout << "relational expression" << endl;
            int uid = makenode("<=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2653 "parser.tab.c"
    break;

  case 86:
#line 778 "parser.y"
                                                               {
            cout << "relational expression" << endl;
            int uid = makenode(">=");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2665 "parser.tab.c"
    break;

  case 88:
#line 789 "parser.y"
                                                         {
            cout << "shift expression" << endl;
            int uid = makenode("<<");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2677 "parser.tab.c"
    break;

  case 89:
#line 796 "parser.y"
                                                         { 
            cout << "shift expression" << endl;
            int uid = makenode(">>");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2689 "parser.tab.c"
    break;

  case 90:
#line 806 "parser.y"
                                     { 
            cout << "additive expression" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2698 "parser.tab.c"
    break;

  case 91:
#line 810 "parser.y"
                                                                { 
            cout << "additive expression" << endl;
            int uid = makenode("+");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2710 "parser.tab.c"
    break;

  case 92:
#line 817 "parser.y"
                                                                 { 
            cout << "additive expression" << endl;
            int uid = makenode("-");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2722 "parser.tab.c"
    break;

  case 93:
#line 827 "parser.y"
                                      { 
            cout << "multiplicative expression" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2731 "parser.tab.c"
    break;

  case 94:
#line 831 "parser.y"
                                                                       { 
            cout << "multiplicative expression" << endl;
            int uid = makenode("*");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2743 "parser.tab.c"
    break;

  case 95:
#line 838 "parser.y"
                                                                        {
            cout << "multiplicative expression" << endl;
            int uid = makenode("/");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2755 "parser.tab.c"
    break;

  case 96:
#line 845 "parser.y"
                                                                       {
            cout << "multiplicative expression" << endl;
            int uid = makenode("//");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2767 "parser.tab.c"
    break;

  case 97:
#line 852 "parser.y"
                                                                     { 
            cout << "multiplicative expression" << endl;
            int uid = makenode("%");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2779 "parser.tab.c"
    break;

  case 98:
#line 862 "parser.y"
                                 {
            cout << "exponentiation expression" << endl;
            (yyval.id) = (yyvsp[0].id);
         }
#line 2788 "parser.tab.c"
    break;

  case 99:
#line 866 "parser.y"
                                                              {
            cout << "exponentiation expression" << endl;
            int uid = makenode("**");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2800 "parser.tab.c"
    break;

  case 100:
#line 876 "parser.y"
                                {
            cout << "negated expression" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2809 "parser.tab.c"
    break;

  case 101:
#line 880 "parser.y"
                                      {
            cout << "negated expression" << endl;
            int uid = makenode("-");
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2820 "parser.tab.c"
    break;

  case 102:
#line 886 "parser.y"
                                            { 
            cout << "negated expression" << endl;
            int uid = makenode("not");
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2831 "parser.tab.c"
    break;

  case 103:
#line 892 "parser.y"
                                            {
            cout << "negated expression" << endl;
            int uid = makenode("~");
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2842 "parser.tab.c"
    break;

  case 104:
#line 898 "parser.y"
                                     { 
            cout << "negated expression" << endl;
            int uid = makenode("+");
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;

        }
#line 2854 "parser.tab.c"
    break;

  case 105:
#line 908 "parser.y"
              { 
            cout << "primary expression" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2863 "parser.tab.c"
    break;

  case 106:
#line 912 "parser.y"
                      { 
            cout << yyval.intNumber << endl; 
            (yyval.id) = makenode(to_string(yyval.intNumber));
        }
#line 2872 "parser.tab.c"
    break;

  case 107:
#line 916 "parser.y"
                        {
            cout << yyval.fltNumber << endl;
            (yyval.id) = makenode(to_string(yyval.fltNumber));
         }
#line 2881 "parser.tab.c"
    break;

  case 108:
#line 920 "parser.y"
                 { 
            cout << "string" << endl;
            // add \ to string start and end
            (yyval.id) = makenode((yyvsp[0].sval));
        }
#line 2891 "parser.tab.c"
    break;

  case 109:
#line 925 "parser.y"
                     { 
            cout << "byte string" << endl;
            (yyval.id) = makenode((yyvsp[0].sval));
        }
#line 2900 "parser.tab.c"
    break;

  case 110:
#line 929 "parser.y"
                  {
            cout << "true" << endl;
            (yyval.id) = makenode("True");
         }
#line 2909 "parser.tab.c"
    break;

  case 111:
#line 933 "parser.y"
                   {
            cout << "false" << endl;
            (yyval.id) = makenode("False");
         }
#line 2918 "parser.tab.c"
    break;

  case 112:
#line 937 "parser.y"
                   { 
            cout << "none" << endl;
            (yyval.id) = makenode("None");
        }
#line 2927 "parser.tab.c"
    break;

  case 113:
#line 941 "parser.y"
                   { 
            cout << "function call" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 2936 "parser.tab.c"
    break;

  case 114:
#line 945 "parser.y"
                                           { 
            int uid = makenode("()");
            addChild(uid, (yyvsp[-1].id));
            (yyval.id) = uid;
        }
#line 2946 "parser.tab.c"
    break;

  case 115:
#line 950 "parser.y"
                                                        {
            int uid = makenode("[]");
            addChild(uid, (yyvsp[-1].id));
            (yyval.id) = uid;
        }
#line 2956 "parser.tab.c"
    break;

  case 116:
#line 961 "parser.y"
                                              {
            int uid = makenode("atomic_expr");
            addChild(uid, (yyvsp[-3].id));
            int child = makenode("()");
            addChild(uid, child);
            addChild(child, (yyvsp[-1].id));
            (yyval.id) = uid;
        }
#line 2969 "parser.tab.c"
    break;

  case 117:
#line 969 "parser.y"
                                        { 
            int uid = makenode("atomic_expr");
            addChild(uid, makenode((yyvsp[-2].sval)));
            int dot = makenode(".");
            addChild(uid, dot);
            addChild(dot, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 2982 "parser.tab.c"
    break;

  case 118:
#line 977 "parser.y"
                                         {
            int uid = makenode("atomic_expr");
            addChild(uid, makenode("self"));
            int dot = makenode(".");
            addChild(uid, dot);
            addChild(dot, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 2995 "parser.tab.c"
    break;

  case 119:
#line 989 "parser.y"
                   { 
            cout << "arguments" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 3004 "parser.tab.c"
    break;

  case 120:
#line 993 "parser.y"
                                           {
            cout << "arguments" << endl;
            int uid = makenode(",");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 3016 "parser.tab.c"
    break;

  case 121:
#line 1000 "parser.y"
                  {
            (yyval.id) = -1;
        }
#line 3024 "parser.tab.c"
    break;

  case 122:
#line 1010 "parser.y"
                     {
            cout << "compound statement" << endl;
            (yyval.id)=(yyvsp[0].id);
        }
#line 3033 "parser.tab.c"
    break;

  case 123:
#line 1014 "parser.y"
                          { 
            cout << "compound statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 3042 "parser.tab.c"
    break;

  case 124:
#line 1018 "parser.y"
                        { 
            cout << "compound statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 3051 "parser.tab.c"
    break;

  case 125:
#line 1022 "parser.y"
                   { 
            cout << "compound statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 3060 "parser.tab.c"
    break;

  case 126:
#line 1026 "parser.y"
                    { 
            cout << "compound statement" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 3069 "parser.tab.c"
    break;

  case 127:
#line 1035 "parser.y"
                                                                 {
            cout << "if statement" << endl;
            int uid = makenode("if");
            addChild(uid, (yyvsp[-4].id));
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[-1].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;

        }
#line 3085 "parser.tab.c"
    break;

  case 128:
#line 1046 "parser.y"
                                                         { 
            cout << "if statement" << endl;
            int uid = makenode("if");
            addChild(uid, (yyvsp[-3].id));
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[-1].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 3099 "parser.tab.c"
    break;

  case 129:
#line 1055 "parser.y"
                                                        { 
            cout << "if statement" << endl;
            int uid = makenode("if");
            addChild(uid, (yyvsp[-3].id));
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[-1].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 3113 "parser.tab.c"
    break;

  case 130:
#line 1064 "parser.y"
                                              { 
            cout << "if statement4" << endl;
            int uid = makenode("if");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;

        }
#line 3127 "parser.tab.c"
    break;

  case 131:
#line 1075 "parser.y"
                             { 
            cout << "elifblocks" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 3136 "parser.tab.c"
    break;

  case 132:
#line 1079 "parser.y"
                                 {
            cout << "elifblocks" << endl;
            int uid = makenode("elif");
            addChild(uid, (yyvsp[-1].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 3148 "parser.tab.c"
    break;

  case 133:
#line 1090 "parser.y"
                                               {
            cout << "elifblock" << endl;
            int uid = makenode("elif");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 3161 "parser.tab.c"
    break;

  case 134:
#line 1101 "parser.y"
                                    { 
            cout << "elseblock" << endl;
            int uid = makenode("else");
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 3173 "parser.tab.c"
    break;

  case 135:
#line 1114 "parser.y"
                                                          {
            cout << "while statement" << endl;
            int uid = makenode("while");
            addChild(uid, (yyvsp[-3].id));
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[-1].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 3187 "parser.tab.c"
    break;

  case 136:
#line 1123 "parser.y"
                                                  { 
            cout << "while statement" << endl;
            int uid = makenode("while");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 3200 "parser.tab.c"
    break;

  case 137:
#line 1137 "parser.y"
                                                            {
            cout << "for statement" << endl;
            int uid = makenode("for");
            addChild(uid, (yyvsp[-3].id));
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[-1].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 3214 "parser.tab.c"
    break;

  case 138:
#line 1146 "parser.y"
                                                    {
            cout << "for statement" << endl;
            int uid = makenode("for");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
         }
#line 3227 "parser.tab.c"
    break;

  case 139:
#line 1157 "parser.y"
                                { 
            cout << "for expression" << endl;
            int uid = makenode("in");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid; 
        }
#line 3239 "parser.tab.c"
    break;

  case 140:
#line 1168 "parser.y"
                   {
            cout << "for list" << endl;
            (yyval.id) = (yyvsp[0].id);
         }
#line 3248 "parser.tab.c"
    break;

  case 141:
#line 1172 "parser.y"
               {
            cout << "for list" << endl;
            (yyval.id) = (yyvsp[0].id);
         }
#line 3257 "parser.tab.c"
    break;

  case 142:
#line 1176 "parser.y"
                                                        {
            cout << "for list" << endl;
            int uid = makenode("[]");
            addChild(uid, (yyvsp[-1].id));
            (yyval.id) = uid;
        
        }
#line 3269 "parser.tab.c"
    break;

  case 143:
#line 1190 "parser.y"
                                                                                              { 
            cout << "function definition" << endl;
            int uid = makenode("def");
            addChild(uid, (yyvsp[-7].id));
            int PARs = makenode("()");
            addChild(PARs, (yyvsp[-5].id));
            addChild(uid, PARs);
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 3286 "parser.tab.c"
    break;

  case 144:
#line 1202 "parser.y"
                                                                        { 
            cout << "function definition" << endl;
            int uid = makenode("def");
            addChild(uid, (yyvsp[-5].id));
            int PARs = makenode("()");
            addChild(PARs, (yyvsp[-3].id));
            addChild(uid, PARs);
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 3302 "parser.tab.c"
    break;

  case 145:
#line 1218 "parser.y"
                              {
            cout << "params" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 3311 "parser.tab.c"
    break;

  case 146:
#line 1222 "parser.y"
                                                  {
            cout << "params" << endl;
            int uid = makenode(",");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 3323 "parser.tab.c"
    break;

  case 147:
#line 1229 "parser.y"
                      {
            cout << "params" << endl;
            (yyval.id) = makenode("self");
        }
#line 3332 "parser.tab.c"
    break;

  case 148:
#line 1233 "parser.y"
                 {
            cout << "params" << endl;
            (yyval.id) = -1;
        }
#line 3341 "parser.tab.c"
    break;

  case 149:
#line 1239 "parser.y"
                       { 
            cout << "return type" << endl;
            (yyval.id) = (yyvsp[0].id);
        }
#line 3350 "parser.tab.c"
    break;

  case 150:
#line 1244 "parser.y"
                   { 
            cout << "return type" << endl;
            (yyval.id) = makenode("None");
        }
#line 3359 "parser.tab.c"
    break;

  case 151:
#line 1250 "parser.y"
                                { 
            cout << "suite" << endl;
            (yyval.id) = (yyvsp[-1].id);
        }
#line 3368 "parser.tab.c"
    break;

  case 152:
#line 1254 "parser.y"
                                           { 
            cout << "--------------" << endl;
            (yyval.id) = (yyvsp[-1].id);
        }
#line 3377 "parser.tab.c"
    break;

  case 153:
#line 1263 "parser.y"
                                             { 
            cout << "class definition" << endl;
            int uid = makenode("class");
            addChild(uid, (yyvsp[-2].id));
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 3390 "parser.tab.c"
    break;

  case 154:
#line 1271 "parser.y"
                                                                             { 
            cout << "class definition" << endl;
            int uid = makenode("class");
            addChild(uid, (yyvsp[-5].id));
            int PARs = makenode("()");
            addChild(PARs, (yyvsp[-3].id));
            addChild(uid, PARs);
            addChild(uid, makenode(":"));
            addChild(uid, (yyvsp[0].id));
            (yyval.id) = uid;
        }
#line 3406 "parser.tab.c"
    break;

  case 155:
#line 1286 "parser.y"
                   { 
            (yyval.id) = makenode((yyvsp[0].sval));
        }
#line 3414 "parser.tab.c"
    break;

  case 156:
#line 1289 "parser.y"
                      { 
            (yyval.id) = makenode("self");
        }
#line 3422 "parser.tab.c"
    break;

  case 157:
#line 1292 "parser.y"
                      { 
            (yyval.id) = makenode("__init__");
        }
#line 3430 "parser.tab.c"
    break;

  case 158:
#line 1295 "parser.y"
                      { 
            (yyval.id) = makenode("main");
        }
#line 3438 "parser.tab.c"
    break;


#line 3442 "parser.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 1313 "parser.y"


int main(int argc, char **argv){
    if(argc > 1){
        /* printf("File name: %s\n", argv[1]); */
        FILE *fp = fopen(argv[1], "r");
        if(fp){
            yyin = fp;
            yyparse();
            fclose(fp);
        }
        else{

            printf("Error: File not found\n");
        }
    }
    else   {
        
         FILE *fp = fopen("input.py", "r");
         if(fp) {
                yyin = fp;
         }
         yyparse();
         fclose(fp);
    }
    writeDotFile(tree, "tree.dot");
    return 0;
}

void yyerror(const char *message)
{
    std::cerr << "Error at line " << yylineno << ": " << message << std::endl;
    std::cerr << "Token: " << yytext << std::endl;
    exit(EXIT_FAILURE); // Terminate the program after encountering an error
}
