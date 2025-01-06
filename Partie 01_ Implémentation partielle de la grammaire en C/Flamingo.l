
%option noyywrap
%{
#include "flamingo.tab.h"
extern void parse(const char *input);
%}

%%
[0-9]+         { return INT; }
[a-zA-Z_][a-zA-Z0-9_]* { return ID; }
"{"            { return CROCHETOUVRANT; }
"}"            { return CROCHETFERMANT; }
"("            { return PARENTHESEOUVRANTE; }
")"            { return PARENTHESEFERMANTE; }
[ \t\n]        { /* Ignore whitespace */ }
.              { printf("Unexpected character: %s\n", yytext); exit(1); }
%%


