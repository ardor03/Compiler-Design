/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 171 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
