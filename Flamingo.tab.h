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
    CONST = 260,                   /* CONST  */
    typeVAR = 261,                 /* typeVAR  */
    TYPE = 262,                    /* TYPE  */
    INTTYPE = 263,                 /* INTTYPE  */
    BIGINTTYPE = 264,              /* BIGINTTYPE  */
    LONGINTTYPE = 265,             /* LONGINTTYPE  */
    STRINGTYPE = 266,              /* STRINGTYPE  */
    FLOATTYPE = 267,               /* FLOATTYPE  */
    BIGFLOATTYPE = 268,            /* BIGFLOATTYPE  */
    LONGFLOATTYPE = 269,           /* LONGFLOATTYPE  */
    BOOLTYPE = 270,                /* BOOLTYPE  */
    STRUCT = 271,                  /* STRUCT  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    REPEAT = 274,                  /* REPEAT  */
    WHILE = 275,                   /* WHILE  */
    FOR = 276,                     /* FOR  */
    FROM = 277,                    /* FROM  */
    TO = 278,                      /* TO  */
    GIVEBACK = 279,                /* GIVEBACK  */
    READ = 280,                    /* READ  */
    WRITE = 281,                   /* WRITE  */
    FLOAT = 282,                   /* FLOAT  */
    INT = 283,                     /* INT  */
    BOOL = 284,                    /* BOOL  */
    STRING = 285,                  /* STRING  */
    PARENTHESEOUVRANTE = 286,      /* PARENTHESEOUVRANTE  */
    PARENTHESEFERMANTE = 287,      /* PARENTHESEFERMANTE  */
    ACCOLADEOUVRANTE = 288,        /* ACCOLADEOUVRANTE  */
    ACCOLADEFERMANTE = 289,        /* ACCOLADEFERMANTE  */
    CROCHETOUVRANT = 290,          /* CROCHETOUVRANT  */
    CROCHETFERMANT = 291,          /* CROCHETFERMANT  */
    EXCLAM = 292,                  /* EXCLAM  */
    POINT = 293,                   /* POINT  */
    VIRG = 294,                    /* VIRG  */
    INC = 295,                     /* INC  */
    DEC = 296,                     /* DEC  */
    AFFECT = 297,                  /* AFFECT  */
    NOTEQUALS = 298,               /* NOTEQUALS  */
    ADDEQUALS = 299,               /* ADDEQUALS  */
    SUBEQUALS = 300,               /* SUBEQUALS  */
    MULEQUALS = 301,               /* MULEQUALS  */
    DIVINTEQUALS = 302,            /* DIVINTEQUALS  */
    DIVEQUALS = 303,               /* DIVEQUALS  */
    MODEQUALS = 304,               /* MODEQUALS  */
    POWEQUALS = 305,               /* POWEQUALS  */
    EQUALS = 306,                  /* EQUALS  */
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
