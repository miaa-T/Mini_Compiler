%define parse.error verbose

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define YYDEBUG 1
#include "SymboleTable.h"
#include "quadruplets.h"
#include "pile.h"
SymboleTable *symboleTable;
int quadCount = 0;
 int cpt_param=0;
 int write=0;
NodeSymbole *current_function  = NULL;
 NodeSymbole *current_call  = NULL;

%}

%token PACK
%token FONCTION
%token MAIN
%token ExpressionHELLO
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
%{
extern FILE *yyin;
extern int yylineno;
extern int yyleng;
extern int yylex();

char* file = "fl.txt";

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
Importationlib: %empty
    |PACK STRING ENDINST Importationlib
    ;
FuncsDeclar: %empty
    |FuncDeclar FuncsDeclar
    ;

FuncDeclar://djihene+dina
    FONCTION typeVAR ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc GIVEBACK ID ACCOLADEFERMANTE /* pour les fonctions*/
        {
        NodeSymbole *symbole = search(symboleTable, $3);
        if (symbole != NULL) {
            yyerror("Function already declared");
        }
        insertSymbole(symboleTable, $3, Fonction, $2);//on va ici inserer la fonction qui a ID=$3 et son type est typeVAR=$2
        current_function=symbole;
        cpt_param=0;
        NodeAttribut *searchedAttr =searchAttributByName(symbole,$10);
        if (searchedAttr == NULL) {
            yyerror("Return type variable not declared");
        }
        if (!areTypesCompatible(searchedAttr->type, symbole->type)) {
            yyerror("Type mismatch in return type");
        }

        }
    |FONCTION ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc  ACCOLADEFERMANTE /* pour les procédures*/
    {

          NodeSymbole *symbole = search(symboleTable, $2);
        if (symbole != NULL) {
            yyerror("Function already declared");
        }
        insertSymbole(symboleTable, $2, Fonction, NULLL);
        current_function=symbole;

    }
    |FONCTION typeVAR ID PARENTHESEOUVRANTE  PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc GIVEBACK ID ACCOLADEFERMANTE /* pour les fonctions*/
     {
         NodeSymbole *symbole = search(symboleTable, $3);
        if (symbole != NULL) {
            yyerror("Function already declared");
        }
        insertSymbole(symboleTable, $3, Fonction, $2);//on va ici inserer la fonction qui a ID=$3 et son type est typeVAR=$2
        current_function=symbole;
          cpt_param=1;
        NodeAttribut *searchedAttr =searchAttributByName(symbole,$10);
        if (searchedAttr == NULL) {
            yyerror("Return type variable not declared");
        }
        if (!areTypesCompatible(searchedAttr->type, symbole->type)) {
            yyerror("Type mismatch in return type");
        }

    }

    |FONCTION ID PARENTHESEOUVRANTE  PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc  ACCOLADEFERMANTE /* pour les procédures*/
    {
          NodeSymbole *symbole = search(symboleTable, $2);
        if (symbole != NULL) {
            yyerror("Function already declared");
        }
         insertSymbole(symboleTable, $2, Fonction, NULLL);
                  current_function=symbole;
           cpt_param=1;

    }
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
CorMain: MAIN PARENTHESEOUVRANTE ExpressionHELLO PARENTHESEFERMANTE ACCOLADEOUVRANTE aumoinsInst ACCOLADEFERMANTE  /*elimination du cas empty*/
{
    current_function=NULL;
}
    ;
Parametres:
    Parametre VIRG Parametres
    |Parametre ;

Parametre: typeVAR ID
{
    if (current_function != NULL){
            addParam(current_function, $2, $1 );

    }

}

    ;
Declar: %empty
    |STRUCT ID AFFECT ACCOLADEOUVRANTE Parametres ACCOLADEFERMANTE
    |STRUCT ID AFFECT ACCOLADEOUVRANTE  ACCOLADEFERMANTE
    |CONST typeVAR Affec
    |typeVAR Affec
    |typeVAR ID
    {
       if (current_function != NULL){
        setAttribut(current_function, $2,$1);

    }
    else{
    NodeSymbole *sym1 = insertSymbole(symboleTable, $2, attsimple, $1);
    }
    }
    |typeVAR ID CROCHETOUVRANT INT CROCHETFERMANT
    |typeVAR ID CROCHETOUVRANT CROCHETFERMANT
    |typeVAR ID CROCHETOUVRANT INT CROCHETFERMANT CROCHETOUVRANT INT CROCHETFERMANT
    |typeVAR ID CROCHETOUVRANT CROCHETFERMANT CROCHETOUVRANT CROCHETFERMANT
    ;

AffecType:
StructChamp|expression|TYPE;

Affec://mahdia
    %empty
    |ID AFFECT AffecType
    {
        // Déclaration de l'ID
        verifierExistance($1);

        // Vérification de compatibilité de types
        Type varType = getTypeByID(symboleTable, $1);
        Type assignedType = getTypeOfExpression($3); // Tout depend de la nature de AffecType : struct, expression (int, float, id, opérateur unitaire et binaire....), TYPE ((nb_int|nb_float|c_string|bol))

        if (!areTypesCompatible(varType, assignedType)) {
            yyerror("Incompatibilité de type dans l'affectation à la variable");
        }
    }
    |StructChamp AFFECT AffecType
    {
        // Vérifier si l'enregistrement et le champ sont declares
        char *structName = strtok($1, ".");
        verifierExistance(structName);

        // Verifier si le champ de l enregistrement existe
        NodeSymbole *structSymbol = search(symboleTable, structName);
        NodeAttribut *field = searchAttributByName(structSymbol, strtok(NULL, "."));
        if (field == NULL) {
            yyerror("Champ de structure non trouvé");
        }

        // Verifier la compatibilité de type entre le champ et la valeur assignée
        Type fieldType = field->type;
        Type assignedType = getTypeOfExpression($3);
        if (!areTypesCompatible(fieldType, assignedType)) {
            yyerror("Incompatibilité de type dans l'affectation au champ de structure");
        }
    }
    |ID CROCHETOUVRANT ID CROCHETFERMANT AFFECT AffecType
    {
        // VErifier si le tableau est declare
        verifierExistance($1);


        // VErifier la compatibilité de type entre le type d'élément du tableau et la valeur assignée
         NodeSymbole *arraySymbol = search(symboleTable, $1);
         // les elemenst du tableau ont un type associe dans la table des symboles
        Type arrayElementType = arraySymbol->type;
        Type assignedType = getTypeOfExpression($6);
        if (!areTypesCompatible(arrayElementType, assignedType)) {
            yyerror("Type mismatch in assignment to array element");
        }
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
    NodeSymbole *symbole = search(symboleTable, $1);
    if (symbole == NULL || symbole->type != BOOLTYPE) {
        yyerror("Invalid boolean variable");
    }
}
;

CorFor: FOR PARENTHESEOUVRANTE ID FROM INT TO INT PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE;


ReadMethod: READ PARENTHESEOUVRANTE ID PARENTHESEFERMANTE;
{
  if (current_function != NULL){
    NodeAttribut *searchedAttr = searchAttributByName(current_function, $3);
if (searchedAttr==NULL)
{
    yyerror("id not declared ");
}
    }
    else{
  verifierExistance($3);
    }
}
WriteMethod: WRITE PARENTHESEOUVRANTE ParamsWithoutVARTYPE PARENTHESEFERMANTE;
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
            yyerror("nombre de paramaitre invalide")
        }
       if(write){
          if (current_function != NULL){
              NodeAttribut *searchedAttr = searchAttributByName(current_function, $1);
              if (searchedAttr==NULL)
             { yyerror("id not declared ");} }
          else{ verifierExistance($1); }
        else{
Type type =getTypeOfParamByIndex(current_call, cpt_param);
Type type2= getTypeByID(symboleTable,$1 );
if(!areTypesCompatible(type1,type2)){
  yyerror("type incompatible");
}
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
              NodeAttribut *searchedAttr = searchAttributByName(current_function, $1);
              if (searchedAttr==NULL)
             { yyerror("id not declared ");} }
          else{ verifierExistance($1); }
        else{
Type type =getTypeOfParamByIndex(current_call, cpt_param);
Type type2= getTypeByID(symboleTable,$1 );
if(!areTypesCompatible(type1,type2)){
  yyerror("type incompatible");
}
        }

    }
    }
    |TYPE VIRG ParamsWithoutVARTYPE
    | StructChamp VIRG ParamsWithoutVARTYPE
    | ID CROCHETOUVRANT ID CROCHETFERMANT VIRG ParamsWithoutVARTYPE
    ;

CallMethod: ID PARENTHESEOUVRANTE ParamsWithoutVARTYPE PARENTHESEFERMANTE
{
current_call=search(symboleTable,$1);
if(!current_call)
    {
        yyerror("fonction non declaré")
    }
    write=0;
}
|ID PARENTHESEOUVRANTE PARENTHESEFERMANTE ;
{
current_call=search(symboleTable,$1);
 if(!current_call)
    {
        yyerror("fonction non declaré")
    }
    write=0;
}








//imene
CorIf: IF Condition  ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE Alternate;

Alternate: %empty
    |ELSE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE
    |ELSE CorIf
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




// Check if a variable is declared before use
void verifierExistance(int tokenId) {
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
Type getFunctionReturnType(int functionId) {
    NodeSymbole *symbole = search(symboleTable, functionId);
    if (symbole == NULL || symbole->categorieNoeud != Fonction) {
        yyerror("Invalid function call");
        return NULLL;
    }
    return symbole->type;
}
Type getTypeOfExpression(const char* expression) {

    //  Vérifier les terminaux
    if (isIntegerLiteral(expression)) {
        return INT32;
    } else if (isFloatLiteral(expression)) {
        return FLOAT32;
    } else if (isStringLiteral(expression)) {
        return STRING;
    } else if (isBooleanLiteral(expression)) {
        return BOOL;
    }

    // erifier les variables
    if (isIdentifier(expression)) {
        NodeSymbole* symbol = search(symboleTable, expression);
        if (symbol != NULL) {
            return symbol->type;
        } else {
            yyerror("Variable non déclarée");
            return NULLL;
    }

    //Vérifier les opérateurs binaires
    if (containsOperator(expression, "+")) {
        // Extraire les opérandes de l'expression (par exemple, en utilisant strtok)
        char* operand1 = extractOperand1(expression);
        char* operand2 = extractOperand2(expression);

        Type type1 = getTypeOfExpression(operand1);
        Type type2 = getTypeOfExpression(operand2);

        // Déterminer le type du résultat en fonction des types des opérandes, dans le cas ou operand1 et operand2 sont compatibles en fct de leurs types

        if (type1 == INT32 && type2 == INT32) {
            return INT32;
        } else if (type1 == FLOAT32 || type2 == FLOAT32) {
            return FLOAT32; // Promouvoir au flottant si un opérande est flottant
        } else {
            yyerror("Incompatibilité de type dans l'opération binaire");
            return NULLL;
        }
    }

   if (containsOperator(expression, "-")) {//soustraction
        // Extraire les opérandes de l'expression (par exemple, en utilisant strtok)
        char* operand1 = extractOperand1(expression);
        char* operand2 = extractOperand2(expression);

        Type type1 = getTypeOfExpression(operand1);
        Type type2 = getTypeOfExpression(operand2);

        // Déterminer le type du résultat en fonction des types des opérandes, dans le cas ou operand1 et operand2 sont compatibles en fct de leurs types

        if (type1 == INT32 && type2 == INT32) {
            return INT32;
        } else if (type1 == FLOAT32 || type2 == FLOAT32) {
            return FLOAT32; // Promouvoir au flottant si un opérande est flottant
        } else {
            yyerror("Incompatibilité de type dans l'opération binaire");
            return NULLL;
        }
    }
       if (containsOperator(expression, "*")) { // Multiplication
    char* operand1 = extractOperand1(expression);
    char* operand2 = extractOperand2(expression);

    Type type1 = getTypeOfExpression(operand1);
    Type type2 = getTypeOfExpression(operand2);

    if (type1 == INT32 && type2 == INT32) {
        return INT32;
    } else if (type1 == FLOAT32 || type2 == FLOAT32) {
        return FLOAT32; // Promote to float if either operand is float
    } else {
        yyerror("Incompatibilité de type dans l'opération de multiplication");
        return NULLL;
    }
}
    if (containsOperator(expression, "/")) { // Division
    char* operand1 = extractOperand1(expression);
    char* operand2 = extractOperand2(expression);

    Type type1 = getTypeOfExpression(operand1);
    Type type2 = getTypeOfExpression(operand2);

    if (type1 == INT32 && type2 == INT32) {
        return FLOAT32; // Division always results in a float
    } else if (type1 == FLOAT32 || type2 == FLOAT32) {
        return FLOAT32; // If either operand is float, result is float
    } else {
        yyerror("Incompatibilité de type dans l'opération de division");
        return NULLL;
    }
}
     if (containsOperator(expression, "//")) { // Integer Division
    char* operand1 = extractOperand1(expression);
    char* operand2 = extractOperand2(expression);

    Type type1 = getTypeOfExpression(operand1);
    Type type2 = getTypeOfExpression(operand2);

    if (type1 == INT32 && type2 == INT32) {
        return INT32; // Integer division results in an integer
    } else if (type1 == FLOAT32 || type2 == FLOAT32) {
        yyerror("La division entière ne peut pas être appliquée à des flottants");
        return NULLL;
    } else {
        yyerror("Incompatibilité de type dans l'opération de division entière");
        return NULLL;
    }
}

    //  Vérifier les appels de fonction
    if (isFunctionCall(expression)) {
        std::string functionName;
        std::vector<Argument> arguments;
        extractFunctionCallInfo(expression, functionName, arguments);
        Type returnType = getFunctionReturnType(functionName, arguments);

        if (returnType != NULLL) {
            return returnType;
        } else {
            yyerror("Appel de fonction invalide");
            return NULLL;
        }
    }

    yyerror("Expression invalide");
    return NULLL;
}}
 void extractFunctionInfo(const string& expression, string& functionName, vector<string>& arguments) {
    size_t openParenIndex = expression.find('(');
    if (openParenIndex == string::npos) {
        cout << "Expression invalide: parenthèse ouvrante manquante" << endl;
        return;
    }

    // Extraire le nom de la fonction
    functionName = expression.substr(0, openParenIndex);

    // Extraire les arguments
    size_t closeParenIndex = expression.find(')');
    if (closeParenIndex == string::npos) {
        cout << "Expression invalide: parenthèse fermante manquante" << endl;
        return;
    }

    string argsStr = expression.substr(openParenIndex + 1, closeParenIndex - openParenIndex - 1);
    size_t pos = 0;
    while ((pos = argsStr.find(",")) != string::npos) {
        arguments.push_back(argsStr.substr(0, pos));
        argsStr.erase(0, pos + 1);
    }
    if (!argsStr.empty()) {
        arguments.push_back(argsStr);
    }
}

char* extractOperand1(const char* expression) {

    char* operator_ptr = strchr(expression, '+');
    if (operator_ptr == NULL) {
        operator_ptr = strchr(expression, '-');
    }
    if (operator_ptr == NULL) {
        operator_ptr = strchr(expression, '*');
    }
    if (operator_ptr == NULL) {
        operator_ptr = strchr(expression, '/');
    }
    if (operator_ptr == NULL) {
        operator_ptr = strchr(expression, '//');
    }if (operator_ptr == NULL) {
        operator_ptr = strchr(expression, '<=');
    }if (operator_ptr == NULL) {
        operator_ptr = strchr(expression, '%');
    }
    //a ajouter plus tard les autres cas possibles

    if (operator_ptr == NULL) {//aucun operateru
        yyerror("Invalid binary expression");
        return NULL;
    }

    int operand1_length = operator_ptr - expression;
    char* operand1 = (char*)malloc(operand1_length + 1);
    strncpy(operand1, expression, operand1_length);
    operand1[operand1_length] = '\0';

    return operand1;
}

//kifkif as operand1, we extract l operand2

char* extractOperand2(const char* expression) {
    const char* operators = "+-*/%";
    const char* operator_ptr = strchr(expression, '+');
    if (operator_ptr == NULL) {
        operator_ptr = strchr(expression, '-');
    }
    if (operator_ptr == NULL) {
        operator_ptr = strchr(expression, '*');
    }
    if (operator_ptr == NULL) {
        operator_ptr = strchr(expression, '/');
    }
    if (operator_ptr == NULL) {
        operator_ptr = strchr(expression, '%');
    }

    if (operator_ptr == NULL) {
        return strdup(expression); // Copie l'expression entière
    }

    int operand2_length = strlen(expression) - (operator_ptr - expression) - 1;

    // Extraire l'opérande 2
    char* operand2 = (char*)malloc(operand2_length + 1);
    strncpy(operand2, operator_ptr + 1, operand2_length);
    operand2[operand2_length] = '\0';

    return operand2;
}




// Fonctions auxiliaires (implémenter celles-ci en fonction de la syntaxe de votre langage)
bool isIntegerLiteral(const char* str);
bool isFloatLiteral(const char* str);
bool isStringLiteral(const char* str);
bool isBooleanLiteral(const char* str);
bool isIdentifier(const char* str);
bool containsOperator(const char* str, const char* op);
char* extractOperand1(const char* expression);
char* extractOperand2(const char* expression);
bool isFunctionCall(const char* str);
char* extractFunctionName(const char* str);
