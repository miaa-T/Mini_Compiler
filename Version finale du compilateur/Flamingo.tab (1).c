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
#line 3 "Flamingo.y"

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

#line 118 "Flamingo.tab.c"

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

#include "Flamingo.tab.h"
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
  YYSYMBOL_HelloMain = 6,                  /* HelloMain  */
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
  YYSYMBOL_YYACCEPT = 68,                  /* $accept  */
  YYSYMBOL_typeVAR = 69,                   /* typeVAR  */
  YYSYMBOL_ProgrammeFlamingo = 70,         /* ProgrammeFlamingo  */
  YYSYMBOL_Importationlib = 71,            /* Importationlib  */
  YYSYMBOL_FuncsDeclar = 72,               /* FuncsDeclar  */
  YYSYMBOL_FuncDeclar = 73,                /* FuncDeclar  */
  YYSYMBOL_CorFunc = 74,                   /* CorFunc  */
  YYSYMBOL_aumoinsInst = 75,               /* aumoinsInst  */
  YYSYMBOL_Inst = 76,                      /* Inst  */
  YYSYMBOL_CorMain = 77,                   /* CorMain  */
  YYSYMBOL_Parametres = 78,                /* Parametres  */
  YYSYMBOL_Parametre = 79,                 /* Parametre  */
  YYSYMBOL_Declar = 80,                    /* Declar  */
  YYSYMBOL_AffecType = 81,                 /* AffecType  */
  YYSYMBOL_Affec = 82,                     /* Affec  */
  YYSYMBOL_StructChamp = 83,               /* StructChamp  */
  YYSYMBOL_CorIf = 84,                     /* CorIf  */
  YYSYMBOL_85_1 = 85,                      /* $@1  */
  YYSYMBOL_86_2 = 86,                      /* $@2  */
  YYSYMBOL_Alternate = 87,                 /* Alternate  */
  YYSYMBOL_CorWhile = 88,                  /* CorWhile  */
  YYSYMBOL_89_3 = 89,                      /* $@3  */
  YYSYMBOL_90_4 = 90,                      /* $@4  */
  YYSYMBOL_CorFor = 91,                    /* CorFor  */
  YYSYMBOL_ReadMethod = 92,                /* ReadMethod  */
  YYSYMBOL_WriteMethod = 93,               /* WriteMethod  */
  YYSYMBOL_ParamsWrite = 94,               /* ParamsWrite  */
  YYSYMBOL_ParamsWithoutVARTYPE = 95,      /* ParamsWithoutVARTYPE  */
  YYSYMBOL_CallMethod = 96,                /* CallMethod  */
  YYSYMBOL_Condition = 97,                 /* Condition  */
  YYSYMBOL_comparaison = 98,               /* comparaison  */
  YYSYMBOL_expression = 99,                /* expression  */
  YYSYMBOL_terme = 100                     /* terme  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 136 "Flamingo.y"

extern FILE *yyin;
extern int yylineno;
extern int yyleng;
extern int yylex();

/*char* file = "test2.txt";*/


void termeSuiv(char *s);
extern void yyerror(const char *s);
extern void showLexicalError();

#line 266 "Flamingo.tab.c"


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

#if 1

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
#endif /* 1 */

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
#define YYLAST   340

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


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
      65,    66,    67
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   151,   151,   152,   153,   154,   156,   158,   159,   162,
     166,   169,   188,   200,   217,   229,   232,   235,   236,   238,
     239,   240,   241,   242,   243,   244,   245,   247,   254,   255,
     257,   264,   265,   266,   267,   268,   269,   280,   281,   282,
     283,   284,   285,   289,   297,   298,   299,   301,   305,   310,
     305,   323,   329,   335,   337,   341,   337,   364,   365,   366,
     367,   368,   369,   370,   373,   374,   375,   376,   380,   381,
     382,   383,   384,   385,   386,   387,   389,   390,   394,   395,
     396,   397,   398,   403,   404,   405,   406,   407,   408,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PACK", "FONCTION",
  "MAIN", "HelloMain", "CONST", "TYPE", "INTTYPE", "BIGINTTYPE",
  "LONGINTTYPE", "STRINGTYPE", "FLOATTYPE", "BIGFLOATTYPE",
  "LONGFLOATTYPE", "BOOLTYPE", "STRUCT", "IF", "ELSE", "REPEAT", "WHILE",
  "FOR", "FROM", "TO", "GIVEBACK", "READ", "WRITE", "FLOAT", "INT", "BOOL",
  "STRING", "PARENTHESEOUVRANTE", "PARENTHESEFERMANTE", "ACCOLADEOUVRANTE",
  "ACCOLADEFERMANTE", "CROCHETOUVRANT", "CROCHETFERMANT", "ENDINST",
  "POINT", "VIRG", "INC", "DEC", "AFFECT", "NOTEQUALS", "ADDEQUALS",
  "SUBEQUALS", "MULEQUALS", "DIVINTEQUALS", "DIVEQUALS", "MODEQUALS",
  "POWEQUALS", "ADD", "SUB", "MUL", "MOD", "DIV", "INTDIV", "POW", "NEG",
  "LESS", "LESSEQUALS", "GREATER", "GREATEREQUALS", "DOUBLEEQUALS", "AND",
  "OR", "ID", "$accept", "typeVAR", "ProgrammeFlamingo", "Importationlib",
  "FuncsDeclar", "FuncDeclar", "CorFunc", "aumoinsInst", "Inst", "CorMain",
  "Parametres", "Parametre", "Declar", "AffecType", "Affec", "StructChamp",
  "CorIf", "$@1", "$@2", "Alternate", "CorWhile", "$@3", "$@4", "CorFor",
  "ReadMethod", "WriteMethod", "ParamsWrite", "ParamsWithoutVARTYPE",
  "CallMethod", "Condition", "comparaison", "expression", "terme", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-83)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,    -6,   124,   128,    88,  -116,    28,   133,   128,    18,
    -116,  -116,  -116,  -116,   111,    79,   115,  -116,  -116,  -116,
      50,   119,   146,   136,    89,   141,   126,    52,   142,   132,
    -116,   143,   280,   145,   148,   152,   280,    98,   -13,  -116,
     144,   156,   162,   125,   134,   165,  -116,   160,  -116,  -116,
     174,  -116,  -116,  -116,  -116,  -116,  -116,   132,  -116,   132,
     172,   132,   158,   180,   190,  -116,  -116,   -13,   159,   168,
       8,     3,   173,   179,   161,    67,  -116,  -116,    60,   163,
     194,   183,   132,   204,    67,  -116,   193,  -116,  -116,   190,
     181,   186,    29,    51,   -13,   131,  -116,    26,   221,   208,
     245,   222,   235,   237,   225,   234,   238,    54,   244,   122,
     242,  -116,   254,   251,  -116,  -116,   256,   192,   241,  -116,
    -116,   257,  -116,  -116,  -116,  -116,   239,   279,  -116,    11,
     203,  -116,  -116,  -116,  -116,  -116,  -116,   272,   192,  -116,
    -116,   -13,   -13,  -116,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   132,   273,   -19,
    -116,     7,     8,   243,     7,     7,  -116,     8,  -116,  -116,
     265,    93,   276,   209,   277,   246,  -116,   281,  -116,  -116,
     274,   282,   284,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,   283,  -116,   290,   295,
    -116,  -116,  -116,   285,  -116,  -116,  -116,   163,   249,  -116,
     286,  -116,  -116,  -116,  -116,  -116,   132,   -16,   -12,  -116,
    -116,  -116,  -116,   301,   288,   291,   292,   293,   294,    70,
    -116,  -116,   296,   297,   298,   299,   132,  -116,   132,   132,
     132,   132,   300,   302,   303,   304,   305,  -116,  -116,  -116,
    -116,  -116
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       8,     0,     0,    15,     0,     1,     0,     0,    10,     8,
       2,     4,     3,     5,     0,     0,     0,     6,     9,     7,
       0,     0,     0,     0,     0,     0,    29,     0,     0,    31,
      30,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,    16,     0,    19,    20,
       0,    21,    22,    23,    24,    25,    26,    31,    28,    31,
       0,    31,     0,     0,     0,    82,    48,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    35,    14,    17,     0,
       0,     0,    31,     0,     0,    34,     0,    99,    98,     0,
       0,     0,     0,     0,     0,   100,   102,     0,     0,     0,
      90,     0,     0,     0,     0,    71,    65,    70,    68,     0,
      64,    77,     0,     0,    47,    42,    98,     0,   100,    44,
      38,   102,    41,    18,    45,    12,     0,     0,    27,     0,
       0,   107,   108,   105,   103,   106,   104,     0,     0,   109,
     110,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
      61,     0,     0,     0,     0,     0,    63,     0,    62,    76,
       0,   100,     0,     0,     0,     0,    33,     0,    89,    79,
       0,     0,     0,    84,    87,    88,    85,    86,    83,    91,
      92,    93,    95,    94,    96,    97,     0,    55,     0,     0,
      73,    66,    64,     0,    72,    74,    67,     0,   100,    13,
       0,    32,   101,    80,    81,    49,    31,     0,     0,    69,
      46,    39,    11,    51,     0,     0,     0,     0,     0,     0,
      50,    56,     0,     0,     0,     0,    31,    53,    31,    31,
      31,    31,     0,     0,     0,     0,     0,    52,    57,    58,
      59,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,     2,  -116,   319,   321,  -116,   -56,   -43,  -116,  -116,
     -20,  -116,  -116,   -77,    27,   -65,   105,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -115,   -28,   -29,   -34,
    -116,   -33,  -116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    44,     2,     3,     7,     8,    45,    46,    47,    17,
      25,    26,    48,   119,    49,    50,    51,   101,   223,   230,
      52,    67,   216,    53,    54,    55,   109,   202,    96,    97,
      98,   122,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    80,   124,    81,    66,   108,   108,    34,    15,   120,
     198,   105,    58,   225,   120,   105,   105,   227,    83,    64,
      10,     1,    24,    11,    12,     4,   127,    13,    56,    24,
      56,    99,    56,   102,    24,   123,   111,    10,    62,   106,
      11,    12,   110,   112,    13,   121,   176,   201,   199,    56,
     121,   226,   206,    56,    65,   228,   130,   133,   134,    10,
     137,    10,    11,    12,    11,    12,    13,    36,    13,    10,
     107,    76,    11,    12,   107,   107,    13,    37,    38,   135,
     136,    39,    40,    23,   172,    33,    41,    42,    38,    85,
     163,   141,   142,    73,   164,    14,   108,   108,   -31,   108,
     108,   196,   108,    72,   236,   180,    73,   181,   182,   177,
      74,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     5,    71,     9,    43,    56,   138,
     220,    24,     6,   200,   139,   140,   204,   205,    16,    36,
     180,    10,   120,    20,    11,    12,    21,    22,    13,    37,
      38,    27,    28,    39,    40,   166,    30,    71,    41,    42,
     224,    72,   167,    71,    73,    63,    32,   138,    74,   115,
      29,   115,   139,   140,    31,    35,    68,    57,   121,    59,
     242,    60,   243,   244,   245,   246,    61,    56,    69,    87,
     116,    87,    88,   117,    70,   117,   -82,   -82,    78,    43,
      77,    75,    90,    91,    90,    91,    82,    56,   126,    56,
      56,    56,    56,    92,    93,    92,    93,    79,    87,    88,
      87,    88,    89,    86,   117,    84,   103,   129,   118,   125,
     118,    90,    91,    90,    91,   104,   178,    87,    88,   128,
     113,   117,    92,    93,    92,    93,   114,   144,   131,    94,
      90,    91,   144,   132,   143,   158,   157,    95,   160,   171,
     159,    92,    93,   145,   146,   147,   148,   149,   145,   146,
     147,   148,   149,    71,   161,   168,   208,   173,   162,   -37,
      73,    71,   139,   140,   165,   138,   221,   169,   170,    10,
     139,   140,    11,    12,   -43,   -40,    13,   150,   151,   152,
     153,   154,   155,   156,   175,   179,   174,   197,   207,   178,
     203,   212,   209,   210,   217,   213,   211,   214,   215,   218,
     229,   222,   219,   231,   232,   233,   234,   235,    19,    18,
     238,   239,   240,   241,   237,   247,     0,   248,   249,   250,
     251
};

static const yytype_int16 yycheck[] =
{
      29,    57,    79,    59,    38,    70,    71,    27,     6,    74,
      29,     8,    32,    29,    79,     8,     8,    29,    61,    32,
       9,     3,    20,    12,    13,    31,    82,    16,    57,    27,
      59,    64,    61,    67,    32,    78,    33,     9,    36,    31,
      12,    13,    70,    71,    16,    74,    35,   162,    67,    78,
      79,    67,   167,    82,    67,    67,    89,    28,    29,     9,
      94,     9,    12,    13,    12,    13,    16,     7,    16,     9,
      67,    44,    12,    13,    67,    67,    16,    17,    18,    28,
      29,    21,    22,    33,   117,    33,    26,    27,    18,    62,
      36,    65,    66,    39,    40,    67,   161,   162,    38,   164,
     165,   157,   167,    36,    34,   138,    39,   141,   142,   129,
      43,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,    32,    38,    67,   157,    36,
     207,   129,     4,   161,    41,    42,   164,   165,     5,     7,
     173,     9,   207,    32,    12,    13,    67,    32,    16,    17,
      18,    32,     6,    21,    22,    33,    67,    32,    26,    27,
     216,    36,    40,    32,    39,    67,    40,    36,    43,     8,
      34,     8,    41,    42,    33,    33,    32,    34,   207,    34,
     236,    33,   238,   239,   240,   241,    34,   216,    32,    28,
      29,    28,    29,    32,    32,    32,    65,    66,    38,    67,
      35,    67,    41,    42,    41,    42,    34,   236,    25,   238,
     239,   240,   241,    52,    53,    52,    53,    43,    28,    29,
      28,    29,    32,    43,    32,    67,    67,    34,    67,    35,
      67,    41,    42,    41,    42,    67,    33,    28,    29,    35,
      67,    32,    52,    53,    52,    53,    67,    44,    67,    59,
      41,    42,    44,    67,    33,    20,    34,    67,    33,    67,
      23,    52,    53,    60,    61,    62,    63,    64,    60,    61,
      62,    63,    64,    32,    40,    33,    67,    36,    40,    38,
      39,    32,    41,    42,    40,    36,    37,    33,    37,     9,
      41,    42,    12,    13,    38,    38,    16,    52,    53,    54,
      55,    56,    57,    58,    25,    33,    67,    34,    43,    33,
      67,    37,    35,    67,    24,    33,    35,    33,    35,    24,
      19,    35,    37,    35,    33,    33,    33,    33,     9,     8,
      34,    34,    34,    34,   229,    35,    -1,    35,    35,    35,
      35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    70,    71,    31,     0,     4,    72,    73,    38,
       9,    12,    13,    16,    67,    69,     5,    77,    72,    71,
      32,    67,    32,    33,    69,    78,    79,    32,     6,    34,
      67,    33,    40,    33,    78,    33,     7,    17,    18,    21,
      22,    26,    27,    67,    69,    74,    75,    76,    80,    82,
      83,    84,    88,    91,    92,    93,    96,    34,    78,    34,
      33,    34,    69,    67,    32,    67,    97,    89,    32,    32,
      32,    32,    36,    39,    43,    67,    82,    35,    38,    43,
      74,    74,    34,    75,    67,    82,    43,    28,    29,    32,
      41,    42,    52,    53,    59,    67,    96,    97,    98,    99,
     100,    85,    97,    67,    67,     8,    31,    67,    83,    94,
      95,    33,    95,    67,    67,     8,    29,    32,    67,    81,
      83,    96,    99,    75,    81,    35,    25,    74,    35,    34,
      99,    67,    67,    28,    29,    28,    29,    97,    36,    41,
      42,    65,    66,    33,    44,    60,    61,    62,    63,    64,
      52,    53,    54,    55,    56,    57,    58,    34,    20,    23,
      33,    40,    40,    36,    40,    40,    33,    40,    33,    33,
      37,    67,    99,    36,    67,    25,    35,    78,    33,    33,
      99,    97,    97,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    74,    34,    29,    67,
      95,    94,    95,    67,    95,    95,    94,    43,    67,    35,
      67,    35,    37,    33,    33,    35,    90,    24,    24,    37,
      81,    37,    35,    86,    74,    29,    67,    29,    67,    19,
      87,    35,    33,    33,    33,    33,    34,    84,    34,    34,
      34,    34,    74,    74,    74,    74,    74,    35,    35,    35,
      35,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    69,    69,    69,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    78,    78,
      79,    80,    80,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    82,    83,    85,    86,
      84,    87,    87,    87,    89,    90,    88,    91,    91,    91,
      91,    92,    93,    93,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    97,    97,
      97,    97,    97,    98,    98,    98,    98,    98,    98,    99,
      99,    99,    99,    99,    99,    99,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     4,     0,     2,
       1,    11,     8,    10,     7,     0,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     7,     3,     1,
       2,     0,     6,     5,     3,     2,     2,     1,     1,     4,
       1,     1,     1,     3,     3,     3,     6,     3,     0,     0,
       8,     0,     4,     2,     0,     0,     8,    11,    11,    11,
      11,     4,     4,     4,     1,     1,     3,     3,     1,     4,
       1,     1,     3,     3,     3,     6,     4,     3,     3,     4,
       5,     5,     1,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     4,     1,     2,     2,     2,     2,     2,     2,     2,
       2
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* typeVAR: INTTYPE  */
#line 151 "Flamingo.y"
        { (yyval.type) = 0; }
#line 1681 "Flamingo.tab.c"
    break;

  case 3: /* typeVAR: FLOATTYPE  */
#line 152 "Flamingo.y"
                { (yyval.type) = 1; }
#line 1687 "Flamingo.tab.c"
    break;

  case 4: /* typeVAR: STRINGTYPE  */
#line 153 "Flamingo.y"
                 { (yyval.type) = 2; }
#line 1693 "Flamingo.tab.c"
    break;

  case 5: /* typeVAR: BOOLTYPE  */
#line 154 "Flamingo.y"
               { (yyval.type) = 3; }
#line 1699 "Flamingo.tab.c"
    break;

  case 9: /* FuncsDeclar: FuncDeclar FuncsDeclar  */
#line 163 "Flamingo.y"
    {
        printf("hello am in ..");
    }
#line 1707 "Flamingo.tab.c"
    break;

  case 11: /* FuncDeclar: FONCTION typeVAR ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc GIVEBACK ID ACCOLADEFERMANTE  */
#line 170 "Flamingo.y"
{

  NodeSymbole *symbole = search(symboleTable, (yyvsp[-8].identifier));
        if (symbole != NULL) {
            yyerror("Function already declared");
        } 
        insertSymbole(symboleTable, (yyvsp[-8].identifier), Fonction, (yyvsp[-9].type));
symbole=search(symboleTable, (yyvsp[-8].identifier));
        current_function = symbole;
               cpt_param = 0;
        NodeAttribut *searchedAttr = searchAttributByName(symbole, (yyvsp[-1].identifier));
        if (searchedAttr != NULL) {
       if (!(searchedAttr->type== symbole->type)) {
            yyerror("Type mismatch in return type");
        }}

      
}
#line 1730 "Flamingo.tab.c"
    break;

  case 12: /* FuncDeclar: FONCTION ID PARENTHESEOUVRANTE Parametres PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE  */
#line 189 "Flamingo.y"
    {
 NodeSymbole *symbole = search(symboleTable, (yyvsp[-6].identifier));
        if (symbole != NULL) {
            yyerror("Function already declared");
        } 
        insertSymbole(symboleTable, (yyvsp[-6].identifier), Fonction, -1);
symbole=search(symboleTable, (yyvsp[-6].identifier));
        current_function = symbole;
    

    }
#line 1746 "Flamingo.tab.c"
    break;

  case 13: /* FuncDeclar: FONCTION typeVAR ID PARENTHESEOUVRANTE PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc GIVEBACK ID ACCOLADEFERMANTE  */
#line 201 "Flamingo.y"
    {
 NodeSymbole *symbole = search(symboleTable, (yyvsp[-7].identifier));
        if (symbole != NULL) {
            yyerror("Function already declared");
        } 
        insertSymbole(symboleTable, (yyvsp[-7].identifier), Fonction, (yyvsp[-8].type));
symbole=search(symboleTable, (yyvsp[-7].identifier));
        current_function = symbole;
               cpt_param = 0;
        NodeAttribut *searchedAttr = searchAttributByName(symbole, (yyvsp[-1].identifier));
        if (searchedAttr != NULL) {
       if (!(searchedAttr->type== symbole->type)) {
            yyerror("Type mismatch in return type");
        }}

    }
#line 1767 "Flamingo.tab.c"
    break;

  case 14: /* FuncDeclar: FONCTION ID PARENTHESEOUVRANTE PARENTHESEFERMANTE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE  */
#line 218 "Flamingo.y"
    {
NodeSymbole *symbole = search(symboleTable, (yyvsp[-5].identifier));
        if (symbole != NULL) {
            yyerror("Function already declared");
        } 
        insertSymbole(symboleTable, (yyvsp[-5].identifier), Fonction, -1);
symbole=search(symboleTable, (yyvsp[-5].identifier));
        current_function = symbole;
    

    }
#line 1783 "Flamingo.tab.c"
    break;

  case 27: /* CorMain: MAIN PARENTHESEOUVRANTE HelloMain PARENTHESEFERMANTE ACCOLADEOUVRANTE aumoinsInst ACCOLADEFERMANTE  */
#line 248 "Flamingo.y"
      {
      
        current_function = NULL;
    }
#line 1792 "Flamingo.tab.c"
    break;

  case 30: /* Parametre: typeVAR ID  */
#line 258 "Flamingo.y"
   {
        if (current_function != NULL) {
            addParam(current_function, (yyvsp[0].identifier), (yyvsp[-1].type));
        }
    }
#line 1802 "Flamingo.tab.c"
    break;

  case 36: /* Declar: typeVAR ID  */
#line 270 "Flamingo.y"
    {
        if (current_function != NULL) {
            setAttribut(current_function, (yyvsp[0].identifier), (yyvsp[-1].type), NULL);
        } else {
            NodeSymbole *sym1 = insertSymbole(symboleTable, (char*)(yyvsp[0].identifier), Attsimple, (yyvsp[-1].type));
        }
    }
#line 1814 "Flamingo.tab.c"
    break;

  case 43: /* Affec: ID AFFECT INT  */
#line 290 "Flamingo.y"
    {
    char strr[12]; 

    sprintf(strr, "%d", (yyvsp[0].integerValue)); 
        insererQuadreplet(&q, "AFFECT", strr, "", (yyvsp[-2].identifier), qc);
        qc++;
    }
#line 1826 "Flamingo.tab.c"
    break;

  case 48: /* $@1: %empty  */
#line 305 "Flamingo.y"
                    {	
    insererQuadreplet(&q, "BZ", "tmp", "", "", qc);
    empiler(stack, qc); 
    
    qc++;
}
#line 1837 "Flamingo.tab.c"
    break;

  case 49: /* $@2: %empty  */
#line 310 "Flamingo.y"
                                            {

        int addrBR = depiler(stack); 
  char adresse[10];
    sprintf(adresse, "%d", qc);
      updateQuadreplet(q, addrBR, adresse);

    insererQuadreplet(&q, "BR", "", "", "", qc);
    empiler(stack, qc);  // Empile addrBR
    qc++;
}
#line 1853 "Flamingo.tab.c"
    break;

  case 51: /* Alternate: %empty  */
#line 323 "Flamingo.y"
           {
        char adresse[10];
        sprintf(adresse, "%d", qc);
        int addrBR = depiler(stack);
        updateQuadreplet(q, addrBR, adresse);
    }
#line 1864 "Flamingo.tab.c"
    break;

  case 52: /* Alternate: ELSE ACCOLADEOUVRANTE CorFunc ACCOLADEFERMANTE  */
#line 329 "Flamingo.y"
                                                     {
        char adresse[10];
        sprintf(adresse, "%d", qc);
        int addrBR = depiler(stack);
        updateQuadreplet(q, addrBR, adresse);
    }
#line 1875 "Flamingo.tab.c"
    break;

  case 54: /* $@3: %empty  */
#line 337 "Flamingo.y"
                {


empiler(stack, qc); 
}
#line 1885 "Flamingo.tab.c"
    break;

  case 55: /* $@4: %empty  */
#line 341 "Flamingo.y"
                                   {

insererQuadreplet(&q, "BZ", "tmp", "", "", qc);
empiler(stack,qc);
qc++;

}
#line 1897 "Flamingo.tab.c"
    break;

  case 56: /* CorWhile: WHILE $@3 Condition REPEAT ACCOLADEOUVRANTE $@4 CorFunc ACCOLADEFERMANTE  */
#line 347 "Flamingo.y"
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
#line 1918 "Flamingo.tab.c"
    break;


#line 1922 "Flamingo.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 444 "Flamingo.y"

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

