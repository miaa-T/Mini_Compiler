#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flamingo.tab.h"

#define MAX_SYMBOLS 100
#define MAX_RULES 10

extern int yylex();
extern char *yytext;
extern void yy_scan_string(const char *str);

typedef enum
{
    TERMINAL,
    NON_TERMINAL
} SymbolType;

typedef struct
{
    char symbol[20];
    SymbolType type;
} Symbol;

typedef struct
{
    Symbol lhs;
    Symbol rhs[MAX_SYMBOLS];
    int rhs_count;
} Rule;

typedef struct
{
    char symbol[20];
    char first[MAX_SYMBOLS][20];
    int first_count;
} FirstSet;

Rule grammar[MAX_RULES];
FirstSet firstSets[MAX_RULES];
int num_rules = 0;

int isTerminal(Symbol s)
{
    return s.type == TERMINAL;
}

void calculateFirstSet()
{
    for (int i = 0; i < num_rules; i++)
    {
        strcpy(firstSets[i].symbol, grammar[i].lhs.symbol);
        firstSets[i].first_count = 0;
    }

    int updated = 1;
    while (updated)
    {
        updated = 0;

        for (int i = 0; i < num_rules; i++)
        {
            Rule rule = grammar[i];
            int current_index = -1;

            for (int j = 0; j < num_rules; j++)
            {
                if (strcmp(firstSets[j].symbol, rule.lhs.symbol) == 0)
                {
                    current_index = j;
                    break;
                }
            }

            if (current_index == -1)
                continue;

            for (int j = 0; j < rule.rhs_count; j++)
            {
                Symbol rhs_symbol = rule.rhs[j];

                if (isTerminal(rhs_symbol))
                {
                    int found = 0;
                    for (int k = 0; k < firstSets[current_index].first_count; k++)
                    {
                        if (strcmp(firstSets[current_index].first[k], rhs_symbol.symbol) == 0)
                        {
                            found = 1;
                            break;
                        }
                    }
                    if (!found)
                    {
                        strcpy(firstSets[current_index].first[firstSets[current_index].first_count], rhs_symbol.symbol);
                        firstSets[current_index].first_count++;
                        updated = 1;
                    }
                    break;
                }
                else
                {
                    int rhs_index = -1;
                    for (int k = 0; k < num_rules; k++)
                    {
                        if (strcmp(firstSets[k].symbol, rhs_symbol.symbol) == 0)
                        {
                            rhs_index = k;
                            break;
                        }
                    }
                    if (rhs_index == -1)
                        continue;

                    for (int k = 0; k < firstSets[rhs_index].first_count; k++)
                    {
                        int found = 0;
                        for (int l = 0; l < firstSets[current_index].first_count; l++)
                        {
                            if (strcmp(firstSets[current_index].first[l], firstSets[rhs_index].first[k]) == 0)
                            {
                                found = 1;
                                break;
                            }
                        }
                        if (!found)
                        {
                            strcpy(firstSets[current_index].first[firstSets[current_index].first_count], firstSets[rhs_index].first[k]);
                            firstSets[current_index].first_count++;
                            updated = 1;
                        }
                    }

                    break;
                }
            }
        }
    }
}

void printFirstSets()
{
    printf("\nFirst Sets:\n");
    for (int i = 0; i < num_rules; i++)
    {
        printf("First(%s) = { ", firstSets[i].symbol);
        for (int j = 0; j < firstSets[i].first_count; j++)
        {
            printf("%s ", firstSets[i].first[j]);
        }
        printf("}\n");
    }
}

void printGrammar()
{
    printf("\nGrammar Rules:\n");
    printf("-----------------------------------------------------------------------\n");
    printf("| LHS             | RHS                                               |\n");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < num_rules; i++)
    {
        printf("| %-15s | ", grammar[i].lhs.symbol);
        int totalLength = 0;
        for (int j = 0; j < grammar[i].rhs_count; j++)
        {
            totalLength += strlen(grammar[i].rhs[j].symbol);
            printf("%s ", grammar[i].rhs[j].symbol);
            totalLength++;
        }
        int spacesToPrint = 50 - totalLength;
        for (int i = 0; i < spacesToPrint; i++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    printf("-----------------------------------------------------------------------\n");
}

typedef struct
{
    char symbol[20];
    char follow[MAX_SYMBOLS][20];
    int follow_count;
} FollowSet;

FollowSet followSets[MAX_RULES];

void initializeFollowSets()
{
    for (int i = 0; i < num_rules; i++)
    {
        strcpy(followSets[i].symbol, grammar[i].lhs.symbol);
        followSets[i].follow_count = 0;
    }
    strcpy(followSets[0].follow[followSets[0].follow_count++], "$");
}

int findFollowIndex(const char *symbol)
{
    for (int i = 0; i < num_rules; i++)
    {
        if (strcmp(followSets[i].symbol, symbol) == 0)
        {
            return i;
        }
    }
    return -1;
}

void calculateFollowSet()
{
    initializeFollowSets();
    int updated = 1;

    while (updated)
    {
        updated = 0;

        for (int i = 0; i < num_rules; i++)
        {
            Rule rule = grammar[i];
            for (int j = 0; j < rule.rhs_count; j++)
            {
                Symbol current_symbol = rule.rhs[j];

                if (!isTerminal(current_symbol))
                {
                    int current_index = findFollowIndex(current_symbol.symbol);
                    if (current_index == -1)
                        continue;

                    if (j + 1 < rule.rhs_count)
                    {
                        Symbol next_symbol = rule.rhs[j + 1];
                        if (isTerminal(next_symbol))
                        {
                            int found = 0;
                            for (int k = 0; k < followSets[current_index].follow_count; k++)
                            {
                                if (strcmp(followSets[current_index].follow[k], next_symbol.symbol) == 0)
                                {
                                    found = 1;
                                    break;
                                }
                            }
                            if (!found)
                            {
                                strcpy(followSets[current_index].follow[followSets[current_index].follow_count++], next_symbol.symbol);
                                updated = 1;
                            }
                        }
                        else
                        {
                            int next_index = findFollowIndex(next_symbol.symbol);
                            if (next_index != -1)
                            {
                                for (int k = 0; k < firstSets[next_index].first_count; k++)
                                {
                                    if (strcmp(firstSets[next_index].first[k], "epsilon") != 0)
                                    {
                                        int found = 0;
                                        for (int l = 0; l < followSets[current_index].follow_count; l++)
                                        {
                                            if (strcmp(followSets[current_index].follow[l], firstSets[next_index].first[k]) == 0)
                                            {
                                                found = 1;
                                                break;
                                            }
                                        }
                                        if (!found)
                                        {
                                            strcpy(followSets[current_index].follow[followSets[current_index].follow_count++], firstSets[next_index].first[k]);
                                            updated = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if (j + 1 == rule.rhs_count || (j + 1 < rule.rhs_count && strcmp(rule.rhs[j + 1].symbol, "epsilon") == 0))
                    {
                        int lhs_index = findFollowIndex(rule.lhs.symbol);
                        if (lhs_index != -1)
                        {
                            for (int k = 0; k < followSets[lhs_index].follow_count; k++)
                            {
                                int found = 0;
                                for (int l = 0; l < followSets[current_index].follow_count; l++)
                                {
                                    if (strcmp(followSets[current_index].follow[l], followSets[lhs_index].follow[k]) == 0)
                                    {
                                        found = 1;
                                        break;
                                    }
                                }
                                if (!found)
                                {
                                    strcpy(followSets[current_index].follow[followSets[current_index].follow_count++], followSets[lhs_index].follow[k]);
                                    updated = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void printFollowSets()
{
    printf("\nFollow Sets:\n");
    for (int i = 0; i < num_rules; i++)
    {
        printf("Follow(%s) = { ", followSets[i].symbol);
        for (int j = 0; j < followSets[i].follow_count; j++)
        {
            printf("%s ", followSets[i].follow[j]);
        }
        printf("}\n");
    }
}

typedef struct
{
    char terminal[20];
    int rule_index;
} TableEntry;

#define MAX_TERMINALS 10
#define MAX_NON_TERMINALS 10

TableEntry parsing_table[MAX_NON_TERMINALS][MAX_TERMINALS];
char terminals[MAX_TERMINALS][20];
int num_terminals = 0;
char non_terminals[MAX_NON_TERMINALS][20];
int num_non_terminals = 0;

void initializeParsingTable()
{
    for (int i = 0; i < MAX_NON_TERMINALS; i++)
    {
        for (int j = 0; j < MAX_TERMINALS; j++)
        {
            parsing_table[i][j].rule_index = -1;
        }
    }
}

void collectSymbols()
{
    for (int i = 0; i < num_rules; i++)
    {
        int found = 0;
        for (int j = 0; j < num_non_terminals; j++)
        {
            if (strcmp(non_terminals[j], grammar[i].lhs.symbol) == 0)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            strcpy(non_terminals[num_non_terminals++], grammar[i].lhs.symbol);
        }
    }

    for (int i = 0; i < num_rules; i++)
    {
        for (int j = 0; j < grammar[i].rhs_count; j++)
        {
            if (isTerminal(grammar[i].rhs[j]))
            {
                int found = 0;
                for (int k = 0; k < num_terminals; k++)
                {
                    if (strcmp(terminals[k], grammar[i].rhs[j].symbol) == 0)
                    {
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    strcpy(terminals[num_terminals++], grammar[i].rhs[j].symbol);
                }
            }
        }
    }
    int dollar_found = 0;
    for (int i = 0; i < num_terminals; i++)
    {
        if (strcmp(terminals[i], "$") == 0)
        {
            dollar_found = 1;
            break;
        }
    }
    if (!dollar_found)
    {
        strcpy(terminals[num_terminals++], "$");
    }
}

void constructParsingTable()
{
    initializeParsingTable();
    collectSymbols();

    for (int i = 0; i < num_rules; i++)
    {
        char *non_terminal = grammar[i].lhs.symbol;
        int non_term_index = -1;

        for (int j = 0; j < num_non_terminals; j++)
        {
            if (strcmp(non_terminals[j], non_terminal) == 0)
            {
                non_term_index = j;
                break;
            }
        }

        if (non_term_index == -1)
            continue;

        Symbol first_symbol = grammar[i].rhs[0];
        if (isTerminal(first_symbol))
        {
            for (int j = 0; j < num_terminals; j++)
            {
                if (strcmp(terminals[j], first_symbol.symbol) == 0)
                {
                    parsing_table[non_term_index][j].rule_index = i;
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j < num_rules; j++)
            {
                if (strcmp(firstSets[j].symbol, first_symbol.symbol) == 0)
                {
                    for (int k = 0; k < firstSets[j].first_count; k++)
                    {
                        for (int l = 0; l < num_terminals; l++)
                        {
                            if (strcmp(terminals[l], firstSets[j].first[k]) == 0)
                            {
                                parsing_table[non_term_index][l].rule_index = i;
                            }
                        }
                    }
                }
            }
        }
    }
}

void printParsingTable()
{
    printf("\nParsing Table:\n");

    printf("%-15s", "");
    for (int i = 0; i < num_terminals; i++)
    {
        printf("%-20s", terminals[i]);
    }
    printf("\n");

    for (int i = 0; i < 15 + (20 * num_terminals); i++)
    {
        printf("-");
    }
    printf("\n");

    for (int i = 0; i < num_non_terminals; i++)
    {
        printf("%-15s", non_terminals[i]);
        for (int j = 0; j < num_terminals; j++)
        {
            if (parsing_table[i][j].rule_index != -1)
            {
                printf("%-20d", parsing_table[i][j].rule_index);
            }
            else
            {
                printf("%-20s", "-");
            }
        }
        printf("\n");
    }
}

typedef struct
{
    char items[100][20];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, const char *item)
{
    strcpy(s->items[++s->top], item);
}

void pop(Stack *s)
{
    if (s->top >= 0)
        s->top--;
}

char *peek(Stack *s)
{
    if (s->top >= 0)
        return s->items[s->top];
    return NULL;
}

void printParserState(Stack *stack, const char *input, const char *action)
{

    int totalLength = 0;
    printf("| ");
    for (int i = 0; i <= stack->top; i++)
    {
        totalLength += strlen(stack->items[i]);
        printf("%s ", stack->items[i]);
        totalLength++;
    }
    int spacesToPrint = 66 - totalLength;
    for (int i = 0; i < spacesToPrint; i++)
    {
        printf(" ");
    }
    totalLength = 0;
    printf("| %s", input);
    totalLength += strlen(input);
    spacesToPrint = 74 - totalLength;

    for (int i = 0; i < spacesToPrint; i++)
    {
        printf(" ");
    }

    printf("| %s", action);
    for (int i = strlen(action); i < 16; i++)
    {
        printf(" ");
    }
    printf("|\n");
    printf("+-------------------------------------------------------------------+---------------------------------------------------------------------------+-----------------+\n");
}

int findTerminalIndex(const char *terminal)
{
    for (int i = 0; i < num_terminals; i++)
    {
        if (strcmp(terminals[i], terminal) == 0)
        {
            return i;
        }
    }
    return -1;
}

int findNonTerminalIndex(const char *non_terminal)
{
    for (int i = 0; i < num_non_terminals; i++)
    {
        if (strcmp(non_terminals[i], non_terminal) == 0)
        {
            return i;
        }
    }
    return -1;
}

const char *tokenToString(int token)
{
    switch (token)
    {
    case INT:
        return "INT";
    case CROCHETOUVRANT:
        return "CROCHETOUVRANT";
    case CROCHETFERMANT:
        return "CROCHETFERMANT";
    case PARENTHESEOUVRANTE:
        return "PARENTHESEOUVRANTE";
    case PARENTHESEFERMANTE:
        return "PARENTHESEFERMANTE";
    case ID:
        return "ID";
    default:
        return "UNKNOWN";
    }
}

void parse(const char *input)
{
    Stack stack;
    initStack(&stack);

    push(&stack, "#");
    push(&stack, "expression");

    yy_scan_string(input);

    int token = yylex();
    char current_input[20];
    char display_input[1000]; // Buffer for displaying remaining input
    strcpy(display_input, input); // Initialize with full input
   
    if (token != 0)
    {
        strcpy(current_input, tokenToString(token));
    }
    else
    {
        strcpy(current_input, "#");
    }

    printf("\nStarting LL(1) parsing for input: %s\n", input);
    printf("\n+-------------------------------------------------------------------+---------------------------------------------------------------------------+-----------------+\n");
    printf("| Stack Content                                                     | Input String                                                              | Action          |\n");
    printf("+-------------------------------------------------------------------+---------------------------------------------------------------------------+-----------------+\n");
   
    while (1)
    {
        char *top = peek(&stack);
        if (top == NULL)
            break;

        if (strcmp(top, "#") == 0 && strcmp(current_input, "#") == 0)
        {
            printParserState(&stack, display_input, "Accept");
            printf("\nParsing completed successfully!\n");
            break;
        }

        if (strcmp(top, current_input) == 0)
        {
            pop(&stack);
            // Update display input by removing the matched token
            if (strlen(display_input) > strlen(yytext))
            {
                memmove(display_input, display_input + strlen(yytext),
                       strlen(display_input) - strlen(yytext) + 1);
            }
            else
            {
                display_input[0] = '\0';
            }
           
            token = yylex();
            if (token != 0)
            {
                strcpy(current_input, tokenToString(token));
            }
            else
            {
                strcpy(current_input, "#");
            }
            printParserState(&stack, display_input, "Match");
        }
        else
        {
            int non_term_idx = findNonTerminalIndex(top);
            int term_idx = findTerminalIndex(current_input);

            if (non_term_idx == -1 || term_idx == -1)
            {
                printParserState(&stack, display_input, "Error");
                printf("\nParsing error: Invalid symbol\n");
                break;
            }

            int rule_idx = parsing_table[non_term_idx][term_idx].rule_index;

            if (rule_idx == -1)
            {
                printParserState(&stack, display_input, "Error");
                printf("\nParsing error: No production rule found\n");
                break;
            }

            pop(&stack);
            for (int i = grammar[rule_idx].rhs_count - 1; i >= 0; i--)
            {
                push(&stack, grammar[rule_idx].rhs[i].symbol);
            }

            char action[50];
            sprintf(action, "Apply Rule %d", rule_idx);
            printParserState(&stack, display_input, action);
        }
    }
}

int main()
{
    // Rule 1: expression -> PARENTHESEOUVRANTE expression PARENTHESEFERMANTE//0
    strcpy(grammar[num_rules].lhs.symbol, "expression");
    grammar[num_rules].lhs.type = NON_TERMINAL;
    grammar[num_rules].rhs[0].type = TERMINAL;
    strcpy(grammar[num_rules].rhs[0].symbol, "PARENTHESEOUVRANTE");
    grammar[num_rules].rhs[1].type = NON_TERMINAL;
    strcpy(grammar[num_rules].rhs[1].symbol, "expression");
    grammar[num_rules].rhs[2].type = TERMINAL;
    strcpy(grammar[num_rules].rhs[2].symbol, "PARENTHESEFERMANTE");
    grammar[num_rules].rhs_count = 3;
    num_rules++;

    // Rule 2: expression -> terme    //1
    strcpy(grammar[num_rules].lhs.symbol, "expression");
    grammar[num_rules].lhs.type = NON_TERMINAL;
    grammar[num_rules].rhs[0].type = NON_TERMINAL;
    strcpy(grammar[num_rules].rhs[0].symbol, "terme");
    grammar[num_rules].rhs_count = 1;
    num_rules++;

    // Rule 3: terme -> INT
    strcpy(grammar[num_rules].lhs.symbol, "terme");
    grammar[num_rules].lhs.type = NON_TERMINAL;
    grammar[num_rules].rhs[0].type = TERMINAL;
    strcpy(grammar[num_rules].rhs[0].symbol, "INT");
    grammar[num_rules].rhs_count = 1;
    num_rules++;

    // Rule 4: terme -> ID CROCHETOUVRANT expression CROCHETFERMANT
    strcpy(grammar[num_rules].lhs.symbol, "terme");
    grammar[num_rules].lhs.type = NON_TERMINAL;
    grammar[num_rules].rhs[0].type = TERMINAL;
    strcpy(grammar[num_rules].rhs[0].symbol, "ID");
    grammar[num_rules].rhs[1].type = TERMINAL;
    strcpy(grammar[num_rules].rhs[1].symbol, "CROCHETOUVRANT");
    grammar[num_rules].rhs[2].type = NON_TERMINAL;
    strcpy(grammar[num_rules].rhs[2].symbol, "expression");
    grammar[num_rules].rhs[3].type = TERMINAL;
    strcpy(grammar[num_rules].rhs[3].symbol, "CROCHETFERMANT");
    grammar[num_rules].rhs_count = 4;
    num_rules++;

    printGrammar();

    calculateFirstSet();
    printFirstSets();

    calculateFollowSet();
    printFollowSets();

    constructParsingTable();
    printParsingTable();

    const char *test_input = "jihene2004{2}";

    parse(test_input);

    return 0;
}