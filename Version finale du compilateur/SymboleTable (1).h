#ifndef SYMBOLETABLE_H
#define SYMBOLETABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Structure */
/*************************************************************************************/

typedef enum {
    INT32,
    INT64,
    INT256,
    CHAR,
    STRINGG,
    FLOAT32,
    FLOAT64,
    FLOAT256,
    CONSTT,
    TABLE,
    BOOLL,
    TABLE2D,
    NULLL,
} Type;

typedef struct NodeAttribut {
    char *name;
    int type; // Type de l'attribut
    union {
        int intValue;
        float floatValue;
        char* stringValue;
        bool boolValue; 
        void* nullValue;
    } value;
    struct NodeAttribut *next;
} NodeAttribut;

typedef struct Param {
    char *name;
    int type;
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
    int type;
    union {
        int intValue;
        float floatValue;
        char* stringValue;
        bool boolValue; 
        void* nullValue;
    } value;
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
NodeSymbole *insertSymbole(SymboleTable *symboleTable, char *tokenId, categorie cat, int type);
// /** Insertion D'un nouveau noeud NodeSymbole avec un index d'insertion **/
NodeSymbole *insertSymboleByIndex(SymboleTable *symboleTable, int index, char *tokenId, categorie cat, Type type);
// /** Avoir un symbole en donnant son index **/
NodeSymbole *getSymboleByIndex(SymboleTable *symboleTable, int index);
// /** Ajout d'un attribut à la liste d'un symbole donné **/
void setAttribut(NodeSymbole *symbole, char *name, int type, void *value);
// /** Ajout d'un attribut à la liste d'un symbole en donnant l'indice de ce dernier **/
void setAttributByIndex(SymboleTable *symboleTable, int index, char *name, Type type, void *value);
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
void addParam(NodeSymbole *symbole, char *name, int type);
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
void updateAttributValue(NodeSymbole *symbole, char *name, void *value);
void *getAttributValue(NodeSymbole *symbole, char *name);
Param *searchParamByName(NodeSymbole *symbole, char *name);
Type getTypeOfParamByIndex(NodeSymbole *symbole, int index);
int countParams(NodeSymbole *symbole);
Type getTypeByID(SymboleTable *symboleTable, char *tokenId);
#endif