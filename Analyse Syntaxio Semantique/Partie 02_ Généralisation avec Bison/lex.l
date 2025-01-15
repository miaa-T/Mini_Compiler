%{
#include <stdio.h>
#include "yacc.tab.h"

extern void termeSuiv(char *s);
extern void yyerror(const char *s);
extern void showLexicalError();
extern int termeCourant;

%}

%option noyywrap 
%option yylineno
/* partie decalaration FLEX  */
ID          [a-zA-Z_][a-zA-Z0-9_]* 
nb_int       [0-9]+
nb_float     {nb_int}+"."+{nb_int} 
c_string     \".*\"
bol        TRUE|FALSE
TYPE       (nb_int|nb_float|c_string|bol)
LINEBREAK           "\n"|"\r"
COMMENTAIRE         "#"([^#]|\n)*"#"
PACK        pack
FONCTION    fn
CONST       cst
INTTYPE     int
BIGINTTYPE  bigint
LONGINTTYPE longint
STRINGTYPE  str
FLOATTYPE   float
BIGFLOATTYPE bigfloat
LONGFLOATTYPE longfloat
BOOLTYPE    bool
STRUCT      struct
IF          if
ELSE        else
REPEAT      repeat
WHILE       while
FOR         for
FROM        from
TO          to
GIVEBACK    giveback
READ        read
WRITE       write
MAIN        Main
HelloMain Hello_Flamingo_Developer
PARENTHESEOUVRANTE   \(
PARENTHESEFERMANTE   \)
ACCOLADEOUVRANTE     \{
ACCOLADEFERMANTE     \}
CROCHETOUVRANT       \[
CROCHETFERMANT       \]
ENDINST               ;;
POINT                \.
VIRG                 ,
INC                  \+\+
DEC                  \-\-
AFFECT               =
NOTEQUALS            !=
ADDEQUALS            \+=
SUBEQUALS            \-=
MULEQUALS            \*=
DIVINTEQUALS         \/\/=
DIVEQUALS            \/=
MODEQUALS            %=
POWEQUALS            \^=
ADD                  \+
SUB                  \-
MUL                  \*
MOD                  %
DIV                  \/\/
INTDIV               \/
POW                  \^
NEG                  !
LESS                 <
LESSEQUALS           <=
GREATER              >
GREATEREQUALS        >=
DOUBLEEQUALS         ==
AND                  \&\&
OR                   \|\|

%%

{PACK} {
    termeSuiv("PACK");
    return PACK;
}
{MAIN} {
    termeSuiv("MAIN");
    return MAIN;
}
{HelloMain} {
    termeSuiv("HelloMain");
    return HelloMain;
}
{FONCTION} {
    termeSuiv("FONCTION");
    return FONCTION;
}
{CONST} {
    termeSuiv("CONST");
    return CONST;
}
{INTTYPE} {
    termeSuiv("INTTYPE");
    return INTTYPE;
}
{BIGINTTYPE} {
    termeSuiv("BIGINTTYPE");
    return BIGINTTYPE;
}
{LONGINTTYPE} {
    termeSuiv("LONGINTTYPE");
    return LONGINTTYPE;
}
{STRINGTYPE} {
    termeSuiv("STRINGTYPE");
    return STRINGTYPE;
}
{FLOATTYPE} {
    termeSuiv("FLOATTYPE");
    return FLOATTYPE;
}
{BIGFLOATTYPE} {
    termeSuiv("BIGFLOATTYPE");
    return BIGFLOATTYPE;
}
{LONGFLOATTYPE} {
    termeSuiv("LONGFLOATTYPE");
    return LONGFLOATTYPE;
}
{BOOLTYPE} {
    termeSuiv("BOOLTYPE");
    return BOOLTYPE;
}
{TYPE} {
    termeSuiv("TYPE");
    return TYPE;
}
{STRUCT} {
    termeSuiv("STRUCT");
    return STRUCT;
}

{IF} {
    termeSuiv("IF");
    return IF;
}
{ELSE} {
    termeSuiv("ELSE");
    return ELSE;
}
{REPEAT} {
    termeSuiv("REPEAT");
    return REPEAT;
}
{WHILE} {
    termeSuiv("WHILE");
    return WHILE;
}
{FOR} {
    termeSuiv("FOR");
    return FOR;
}
{FROM} {
    termeSuiv("FROM");
    return FROM;
}
{TO} {
    termeSuiv("TO");
    return TO;
}
{GIVEBACK} {
    termeSuiv("GIVEBACK");
    return GIVEBACK;
}
{READ} {
    termeSuiv("READ");
    return READ;
}
{WRITE} {
    termeSuiv("WRITE");
    return WRITE;
}
{nb_float} {
    termeSuiv("nb_float");
    return FLOAT;
}
{nb_int} {
    termeSuiv("nb_int");
    return INT;
}
{bol} {
    termeSuiv("bol");
    return BOOL;
}
{c_string} {
    termeSuiv("c_string");
    return STRING;
}

{PARENTHESEOUVRANTE} {
    termeSuiv("(");
    return PARENTHESEOUVRANTE;
}
{PARENTHESEFERMANTE} {
    termeSuiv(")");
    return PARENTHESEFERMANTE;
}
{ACCOLADEOUVRANTE} {
    termeSuiv("{");
    return ACCOLADEOUVRANTE;
}
{ACCOLADEFERMANTE} {
    termeSuiv("}");
    return ACCOLADEFERMANTE;
}
{CROCHETOUVRANT} {
    termeSuiv("[");
    return CROCHETOUVRANT;
}
{CROCHETFERMANT} {
    termeSuiv("]");
    return CROCHETFERMANT;
}
{ENDINST} {
    termeSuiv(";;");
    return ENDINST ;
}
{POINT} {
    termeSuiv(".");
    return POINT;
}
{VIRG} {
    termeSuiv(",");
    return VIRG;
}
{INC} {
    termeSuiv("++");
    return INC;
}
{DEC} {
    termeSuiv("--");
    return DEC;
}
{AFFECT} {
    termeSuiv("=");
    return AFFECT;
}
{NOTEQUALS} {
    termeSuiv("!=");
    return NOTEQUALS;
}
{ADDEQUALS} {
    termeSuiv("+=");
    return ADDEQUALS;
}
{SUBEQUALS} {
    termeSuiv("-=");
    return SUBEQUALS;
}
{MULEQUALS} {
    termeSuiv("*=");
    return MULEQUALS;
}
{DIVINTEQUALS} {
    termeSuiv("//=");
    return DIVINTEQUALS;
}
{DIVEQUALS} {
    termeSuiv("/=");
    return DIVEQUALS;
}
{MODEQUALS} {
    termeSuiv("%=");
    return MODEQUALS;
}
{POWEQUALS} {
    termeSuiv("^=");
    return POWEQUALS;
}
{ADD} {
    termeSuiv("+");
    return ADD;
}
{SUB} {
    termeSuiv("-");
    return SUB;
}
{MUL} {
    termeSuiv("*");
    return MUL;
}
{MOD} {
    termeSuiv("%");
    return MOD;
}
{DIV} {
    termeSuiv("//");
    return DIV;
}
{INTDIV} {
    termeSuiv("/");
    return INTDIV;
}
{POW} {
    termeSuiv("^");
    return POW;
}
{NEG} {
    termeSuiv("!");
    return NEG;
}
{LESS} {
    termeSuiv("<");
    return LESS;
}
{LESSEQUALS} {
    termeSuiv("<=");
    return LESSEQUALS;
}
{GREATER} {
    termeSuiv(">");
    return GREATER;
}
{GREATEREQUALS} {
    termeSuiv(">=");
    return GREATEREQUALS;
}
{DOUBLEEQUALS} {
    termeSuiv("==");
    return DOUBLEEQUALS;
}
{AND} {
    termeSuiv("&&");
    return AND;
}
{OR} {
    termeSuiv("||");
    return OR;
}


{ID}     {
    termeSuiv("ID");
    return ID;
}

{LINEBREAK} {
    termeCourant =1;
}

[ \t]+ {
    termeCourant+=yyleng;
}

{COMMENTAIRE} {}

<<EOF>> yyterminate();

. {
    yyerror("Unexpected token");
    showLexicalError();
    yyterminate();
    }

%%

