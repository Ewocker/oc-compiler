/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
