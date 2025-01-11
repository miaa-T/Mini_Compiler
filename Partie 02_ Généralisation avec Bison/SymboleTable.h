#ifndef SymboleTable_H
#define SymboleTable_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure */
/*************************************************************************************/
typedef struct ChampsEnreg { // ceci est une table contenant les pointeurs vers les différents champs d'un enregistrement
    struct ChampsEnreg *next;
    char *Pointeur;
} ChampsEnreg;

typedef enum {
    INT32,
    INT64,
    INT256,
    CHAR,
    STRING,
    FLOAT32,
    FLOAT64,
    FLOAT256,
    CONST,
    TABLE,
    TABLE2D,
    NULLL,
} Type;

typedef struct NodeAttribut {
    char *name;
    Type type; // Type de l'attribut
    struct NodeAttribut *next;
} NodeAttribut;

typedef struct Param {
    char *name;
    Type type;
    struct Param *next;
} Param;

typedef enum {
    Attsimple, // soit une constante ou une variable
    Fonction, // déclaration d'une fonction
    Enregistrement, // déclaration d'un enregistrement
} categorie;

typedef struct NodeSymbole {
    char *Id; // Nom de la variable, fonction ou structure
    int nbAttribut;
    categorie categorieNoeud;
    Type type;
    struct NodeSymbole *next;
    NodeAttribut *first;
    NodeAttribut *last;
    Param *firstparam;
    Param *lastparam;
} NodeSymbole;

typedef struct SymboleTable {
    NodeSymbole *first;
    NodeSymbole *last;
    int TailleTable;
} SymboleTable;

/*****************************************************************************************/
// /** Allocation d'une table de symboles **/
SymboleTable *allocateSymboleTable();
// /** Insertion D'un nouveau noeud NodeSymbole **/
NodeSymbole *insertSymbole(SymboleTable *symboleTable, char *tokenId, categorie cat, Type type);
// /** Insertion D'un nouveau noeud NodeSymbole avec un index d'insertion **/
NodeSymbole *insertSymboleByIndex(SymboleTable *symboleTable, int index, char *tokenId, categorie cat, Type type);
// /** Avoir un symbole en donnant son index **/
NodeSymbole *getSymboleByIndex(SymboleTable *symboleTable, int index);
// /** Ajout d'un attribut à la liste d'un symbole donné **/
void setAttribut(NodeSymbole *symbole, char *name, Type type);
// /** Ajout d'un attribut à la liste d'un symbole en donnant l'indice de ce dernier **/
void setAttributByIndex(SymboleTable *symboleTable, int index, char *name, Type type);
// /** Avoir un attribut d'un symbole en donnant son nom **/
NodeAttribut *getAttribut(NodeSymbole *nodeSymbole, char *name);
// /** Avoir un attribut d'un symbole en donnant l'index du symbole et le nom d'attribut **/
NodeAttribut *getAttributByIndex(SymboleTable *symboleTable, int Index, char *name);
// /** Suppression des attributs d'un noeud NodeAttribut d'un symbole **/
void DeleteAttributs(NodeSymbole *node);
// /** Suppression d'une table de symbole **/
void DeleteTable(SymboleTable **symboleTable);
// /** Recherche d'un symbole par ID **/
NodeSymbole *search(SymboleTable *symboleTable, char *tokenId);
// /** Ajout d'un paramètre à une fonction **/
void addParam(NodeSymbole *symbole, char *name, Type type);
// /** Affichage des attributs d'un symbole **/
void afficherAttributs(NodeSymbole *symbole);
// /** Affichage d'un symbole avec ses informations **/
void afficherSymbole(NodeSymbole *symbole);
// /** Affichage de toute la table des symboles sous forme de liste de listes **/
void afficherTableSymbole(SymboleTable *table);
// /** Conversion d'un type en chaîne de caractères **/
const char* typeToStr(Type type);
NodeAttribut *searchAttributByName(NodeSymbole *symbole, char *name);
/*****************************************************************************************/
#endif
