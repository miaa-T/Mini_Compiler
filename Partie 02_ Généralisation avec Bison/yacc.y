%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
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
Type getTypeOfExpression(char *expressionn);
Type getFunctionReturnType(char *functionId);
char* extractOperand1(const char *expression);
char* extractOperand2(const char *expression);
bool isIntegerLiteral(const char *str);
bool isFloatLiteral(const char *str);
bool isStringLiteral(const char *str);
bool isBooleanLiteral(const char *str);
bool isIdentifier(const char *str);
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

%token PACK FONCTION MAIN ExpressionHELLO CONST TYPE INTTYPE BIGINTTYPE LONGINTTYPE
%token STRINGTYPE FLOATTYPE BIGFLOATTYPE LONGFLOATTYPE BOOLTYPE STRUCT IF ELSE
%token REPEAT WHILE FOR FROM TO GIVEBACK READ WRITE FLOAT INT BOOL STRING
%token PARENTHESEOUVRANTE PARENTHESEFERMANTE ACCOLADEOUVRANTE ACCOLADEFERMANTE
%token CROCHETOUVRANT CROCHETFERMANT ENDINST POINT VIRG INC DEC AFFECT NOTEQUALS
%token ADDEQUALS SUBEQUALS MULEQUALS DIVINTEQUALS DIVEQUALS MODEQUALS POWEQUALS
%token ADD SUB MUL MOD DIV INTDIV POW NEG LESS LESSEQUALS GREATER GREATEREQUALS
%token DOUBLEEQUALS AND OR ID
%token HelloMain
%left VIRG
%left OR
%left AND
%left ADD SUB
%left MUL DIV INTDIV MOD
%left POINT CROCHETOUVRANT CROCHETFERMANT
%left POW
%right NEG
%left INC DEC
%nonassoc DOUBLEEQUALS LESS GREATER LESSEQUALS GREATEREQUALS
%nonassoc NOTEQUALS ADDEQUALS SUBEQUALS MULEQUALS DIVEQUALS MODEQUALS
%left PARENTHESEOUVRANTE PARENTHESEFERMANTE

%start ProgrammeFlamingo

%%

typeVAR: INTTYPE | BIGINTTYPE | LONGINTTYPE | STRINGTYPE | FLOATTYPE | BIGFLOATTYPE | LONGFLOATTYPE | BOOLTYPE;

ProgrammeFlamingo:
    Importationlib FuncsDeclar CorMain
    ;

Importationlib: %empty
    | PACK STRING ENDINST Importationlib
    ;

FuncsDeclar: %empty
    | FuncDeclar FuncsDeclar
    ;

FuncDeclar:
    FONCTION typeVAR ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc GIVEBACK ID ACCOLADEFERMANTE
    {
        NodeSymbole *symbole = search(symboleTable, (char*)$3);
        if (symbole != NULL) {
            yyerror("Function already declared");
        }
        insertSymbole(symboleTable, (char*)$3, Fonction, $2);
        current_function = symbole;
        cpt_param = 0;
        NodeAttribut *searchedAttr = searchAttributByName(symbole, (char*)$10);
        if (searchedAttr == NULL) {
            yyerror("Return type variable not declared");
        }
        if (!areTypesCompatible(searchedAttr->type, symbole->type)) {
            yyerror("Type mismatch in return type");
        }
    }
    | FONCTION ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE
    {
        NodeSymbole *symbole = search(symboleTable, (char*)$2);
        if (symbole != NULL) {
            yyerror("Function already declared");
        }
        insertSymbole(symboleTable, (char*)$2, Fonction, NULLL);
        current_function = symbole;
    }
    ;

CorFunc:
    aumoinsInst
    ;

aumoinsInst:
    Inst ENDINST
    | Inst ENDINST aumoinsInst
    ;

Inst: Declar
    | Affec
    | CorIf
    | CorWhile
    | CorFor
    | ReadMethod
    | WriteMethod
    | CallMethod
    ;

CorMain: MAIN PARENTHESEOUVRANTE ExpressionHELLO PARENTHESEFERMANTE ACCOLADEOUVRANTE aumoinsInst ACCOLADEFERMANTE
    {
        current_function = NULL;
    }
    ;

Parametres:
    Parametre VIRG Parametres
    | Parametre
    ;

Parametre: typeVAR ID
    {
        if (current_function != NULL) {
            addParam(current_function, (char*)$2, $1);
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
            setAttribut(current_function, (char*)$2, $1, NULL);
        } else {
            NodeSymbole *sym1 = insertSymbole(symboleTable, (char*)$2, Attsimple, $1);
        }
    }
    ;

AffecType:
    StructChamp | expression | TYPE
    ;

Affec:
    ID AFFECT AffecType
    {
        verifierExistance((char*)$1);
        Type varType = getTypeByID(symboleTable, (char*)$1);
        Type assignedType = getTypeOfExpression((char*)$3);
        if (!areTypesCompatible(varType, assignedType)) {
            yyerror("Incompatibilité de type dans l'affectation à la variable");
        }
        insererQuadreplet(&q, "AFFECT", (char*)$3, "", (char*)$1, qc);
        qc++;
    }
    ;


StructChamp: ID POINT ID
    ;

CorWhile: WHILE Condition REPEAT ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE {
    char adresse[10];
    char adresseCondWhile[10];

    int addrFinWhile = depiler(stack);
    int addrDebutWhile = depiler(stack);

    sprintf(adresseCondWhile, "%d", addrDebutWhile);
    insererQuadreplet(&q, "BR", adresseCondWhile, "", "", qc);
    qc++;

    sprintf(adresse, "%d", qc);
    updateQuadreplet(q, addrFinWhile, adresse);
}


Condition: {
    empiler(stack, qc);  // Point de retour de la boucle
}




PARENTHESEOUVRANTE comparaison PARENTHESEFERMANTE {
    insererQuadreplet(&q, "BZ", "tmp", "", "", qc);
    empiler(stack, qc);
    qc++;
}
| PARENTHESEOUVRANTE NEG Condition PARENTHESEFERMANTE {
    insererQuadreplet(&q, "NOT", "", "", "tmp", qc);
    qc++;
}
| PARENTHESEOUVRANTE Condition AND Condition PARENTHESEFERMANTE {
    insererQuadreplet(&q, "AND", "", "", "tmp", qc);
    qc++;
}
| PARENTHESEOUVRANTE Condition OR Condition PARENTHESEFERMANTE {
    insererQuadreplet(&q, "OR", "", "", "tmp", qc);
    qc++;
}
| ID {
    NodeSymbole *symbole = search(symboleTable, (char*)$1);
    if (symbole == NULL || symbole->type != BOOLTYPE) {
        yyerror("Invalid boolean variable");
    }
}
;

CorFor: FOR PARENTHESEOUVRANTE ID FROM INT TO INT PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE;


ReadMethod: READ PARENTHESEOUVRANTE ID PARENTHESEFERMANTE
{
  if (current_function != NULL){
    NodeAttribut *searchedAttr = searchAttributByName(current_function, (char*)$3);
if (searchedAttr==NULL)
{
    yyerror("id not declared ");
}
    }
    else{
  verifierExistance((char*)$3);
    }
}
WriteMethod: WRITE PARENTHESEOUVRANTE ParamsWithoutVARTYPE PARENTHESEFERMANTE
{
    write=1;
}



ParamsWithoutVARTYPE:
    StructChamp
    | ID CROCHETOUVRANT ID CROCHETFERMANT
    | ID
    {
        if(!cpt_param==countParams(current_call))
        {
            yyerror("nombre de paramaitre invalide");
        }
       if(write){
          if (current_function != NULL)
               {
              NodeAttribut *searchedAttr = searchAttributByName(current_function, (char*)$1);
              if (searchedAttr==NULL)
             { yyerror("id not declared ");} 
             }
          else{ verifierExistance((char*)$1); }}

        else{
Type type1 =getTypeOfParamByIndex(current_call, cpt_param);
Type type2= getTypeByID(symboleTable,(char*)$1 );
if(!areTypesCompatible(type1,type2)){
  yyerror("type incompatible");
}
        }
    }
    
    | TYPE
    | ID VIRG ParamsWithoutVARTYPE
    {
      if(cpt_param){
            cpt_param++;
        }

             if(write){
          if (current_function != NULL){
              NodeAttribut *searchedAttr = searchAttributByName(current_function, (char*)$1);
              if (searchedAttr==NULL)
             { yyerror("id not declared ");} }

          else{ verifierExistance((char*)$1); }}
        else{
Type type1 =getTypeOfParamByIndex(current_call, cpt_param);
Type type2= getTypeByID(symboleTable,(char*)$1 );
if(!areTypesCompatible(type1,type2)){
  yyerror("type incompatible");
}
        }

    }
    
    |TYPE VIRG ParamsWithoutVARTYPE
    | StructChamp VIRG ParamsWithoutVARTYPE
    | ID CROCHETOUVRANT ID CROCHETFERMANT VIRG ParamsWithoutVARTYPE
    ;

CallMethod: ID PARENTHESEOUVRANTE ParamsWithoutVARTYPE PARENTHESEFERMANTE
{
current_call=search(symboleTable,(char*)$1);
if(!current_call)
    {
        yyerror("fonction non declaré");
    }
    write=0;
}
|ID PARENTHESEOUVRANTE PARENTHESEFERMANTE
{
current_call=search(symboleTable,(char*)$1);
 if(!current_call)
    {
        yyerror("fonction non declaré");
    }
    write=0;
}








//imene
CorIf: IF Condition {
    insererQuadreplet(&q, "BZ", "tmp", "", "", qc);
    empiler(stack, qc);  // Empile addrBZ
    qc++;
} ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE {
    insererQuadreplet(&q, "BR", "", "", "", qc);
    empiler(stack, qc);  // Empile addrBR
    qc++;

    // Correction :
    int addrBR = depiler(stack);    // On récupère d'abord BR
    int addrBZ = depiler(stack);    // Puis BZ

    char adresse[10];
    sprintf(adresse, "%d", qc);
    updateQuadreplet(q, addrBZ, adresse);

    empiler(stack, addrBR);  // On remet addrBR pour Alternate
} Alternate
;

Alternate:
    %empty {
        // Cas sans ELSE : on récupère et met à jour le BR pour qu'il pointe ici
        char adresse[10];
        sprintf(adresse, "%d", qc);
        int addrBR = depiler(stack);
        updateQuadreplet(q, addrBR, adresse);
    }
    | ELSE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE {
        // Cas avec ELSE : on récupère et met à jour le BR pour qu'il pointe ici
        char adresse[10];
        sprintf(adresse, "%d", qc);
        int addrBR = depiler(stack);
        updateQuadreplet(q, addrBR, adresse);
    }
    | ELSE CorIf  // Cas du IF imbriqué - géré récursivement
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

    yyin=fopen("input.txt", "r");
    if(yyin==NULL){
        printf("erreur dans l'ouverture du fichier");
        return 1;
    }
    yyparse();

 printf("succ\n");
 afficherTableSymbole(symboleTable);

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


Type getTypeOfExpression( char* expressionn) {
    if (isIntegerLiteral(expressionn)) {
        return INT32;
    } else if (isFloatLiteral(expressionn)) {
        return FLOAT32;
    } else if (isStringLiteral(expressionn)) {
        return STRING;
    } else if (isBooleanLiteral(expressionn)) {
        return BOOL;
    }

    if (isIdentifier(expressionn)) {
        NodeSymbole* symbol = search(symboleTable, expressionn);
        if (symbol != NULL) {
            return symbol->type;
        } else {
            yyerror("Variable not declared");
            return NULLL;
        }
    }

    if (containsOperator(expressionn, "+") || containsOperator(expressionn, "-") ||
        containsOperator(expressionn, "*") || containsOperator(expressionn, "/")) {
        char* operand1 = extractOperand1(expressionn);
        char* operand2 = extractOperand2(expressionn);

        Type type1 = getTypeOfExpression(operand1);
        Type type2 = getTypeOfExpression(operand2);

        free(operand1);
        free(operand2);

        if (type1 == INT32 && type2 == INT32) {
            return INT32;
        } else if (type1 == FLOAT32 || type2 == FLOAT32) {
            return FLOAT32;
        } else {
            yyerror("Type mismatch in binary operation");
            return NULLL;
        }
    }

    yyerror("Invalid expressionn");
    return NULLL;
}

// Extract the name and arguments of a function call

void extractFunctionInfo(const char* expression, char** functionName, char*** arguments, int* argCount) {
    const char* openParen = strchr(expression, '(');
    if (!openParen) {
        fprintf(stderr, "Invalid expression: Missing opening parenthesis\n");
        return;
    }

    // Extract function name
    size_t funcNameLen = openParen - expression;
    *functionName = (char*)malloc(funcNameLen + 1); // +1 for null terminator
    if (*functionName == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    strncpy(*functionName, expression, funcNameLen);
    (*functionName)[funcNameLen] = '\0'; // Null-terminate the string

    const char* closeParen = strchr(openParen, ')');
    if (!closeParen) {
        fprintf(stderr, "Invalid expression: Missing closing parenthesis\n");
        free(*functionName); // Free allocated memory
        return;
    }

    // Extract arguments string
    size_t argsStrLen = closeParen - (openParen + 1);
    char* argsStr = (char*)malloc(argsStrLen + 1); // +1 for null terminator
    if (argsStr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(*functionName); // Free allocated memory
        return;
    }
    strncpy(argsStr, openParen + 1, argsStrLen);
    argsStr[argsStrLen] = '\0'; // Null-terminate the string

    // Tokenize arguments
    *argCount = 0;
    *arguments = NULL; // Initialize to NULL
    char* token = strtok(argsStr, ",");
    while (token) {
        // Allocate memory for the new argument
        *arguments = (char**)realloc(*arguments, sizeof(char*) * (*argCount + 1));
        if (*arguments == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(argsStr); // Free allocated memory
            free(*functionName); // Free allocated memory
            return;
        }

        // Copy the token into the arguments array
        (*arguments)[*argCount] = strdup(token);
        if ((*arguments)[*argCount] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(argsStr); // Free allocated memory
            free(*functionName); // Free allocated memory
            for (int i = 0; i < *argCount; i++) {
                free((*arguments)[i]); // Free previously allocated arguments
            }
            free(*arguments); // Free the arguments array
            return;
        }

        (*argCount)++;
        token = strtok(NULL, ",");
    }

    free(argsStr); // Free the temporary arguments string
}
// Extract the first operand from an expression
char* extractOperand1(const char* expression) {
    const char* operators = "+-*/%";
    const char* operator_ptr = strpbrk(expression, operators);

    if (!operator_ptr) {
        yyerror("Invalid binary expression");
        return NULL;
    }

    size_t operand1_length = operator_ptr - expression;
    char* operand1 = (char*)malloc(operand1_length + 1);
    strncpy(operand1, expression, operand1_length);
    operand1[operand1_length] = '\0';

    return operand1;
}

// Extract the second operand from an expression
char* extractOperand2(const char* expression) {
    const char* operators = "+-*/%";
    const char* operator_ptr = strpbrk(expression, operators);

    if (!operator_ptr) {
        return strdup(expression); // Entire expression as operand
    }

    char* operand2 = strdup(operator_ptr + 1);
    return operand2;
}

// Check if a string is an integer literal
bool isIntegerLiteral(const char* str) {
    if (!str || !*str) return false;
    while (*str) {
        if (!isdigit(*str)) return false;
        str++;
    }
    return true;
}

// Check if a string is a float literal
bool isFloatLiteral(const char* str) {
    if (!str || !*str) return false;
    bool hasDecimal = false;
    while (*str) {
        if (*str == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return hasDecimal;
}

// Check if a string is a string literal
bool isStringLiteral(const char* str) {
    if (!str || !*str) return false;
    return (*str == '"' && str[strlen(str) - 1] == '"');
}

// Check if a string is a boolean literal
bool isBooleanLiteral(const char* str) {
    if (!str) return false;
    return (strcmp(str, "TRUE") == 0 || strcmp(str, "FALSE") == 0);
}

// Check if a string is a valid identifier
bool isIdentifier(const char* str) {
    if (!str || !*str) return false;
    if (!isalpha(*str) && *str != '_') return false;
    str++;
    while (*str) {
        if (!isalnum(*str) && *str != '_') return false;
        str++;
    }
    return true;
}

// Check if a string contains a specific operator
bool containsOperator(const char* str, const char* op) {
    if (!str || !op) return false;
    return (strstr(str, op) != NULL);
}

// Check if a string is a function call
bool isFunctionCall(const char* str) {
    if (!str) return false;
    char* openParen = strchr(str, '(');
    char* closeParen = strchr(str, ')');
    return (openParen != NULL && closeParen != NULL && closeParen > openParen);
}

// Extract the function name from a function call
char* extractFunctionName(const char* str) {
    if (!str) return NULL;
    const char* openParen = strchr(str, '(');
    if (!openParen) return NULL;

    size_t len = openParen - str;
    char* funcName = (char*)malloc(len + 1);
    strncpy(funcName, str, len);
    funcName[len] = '\0';

    return funcName;
}