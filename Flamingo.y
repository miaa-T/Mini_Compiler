%define parse.error verbose

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define YYDEBUG 1


%}

%token PACK
%token FONCTION
%token CONST
%token typeVAR
%token TYPE
%token INTTYPE
%token BIGINTTYPE
%token LONGINTTYPE
%token STRINGTYPE
%token FLOATTYPE
%token BIGFLOATTYPE
%token LONGFLOATTYPE
%token BOOLTYPE
%token STRUCT
%token IF
%token ELSE
%token REPEAT
%token WHILE
%token FOR
%token FROM
%token TO

%token GIVEBACK
%token READ
%token WRITE
%token FLOAT
%token INT
%token BOOL
%token STRING

%token PARENTHESEOUVRANTE
%token PARENTHESEFERMANTE
%token ACCOLADEOUVRANTE
%token ACCOLADEFERMANTE
%token CROCHETOUVRANT
%token CROCHETFERMANT
%token EXCLAM
%token POINT
%token VIRG
%token INC
%token DEC
%token AFFECT
%token NOTEQUALS
%token ADDEQUALS
%token SUBEQUALS
%token MULEQUALS
%token DIVINTEQUALS
%token DIVEQUALS
%token MODEQUALS
%token POWEQUALS
%token EQUALS
%token ADD
%token SUB
%token MUL
%token MOD
%token DIV
%token INTDIV
%token POW
%token NEG
%token LESS
%token LESSEQUALS
%token GREATER
%token GREATEREQUALS
%token DOUBLEEQUALS
%token AND
%token OR

%token ID


%left VIRG
%left OR            /* Opérateurs logiques ET, OU */
%left AND

%left ADD SUB           /* Opérateurs arithmétiques : +, - */
%left MUL DIV INTDIV MOD       /* Opérateurs arithmétiques : *, /, % */
%left POINT CROCHETOUVRANT CROCHETFERMANT
%left POW               /* Opérateur d'exponentiation : ^ */
%right NEG              /* Négation unaire : ! */
%left INC DEC           /* Incrément et décrément : ++, -- */
%nonassoc EQUALS LESS GREATER LESSEQUALS GREATEREQUALS /* Opérateurs relationnels et d'égalité */
%nonassoc NOTEQUALS ADDEQUALS SUBEQUALS MULEQUALS DIVEQUALS MODEQUALS /* Opérateurs d'affectation */
%left PARENTHESEOUVRANTE PARENTHESEFERMANTE /* Parenthèses */

%start ProgrammeFlamingo
%{
extern FILE *yyin;
extern int yylineno;
extern int yyleng;
extern int yylex();

char* file = "fl.txt";

int currentColumn = 1;

void termeSuiv(char *s);
void erreur(const char *s);
void affichErrLex();
%}
%%
ProgrammeFlamingo: %empty
    |Importationlib FuncsDeclar CorMain 
    ;
Importationlib: %empty
    |PACK STRING EXCLAM Importationlib
    ;
FuncsDeclar: %empty
    |FuncDeclar FuncsDeclar
    ;
FuncDeclar:
    |FONCTION typeVAR ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc GIVEBACK ID ACCOLADEFERMANTE /* pour les fonctions*/
    |FONCTION ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc  ACCOLADEFERMANTE /* pour les procédures*/
    ;
CorFunc: %empty
    |aumoinsInst 
    ;
aumoinsInst: %empty
    |Inst EXCLAM
    |Inst EXCLAM aumoinsInst
    ;
Inst: Declar 
    |Affec 
    |CorIf
    |CorWhile
    |CorFor
    |ReadMethod
    |WriteMethod
    |CallMethod
    ;
CorMain: aumoinsInst /*elimination du cas empty*/
    ;
Parametres: %empty
    |Parametre VIRG Parametres
    ;
Parametre: typeVAR ID
    ;
Declar: %empty
    |STRUCT ID AFFECT ACCOLADEOUVRANTE Parametres ACCOLADEFERMANTE 
    |CONST typeVAR ID Affec TYPE
    |typeVAR Affec
    |typeVAR ID
    |typeVAR ID CROCHETOUVRANT CROCHETFERMANT
    |typeVAR ID CROCHETOUVRANT INT CROCHETFERMANT
    |typeVAR ID CROCHETOUVRANT CROCHETFERMANT CROCHETOUVRANT CROCHETFERMANT
    |typeVAR ID CROCHETOUVRANT INT CROCHETFERMANT CROCHETOUVRANT INT CROCHETFERMANT
    ;
Affec: %empty
    |ID AFFECT TYPE
    |StructChamp AFFECT TYPE /*Affectation des champs d'une structure */
    |ID AFFECT CallMethod
    |ID CROCHETOUVRANT ID CROCHETFERMANT AFFECT ID
    |ID CROCHETOUVRANT ID CROCHETFERMANT AFFECT TYPE
    |ID CROCHETOUVRANT ID CROCHETFERMANT AFFECT ID CROCHETOUVRANT ID CROCHETFERMANT
    |ID AFFECT ID CROCHETOUVRANT ID CROCHETFERMANT  
    |ID AFFECT ID
    ;
StructChamp: ID POINT ID
    ;
CorIf: IF Condition  ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE Alternate;
Alternate: %empty 
    |ELSE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE
    |ELSE CorIf
    ;
CorWhile: WHILE Condition REPEAT ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE;

CorFor: FOR PARENTHESEOUVRANTE ID FROM INT TO INT PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE
ReadMethod: READ PARENTHESEOUVRANTE ID PARENTHESEFERMANTE
WriteMethod: WRITE PARENTHESEOUVRANTE ParamsWithoutVARTYPE PARENTHESEFERMANTE
ParamsWithoutVARTYPE: %empty
    |StructChamp
    | ID CROCHETOUVRANT ID CROCHETFERMANT 
    | ID
    | TYPE
    | ID ParamsWithoutVARTYPE
    |TYPE ParamsWithoutVARTYPE
    ;
CallMethod: ID PARENTHESEOUVRANTE ParamsWithoutVARTYPE PARENTHESEFERMANTE 

Condition:   
            PARENTHESEOUVRANTE comparaison PARENTHESEFERMANTE  
            | PARENTHESEOUVRANTE NEG Condition PARENTHESEFERMANTE     
            | PARENTHESEOUVRANTE Condition AND Condition PARENTHESEFERMANTE  
            | PARENTHESEOUVRANTE Condition OR Condition PARENTHESEFERMANTE 
            | ID /* une variable de type BOOL */
            ; 

comparaison:  
            expression DOUBLEEQUALS expression    
            | expression NOTEQUALS expression   
            | expression GREATER expression   
            | expression GREATEREQUALS expression   
            | expression LESS expression    
            | expression LESSEQUALS expression  
            ;

expression:    
             PARENTHESEOUVRANTE expression PARENTHESEFERMANTE
            | terme  
            | terme ADD expression   
            | terme SUB expression  
            | terme MUL expression
            | terme DIV expression 
            | terme MOD expression 
            | terme INTDIV expression
            | terme POW expression
            ; 

terme:        
            INT  
            | FLOAT 
            | ID 
            | ID CROCHETOUVRANT expression CROCHETFERMANT /* pour les tableaux */
            | CallMethod
            | ADD INT     /* opérateur unitaire */
            | SUB INT     
            | ADD FLOAT   
            | SUB FLOAT   
            | INC ID      /* incrémentation */
            | DEC ID      /* décrémentation */
            ;






%%
int termeCourant;
void termeSuiv(char *s){
    // fprintf(stdout, "%d: %s\n", yylineno, s);
    termeCourant+=yyleng;
}

void erreur(const char *s) {
  fprintf(stdout, "File '%s', line %d, character %d :  %s \n", file, yylineno, termeCourant, s);
}

int main (void)
{
    // yydebug = 1;
    yyin=fopen(file, "r");
    if(yyin==NULL){
        printf("erreur dans l'ouverture du fichier");
        return 1;
    }
    yyparse(yymsgp);  

// printf("succ\n");

    return 0;
}

void affichErrLex() {

    char line[256], introError[80];

    fseek(yyin, 0, SEEK_SET);
   
    int i = 0;

    while (fgets(line, sizeof(line), yyin)) {
        i++;
        if(i == yylineno) break;  
    }
       
    sprintf(introError, "Lexical error in Line %d : Unrecognized character : ", yylineno);
    printf("%s%s", introError, line);  
    int j=1;
    while(j<termeCourant+strlen(introError)) { printf(" "); j++; }
    printf("^\n");


}

