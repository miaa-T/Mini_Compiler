/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y"

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

#line 121 "yacc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PACK = 3,                       /* PACK  */
  YYSYMBOL_FONCTION = 4,                   /* FONCTION  */
  YYSYMBOL_MAIN = 5,                       /* MAIN  */
  YYSYMBOL_ExpressionHELLO = 6,            /* ExpressionHELLO  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_TYPE = 8,                       /* TYPE  */
  YYSYMBOL_INTTYPE = 9,                    /* INTTYPE  */
  YYSYMBOL_BIGINTTYPE = 10,                /* BIGINTTYPE  */
  YYSYMBOL_LONGINTTYPE = 11,               /* LONGINTTYPE  */
  YYSYMBOL_STRINGTYPE = 12,                /* STRINGTYPE  */
  YYSYMBOL_FLOATTYPE = 13,                 /* FLOATTYPE  */
  YYSYMBOL_BIGFLOATTYPE = 14,              /* BIGFLOATTYPE  */
  YYSYMBOL_LONGFLOATTYPE = 15,             /* LONGFLOATTYPE  */
  YYSYMBOL_BOOLTYPE = 16,                  /* BOOLTYPE  */
  YYSYMBOL_STRUCT = 17,                    /* STRUCT  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_REPEAT = 20,                    /* REPEAT  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_FROM = 23,                      /* FROM  */
  YYSYMBOL_TO = 24,                        /* TO  */
  YYSYMBOL_GIVEBACK = 25,                  /* GIVEBACK  */
  YYSYMBOL_READ = 26,                      /* READ  */
  YYSYMBOL_WRITE = 27,                     /* WRITE  */
  YYSYMBOL_FLOAT = 28,                     /* FLOAT  */
  YYSYMBOL_INT = 29,                       /* INT  */
  YYSYMBOL_BOOL = 30,                      /* BOOL  */
  YYSYMBOL_STRING = 31,                    /* STRING  */
  YYSYMBOL_PARENTHESEOUVRANTE = 32,        /* PARENTHESEOUVRANTE  */
  YYSYMBOL_PARENTHESEFERMANTE = 33,        /* PARENTHESEFERMANTE  */
  YYSYMBOL_ACCOLADEOUVRANTE = 34,          /* ACCOLADEOUVRANTE  */
  YYSYMBOL_ACCOLADEFERMANTE = 35,          /* ACCOLADEFERMANTE  */
  YYSYMBOL_CROCHETOUVRANT = 36,            /* CROCHETOUVRANT  */
  YYSYMBOL_CROCHETFERMANT = 37,            /* CROCHETFERMANT  */
  YYSYMBOL_ENDINST = 38,                   /* ENDINST  */
  YYSYMBOL_POINT = 39,                     /* POINT  */
  YYSYMBOL_VIRG = 40,                      /* VIRG  */
  YYSYMBOL_INC = 41,                       /* INC  */
  YYSYMBOL_DEC = 42,                       /* DEC  */
  YYSYMBOL_AFFECT = 43,                    /* AFFECT  */
  YYSYMBOL_NOTEQUALS = 44,                 /* NOTEQUALS  */
  YYSYMBOL_ADDEQUALS = 45,                 /* ADDEQUALS  */
  YYSYMBOL_SUBEQUALS = 46,                 /* SUBEQUALS  */
  YYSYMBOL_MULEQUALS = 47,                 /* MULEQUALS  */
  YYSYMBOL_DIVINTEQUALS = 48,              /* DIVINTEQUALS  */
  YYSYMBOL_DIVEQUALS = 49,                 /* DIVEQUALS  */
  YYSYMBOL_MODEQUALS = 50,                 /* MODEQUALS  */
  YYSYMBOL_POWEQUALS = 51,                 /* POWEQUALS  */
  YYSYMBOL_ADD = 52,                       /* ADD  */
  YYSYMBOL_SUB = 53,                       /* SUB  */
  YYSYMBOL_MUL = 54,                       /* MUL  */
  YYSYMBOL_MOD = 55,                       /* MOD  */
  YYSYMBOL_DIV = 56,                       /* DIV  */
  YYSYMBOL_INTDIV = 57,                    /* INTDIV  */
  YYSYMBOL_POW = 58,                       /* POW  */
  YYSYMBOL_NEG = 59,                       /* NEG  */
  YYSYMBOL_LESS = 60,                      /* LESS  */
  YYSYMBOL_LESSEQUALS = 61,                /* LESSEQUALS  */
  YYSYMBOL_GREATER = 62,                   /* GREATER  */
  YYSYMBOL_GREATEREQUALS = 63,             /* GREATEREQUALS  */
  YYSYMBOL_DOUBLEEQUALS = 64,              /* DOUBLEEQUALS  */
  YYSYMBOL_AND = 65,                       /* AND  */
  YYSYMBOL_OR = 66,                        /* OR  */
  YYSYMBOL_ID = 67,                        /* ID  */
  YYSYMBOL_HelloMain = 68,                 /* HelloMain  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_typeVAR = 70,                   /* typeVAR  */
  YYSYMBOL_ProgrammeFlamingo = 71,         /* ProgrammeFlamingo  */
  YYSYMBOL_Importationlib = 72,            /* Importationlib  */
  YYSYMBOL_FuncsDeclar = 73,               /* FuncsDeclar  */
  YYSYMBOL_FuncDeclar = 74,                /* FuncDeclar  */
  YYSYMBOL_CorFunc = 75,                   /* CorFunc  */
  YYSYMBOL_aumoinsInst = 76,               /* aumoinsInst  */
  YYSYMBOL_Inst = 77,                      /* Inst  */
  YYSYMBOL_CorMain = 78,                   /* CorMain  */
  YYSYMBOL_Parametres = 79,                /* Parametres  */
  YYSYMBOL_Parametre = 80,                 /* Parametre  */
  YYSYMBOL_Declar = 81,                    /* Declar  */
  YYSYMBOL_AffecType = 82,                 /* AffecType  */
  YYSYMBOL_Affec = 83,                     /* Affec  */
  YYSYMBOL_StructChamp = 84,               /* StructChamp  */
  YYSYMBOL_CorWhile = 85,                  /* CorWhile  */
  YYSYMBOL_Condition = 86,                 /* Condition  */
  YYSYMBOL_87_1 = 87,                      /* $@1  */
  YYSYMBOL_CorFor = 88,                    /* CorFor  */
  YYSYMBOL_ReadMethod = 89,                /* ReadMethod  */
  YYSYMBOL_WriteMethod = 90,               /* WriteMethod  */
  YYSYMBOL_ParamsWithoutVARTYPE = 91,      /* ParamsWithoutVARTYPE  */
  YYSYMBOL_CallMethod = 92,                /* CallMethod  */
  YYSYMBOL_CorIf = 93,                     /* CorIf  */
  YYSYMBOL_94_2 = 94,                      /* $@2  */
  YYSYMBOL_95_3 = 95,                      /* $@3  */
  YYSYMBOL_Alternate = 96,                 /* Alternate  */
  YYSYMBOL_comparaison = 97,               /* comparaison  */
  YYSYMBOL_expression = 98,                /* expression  */
  YYSYMBOL_terme = 99                      /* terme  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      80,    83,    84,    87,    88,    92,   109,   121,   125,   126,
     129,   130,   131,   132,   133,   134,   135,   136,   139,   146,
     147,   150,   158,   159,   160,   161,   162,   163,   174,   174,
     174,   178,   192,   195,   211,   211,   223,   227,   231,   235,
     243,   246,   259,   267,   268,   269,   293,   294,   317,   318,
     319,   322,   331,   349,   353,   349,   371,   378,   385,   389,
     390,   391,   392,   393,   394,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PACK", "FONCTION",
  "MAIN", "ExpressionHELLO", "CONST", "TYPE", "INTTYPE", "BIGINTTYPE",
  "LONGINTTYPE", "STRINGTYPE", "FLOATTYPE", "BIGFLOATTYPE",
  "LONGFLOATTYPE", "BOOLTYPE", "STRUCT", "IF", "ELSE", "REPEAT", "WHILE",
  "FOR", "FROM", "TO", "GIVEBACK", "READ", "WRITE", "FLOAT", "INT", "BOOL",
  "STRING", "PARENTHESEOUVRANTE", "PARENTHESEFERMANTE", "ACCOLADEOUVRANTE",
  "ACCOLADEFERMANTE", "CROCHETOUVRANT", "CROCHETFERMANT", "ENDINST",
  "POINT", "VIRG", "INC", "DEC", "AFFECT", "NOTEQUALS", "ADDEQUALS",
  "SUBEQUALS", "MULEQUALS", "DIVINTEQUALS", "DIVEQUALS", "MODEQUALS",
  "POWEQUALS", "ADD", "SUB", "MUL", "MOD", "DIV", "INTDIV", "POW", "NEG",
  "LESS", "LESSEQUALS", "GREATER", "GREATEREQUALS", "DOUBLEEQUALS", "AND",
  "OR", "ID", "HelloMain", "$accept", "typeVAR", "ProgrammeFlamingo",
  "Importationlib", "FuncsDeclar", "FuncDeclar", "CorFunc", "aumoinsInst",
  "Inst", "CorMain", "Parametres", "Parametre", "Declar", "AffecType",
  "Affec", "StructChamp", "CorWhile", "Condition", "$@1", "CorFor",
  "ReadMethod", "WriteMethod", "ParamsWithoutVARTYPE", "CallMethod",
  "CorIf", "$@2", "$@3", "Alternate", "comparaison", "expression", "terme", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-33)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,    -2,    31,    29,     6,   -70,     3,    37,    29,    25,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    15,   -31,
      21,   -70,   -70,   -70,   193,    30,    59,     9,    38,    33,
     193,    46,   -70,    49,   193,    52,    53,   164,   -70,    57,
     164,   193,    41,   -22,   -22,    86,    87,    93,    -9,    69,
     102,   -70,   116,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   164,   122,    91,   119,    -7,   -70,   -70,   127,   144,
     100,   101,     0,    -1,    40,   123,   -70,   -70,   134,   145,
     -70,   123,   -70,   135,   -22,   -26,   149,    22,   150,   166,
     154,   153,    99,   159,   161,   -70,   163,   -70,   -70,   -70,
      22,   133,   151,    77,    82,   156,   -70,   -70,   -70,   -70,
     158,   -70,   152,   118,   184,   -22,   -22,   164,    54,   187,
      60,   164,   192,   -70,     0,   155,   157,     0,     0,   -70,
     -70,   190,   -70,   -70,   -70,   -70,   -70,   -70,    22,   -70,
     -70,    22,    22,    22,    22,    22,    22,    22,   191,   -70,
     194,   -70,   195,   197,   198,   -70,    22,    22,    22,    22,
      22,    22,   199,   201,   -70,   200,   -70,   -70,   -70,   -70,
     202,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     203,   196,   -70,   208,   205,     0,     4,   -70,   206,   -70,
     164,   -70,   164,   207,   209,   -70,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      11,     0,     0,    13,     0,     1,     0,     0,    13,    11,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,    10,    14,    12,     0,     0,     0,     0,     0,    30,
       0,     0,    31,     0,     0,     0,     0,    32,    29,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,    20,    21,    23,    24,    25,    26,    27,
      22,    32,     0,     0,     0,     0,    49,    63,     0,     0,
       0,     0,     0,     0,     0,    37,    36,    16,    18,     0,
      28,     0,    35,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    55,    53,     0,    62,     0,    40,    85,    84,
       0,     0,     0,     0,     0,    86,    41,    38,    88,    39,
      76,    19,     0,     0,     0,     0,     0,    32,    86,     0,
       0,    32,     0,    51,     0,     0,     0,     0,     0,    52,
      61,     0,    93,    94,    91,    89,    92,    90,     0,    95,
      96,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,    46,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,    42,    57,    59,    75,
       0,    77,    78,    79,    81,    80,    82,    83,    15,    33,
      47,    48,    64,    70,    73,    74,    71,    72,    69,    43,
       0,    54,    87,    66,     0,     0,     0,    65,     0,    60,
      32,    68,    32,     0,     0,    67,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,    -4,   -70,   226,   233,   -70,   -60,   -29,   -70,   -70,
     -25,   -70,   -70,   -70,   -28,   169,   -70,   -38,   -70,   -70,
     -70,   -70,   -69,   -37,    50,   -70,   -70,   -70,   -70,   -44,
     -70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    49,     2,     3,     7,     8,    50,    51,    52,    21,
      28,    29,    53,   106,    54,    93,    55,    67,    68,    56,
      57,    58,    94,   108,    60,    86,   193,   197,   119,   109,
     110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    79,    19,    59,    96,    35,    69,    91,    91,    38,
      65,    62,    10,    11,    12,    13,    14,    15,    16,    17,
      27,    76,    43,    73,    59,    65,    27,    85,     1,     4,
      27,     5,    95,     6,    74,    82,    25,    63,   200,   115,
     116,    59,    20,   120,     9,    66,   114,    24,    97,   111,
      98,    99,    84,    26,   100,   164,   131,   154,   167,   168,
      66,   162,    30,   101,   102,    31,    92,    92,    98,    99,
      18,    33,   100,    34,   103,   104,    32,   152,   153,    36,
      59,   101,   102,    37,    59,    39,    73,    40,   150,   118,
     138,    61,   103,   104,   170,   139,   140,   171,   172,   173,
     174,   175,   176,   177,   156,   134,   135,   105,    64,    27,
     136,   137,   183,   184,   185,   186,   187,   188,    70,    71,
     157,   158,   159,   160,   161,    72,   199,    10,    11,    12,
      13,    14,    15,    16,    17,   125,    75,    77,   126,   127,
     203,    41,   204,    10,    11,    12,    13,    14,    15,    16,
      17,    42,    43,   149,    78,    44,    45,    80,    81,    87,
      46,    47,    83,    59,    88,    59,    74,    89,    90,   113,
     112,    41,   -32,    10,    11,    12,    13,    14,    15,    16,
      17,    42,    43,   117,   121,    44,    45,   123,    73,   122,
      46,    47,   138,   124,   129,   126,   130,   139,   140,   128,
     132,    48,    10,    11,    12,    13,    14,    15,    16,    17,
     141,   142,   143,   144,   145,   146,   147,   151,   133,   148,
     155,   163,   165,   169,   166,   190,   178,   196,   180,   179,
     181,    48,   194,   182,   189,    23,   195,   191,   198,   192,
     202,    22,   205,   107,   206,     0,   201
};

static const yytype_int16 yycheck[] =
{
      37,    61,     6,    40,    73,    30,    44,     8,     8,    34,
      32,    40,     9,    10,    11,    12,    13,    14,    15,    16,
      24,    49,    18,    32,    61,    32,    30,    65,     3,    31,
      34,     0,    33,     4,    43,    63,    67,    41,    34,    65,
      66,    78,     5,    87,    38,    67,    84,    32,     8,    78,
      28,    29,    59,    32,    32,   124,   100,   117,   127,   128,
      67,   121,    32,    41,    42,     6,    67,    67,    28,    29,
      67,    33,    32,    40,    52,    53,    67,   115,   116,    33,
     117,    41,    42,    34,   121,    33,    32,    34,   113,    67,
      36,    34,    52,    53,   138,    41,    42,   141,   142,   143,
     144,   145,   146,   147,    44,    28,    29,    67,    67,   113,
      28,    29,   156,   157,   158,   159,   160,   161,    32,    32,
      60,    61,    62,    63,    64,    32,   195,     9,    10,    11,
      12,    13,    14,    15,    16,    36,    67,    35,    39,    40,
     200,     7,   202,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    35,    38,    21,    22,    35,    67,    32,
      26,    27,    43,   200,    20,   202,    43,    67,    67,    34,
      25,     7,    38,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    34,    34,    21,    22,    33,    32,    23,
      26,    27,    36,    40,    33,    39,    33,    41,    42,    40,
      67,    67,     9,    10,    11,    12,    13,    14,    15,    16,
      52,    53,    54,    55,    56,    57,    58,    33,    67,    67,
      33,    29,    67,    33,    67,    24,    35,    19,    33,    35,
      33,    67,    29,    35,    35,     9,    40,    37,    33,    37,
      34,     8,    35,    74,    35,    -1,   196
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    71,    72,    31,     0,     4,    73,    74,    38,
       9,    10,    11,    12,    13,    14,    15,    16,    67,    70,
       5,    78,    73,    72,    32,    67,    32,    70,    79,    80,
      32,     6,    67,    33,    40,    79,    33,    34,    79,    33,
      34,     7,    17,    18,    21,    22,    26,    27,    67,    70,
      75,    76,    77,    81,    83,    85,    88,    89,    90,    92,
      93,    34,    76,    70,    67,    32,    67,    86,    87,    86,
      32,    32,    32,    32,    43,    67,    83,    35,    38,    75,
      35,    67,    83,    43,    59,    86,    94,    32,    20,    67,
      67,     8,    67,    84,    91,    33,    91,     8,    28,    29,
      32,    41,    42,    52,    53,    67,    82,    84,    92,    98,
      99,    76,    25,    34,    86,    65,    66,    34,    67,    97,
      98,    34,    23,    33,    40,    36,    39,    40,    40,    33,
      33,    98,    67,    67,    28,    29,    28,    29,    36,    41,
      42,    52,    53,    54,    55,    56,    57,    58,    67,    35,
      79,    33,    86,    86,    75,    33,    44,    60,    61,    62,
      63,    64,    75,    29,    91,    67,    67,    91,    91,    33,
      98,    98,    98,    98,    98,    98,    98,    98,    35,    35,
      33,    33,    35,    98,    98,    98,    98,    98,    98,    35,
      24,    37,    37,    95,    29,    40,    19,    96,    33,    91,
      34,    93,    34,    75,    75,    35,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    72,    72,    73,    73,    74,    74,    75,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    79,
      79,    80,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    83,    84,    85,    87,    86,    86,    86,    86,    86,
      88,    89,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    92,    92,    94,    95,    93,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     4,     0,     2,    11,     8,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     7,     3,
       1,     2,     0,     6,     5,     3,     2,     2,     1,     1,
       1,     3,     3,     6,     0,     4,     4,     5,     5,     1,
      11,     4,     4,     1,     4,     1,     1,     3,     3,     3,
       6,     4,     3,     0,     0,     8,     0,     4,     2,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     4,     1,     2,
       2,     2,     2,     2,     2,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 15: /* FuncDeclar: FONCTION typeVAR ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc GIVEBACK ID ACCOLADEFERMANTE  */
#line 93 "yacc.y"
    {
        NodeSymbole *symbole = search(symboleTable, (char*)yyvsp[-8]);
        if (symbole != NULL) {
            yyerror("Function already declared");
        }
        insertSymbole(symboleTable, (char*)yyvsp[-8], Fonction, yyvsp[-9]);
        current_function = symbole;
        cpt_param = 0;
        NodeAttribut *searchedAttr = searchAttributByName(symbole, (char*)yyvsp[-1]);
        if (searchedAttr == NULL) {
            yyerror("Return type variable not declared");
        }
        if (!areTypesCompatible(searchedAttr->type, symbole->type)) {
            yyerror("Type mismatch in return type");
        }
    }
#line 1371 "yacc.tab.c"
    break;

  case 16: /* FuncDeclar: FONCTION ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE  */
#line 110 "yacc.y"
    {
        NodeSymbole *symbole = search(symboleTable, (char*)yyvsp[-6]);
        if (symbole != NULL) {
            yyerror("Function already declared");
        }
        insertSymbole(symboleTable, (char*)yyvsp[-6], Fonction, NULLL);
        current_function = symbole;
    }
#line 1384 "yacc.tab.c"
    break;

  case 28: /* CorMain: MAIN PARENTHESEOUVRANTE ExpressionHELLO PARENTHESEFERMANTE ACCOLADEOUVRANTE aumoinsInst ACCOLADEFERMANTE  */
#line 140 "yacc.y"
    {
        current_function = NULL;
    }
#line 1392 "yacc.tab.c"
    break;

  case 31: /* Parametre: typeVAR ID  */
#line 151 "yacc.y"
    {
        if (current_function != NULL) {
            addParam(current_function, (char*)yyvsp[0], yyvsp[-1]);
        }
    }
#line 1402 "yacc.tab.c"
    break;

  case 37: /* Declar: typeVAR ID  */
#line 164 "yacc.y"
    {
        if (current_function != NULL) {
            setAttribut(current_function, (char*)yyvsp[0], yyvsp[-1], NULL);
        } else {
            NodeSymbole *sym1 = insertSymbole(symboleTable, (char*)yyvsp[0], Attsimple, yyvsp[-1]);
        }
    }
#line 1414 "yacc.tab.c"
    break;

  case 41: /* Affec: ID AFFECT AffecType  */
#line 179 "yacc.y"
    {
        verifierExistance((char*)yyvsp[-2]);
        Type varType = getTypeByID(symboleTable, (char*)yyvsp[-2]);
        Type assignedType = getTypeOfExpression((char*)yyvsp[0]);
        if (!areTypesCompatible(varType, assignedType)) {
            yyerror("Incompatibilité de type dans l'affectation à la variable");
        }
        insererQuadreplet(&q, "AFFECT", (char*)yyvsp[0], "", (char*)yyvsp[-2], qc);
        qc++;
    }
#line 1429 "yacc.tab.c"
    break;

  case 43: /* CorWhile: WHILE Condition REPEAT ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE  */
#line 195 "yacc.y"
                                                                           {
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
#line 1448 "yacc.tab.c"
    break;

  case 44: /* $@1: %empty  */
#line 211 "yacc.y"
           {
    empiler(stack, qc);  // Point de retour de la boucle
}
#line 1456 "yacc.tab.c"
    break;

  case 45: /* Condition: $@1 PARENTHESEOUVRANTE comparaison PARENTHESEFERMANTE  */
#line 218 "yacc.y"
                                                  {
    insererQuadreplet(&q, "BZ", "tmp", "", "", qc);
    empiler(stack, qc);
    qc++;
}
#line 1466 "yacc.tab.c"
    break;

  case 46: /* Condition: PARENTHESEOUVRANTE NEG Condition PARENTHESEFERMANTE  */
#line 223 "yacc.y"
                                                      {
    insererQuadreplet(&q, "NOT", "", "", "tmp", qc);
    qc++;
}
#line 1475 "yacc.tab.c"
    break;

  case 47: /* Condition: PARENTHESEOUVRANTE Condition AND Condition PARENTHESEFERMANTE  */
#line 227 "yacc.y"
                                                                {
    insererQuadreplet(&q, "AND", "", "", "tmp", qc);
    qc++;
}
#line 1484 "yacc.tab.c"
    break;

  case 48: /* Condition: PARENTHESEOUVRANTE Condition OR Condition PARENTHESEFERMANTE  */
#line 231 "yacc.y"
                                                               {
    insererQuadreplet(&q, "OR", "", "", "tmp", qc);
    qc++;
}
#line 1493 "yacc.tab.c"
    break;

  case 49: /* Condition: ID  */
#line 235 "yacc.y"
     {
    NodeSymbole *symbole = search(symboleTable, (char*)yyvsp[0]);
    if (symbole == NULL || symbole->type != BOOLTYPE) {
        yyerror("Invalid boolean variable");
    }
}
#line 1504 "yacc.tab.c"
    break;

  case 51: /* ReadMethod: READ PARENTHESEOUVRANTE ID PARENTHESEFERMANTE  */
#line 247 "yacc.y"
{
  if (current_function != NULL){
    NodeAttribut *searchedAttr = searchAttributByName(current_function, (char*)yyvsp[-1]);
if (searchedAttr==NULL)
{
    yyerror("id not declared ");
}
    }
    else{
  verifierExistance((char*)yyvsp[-1]);
    }
}
#line 1521 "yacc.tab.c"
    break;

  case 52: /* WriteMethod: WRITE PARENTHESEOUVRANTE ParamsWithoutVARTYPE PARENTHESEFERMANTE  */
#line 260 "yacc.y"
{
    write=1;
}
#line 1529 "yacc.tab.c"
    break;

  case 55: /* ParamsWithoutVARTYPE: ID  */
#line 270 "yacc.y"
    {
        if(!cpt_param==countParams(current_call))
        {
            yyerror("nombre de paramaitre invalide");
        }
       if(write){
          if (current_function != NULL)
               {
              NodeAttribut *searchedAttr = searchAttributByName(current_function, (char*)yyvsp[0]);
              if (searchedAttr==NULL)
             { yyerror("id not declared ");} 
             }
          else{ verifierExistance((char*)yyvsp[0]); }}

        else{
Type type1 =getTypeOfParamByIndex(current_call, cpt_param);
Type type2= getTypeByID(symboleTable,(char*)yyvsp[0] );
if(!areTypesCompatible(type1,type2)){
  yyerror("type incompatible");
}
        }
    }
#line 1556 "yacc.tab.c"
    break;

  case 57: /* ParamsWithoutVARTYPE: ID VIRG ParamsWithoutVARTYPE  */
#line 295 "yacc.y"
    {
      if(cpt_param){
            cpt_param++;
        }

             if(write){
          if (current_function != NULL){
              NodeAttribut *searchedAttr = searchAttributByName(current_function, (char*)yyvsp[-2]);
              if (searchedAttr==NULL)
             { yyerror("id not declared ");} }

          else{ verifierExistance((char*)yyvsp[-2]); }}
        else{
Type type1 =getTypeOfParamByIndex(current_call, cpt_param);
Type type2= getTypeByID(symboleTable,(char*)yyvsp[-2] );
if(!areTypesCompatible(type1,type2)){
  yyerror("type incompatible");
}
        }

    }
#line 1582 "yacc.tab.c"
    break;

  case 61: /* CallMethod: ID PARENTHESEOUVRANTE ParamsWithoutVARTYPE PARENTHESEFERMANTE  */
#line 323 "yacc.y"
{
current_call=search(symboleTable,(char*)yyvsp[-3]);
if(!current_call)
    {
        yyerror("fonction non declaré");
    }
    write=0;
}
#line 1595 "yacc.tab.c"
    break;

  case 62: /* CallMethod: ID PARENTHESEOUVRANTE PARENTHESEFERMANTE  */
#line 332 "yacc.y"
{
current_call=search(symboleTable,(char*)yyvsp[-2]);
 if(!current_call)
    {
        yyerror("fonction non declaré");
    }
    write=0;
}
#line 1608 "yacc.tab.c"
    break;

  case 63: /* $@2: %empty  */
#line 349 "yacc.y"
                    {
    insererQuadreplet(&q, "BZ", "tmp", "", "", qc);
    empiler(stack, qc);  // Empile addrBZ
    qc++;
}
#line 1618 "yacc.tab.c"
    break;

  case 64: /* $@3: %empty  */
#line 353 "yacc.y"
                                            {
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
}
#line 1638 "yacc.tab.c"
    break;

  case 66: /* Alternate: %empty  */
#line 371 "yacc.y"
           {
        // Cas sans ELSE : on récupère et met à jour le BR pour qu'il pointe ici
        char adresse[10];
        sprintf(adresse, "%d", qc);
        int addrBR = depiler(stack);
        updateQuadreplet(q, addrBR, adresse);
    }
#line 1650 "yacc.tab.c"
    break;

  case 67: /* Alternate: ELSE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE  */
#line 378 "yacc.y"
                                                     {
        // Cas avec ELSE : on récupère et met à jour le BR pour qu'il pointe ici
        char adresse[10];
        sprintf(adresse, "%d", qc);
        int addrBR = depiler(stack);
        updateQuadreplet(q, addrBR, adresse);
    }
#line 1662 "yacc.tab.c"
    break;


#line 1666 "yacc.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 430 "yacc.y"

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
