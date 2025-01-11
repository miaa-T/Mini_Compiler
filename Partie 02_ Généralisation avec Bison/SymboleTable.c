#include "SymboleTable.h"

const char* typeToStr(Type type) {
    switch (type) {
        case INT32: return "int32";
        case INT64: return "int64";
        case INT256: return "int256";
        case CHAR: return "char";
        case STRING: return "string";
        case FLOAT32: return "float32";
        case FLOAT64: return "float64";
        case FLOAT256: return "float256";
        case CONST: return "const";
        case TABLE: return "table";
        case TABLE2D: return "table2d";
        case NULLL: return "NULL";
        default: return "Inconnu";
    }
}

SymboleTable *allocateSymboleTable() {
    SymboleTable *table = (SymboleTable *)malloc(sizeof(SymboleTable));
    table->first = NULL;
    table->last = NULL;
    table->TailleTable = 0;
    return table;
}

// Fonction pour afficher un attribut d'un symbole
void afficherAttributs(NodeSymbole *symbole) {
    NodeAttribut *currentAttribut = symbole->first;
    printf("Affichage des attributs pour le symbole ID=%s\n", symbole->Id);
    while (currentAttribut != NULL) {
        printf("Attribut: %s, Type: %s\n", currentAttribut->name, typeToStr(currentAttribut->type));
        currentAttribut = currentAttribut->next;
    }
    printf("\n");
}

// Fonction pour afficher un symbole avec ses informations
void afficherSymbole(NodeSymbole *symbole) {
    const char *categorieStr = (symbole->categorieNoeud == Attsimple) ? "Simple" :
                               (symbole->categorieNoeud == Fonction) ? "Fonction" : "Enregistrement";
    const char *typeStr = typeToStr(symbole->type);
    printf("Symbole ID: %s\n", symbole->Id);
    printf("Nombre d'attributs: %d\n", symbole->nbAttribut);
    printf("Categorie: %s\n", categorieStr);
    printf("Type: %s\n", typeStr);
    afficherAttributs(symbole); // Affiche les attributs associés au symbole
    if (symbole->categorieNoeud == Fonction) {
        Param *currentParam = symbole->firstparam;
        printf("Paramètres de la fonction:\n");
        while (currentParam != NULL) {
            printf("Paramètre: %s, Type: %s\n", currentParam->name, typeToStr(currentParam->type));
            currentParam = currentParam->next;
        }
    }
}

/** Insertion d'un nouveau noeud NodeSymbole **/
NodeSymbole *insertSymbole(SymboleTable *symboleTable, char *tokenId, categorie cat, Type type) {
    NodeSymbole *newNode = (NodeSymbole *)malloc(sizeof(NodeSymbole));
    newNode->Id = strdup(tokenId);
    newNode->nbAttribut = 0;
    newNode->categorieNoeud = cat; // Par défaut
    newNode->next = NULL;
    newNode->first = NULL;
    newNode->last = NULL;
    newNode->firstparam = NULL;
    newNode->lastparam = NULL;
    newNode->type = type;
    if (!symboleTable->first) {
        symboleTable->first = symboleTable->last = newNode;
    } else {
        symboleTable->last->next = newNode;
        symboleTable->last = newNode;
    }

    symboleTable->TailleTable++;
    return newNode;
}

NodeSymbole *insertSymboleByIndex(SymboleTable *symboleTable, int index, char *tokenId, categorie cat, Type type) {
    if (index < 0 || index > symboleTable->TailleTable) {
        printf("Index hors limites\n");
        return NULL;
    }

    NodeSymbole *newNode = (NodeSymbole *)malloc(sizeof(NodeSymbole));
    newNode->Id = strdup(tokenId);
    newNode->nbAttribut = 0;
    newNode->categorieNoeud = cat;
    newNode->next = NULL;
    newNode->first = NULL;
    newNode->last = NULL;
    newNode->firstparam = NULL;
    newNode->lastparam = NULL;
    newNode->type = type;
    if (index == 0) {
        newNode->next = symboleTable->first;
        symboleTable->first = newNode;
        if (!symboleTable->last) symboleTable->last = newNode;
    } else {
        NodeSymbole *current = symboleTable->first;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == NULL) symboleTable->last = newNode;
    }

    symboleTable->TailleTable++;
    return newNode;
}

/** Récupération d'un symbole par index **/
NodeSymbole *getSymboleByIndex(SymboleTable *symboleTable, int index) {
    if (index < 0 || index >= symboleTable->TailleTable) {
        printf("Index hors limites\n");
        return NULL;
    }

    NodeSymbole *current = symboleTable->first;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

/** Ajout d'un attribut à un symbole donné **/
void setAttribut(NodeSymbole *symbole, char *name, Type type) {
    NodeAttribut *newAttr = (NodeAttribut *)malloc(sizeof(NodeAttribut));
    newAttr->name = strdup(name);
    newAttr->type = type;
    newAttr->next = NULL;

    if (!symbole->first) {
        symbole->first = symbole->last = newAttr;
    } else {
        symbole->last->next = newAttr;
        symbole->last = newAttr;
    }

    symbole->nbAttribut++;
}

/** Ajout d'un attribut à un symbole par index **/
void setAttributByIndex(SymboleTable *symboleTable, int index, char *name, Type type) {
    NodeSymbole *symbole = getSymboleByIndex(symboleTable, index);
    if (symbole) {
        setAttribut(symbole, name, type);
    }
}

/** Récupération d'un attribut par nom **/
NodeAttribut *getAttribut(NodeSymbole *nodeSymbole, char *name) {
    NodeAttribut *current = nodeSymbole->first;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/** Récupération d'un attribut par index et nom **/
NodeAttribut *getAttributByIndex(SymboleTable *symboleTable, int index, char *name) {
    NodeSymbole *symbole = getSymboleByIndex(symboleTable, index);
    return symbole ? getAttribut(symbole, name) : NULL;
}

/** Suppression des attributs d'un noeud NodeAttribut d'un symbole **/
void DeleteAttributs(NodeSymbole *node) {
    NodeAttribut *current = node->first;
    while (current) {
        NodeAttribut *tmp = current;
        current = current->next;
        free(tmp->name);
        free(tmp);
    }
    node->first = node->last = NULL;
    node->nbAttribut = 0;
}

void DeleteTable(SymboleTable **symboleTable) {
    if (*symboleTable == NULL) return;

    NodeSymbole *current = (*symboleTable)->first;
    while (current) {
        NodeSymbole *tmp = current;
        DeleteAttributs(current); // Supprime tous les attributs associés
        current = current->next;
        free(tmp->Id);
        free(tmp);
    }

    // Libérez la mémoire de la table
    free(*symboleTable);
    *symboleTable = NULL; // Mettez le pointeur à NULL pour éviter un accès à une zone libérée
}

void afficherTableSymbole(SymboleTable *table) {
    if (table == NULL || table->first == NULL) {
        printf("La table des symboles est vide ou non allouée.\n");
        return;
    }
    NodeSymbole *currentSymbole = table->first;

    if (currentSymbole == NULL) {
        printf("La table des symboles est vide.\n");
        return;
    }

    printf("=== Affichage de la Table des Symboles ===\n");
    printf("| %-20s | %-20s | %-18s | %-10s | %-20s | %-20s |\n", "ID", "Categorie", "Nb Attributs", "Type", "Attributs", "Paramètres");
    printf("----------------------------------------------------------------------------------------------------\n");

    // Parcourt chaque symbole dans la table
    while (currentSymbole != NULL) {
        const char *categorieStr = (currentSymbole->categorieNoeud == Attsimple) ? "Simple" :
                                   (currentSymbole->categorieNoeud == Fonction) ? "Fonction" : "Enregistrement";

        printf("| %-20s | %-20s | %-18d| %-10s | ", currentSymbole->Id, categorieStr, currentSymbole->nbAttribut, typeToStr(currentSymbole->type));

        // Affiche les attributs de chaque symbole
        NodeAttribut *currentAttribut = currentSymbole->first;
        if (currentAttribut != NULL) {
            printf("(");
            while (currentAttribut != NULL) {
                printf("%s: %s", currentAttribut->name, typeToStr(currentAttribut->type));
                if (currentAttribut->next != NULL) {
                    printf(", ");
                }
                currentAttribut = currentAttribut->next;
            }
            printf(") ");
        } else {
            printf("(Aucun attribut) ");
        }

        printf("| ");

        // Affiche les paramètres de la fonction
        if (currentSymbole->categorieNoeud == Fonction) {
            Param *currentParam = currentSymbole->firstparam;
            if (currentParam != NULL) {
                printf("(");
                while (currentParam != NULL) {
                    printf("%s: %s", currentParam->name, typeToStr(currentParam->type));
                    if (currentParam->next != NULL) {
                        printf(", ");
                    }
                    currentParam = currentParam->next;
                }
                printf(") ");
            } else {
                printf("(Aucun paramètre) ");
            }
        } else {
            printf("(Non applicable) ");
        }

        printf("\n");

        currentSymbole = currentSymbole->next;
    }
    printf("\n");
}

/** Recherche d'un symbole par ID **/
NodeSymbole *search(SymboleTable *symboleTable, char *tokenId) {
    NodeSymbole *current = symboleTable->first;
    while (current) {
        if (strcmp(current->Id, tokenId) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/** Ajout d'un paramètre à une fonction **/
void addParam(NodeSymbole *symbole, char *name, Type type) {
    if (symbole->categorieNoeud != Fonction) {
        printf("Le symbole n'est pas une fonction.\n");
        return;
    }

    Param *newParam = (Param *)malloc(sizeof(Param));
    newParam->name = strdup(name);
    newParam->type = type;
    newParam->next = NULL;

    if (!symbole->firstparam) {
        symbole->firstparam = symbole->lastparam = newParam;
    } else {
        symbole->lastparam->next = newParam;
        symbole->lastparam = newParam;
    }
}

NodeAttribut *searchAttributByName(NodeSymbole *symbole, char *name) {
    NodeAttribut *current = symbole->first;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Param *searchParamByName(NodeSymbole *symbole, char *name) {
    Param *current = symbole->firstparam;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Type getTypeOfParamByIndex(NodeSymbole *symbole, int index) {
    Param *current = symbole->firstparam;
    for (int i = 0; i < index; i++) {
        if (current == NULL) {
            printf("Index hors limites\n");
            return NULLL; // Retourne NULLL si l'index est hors limites
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Index hors limites\n");
        return NULLL; // Retourne NULLL si l'index est hors limites
    }
    return current->type;
}
int main() {
    printf("=== Test de SymboleTable ===\n");

    SymboleTable *table = allocateSymboleTable();
    printf("\n\n\n\n\n");

    // Test 1: Insertion d'un nouveau symbole de type variable simple
    NodeSymbole *sym1 = insertSymbole(table, "fonction1", Fonction, INT32);
    setAttribut(sym1, "var1", INT32);
    setAttribut(sym1, "var2",INT32);
    addParam(sym1, "att1", INT32 );
    afficherTableSymbole(table);
NodeAttribut *searchedAttr = searchAttributByName(sym1, "var1");
    if (searchedAttr) {
        printf("Attribut trouvé: %s, Type: %s\n", searchedAttr->name, typeToStr(searchedAttr->type));
    } else {
        printf("Attribut non trouvé.\n");
    }
    Param *searchedparam= searchParamByName(sym1, "att1");
 if (searchedparam) {
        printf("Attribut trouvé: %s, Type: %s\n", searchedparam->name, typeToStr(searchedparam->type));
    } else {
        printf("Attribut non trouvé.\n");
    }

    return 0;
}

int countParams(NodeSymbole *symbole) {
    int count = 0;
    Param *current = symbole->firstparam;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
Type getTypeByID(SymboleTable *symboleTable, char *tokenId) {
    NodeSymbole *symbole = search(symboleTable, tokenId);
    if (symbole) {
        return symbole->type;
    }
    return NULLL; // Retourne NULLL si le symbole n'est pas trouvé
}