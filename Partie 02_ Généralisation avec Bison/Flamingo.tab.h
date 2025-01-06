/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_FLAMINGO_TAB_H_INCLUDED
# define YY_YY_FLAMINGO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PACK = 258,                    /* PACK  */
    FONCTION = 259,                /* FONCTION  */
    MAIN = 260,                    /* MAIN  */
    HelloMain = 261,               /* HelloMain  */
    CONST = 262,                   /* CONST  */
    TYPE = 263,                    /* TYPE  */
    INTTYPE = 264,                 /* INTTYPE  */
    BIGINTTYPE = 265,              /* BIGINTTYPE  */
    LONGINTTYPE = 266,             /* LONGINTTYPE  */
    STRINGTYPE = 267,              /* STRINGTYPE  */
    FLOATTYPE = 268,               /* FLOATTYPE  */
    BIGFLOATTYPE = 269,            /* BIGFLOATTYPE  */
    LONGFLOATTYPE = 270,           /* LONGFLOATTYPE  */
    BOOLTYPE = 271,                /* BOOLTYPE  */
    STRUCT = 272,                  /* STRUCT  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    REPEAT = 275,                  /* REPEAT  */
    WHILE = 276,                   /* WHILE  */
    FOR = 277,                     /* FOR  */
    FROM = 278,                    /* FROM  */
    TO = 279,                      /* TO  */
    GIVEBACK = 280,                /* GIVEBACK  */
    READ = 281,                    /* READ  */
    WRITE = 282,                   /* WRITE  */
    FLOAT = 283,                   /* FLOAT  */
    INT = 284,                     /* INT  */
    BOOL = 285,                    /* BOOL  */
    STRING = 286,                  /* STRING  */
    PARENTHESEOUVRANTE = 287,      /* PARENTHESEOUVRANTE  */
    PARENTHESEFERMANTE = 288,      /* PARENTHESEFERMANTE  */
    ACCOLADEOUVRANTE = 289,        /* ACCOLADEOUVRANTE  */
    ACCOLADEFERMANTE = 290,        /* ACCOLADEFERMANTE  */
    CROCHETOUVRANT = 291,          /* CROCHETOUVRANT  */
    CROCHETFERMANT = 292,          /* CROCHETFERMANT  */
    ENDINST = 293,                 /* ENDINST  */
    POINT = 294,                   /* POINT  */
    VIRG = 295,                    /* VIRG  */
    INC = 296,                     /* INC  */
    DEC = 297,                     /* DEC  */
    AFFECT = 298,                  /* AFFECT  */
    NOTEQUALS = 299,               /* NOTEQUALS  */
    ADDEQUALS = 300,               /* ADDEQUALS  */
    SUBEQUALS = 301,               /* SUBEQUALS  */
    MULEQUALS = 302,               /* MULEQUALS  */
    DIVINTEQUALS = 303,            /* DIVINTEQUALS  */
    DIVEQUALS = 304,               /* DIVEQUALS  */
    MODEQUALS = 305,               /* MODEQUALS  */
    POWEQUALS = 306,               /* POWEQUALS  */
    ADD = 307,                     /* ADD  */
    SUB = 308,                     /* SUB  */
    MUL = 309,                     /* MUL  */
    MOD = 310,                     /* MOD  */
    DIV = 311,                     /* DIV  */
    INTDIV = 312,                  /* INTDIV  */
    POW = 313,                     /* POW  */
    NEG = 314,                     /* NEG  */
    LESS = 315,                    /* LESS  */
    LESSEQUALS = 316,              /* LESSEQUALS  */
    GREATER = 317,                 /* GREATER  */
    GREATEREQUALS = 318,           /* GREATEREQUALS  */
    DOUBLEEQUALS = 319,            /* DOUBLEEQUALS  */
    AND = 320,                     /* AND  */
    OR = 321,                      /* OR  */
    ID = 322                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_FLAMINGO_TAB_H_INCLUDED  */
