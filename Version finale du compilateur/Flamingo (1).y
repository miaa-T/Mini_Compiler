%define parse.error verbose

%{
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <math.h>
#define YYDEBUG 1
#include "SymboleTable.h"
#include "quadruplets.h"
#include "pile.h"

// Global variables
SymboleTable *symboleTable;
int cpt_param = 0;
int write = 0;
NodeSymbole *current_function = NULL;
NodeSymbole *current_call = NULL;
pile *stack;
quad *q;
int qc=0;
// Function prototypes
void verifierExistance(char *tokenId);
bool areTypesCompatible(Type type1, Type type2);
Type getFunctionReturnType(char *functionId);
char* extractOperand1(const char *expression);
char* extractOperand2(const char *expression);
bool isIntegerLiteral(const char *str);
bool isFloatLiteral(const char *str);
bool isStringLiteral(const char *str);
bool isBooleanLiteral(const char *str);
bool containsOperator(const char *str, const char *op);
bool isFunctionCall(const char *str);

extern FILE *yyin;
extern int yylineno;
extern int yyleng;
extern int yylex();

char* file = "input.txt";
int termeCourant = 1;

void termeSuiv(char *s);
extern void yyerror(const char *s);
extern void showLexicalError();
%}

%union{
     char identifier[255];
    int type;
    int integerValue;
    double floatValue;
    char stringValue[255];
}

%token PACK
%token FONCTION
%token MAIN 
%token HelloMain
%token CONST
%token <integerValue> TYPE
%token <type> INTTYPE BIGINTTYPE LONGINTTYPE STRINGTYPE FLOATTYPE BIGFLOATTYPE LONGFLOATTYPE BOOLTYPE
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
%token <floatValue> FLOAT
%token <integerValue> INT
%token <booleanValue> BOOL
%token <stringValue> STRING

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

%token <identifier> ID
%type <type> typeVAR

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

/*char* file = "test2.txt";*/


void termeSuiv(char *s);
extern void yyerror(const char *s);
extern void showLexicalError();
%}
%%
typeVAR: 
INTTYPE { $$ = 0; }
    | FLOATTYPE { $$ = 1; } 
    | STRINGTYPE { $$ = 2; }
    | BOOLTYPE { $$ = 3; }
ProgrammeFlamingo:
    Importationlib FuncsDeclar CorMain 
    ;
Importationlib: PACK STRING ENDINST Importationlib
    | %empty
    ;
FuncsDeclar: 
    FuncDeclar FuncsDeclar
    {
        printf("hello am in ..");
    }
     | FuncDeclar
    ;
    
FuncDeclar:FONCTION typeVAR ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE 
ACCOLADEOUVRANTE CorFunc GIVEBACK ID ACCOLADEFERMANTE /* pour les fonctions*/
{

  NodeSymbole *symbole = search(symboleTable, $3);
        if (symbole != NULL) {
            yyerror("Function already declared");
        } 
        insertSymbole(symboleTable, $3, Fonction, $2);
symbole=search(symboleTable, $3);
        current_function = symbole;
               cpt_param = 0;
        NodeAttribut *searchedAttr = searchAttributByName(symbole, $10);
        if (searchedAttr != NULL) {
       if (!(searchedAttr->type== symbole->type)) {
            yyerror("Type mismatch in return type");
        }}

      
}
    |FONCTION ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc  ACCOLADEFERMANTE /* pour les procédures*/
    {
 NodeSymbole *symbole = search(symboleTable, $2);
        if (symbole != NULL) {
            yyerror("Function already declared");
        } 
        insertSymbole(symboleTable, $2, Fonction, -1);
symbole=search(symboleTable, $2);
        current_function = symbole;
    

    }
    |FONCTION typeVAR ID PARENTHESEOUVRANTE  PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc GIVEBACK ID ACCOLADEFERMANTE /* pour les fonctions*/
    {
 NodeSymbole *symbole = search(symboleTable, $3);
        if (symbole != NULL) {
            yyerror("Function already declared");
        } 
        insertSymbole(symboleTable, $3, Fonction, $2);
symbole=search(symboleTable, $3);
        current_function = symbole;
               cpt_param = 0;
        NodeAttribut *searchedAttr = searchAttributByName(symbole, $9);
        if (searchedAttr != NULL) {
       if (!(searchedAttr->type== symbole->type)) {
            yyerror("Type mismatch in return type");
        }}

    }
    |FONCTION ID PARENTHESEOUVRANTE  PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc  ACCOLADEFERMANTE /* pour les procédures*/
    {
NodeSymbole *symbole = search(symboleTable, $2);
        if (symbole != NULL) {
            yyerror("Function already declared");
        } 
        insertSymbole(symboleTable, $2, Fonction, -1);
symbole=search(symboleTable, $2);
        current_function = symbole;
    

    }
   | %empty  
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
      {
      
        current_function = NULL;
    }
    ;
Parametres: 
    Parametre VIRG Parametres
    |Parametre ;
    
Parametre: typeVAR ID
   {
        if (current_function != NULL) {
            addParam(current_function, $2, $1);
        }
    }
    ;
Declar: %empty
    | STRUCT ID AFFECT ACCOLADEOUVRANTE Parametres ACCOLADEFERMANTE
    | STRUCT ID AFFECT ACCOLADEOUVRANTE ACCOLADEFERMANTE
    | CONST typeVAR Affec
    | typeVAR Affec
    | typeVAR ID
    {
        if (current_function != NULL) {
            setAttribut(current_function, $2, $1, NULL);
        } else {
            NodeSymbole *sym1 = insertSymbole(symboleTable, (char*)$2, Attsimple, $1);
        }
    }
    ;
    
AffecType: 
ID
|StructChamp
|ID CROCHETOUVRANT ID CROCHETFERMANT
|CallMethod
|expression
|TYPE;


Affec:
    ID AFFECT INT
    {
    char strr[12]; 

    sprintf(strr, "%d", $3); 
        insererQuadreplet(&q, "AFFECT", strr, "", $1, qc);
        qc++;
    }
    |ID AFFECT AffecType
    |StructChamp AFFECT AffecType /*des champs d'une structure */
    |ID CROCHETOUVRANT ID CROCHETFERMANT AFFECT AffecType
    ;
StructChamp: ID POINT ID
    ;


CorIf: IF Condition {	
    insererQuadreplet(&q, "BZ", "tmp", "", "", qc);
    empiler(stack, qc); 
    
    qc++;
} ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE {

        int addrBR = depiler(stack); 
  char adresse[10];
    sprintf(adresse, "%d", qc);
      updateQuadreplet(q, addrBR, adresse);

    insererQuadreplet(&q, "BR", "", "", "", qc);
    empiler(stack, qc);  // Empile addrBR
    qc++;
} Alternate
;
Alternate:
    %empty {
        char adresse[10];
        sprintf(adresse, "%d", qc);
        int addrBR = depiler(stack);
        updateQuadreplet(q, addrBR, adresse);
    }
    | ELSE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE {
        char adresse[10];
        sprintf(adresse, "%d", qc);
        int addrBR = depiler(stack);
        updateQuadreplet(q, addrBR, adresse);
    }
    | ELSE CorIf  
;
CorWhile: WHILE {


empiler(stack, qc); 
}Condition REPEAT ACCOLADEOUVRANTE {

insererQuadreplet(&q, "BZ", "tmp", "", "", qc);
empiler(stack,qc);
qc++;

}CorFunc ACCOLADEFERMANTE {

   char adresse[10];
    char adresseCondWhile[10];

    int addrFinWhile = depiler(stack);
    int addrDebutWhile = depiler(stack);

    sprintf(adresseCondWhile, "%d", addrDebutWhile);
    insererQuadreplet(&q, "BR", adresseCondWhile, "", "", qc);
    qc++;

    sprintf(adresse, "%d", qc);
    updateQuadreplet(q, addrFinWhile, adresse);

};

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
| ID 
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
symboleTable= allocateSymboleTable();
stack = (pile *)malloc(sizeof(pile));
initPile(stack);
    yyin=fopen(file, "r");
    if(yyin==NULL){
        printf("erreur dans l'ouverture du fichier");
        return 1;
    }
    yyparse();  

 afficherQuad(q);
 afficherTableSymbole(symboleTable);
afficherPile(stack);
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




// Check if a variable is declared before use
void verifierExistance(char *tokenId) {
    if (search(symboleTable, tokenId) == NULL) {
        yyerror("Variable not declared");
    }
}



// elle verifier la ccompatibilite de deux variables
bool areTypesCompatible(Type type1, Type type2) {
    // Allow assignments between numeric types (int, float, etc.)
    if ((type1 == INT32 || type1 == INT64 || type1 == FLOAT32 || type1 == FLOAT64) &&
        (type2 == INT32 || type2 == INT64 || type2 == FLOAT32 || type2 == FLOAT64)) {
        return true;
    }
    // Allow assignments between the same types
    if (type1 == type2) {
        return true;
    }
    return false;
}

//elle retourne le type de la fonction
Type getFunctionReturnType(char *functionId) {
    NodeSymbole *symbole = search(symboleTable, functionId);
    if (symbole == NULL || symbole->categorieNoeud != Fonction) {
        yyerror("Invalid function call");
        return NULLL;
    }
    return symbole->type;
}

