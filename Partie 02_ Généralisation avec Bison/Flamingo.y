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
%token MAIN 
%token HelloMain
%token CONST
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
%token ENDINST 
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
%nonassoc DOUBLEEQUALS LESS GREATER LESSEQUALS GREATEREQUALS /* Opérateurs relationnels et d'égalité */
%nonassoc NOTEQUALS ADDEQUALS SUBEQUALS MULEQUALS DIVEQUALS MODEQUALS /* Opérateurs d'affectation */
%left PARENTHESEOUVRANTE PARENTHESEFERMANTE /* Parenthèses */

%start ProgrammeFlamingo
%{
extern FILE *yyin;
extern int yylineno;
extern int yyleng;
extern int yylex();

char* file = "input.txt";
/*char* file = "test2.txt";*/

int termeCourant = 1;

void termeSuiv(char *s);
extern void yyerror(const char *s);
extern void showLexicalError();
%}
%%
typeVAR: INTTYPE|BIGINTTYPE|LONGINTTYPE|STRINGTYPE|FLOATTYPE|BIGFLOATTYPE|LONGFLOATTYPE|BOOLTYPE;
ProgrammeFlamingo:
    Importationlib FuncsDeclar CorMain 
    ;
Importationlib: PACK STRING ENDINST Importationlib
    | %empty
    ;
FuncsDeclar: 
    FuncDeclar FuncsDeclar
     | FuncDeclar
    ;
    
FuncDeclar:FONCTION typeVAR ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc GIVEBACK ID ACCOLADEFERMANTE /* pour les fonctions*/
    |FONCTION ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc  ACCOLADEFERMANTE /* pour les procédures*/
    |FONCTION typeVAR ID PARENTHESEOUVRANTE  PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc GIVEBACK ID ACCOLADEFERMANTE /* pour les fonctions*/
    |FONCTION ID PARENTHESEOUVRANTE  PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc  ACCOLADEFERMANTE /* pour les procédures*/
   | %empty  /* Ajouter en dernier pour eviter une reduction prématurée et laisser la priorité aux déclarations complétes*/
    ;
CorFunc: 
    aumoinsInst 
    ;
aumoinsInst:
    Inst ENDINST 
    |Inst ENDINST aumoinsInst
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
CorMain: MAIN PARENTHESEOUVRANTE HelloMain PARENTHESEFERMANTE ACCOLADEOUVRANTE aumoinsInst ACCOLADEFERMANTE  /*elimination du cas empty*/
    ;
Parametres: 
    Parametre VIRG Parametres
    |Parametre ;
    
Parametre: typeVAR ID
    ;
Declar: 
    STRUCT ID AFFECT ACCOLADEOUVRANTE Parametres ACCOLADEFERMANTE 
    |STRUCT ID AFFECT ACCOLADEOUVRANTE  ACCOLADEFERMANTE 
    |CONST typeVAR Affec
    |typeVAR Affec
    |typeVAR ID
    |typeVAR ID CROCHETOUVRANT INT CROCHETFERMANT
    |typeVAR ID CROCHETOUVRANT CROCHETFERMANT
    |typeVAR ID CROCHETOUVRANT INT CROCHETFERMANT CROCHETOUVRANT INT CROCHETFERMANT
    |typeVAR ID CROCHETOUVRANT CROCHETFERMANT CROCHETOUVRANT CROCHETFERMANT
|%empty  /* Ajouter en dernier pour eviter une reduction prématurée et laisser la priorité aux déclarations complétes*/
    ;

    
AffecType: 
ID|StructChamp|ID CROCHETOUVRANT ID CROCHETFERMANT|CallMethod|expression|TYPE;
Affec:
    ID AFFECT AffecType
    |StructChamp AFFECT AffecType /*des champs d'une structure */
    |ID CROCHETOUVRANT ID CROCHETFERMANT AFFECT AffecType
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
|FOR PARENTHESEOUVRANTE ID FROM INT TO ID PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE
|FOR PARENTHESEOUVRANTE ID FROM ID TO INT PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE
|FOR PARENTHESEOUVRANTE ID FROM ID TO ID PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE;
ReadMethod: READ PARENTHESEOUVRANTE ID PARENTHESEFERMANTE;
WriteMethod: WRITE PARENTHESEOUVRANTE ParamsWithoutVARTYPE PARENTHESEFERMANTE
|WRITE PARENTHESEOUVRANTE ParamsWrite PARENTHESEFERMANTE;

ParamsWrite: 
ParamsWithoutVARTYPE
 |STRING  
 |STRING VIRG ParamsWrite
 |ParamsWrite VIRG ParamsWrite ;

    
ParamsWithoutVARTYPE: 
    StructChamp
    | ID CROCHETOUVRANT ID CROCHETFERMANT 
    | ID
    | TYPE
    | ID VIRG ParamsWithoutVARTYPE 
    |TYPE VIRG ParamsWithoutVARTYPE
    | StructChamp VIRG ParamsWithoutVARTYPE 
    | ID CROCHETOUVRANT ID CROCHETFERMANT VIRG ParamsWithoutVARTYPE 
    ;
CallMethod: ID PARENTHESEOUVRANTE ParamsWithoutVARTYPE PARENTHESEFERMANTE
|ID PARENTHESEOUVRANTE PARENTHESEFERMANTE ;

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
            | INC ID      /*  Pre-incrémentation */
            | DEC ID      /* Pre-décrémentation */
            | ID INC      /* post-incrémentation */
            | ID DEC       /* post-décrémentation */
            ;






%%
void termeSuiv(char *s){
    // fprintf(stdout, "%d: %s\n", yylineno, s);
    termeCourant+=yyleng;
}

void yyerror(const char *s) {
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
    yyparse();  

// printf("succ\n");

    return 0;
}

void showLexicalError() {

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

