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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_WHITESPACE = 3,                 /* WHITESPACE  */
  YYSYMBOL_LETTER = 4,                     /* LETTER  */
  YYSYMBOL_ALPHANUM = 5,                   /* ALPHANUM  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_LIST = 7,                       /* LIST  */
  YYSYMBOL_LITERALSTRING = 8,              /* LITERALSTRING  */
  YYSYMBOL_LITERALCHAR = 9,                /* LITERALCHAR  */
  YYSYMBOL_KEYWORD_FALSE = 10,             /* KEYWORD_FALSE  */
  YYSYMBOL_KEYWORD_TRUE = 11,              /* KEYWORD_TRUE  */
  YYSYMBOL_MULTILINESTRING = 12,           /* MULTILINESTRING  */
  YYSYMBOL_KEYWORD_AWAIT = 13,             /* KEYWORD_AWAIT  */
  YYSYMBOL_KEYWORD_IF = 14,                /* KEYWORD_IF  */
  YYSYMBOL_KEYWORD_ELSE = 15,              /* KEYWORD_ELSE  */
  YYSYMBOL_KEYWORD_ELSE_IF = 16,           /* KEYWORD_ELSE_IF  */
  YYSYMBOL_KEYWORD_IMPORT = 17,            /* KEYWORD_IMPORT  */
  YYSYMBOL_KEYWORD_PASS = 18,              /* KEYWORD_PASS  */
  YYSYMBOL_KEYWORD_NONE = 19,              /* KEYWORD_NONE  */
  YYSYMBOL_KEYWORD_BREAK = 20,             /* KEYWORD_BREAK  */
  YYSYMBOL_KEYWORD_EXCEPT = 21,            /* KEYWORD_EXCEPT  */
  YYSYMBOL_KEYWORD_IN = 22,                /* KEYWORD_IN  */
  YYSYMBOL_KEYWORD_RAISE = 23,             /* KEYWORD_RAISE  */
  YYSYMBOL_KEYWORD_CLASS = 24,             /* KEYWORD_CLASS  */
  YYSYMBOL_KEYWORD_FINALLY = 25,           /* KEYWORD_FINALLY  */
  YYSYMBOL_KEYWORD_IS = 26,                /* KEYWORD_IS  */
  YYSYMBOL_KEYWORD_RETURN = 27,            /* KEYWORD_RETURN  */
  YYSYMBOL_KEYWORD_AND = 28,               /* KEYWORD_AND  */
  YYSYMBOL_KEYWORD_CONTINUE = 29,          /* KEYWORD_CONTINUE  */
  YYSYMBOL_KEYWORD_FOR = 30,               /* KEYWORD_FOR  */
  YYSYMBOL_KEYWORD_LAMBDA = 31,            /* KEYWORD_LAMBDA  */
  YYSYMBOL_KEYWORD_TRY = 32,               /* KEYWORD_TRY  */
  YYSYMBOL_KEYWORD_AS = 33,                /* KEYWORD_AS  */
  YYSYMBOL_KEYWORD_DEF = 34,               /* KEYWORD_DEF  */
  YYSYMBOL_KEYWORD_FROM = 35,              /* KEYWORD_FROM  */
  YYSYMBOL_KEYWORD_NONLOCAL = 36,          /* KEYWORD_NONLOCAL  */
  YYSYMBOL_KEYWORD_WHILE = 37,             /* KEYWORD_WHILE  */
  YYSYMBOL_KEYWORD_ASSERT = 38,            /* KEYWORD_ASSERT  */
  YYSYMBOL_KEYWORD_DEL = 39,               /* KEYWORD_DEL  */
  YYSYMBOL_KEYWORD_GLOBAL = 40,            /* KEYWORD_GLOBAL  */
  YYSYMBOL_KEYWORD_NOT = 41,               /* KEYWORD_NOT  */
  YYSYMBOL_KEYWORD_WITH = 42,              /* KEYWORD_WITH  */
  YYSYMBOL_KEYWORD_ASYNC = 43,             /* KEYWORD_ASYNC  */
  YYSYMBOL_KEYWORD_OR = 44,                /* KEYWORD_OR  */
  YYSYMBOL_KEYWORD_YIELD = 45,             /* KEYWORD_YIELD  */
  YYSYMBOL_OPERATORS = 46,                 /* OPERATORS  */
  YYSYMBOL_COMMENT = 47,                   /* COMMENT  */
  YYSYMBOL_ADD = 48,                       /* ADD  */
  YYSYMBOL_MINUS = 49,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 50,                  /* MULTIPLY  */
  YYSYMBOL_MULTILINECOMMENT = 51,          /* MULTILINECOMMENT  */
  YYSYMBOL_DIVIDE = 52,                    /* DIVIDE  */
  YYSYMBOL_POWER = 53,                     /* POWER  */
  YYSYMBOL_MODULO = 54,                    /* MODULO  */
  YYSYMBOL_ASSIGN = 55,                    /* ASSIGN  */
  YYSYMBOL_ASSIGNADD = 56,                 /* ASSIGNADD  */
  YYSYMBOL_ASSIGNMINUS = 57,               /* ASSIGNMINUS  */
  YYSYMBOL_ASSIGNMULTIPLY = 58,            /* ASSIGNMULTIPLY  */
  YYSYMBOL_ASSIGNDIVIDE = 59,              /* ASSIGNDIVIDE  */
  YYSYMBOL_ASSIGNMODULO = 60,              /* ASSIGNMODULO  */
  YYSYMBOL_ASSIGNFLOORDIVISION = 61,       /* ASSIGNFLOORDIVISION  */
  YYSYMBOL_ASSIGNEXPONINTIATION = 62,      /* ASSIGNEXPONINTIATION  */
  YYSYMBOL_ASSIGNBITWISEAND = 63,          /* ASSIGNBITWISEAND  */
  YYSYMBOL_ASSIGNBITWISEOR = 64,           /* ASSIGNBITWISEOR  */
  YYSYMBOL_ASSIGNBITWISEXOR = 65,          /* ASSIGNBITWISEXOR  */
  YYSYMBOL_ASSIGNRIGHTSHIFT = 66,          /* ASSIGNRIGHTSHIFT  */
  YYSYMBOL_ASSIGNLEFTSHIFT = 67,           /* ASSIGNLEFTSHIFT  */
  YYSYMBOL_EQUAL = 68,                     /* EQUAL  */
  YYSYMBOL_NOT = 69,                       /* NOT  */
  YYSYMBOL_NOTEQUAL = 70,                  /* NOTEQUAL  */
  YYSYMBOL_GREATERTHAN = 71,               /* GREATERTHAN  */
  YYSYMBOL_GREATEROREQUAL = 72,            /* GREATEROREQUAL  */
  YYSYMBOL_LESSTHAN = 73,                  /* LESSTHAN  */
  YYSYMBOL_LESSOREQUAL = 74,               /* LESSOREQUAL  */
  YYSYMBOL_LEFT_PARENTHES = 75,            /* LEFT_PARENTHES  */
  YYSYMBOL_RIGHT_PARENTHES = 76,           /* RIGHT_PARENTHES  */
  YYSYMBOL_LEFT_BRACES = 77,               /* LEFT_BRACES  */
  YYSYMBOL_RIGHT_BRACES = 78,              /* RIGHT_BRACES  */
  YYSYMBOL_LEFT_BRACKETS = 79,             /* LEFT_BRACKETS  */
  YYSYMBOL_RIGHT_BRACKETS = 80,            /* RIGHT_BRACKETS  */
  YYSYMBOL_COLON = 81,                     /* COLON  */
  YYSYMBOL_COMMA = 82,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 83,                 /* SEMICOLON  */
  YYSYMBOL_INTEGER = 84,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 85,                     /* FLOAT  */
  YYSYMBOL_DEDENT = 86,                    /* DEDENT  */
  YYSYMBOL_INDENT = 87,                    /* INDENT  */
  YYSYMBOL_NEWLINE = 88,                   /* NEWLINE  */
  YYSYMBOL_KEYWORD_MATCH = 89,             /* KEYWORD_MATCH  */
  YYSYMBOL_KEYWORD_CASE = 90,              /* KEYWORD_CASE  */
  YYSYMBOL_91_ = 91,                       /* '+'  */
  YYSYMBOL_92_ = 92,                       /* '-'  */
  YYSYMBOL_93_ = 93,                       /* '*'  */
  YYSYMBOL_94_ = 94,                       /* '/'  */
  YYSYMBOL_95_ = 95,                       /* '|'  */
  YYSYMBOL_UMINUS = 96,                    /* UMINUS  */
  YYSYMBOL_97_ = 97,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 98,                  /* $accept  */
  YYSYMBOL_prog = 99,                      /* prog  */
  YYSYMBOL_statements = 100,               /* statements  */
  YYSYMBOL_statement = 101,                /* statement  */
  YYSYMBOL_simple_statement = 102,         /* simple_statement  */
  YYSYMBOL_compound_statement = 103,       /* compound_statement  */
  YYSYMBOL_import_statment = 104,          /* import_statment  */
  YYSYMBOL_assignment = 105,               /* assignment  */
  YYSYMBOL_expression = 106,               /* expression  */
  YYSYMBOL_set_items = 107,                /* set_items  */
  YYSYMBOL_number = 108,                   /* number  */
  YYSYMBOL_del_statment = 109,             /* del_statment  */
  YYSYMBOL_return_statement = 110,         /* return_statement  */
  YYSYMBOL_yield_statement = 111,          /* yield_statement  */
  YYSYMBOL_assert_statement = 112,         /* assert_statement  */
  YYSYMBOL_raise_statement = 113,          /* raise_statement  */
  YYSYMBOL_global_statement = 114,         /* global_statement  */
  YYSYMBOL_nonlocal_statement = 115,       /* nonlocal_statement  */
  YYSYMBOL_global_nonlocal_targets = 116,  /* global_nonlocal_targets  */
  YYSYMBOL_match_statement = 117,          /* match_statement  */
  YYSYMBOL_match_block = 118,              /* match_block  */
  YYSYMBOL_case = 119,                     /* case  */
  YYSYMBOL_try_statement = 120,            /* try_statement  */
  YYSYMBOL_try = 121,                      /* try  */
  YYSYMBOL_except = 122,                   /* except  */
  YYSYMBOL_finally = 123,                  /* finally  */
  YYSYMBOL_except_statements = 124,        /* except_statements  */
  YYSYMBOL_with = 125,                     /* with  */
  YYSYMBOL_with_statements = 126,          /* with_statements  */
  YYSYMBOL_class = 127,                    /* class  */
  YYSYMBOL_class_block = 128,              /* class_block  */
  YYSYMBOL_class_body = 129,               /* class_body  */
  YYSYMBOL_function_call = 130,            /* function_call  */
  YYSYMBOL_function = 131,                 /* function  */
  YYSYMBOL_block = 132,                    /* block  */
  YYSYMBOL_parameters = 133,               /* parameters  */
  YYSYMBOL_parameter_list = 134,           /* parameter_list  */
  YYSYMBOL_parameter = 135,                /* parameter  */
  YYSYMBOL_args = 136,                     /* args  */
  YYSYMBOL_arg = 137,                      /* arg  */
  YYSYMBOL_member_expression = 138,        /* member_expression  */
  YYSYMBOL_logical_expression = 139,       /* logical_expression  */
  YYSYMBOL_logical_or = 140,               /* logical_or  */
  YYSYMBOL_logical_and = 141,              /* logical_and  */
  YYSYMBOL_logical_not = 142,              /* logical_not  */
  YYSYMBOL_comparison = 143,               /* comparison  */
  YYSYMBOL_conditional_statement = 144,    /* conditional_statement  */
  YYSYMBOL_elif_else = 145,                /* elif_else  */
  YYSYMBOL_elif_stmts = 146,               /* elif_stmts  */
  YYSYMBOL_if_statement = 147,             /* if_statement  */
  YYSYMBOL_else_statement = 148,           /* else_statement  */
  YYSYMBOL_elif_statement = 149,           /* elif_statement  */
  YYSYMBOL_for_statement = 150,            /* for_statement  */
  YYSYMBOL_while_statement = 151           /* while_statement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 9 "src/parser.y"

      extern int yylex();
      extern int yyparse();
      extern FILE *yyin;
      void yyerror(const char *);
      AstNode* root = NULL;
      int n_nodes = 0;

#line 263 "src/generated/parser.cpp"


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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   514

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  98
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  296

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   346


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
       2,     2,    93,    91,     2,    92,    97,    94,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    95,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    96
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    56,    60,    70,    74,    80,    81,    82,
      83,    84,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   103,   104,   105,   106,
     107,   108,   109,   113,   118,   124,   129,   135,   144,   152,
     155,   158,   161,   164,   167,   170,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   185,   189,   193,   196,   197,
     200,   205,   213,   218,   225,   232,   237,   241,   246,   254,
     261,   268,   271,   277,   285,   289,   296,   304,   308,   312,
     317,   322,   330,   337,   342,   348,   357,   364,   368,   373,
     381,   382,   385,   392,   400,   404,   411,   415,   419,   423,
     430,   438,   445,   452,   455,   458,   462,   466,   469,   473,
     480,   484,   491,   495,   499,   505,   508,   515,   517,   520,
     523,   526,   529,   532,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   548,   554,   558,   562,   565,
     570,   573,   579,   585,   593,   600,   606,   614,   621,   628,
     635,   642,   650,   661,   667
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
  "\"end of file\"", "error", "\"invalid token\"", "WHITESPACE", "LETTER",
  "ALPHANUM", "IDENTIFIER", "LIST", "LITERALSTRING", "LITERALCHAR",
  "KEYWORD_FALSE", "KEYWORD_TRUE", "MULTILINESTRING", "KEYWORD_AWAIT",
  "KEYWORD_IF", "KEYWORD_ELSE", "KEYWORD_ELSE_IF", "KEYWORD_IMPORT",
  "KEYWORD_PASS", "KEYWORD_NONE", "KEYWORD_BREAK", "KEYWORD_EXCEPT",
  "KEYWORD_IN", "KEYWORD_RAISE", "KEYWORD_CLASS", "KEYWORD_FINALLY",
  "KEYWORD_IS", "KEYWORD_RETURN", "KEYWORD_AND", "KEYWORD_CONTINUE",
  "KEYWORD_FOR", "KEYWORD_LAMBDA", "KEYWORD_TRY", "KEYWORD_AS",
  "KEYWORD_DEF", "KEYWORD_FROM", "KEYWORD_NONLOCAL", "KEYWORD_WHILE",
  "KEYWORD_ASSERT", "KEYWORD_DEL", "KEYWORD_GLOBAL", "KEYWORD_NOT",
  "KEYWORD_WITH", "KEYWORD_ASYNC", "KEYWORD_OR", "KEYWORD_YIELD",
  "OPERATORS", "COMMENT", "ADD", "MINUS", "MULTIPLY", "MULTILINECOMMENT",
  "DIVIDE", "POWER", "MODULO", "ASSIGN", "ASSIGNADD", "ASSIGNMINUS",
  "ASSIGNMULTIPLY", "ASSIGNDIVIDE", "ASSIGNMODULO", "ASSIGNFLOORDIVISION",
  "ASSIGNEXPONINTIATION", "ASSIGNBITWISEAND", "ASSIGNBITWISEOR",
  "ASSIGNBITWISEXOR", "ASSIGNRIGHTSHIFT", "ASSIGNLEFTSHIFT", "EQUAL",
  "NOT", "NOTEQUAL", "GREATERTHAN", "GREATEROREQUAL", "LESSTHAN",
  "LESSOREQUAL", "LEFT_PARENTHES", "RIGHT_PARENTHES", "LEFT_BRACES",
  "RIGHT_BRACES", "LEFT_BRACKETS", "RIGHT_BRACKETS", "COLON", "COMMA",
  "SEMICOLON", "INTEGER", "FLOAT", "DEDENT", "INDENT", "NEWLINE",
  "KEYWORD_MATCH", "KEYWORD_CASE", "'+'", "'-'", "'*'", "'/'", "'|'",
  "UMINUS", "'.'", "$accept", "prog", "statements", "statement",
  "simple_statement", "compound_statement", "import_statment",
  "assignment", "expression", "set_items", "number", "del_statment",
  "return_statement", "yield_statement", "assert_statement",
  "raise_statement", "global_statement", "nonlocal_statement",
  "global_nonlocal_targets", "match_statement", "match_block", "case",
  "try_statement", "try", "except", "finally", "except_statements", "with",
  "with_statements", "class", "class_block", "class_body", "function_call",
  "function", "block", "parameters", "parameter_list", "parameter", "args",
  "arg", "member_expression", "logical_expression", "logical_or",
  "logical_and", "logical_not", "comparison", "conditional_statement",
  "elif_else", "elif_stmts", "if_statement", "else_statement",
  "elif_statement", "for_statement", "while_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-229)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-125)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -52,  -229,    51,  -229,   412,  -229,   176,    67,  -229,  -229,
      67,    72,   199,  -229,     6,     4,    86,    67,    91,   203,
     199,    95,    91,    67,   299,  -229,  -229,  -229,    99,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
    -229,  -229,  -229,    20,  -229,  -229,  -229,  -229,   -35,  -229,
      42,  -229,  -229,  -229,  -229,  -229,   199,   299,   199,   299,
    -229,  -229,   299,   267,  -229,  -229,   -44,    31,    70,    89,
    -229,   240,   -15,   101,   -44,   -31,   299,   440,  -229,   102,
    -229,    38,    55,    -9,    56,  -229,   199,    62,    63,   130,
    -229,    12,   111,   267,    65,     3,    66,  -229,  -229,    17,
     299,  -229,   143,    69,   248,  -229,    42,  -229,  -229,  -229,
     267,   193,    77,   267,    -7,   267,   299,   299,   299,   299,
     299,   299,    38,   199,   199,   299,   285,   132,   299,   299,
     299,   299,   299,   299,   150,   151,  -229,    71,   193,   122,
      82,   299,    73,  -229,   155,    11,    91,    87,    38,   156,
    -229,    38,    67,   160,    79,    38,   -11,    38,  -229,  -229,
     144,   267,    92,  -229,    38,   199,    90,  -229,  -229,  -229,
      96,  -229,   299,   267,   267,   267,   267,   267,   267,  -229,
      89,  -229,   267,   299,   267,   299,   267,   267,   267,   267,
     267,   267,  -229,  -229,   100,    85,   104,   105,    -1,   158,
     299,    50,  -229,   106,   112,   109,  -229,   148,  -229,  -229,
     115,  -229,  -229,  -229,   159,  -229,   113,  -229,   187,    38,
    -229,  -229,  -229,  -229,   125,    38,    38,   267,   267,   267,
     121,  -229,    38,    38,    38,   -54,    67,  -229,   372,    67,
     123,   155,   197,    38,   202,   124,   131,  -229,   134,  -229,
    -229,   128,   127,     1,  -229,  -229,  -229,    38,   213,   139,
    -229,   126,    38,  -229,  -229,  -229,  -229,   299,    -3,  -229,
      38,    38,   137,  -229,     1,  -229,  -229,  -229,   -29,  -229,
     140,    38,  -229,   287,  -229,  -229,  -229,  -229,  -229,    38,
    -229,    38,   141,  -229,  -229,  -229
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     3,     5,     1,     4,   115,     0,     0,    23,    24,
       0,     0,     0,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     9,     0,     6,
       8,     7,    20,    12,    19,    13,    14,    15,    16,    17,
      18,    31,    32,     0,    22,    28,    21,    26,     0,    27,
     136,    29,    30,    48,    53,    49,     0,     0,     0,     0,
      58,    59,     0,   124,    50,    52,    51,     0,   117,   119,
     121,   123,    33,    67,     0,     0,     0,    62,    63,     0,
     112,     0,     0,     0,    71,    70,     0,     0,    65,    60,
      69,     0,     0,    64,     0,     0,     0,    88,    77,    78,
       0,   112,     0,     0,     0,   135,   138,   139,   140,   122,
      47,   124,     0,    55,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,     0,     0,     0,
     112,   111,     0,    82,   103,     0,     0,     0,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     0,    87,    79,
      80,    38,   112,   116,     0,     0,     0,   137,   141,    46,
       0,    54,    57,    39,    40,    41,    42,    43,    44,   142,
     118,   120,   132,     0,   134,     0,   129,   130,   126,   125,
     128,   127,    36,    68,   112,     0,     0,     0,     0,     0,
     110,   113,     5,   108,     0,   104,   105,    34,    35,    72,
       0,   153,    66,    89,     0,    90,     0,    83,     0,     0,
      86,    81,   100,   144,     0,     0,     0,    56,   133,   131,
       0,    96,     0,     0,     0,     0,     0,   114,     0,     0,
       0,   107,     0,     0,     0,     0,     0,    84,     0,   145,
     143,     0,    96,    95,   148,   147,   150,     0,     0,     0,
     102,   109,     0,   106,    37,   154,    91,     0,     0,    75,
       0,     0,     0,    93,    94,    99,    98,    97,     0,   151,
       0,     0,   101,     0,    73,    74,    85,   146,    96,     0,
     149,     0,    96,   152,    76,    92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -229,  -229,    24,  -229,  -229,  -229,  -229,  -220,   -10,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,   -21,  -229,
    -229,   -40,  -229,  -229,   138,   -83,  -229,  -229,  -229,  -229,
     -59,  -228,     0,  -219,   -92,  -229,  -229,    -8,   -76,  -125,
      -4,     9,  -229,   107,   -45,  -229,  -229,  -229,  -229,  -229,
     -60,   133,  -229,  -229
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     4,    29,    30,    31,    32,    33,    63,   114,
      64,    34,    35,    36,    37,    38,    39,    40,    85,    41,
     268,   269,    42,    43,    97,    98,    99,    44,    91,    45,
     252,   253,    65,    47,   143,   204,   205,   206,   140,   141,
      66,    67,    68,    69,    70,    71,    49,   105,   106,    50,
     107,   108,    51,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    90,    77,    72,    46,     5,    74,     5,   145,     5,
      73,   109,    79,    83,    93,   200,   159,   207,   134,    74,
     100,    78,   218,    92,   274,   162,   100,   257,    87,    88,
     179,   101,   103,   276,   277,    16,     1,   200,    95,   160,
     101,    95,    96,   258,   136,    96,   167,   110,   111,   113,
     137,     3,   115,   102,   276,   277,   211,   103,   104,   213,
     194,   208,   102,   217,   274,   220,   138,   112,   102,   200,
     219,   171,   223,     5,   101,   172,   111,   221,    75,   181,
     234,    80,   102,   284,   155,    81,   102,   267,   102,   275,
     161,   156,    82,   151,   152,   147,   102,    84,   116,   117,
     118,    89,   119,   120,   121,    94,   173,   174,   175,   176,
     177,   178,   122,   166,   123,   182,   184,   124,   186,   187,
     188,   189,   190,   191,   139,   209,   142,   247,     5,   196,
     144,   201,   237,   249,   250,   198,   135,   150,   146,   197,
     254,   255,   256,   148,   153,   149,   154,   157,    74,   163,
     164,   265,   214,   170,   185,   111,   192,   193,   199,   195,
     202,   203,   227,   210,   212,   279,   215,   216,   222,    96,
     282,   225,   231,   228,   224,   229,   230,   226,   286,   287,
     236,   242,     5,    53,    54,   232,   233,   239,   240,   290,
     201,   241,   244,   246,    74,    55,   243,   293,   235,   294,
     245,   248,   251,   264,   262,     5,    53,    54,   266,     5,
      53,    54,   270,   273,   267,   271,   272,    56,    55,   280,
     281,   289,    55,   102,   288,    57,   238,   295,   285,   292,
     180,     0,    74,   263,    48,   261,   259,   158,    46,   168,
      56,   116,   117,   118,    56,   119,   120,   121,    57,   278,
       0,    58,    57,    59,     5,    53,    54,   283,     0,     0,
      60,    61,   125,     0,     0,     0,   126,    55,     0,   169,
     278,    62,     0,     0,    76,     0,    59,     0,    86,     0,
      59,   127,     0,    60,    61,     0,     0,    60,    61,    56,
       0,     5,    53,    54,    62,     0,     0,    57,    62,     0,
       0,     0,     0,     0,    55,     5,    53,    54,   128,     0,
     129,   130,   131,   132,   133,   116,   117,   118,    55,   119,
     120,   121,     0,   165,     0,    59,   183,     0,     0,     0,
       0,     0,    60,    61,    57,   116,   117,   118,     0,   119,
     120,   121,     0,    62,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,    59,     0,     0,     0,     0,     0,   291,    60,
      61,     0,     0,     0,    76,     0,    59,     0,     5,     0,
      62,     0,     0,    60,    61,     0,     6,     0,     0,     7,
       8,     0,     9,     0,    62,    10,    11,     0,     0,    12,
       0,    13,    14,     0,    15,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,     0,     0,    24,     5,    25,
       0,     0,     0,    26,     0,     0,     6,     0,     0,     7,
       8,     0,     9,     0,     0,    10,    11,     0,     0,    12,
       0,    13,    14,     0,    15,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,     0,     0,    24,   260,    25,
      27,    28,  -124,    26,     0,     0,  -124,     0,  -124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -124,     0,     0,  -124,     0,     0,     0,   116,   117,
     118,     0,   119,   120,   121,     0,     0,     0,     0,     0,
      27,    28,     0,     0,     0,     0,     0,     0,  -124,     0,
    -124,  -124,  -124,  -124,  -124
};

static const yytype_int16 yycheck[] =
{
       4,    22,    12,     7,     4,     6,    10,     6,    17,     6,
      10,    56,     6,    17,    24,   140,    99,     6,    33,    23,
      55,    12,    33,    23,   252,   101,    55,    81,    19,    20,
     122,    75,    15,   253,   253,    34,    88,   162,    21,    99,
      75,    21,    25,    97,    75,    25,   106,    57,    58,    59,
      81,     0,    62,    97,   274,   274,   148,    15,    16,   151,
     136,    50,    97,   155,   292,   157,    76,    58,    97,   194,
      81,    78,   164,     6,    75,    82,    86,   160,     6,   124,
      81,    75,    97,    86,    81,    81,    97,    90,    97,    88,
     100,    95,     6,    81,    82,    86,    97,     6,    48,    49,
      50,     6,    52,    53,    54,     6,   116,   117,   118,   119,
     120,   121,    81,   104,    44,   125,   126,    28,   128,   129,
     130,   131,   132,   133,    22,   146,    88,   219,     6,     7,
      75,   141,    82,   225,   226,   139,    35,     7,    82,   139,
     232,   233,   234,    81,    33,    82,    81,    81,   152,     6,
      81,   243,   152,    76,    22,   165,     6,     6,    76,    88,
      87,     6,   172,    76,     8,   257,     6,    88,    76,    25,
     262,    81,    87,   183,   165,   185,    76,    81,   270,   271,
      22,    33,     6,     7,     8,    81,    81,    81,    76,   281,
     200,    82,    33,     6,   198,    19,    81,   289,   198,   291,
      87,    76,    81,     6,    81,     6,     7,     8,     6,     6,
       7,     8,    81,    86,    90,    81,    88,    41,    19,     6,
      81,    81,    19,    97,    87,    49,   202,    86,   268,   288,
     123,    -1,   236,   241,   238,   239,   236,    99,   238,   106,
      41,    48,    49,    50,    41,    52,    53,    54,    49,   253,
      -1,    75,    49,    77,     6,     7,     8,   267,    -1,    -1,
      84,    85,    22,    -1,    -1,    -1,    26,    19,    -1,    76,
     274,    95,    -1,    -1,    75,    -1,    77,    -1,    75,    -1,
      77,    41,    -1,    84,    85,    -1,    -1,    84,    85,    41,
      -1,     6,     7,     8,    95,    -1,    -1,    49,    95,    -1,
      -1,    -1,    -1,    -1,    19,     6,     7,     8,    68,    -1,
      70,    71,    72,    73,    74,    48,    49,    50,    19,    52,
      53,    54,    -1,    75,    -1,    77,    41,    -1,    -1,    -1,
      -1,    -1,    84,    85,    49,    48,    49,    50,    -1,    52,
      53,    54,    -1,    95,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    77,    -1,    -1,    -1,    -1,    -1,    81,    84,
      85,    -1,    -1,    -1,    75,    -1,    77,    -1,     6,    -1,
      95,    -1,    -1,    84,    85,    -1,    14,    -1,    -1,    17,
      18,    -1,    20,    -1,    95,    23,    24,    -1,    -1,    27,
      -1,    29,    30,    -1,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    45,     6,    47,
      -1,    -1,    -1,    51,    -1,    -1,    14,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    23,    24,    -1,    -1,    27,
      -1,    29,    30,    -1,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    45,    86,    47,
      88,    89,    22,    51,    -1,    -1,    26,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    48,    49,
      50,    -1,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    71,    72,    73,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    88,    99,     0,   100,     6,    14,    17,    18,    20,
      23,    24,    27,    29,    30,    32,    34,    35,    36,    37,
      38,    39,    40,    42,    45,    47,    51,    88,    89,   101,
     102,   103,   104,   105,   109,   110,   111,   112,   113,   114,
     115,   117,   120,   121,   125,   127,   130,   131,   138,   144,
     147,   150,   151,     7,     8,    19,    41,    49,    75,    77,
      84,    85,    95,   106,   108,   130,   138,   139,   140,   141,
     142,   143,   138,   130,   138,     6,    75,   106,   139,     6,
      75,    81,     6,   138,     6,   116,    75,   139,   139,     6,
     116,   126,   130,   106,     6,    21,    25,   122,   123,   124,
      55,    75,    97,    15,    16,   145,   146,   148,   149,   142,
     106,   106,   139,   106,   107,   106,    48,    49,    50,    52,
      53,    54,    81,    44,    28,    22,    26,    41,    68,    70,
      71,    72,    73,    74,    33,    35,    75,    81,   106,    22,
     136,   137,    88,   132,    75,    17,    82,   139,    81,    82,
       7,    81,    82,    33,    81,    81,   138,    81,   122,   123,
     148,   106,   136,     6,    81,    75,   139,   148,   149,    76,
      76,    78,    82,   106,   106,   106,   106,   106,   106,   132,
     141,   142,   106,    41,   106,    22,   106,   106,   106,   106,
     106,   106,     6,     6,   136,    88,     7,   130,   138,    76,
     137,   106,    87,     6,   133,   134,   135,     6,    50,   116,
      76,   132,     8,   132,   130,     6,    88,   132,    33,    81,
     132,   123,    76,   132,   139,    81,    81,   106,   106,   106,
      76,    87,    81,    81,    81,   130,    22,    82,   100,    81,
      76,    82,    33,    81,    33,    87,     6,   132,    76,   132,
     132,    81,   128,   129,   132,   132,   132,    81,    97,   130,
      86,   138,    81,   135,     6,   132,     6,    90,   118,   119,
      81,    81,    88,    86,   129,    88,   105,   131,   138,   132,
       6,    81,   132,   106,    86,   119,   132,   132,    87,    81,
     132,    81,   128,   132,   132,    86
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    98,    99,    99,    99,   100,   100,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   104,   104,   104,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   107,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   112,   112,   113,   113,   114,
     115,   116,   116,   117,   118,   118,   119,   120,   120,   120,
     120,   120,   121,   122,   122,   122,   123,   124,   124,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   129,   129,
     130,   131,   132,   133,   133,   134,   134,   134,   135,   135,
     136,   136,   137,   137,   137,   138,   138,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   144,   145,   145,   145,   145,
     146,   146,   147,   147,   148,   149,   149,   150,   150,   150,
     150,   150,   150,   151,   151
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     6,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     2,     1,     1,
       2,     3,     2,     2,     2,     2,     4,     2,     4,     2,
       2,     1,     3,     7,     2,     1,     4,     2,     2,     3,
       3,     4,     3,     3,     4,     6,     3,     2,     1,     4,
       3,     5,    10,     7,     2,     1,     0,     2,     2,     2,
       4,     7,     4,     0,     1,     1,     3,     2,     1,     3,
       2,     1,     0,     2,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     1,     3,     3,     3,     3,     3,
       3,     4,     3,     4,     3,     2,     0,     2,     1,     1,
       1,     2,     4,     6,     3,     4,     6,     6,     6,     8,
       6,     7,     9,     4,     6
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
  case 2: /* prog: %empty  */
#line 52 "src/parser.y"
                  { 
            std::string name = "Program" + std::to_string(++n_nodes);
            (yyval.astNode) = new EmptyNode(name); 
      }
#line 1762 "src/generated/parser.cpp"
    break;

  case 3: /* prog: NEWLINE  */
#line 56 "src/parser.y"
                        {
            std::string name = "Program" + std::to_string(++n_nodes);
            (yyval.astNode) = new EmptyNode(name);
      }
#line 1771 "src/generated/parser.cpp"
    break;

  case 4: /* prog: prog statements  */
#line 60 "src/parser.y"
                        {     
            std::string name = "Program" + std::to_string(++n_nodes);
            (yyval.astNode) = new StatementsNode(name);
            (yyval.astNode)->add((yyvsp[-1].astNode));
            (yyval.astNode)->add((yyvsp[0].astNode));
            root = (yyval.astNode);
            YYACCEPT;
      }
#line 1784 "src/generated/parser.cpp"
    break;

  case 5: /* statements: %empty  */
#line 70 "src/parser.y"
                        {
                  std::string name = "Statement" + std::to_string(++n_nodes);
                  (yyval.astNode) = new StatementsNode(name);
            }
#line 1793 "src/generated/parser.cpp"
    break;

  case 6: /* statements: statements statement  */
#line 74 "src/parser.y"
                                    { 
                  if ((yyvsp[0].astNode) != nullptr) (yyvsp[-1].astNode)->add((yyvsp[0].astNode));
                  (yyval.astNode) = (yyvsp[-1].astNode); 
            }
#line 1802 "src/generated/parser.cpp"
    break;

  case 7: /* statement: compound_statement  */
#line 80 "src/parser.y"
                                    { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1808 "src/generated/parser.cpp"
    break;

  case 8: /* statement: simple_statement  */
#line 81 "src/parser.y"
                                    { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1814 "src/generated/parser.cpp"
    break;

  case 9: /* statement: NEWLINE  */
#line 82 "src/parser.y"
                                  { (yyval.astNode) = nullptr; }
#line 1820 "src/generated/parser.cpp"
    break;

  case 10: /* statement: COMMENT  */
#line 83 "src/parser.y"
                                  { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1826 "src/generated/parser.cpp"
    break;

  case 11: /* statement: MULTILINECOMMENT  */
#line 84 "src/parser.y"
                                  { (yyval.astNode) = nullptr; }
#line 1832 "src/generated/parser.cpp"
    break;

  case 12: /* simple_statement: assignment  */
#line 87 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1838 "src/generated/parser.cpp"
    break;

  case 13: /* simple_statement: return_statement  */
#line 88 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1844 "src/generated/parser.cpp"
    break;

  case 14: /* simple_statement: yield_statement  */
#line 89 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1850 "src/generated/parser.cpp"
    break;

  case 15: /* simple_statement: assert_statement  */
#line 90 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1856 "src/generated/parser.cpp"
    break;

  case 16: /* simple_statement: raise_statement  */
#line 91 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1862 "src/generated/parser.cpp"
    break;

  case 17: /* simple_statement: global_statement  */
#line 92 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1868 "src/generated/parser.cpp"
    break;

  case 18: /* simple_statement: nonlocal_statement  */
#line 93 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1874 "src/generated/parser.cpp"
    break;

  case 19: /* simple_statement: del_statment  */
#line 94 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1880 "src/generated/parser.cpp"
    break;

  case 20: /* simple_statement: import_statment  */
#line 95 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1886 "src/generated/parser.cpp"
    break;

  case 21: /* simple_statement: function_call  */
#line 96 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1892 "src/generated/parser.cpp"
    break;

  case 22: /* simple_statement: with  */
#line 97 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1898 "src/generated/parser.cpp"
    break;

  case 23: /* simple_statement: KEYWORD_PASS  */
#line 98 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1904 "src/generated/parser.cpp"
    break;

  case 24: /* simple_statement: KEYWORD_BREAK  */
#line 99 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1910 "src/generated/parser.cpp"
    break;

  case 25: /* simple_statement: KEYWORD_CONTINUE  */
#line 100 "src/parser.y"
                                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1916 "src/generated/parser.cpp"
    break;

  case 26: /* compound_statement: function  */
#line 103 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1922 "src/generated/parser.cpp"
    break;

  case 27: /* compound_statement: conditional_statement  */
#line 104 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1928 "src/generated/parser.cpp"
    break;

  case 28: /* compound_statement: class  */
#line 105 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1934 "src/generated/parser.cpp"
    break;

  case 29: /* compound_statement: for_statement  */
#line 106 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1940 "src/generated/parser.cpp"
    break;

  case 30: /* compound_statement: while_statement  */
#line 107 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1946 "src/generated/parser.cpp"
    break;

  case 31: /* compound_statement: match_statement  */
#line 108 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1952 "src/generated/parser.cpp"
    break;

  case 32: /* compound_statement: try_statement  */
#line 109 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 1958 "src/generated/parser.cpp"
    break;

  case 33: /* import_statment: KEYWORD_IMPORT member_expression  */
#line 113 "src/parser.y"
                                                     {
                        std::string name = "Import" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ImportNode(name);
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 1968 "src/generated/parser.cpp"
    break;

  case 34: /* import_statment: KEYWORD_FROM member_expression KEYWORD_IMPORT IDENTIFIER  */
#line 118 "src/parser.y"
                                                                             {
                        std::string name = "Import" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ImportNode(name);
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 1979 "src/generated/parser.cpp"
    break;

  case 35: /* import_statment: KEYWORD_FROM member_expression KEYWORD_IMPORT MULTIPLY  */
#line 124 "src/parser.y"
                                                                           {
                        std::string name = "Import" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ImportNode(name);
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                  }
#line 1989 "src/generated/parser.cpp"
    break;

  case 36: /* import_statment: KEYWORD_IMPORT member_expression KEYWORD_AS IDENTIFIER  */
#line 129 "src/parser.y"
                                                                           {
                        std::string name = "Import" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ImportNode(name);
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2000 "src/generated/parser.cpp"
    break;

  case 37: /* import_statment: KEYWORD_FROM member_expression KEYWORD_IMPORT IDENTIFIER KEYWORD_AS IDENTIFIER  */
#line 135 "src/parser.y"
                                                                                                   {
                        std::string name = "Import" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ImportNode(name);
                        (yyval.astNode)->add((yyvsp[-4].astNode));
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2012 "src/generated/parser.cpp"
    break;

  case 38: /* assignment: member_expression ASSIGN expression  */
#line 144 "src/parser.y"
                                                  {  
                  std::string name = "assignment" + std::to_string(++n_nodes);
                  (yyval.astNode) = new AssignmentStatement(name);
                  (yyval.astNode)->add((yyvsp[-2].astNode));
                  (yyval.astNode)->add((yyvsp[0].astNode));
            }
#line 2023 "src/generated/parser.cpp"
    break;

  case 39: /* expression: expression ADD expression  */
#line 152 "src/parser.y"
                                          { 
                  (yyval.astNode) = new BinaryExpressionNode("+", (yyvsp[-2].astNode), (yyvsp[0].astNode));
            }
#line 2031 "src/generated/parser.cpp"
    break;

  case 40: /* expression: expression MINUS expression  */
#line 155 "src/parser.y"
                                                { 
                  (yyval.astNode) = new BinaryExpressionNode("-", (yyvsp[-2].astNode), (yyvsp[0].astNode));
            }
#line 2039 "src/generated/parser.cpp"
    break;

  case 41: /* expression: expression MULTIPLY expression  */
#line 158 "src/parser.y"
                                                { 
                  (yyval.astNode) = new BinaryExpressionNode("*", (yyvsp[-2].astNode), (yyvsp[0].astNode));
            }
#line 2047 "src/generated/parser.cpp"
    break;

  case 42: /* expression: expression DIVIDE expression  */
#line 161 "src/parser.y"
                                                { 
                  (yyval.astNode) = new BinaryExpressionNode("/", (yyvsp[-2].astNode), (yyvsp[0].astNode));
            }
#line 2055 "src/generated/parser.cpp"
    break;

  case 43: /* expression: expression POWER expression  */
#line 164 "src/parser.y"
                                                { 
                  (yyval.astNode) = new BinaryExpressionNode("**", (yyvsp[-2].astNode), (yyvsp[0].astNode));
            }
#line 2063 "src/generated/parser.cpp"
    break;

  case 44: /* expression: expression MODULO expression  */
#line 167 "src/parser.y"
                                                {
                  (yyval.astNode) = new BinaryExpressionNode("%", (yyvsp[-2].astNode), (yyvsp[0].astNode));
            }
#line 2071 "src/generated/parser.cpp"
    break;

  case 45: /* expression: '|' expression  */
#line 170 "src/parser.y"
                                                { /*The rule for negation includes %prec UMINUS . The only operator in this rule is - , 
                                                      which has low precedence, but we want unary minus to have higher precedence than multiplication 
                                                      rather than lower. The %prec tells bison to use the precedence of UMINUS for this rule.*/
                                                }
#line 2080 "src/generated/parser.cpp"
    break;

  case 46: /* expression: LEFT_PARENTHES expression RIGHT_PARENTHES  */
#line 174 "src/parser.y"
                                                                       {(yyval.astNode) = (yyvsp[-1].astNode); }
#line 2086 "src/generated/parser.cpp"
    break;

  case 47: /* expression: MINUS expression  */
#line 175 "src/parser.y"
                                                  { }
#line 2092 "src/generated/parser.cpp"
    break;

  case 49: /* expression: KEYWORD_NONE  */
#line 177 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2098 "src/generated/parser.cpp"
    break;

  case 50: /* expression: number  */
#line 178 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2104 "src/generated/parser.cpp"
    break;

  case 51: /* expression: member_expression  */
#line 179 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2110 "src/generated/parser.cpp"
    break;

  case 52: /* expression: function_call  */
#line 180 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2116 "src/generated/parser.cpp"
    break;

  case 53: /* expression: LITERALSTRING  */
#line 181 "src/parser.y"
                                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2122 "src/generated/parser.cpp"
    break;

  case 54: /* expression: LEFT_BRACES set_items RIGHT_BRACES  */
#line 182 "src/parser.y"
                                                 { (yyval.astNode) = (yyvsp[-1].astNode); }
#line 2128 "src/generated/parser.cpp"
    break;

  case 55: /* set_items: expression  */
#line 185 "src/parser.y"
                       {
                  (yyval.astNode) = new SetNode("Set" + std::to_string(++n_nodes));
                  (yyval.astNode)->add((yyvsp[0].astNode));
            }
#line 2137 "src/generated/parser.cpp"
    break;

  case 56: /* set_items: set_items COMMA expression  */
#line 189 "src/parser.y"
                                         {
                  (yyvsp[-2].astNode)->add((yyvsp[0].astNode));
                  (yyval.astNode) = (yyvsp[-2].astNode);
            }
#line 2146 "src/generated/parser.cpp"
    break;

  case 57: /* set_items: set_items COMMA  */
#line 193 "src/parser.y"
                              { (yyval.astNode) = (yyvsp[-1].astNode); }
#line 2152 "src/generated/parser.cpp"
    break;

  case 58: /* number: INTEGER  */
#line 196 "src/parser.y"
                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2158 "src/generated/parser.cpp"
    break;

  case 59: /* number: FLOAT  */
#line 197 "src/parser.y"
                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2164 "src/generated/parser.cpp"
    break;

  case 60: /* del_statment: KEYWORD_DEL IDENTIFIER  */
#line 200 "src/parser.y"
                                                {
                        std::string name = "Del" + std::to_string(++n_nodes);
                        (yyval.astNode) = new DelNode(name);
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2174 "src/generated/parser.cpp"
    break;

  case 61: /* del_statment: KEYWORD_DEL IDENTIFIER LIST  */
#line 205 "src/parser.y"
                                                { 
                        std::string name = "Del" + std::to_string(++n_nodes);
                        (yyval.astNode) = new DelNode(name);
                        (yyval.astNode)->add((yyvsp[-1].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2185 "src/generated/parser.cpp"
    break;

  case 62: /* return_statement: KEYWORD_RETURN expression  */
#line 213 "src/parser.y"
                                              {
                        std::string name = "Return" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ReturnNode(name);
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2195 "src/generated/parser.cpp"
    break;

  case 63: /* return_statement: KEYWORD_RETURN logical_expression  */
#line 218 "src/parser.y"
                                                      {
                        std::string name = "Return" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ReturnNode(name);
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2205 "src/generated/parser.cpp"
    break;

  case 64: /* yield_statement: KEYWORD_YIELD expression  */
#line 225 "src/parser.y"
                                                {
                        std::string name = "Yield" + std::to_string(++n_nodes);
                        (yyval.astNode) = new YieldNode(name);
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2215 "src/generated/parser.cpp"
    break;

  case 65: /* assert_statement: KEYWORD_ASSERT logical_expression  */
#line 232 "src/parser.y"
                                                      {
                        std::string name = "Assert" + std::to_string(++n_nodes);
                        (yyval.astNode) = new AssertNode(name);
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2225 "src/generated/parser.cpp"
    break;

  case 66: /* assert_statement: KEYWORD_ASSERT logical_expression COMMA LITERALSTRING  */
#line 237 "src/parser.y"
                                                                          {
                  }
#line 2232 "src/generated/parser.cpp"
    break;

  case 67: /* raise_statement: KEYWORD_RAISE function_call  */
#line 241 "src/parser.y"
                                                {
                        std::string name = "Raise" + std::to_string(++n_nodes);
                        (yyval.astNode) = new RaiseNode(name);
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2242 "src/generated/parser.cpp"
    break;

  case 68: /* raise_statement: KEYWORD_RAISE function_call KEYWORD_FROM IDENTIFIER  */
#line 246 "src/parser.y"
                                                                        {
                        std::string name = "Raise" + std::to_string(++n_nodes);
                        (yyval.astNode) = new RaiseNode(name);
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2253 "src/generated/parser.cpp"
    break;

  case 69: /* global_statement: KEYWORD_GLOBAL global_nonlocal_targets  */
#line 254 "src/parser.y"
                                                           {
                        std::string name = "Global" + std::to_string(++n_nodes);
                        (yyval.astNode) = new GlobalNode(name);
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2263 "src/generated/parser.cpp"
    break;

  case 70: /* nonlocal_statement: KEYWORD_NONLOCAL global_nonlocal_targets  */
#line 261 "src/parser.y"
                                                                   {
                              std::string name = "NonLocal" + std::to_string(++n_nodes);
                              (yyval.astNode) = new NonLocalNode(name);
                              (yyval.astNode)->add((yyvsp[0].astNode));
                        }
#line 2273 "src/generated/parser.cpp"
    break;

  case 71: /* global_nonlocal_targets: IDENTIFIER  */
#line 268 "src/parser.y"
                                     {
                              (yyval.astNode) = (yyvsp[0].astNode);
                        }
#line 2281 "src/generated/parser.cpp"
    break;

  case 72: /* global_nonlocal_targets: IDENTIFIER COMMA global_nonlocal_targets  */
#line 271 "src/parser.y"
                                                                   { 
                              (yyvsp[-2].astNode)->add((yyvsp[0].astNode));
                              (yyval.astNode) = (yyvsp[-2].astNode);
                        }
#line 2290 "src/generated/parser.cpp"
    break;

  case 73: /* match_statement: KEYWORD_MATCH IDENTIFIER COLON NEWLINE INDENT match_block DEDENT  */
#line 277 "src/parser.y"
                                                                                     {
                        std::string name = dynamic_cast<IdentifierNode*>((yyvsp[-5].astNode))->value;
                        (yyval.astNode) = new MatchNode(name);
                        (yyval.astNode)->add((yyvsp[-5].astNode));
                        (yyval.astNode)->add((yyvsp[-1].astNode));
                  }
#line 2301 "src/generated/parser.cpp"
    break;

  case 74: /* match_block: match_block case  */
#line 285 "src/parser.y"
                                    { 
                  (yyvsp[-1].astNode)->add((yyvsp[0].astNode));
                  (yyval.astNode) = (yyvsp[-1].astNode);
            }
#line 2310 "src/generated/parser.cpp"
    break;

  case 75: /* match_block: case  */
#line 289 "src/parser.y"
                        {
                  std::string name = "MatchBlock" + std::to_string(++n_nodes);
                  (yyval.astNode) = new MatchBlock(name);
                  (yyval.astNode)->add((yyvsp[0].astNode));
            }
#line 2320 "src/generated/parser.cpp"
    break;

  case 76: /* case: KEYWORD_CASE expression COLON block  */
#line 296 "src/parser.y"
                                            {
            std::string name = "Case" + std::to_string(++n_nodes);
            (yyval.astNode) = new CaseNode(name);
            (yyval.astNode)->add((yyvsp[-2].astNode));
            (yyval.astNode)->add((yyvsp[0].astNode));
      }
#line 2331 "src/generated/parser.cpp"
    break;

  case 77: /* try_statement: try finally  */
#line 304 "src/parser.y"
                                {
                        (yyval.astNode)->add((yyvsp[-1].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2340 "src/generated/parser.cpp"
    break;

  case 78: /* try_statement: try except_statements  */
#line 308 "src/parser.y"
                                          {
                        (yyval.astNode)->add((yyvsp[-1].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2349 "src/generated/parser.cpp"
    break;

  case 79: /* try_statement: try except_statements finally  */
#line 312 "src/parser.y"
                                                  {
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[-1].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2359 "src/generated/parser.cpp"
    break;

  case 80: /* try_statement: try except_statements else_statement  */
#line 317 "src/parser.y"
                                                         {
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[-1].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2369 "src/generated/parser.cpp"
    break;

  case 81: /* try_statement: try except_statements else_statement finally  */
#line 322 "src/parser.y"
                                                                {
                        (yyval.astNode)->add((yyvsp[-3].astNode));
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[-1].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2380 "src/generated/parser.cpp"
    break;

  case 82: /* try: KEYWORD_TRY COLON block  */
#line 330 "src/parser.y"
                                {
            std::string name = "Try" + std::to_string(++n_nodes);
            (yyval.astNode) = new TryNode(name);
            (yyval.astNode)->add((yyvsp[0].astNode));
      }
#line 2390 "src/generated/parser.cpp"
    break;

  case 83: /* except: KEYWORD_EXCEPT COLON block  */
#line 337 "src/parser.y"
                                   {
            std::string name = "Except" + std::to_string(++n_nodes);
            (yyval.astNode) = new ExceptNode(name);
            (yyval.astNode)->add((yyvsp[0].astNode));
      }
#line 2400 "src/generated/parser.cpp"
    break;

  case 84: /* except: KEYWORD_EXCEPT member_expression COLON block  */
#line 342 "src/parser.y"
                                                     {
            std::string name = "Except" + std::to_string(++n_nodes);
            (yyval.astNode) = new ExceptNode(name);
            (yyval.astNode)->add((yyvsp[0].astNode));
            (yyval.astNode)->add((yyvsp[-2].astNode));
      }
#line 2411 "src/generated/parser.cpp"
    break;

  case 85: /* except: KEYWORD_EXCEPT member_expression KEYWORD_AS IDENTIFIER COLON block  */
#line 348 "src/parser.y"
                                                                           {
            std::string name = "Except" + std::to_string(++n_nodes);
            (yyval.astNode) = new ExceptNode(name);
            (yyval.astNode)->add((yyvsp[-2].astNode));
            (yyval.astNode)->add((yyvsp[-4].astNode));
            (yyval.astNode)->add((yyvsp[0].astNode));
      }
#line 2423 "src/generated/parser.cpp"
    break;

  case 86: /* finally: KEYWORD_FINALLY COLON block  */
#line 357 "src/parser.y"
                                          {
                  std::string name = "Finally" + std::to_string(++n_nodes);
                  (yyval.astNode) = new FinallyNode(name);
                  (yyval.astNode)->add((yyvsp[0].astNode));
            }
#line 2433 "src/generated/parser.cpp"
    break;

  case 87: /* except_statements: except_statements except  */
#line 364 "src/parser.y"
                                             {
                        (yyvsp[-1].astNode)->add((yyvsp[0].astNode));
                        (yyval.astNode) = (yyvsp[-1].astNode);
                  }
#line 2442 "src/generated/parser.cpp"
    break;

  case 88: /* except_statements: except  */
#line 368 "src/parser.y"
                           {
                        (yyval.astNode) = (yyvsp[0].astNode);
                  }
#line 2450 "src/generated/parser.cpp"
    break;

  case 89: /* with: KEYWORD_WITH with_statements COLON block  */
#line 373 "src/parser.y"
                                                 {
            std::string name = "With" + std::to_string(++n_nodes);
            (yyval.astNode) = new WithNode(name);
            (yyval.astNode)->add((yyvsp[-2].astNode));
            (yyval.astNode)->add((yyvsp[0].astNode));
      }
#line 2461 "src/generated/parser.cpp"
    break;

  case 92: /* class: KEYWORD_CLASS IDENTIFIER LEFT_PARENTHES args RIGHT_PARENTHES COLON NEWLINE INDENT class_block DEDENT  */
#line 385 "src/parser.y"
                                                                                                               {
            std::string name = "classWithInheritance" + std::to_string(++n_nodes);
            (yyval.astNode) = new ClassNode(name);
            (yyval.astNode)->add((yyvsp[-8].astNode));
            (yyval.astNode)->add((yyvsp[-6].astNode));
            (yyval.astNode)->add((yyvsp[-1].astNode));
      }
#line 2473 "src/generated/parser.cpp"
    break;

  case 93: /* class: KEYWORD_CLASS IDENTIFIER COLON NEWLINE INDENT class_block DEDENT  */
#line 392 "src/parser.y"
                                                                         {
            std::string name = "classWithoutInheritance" + std::to_string(++n_nodes);
            (yyval.astNode) = new ClassNode(name);
            (yyval.astNode)->add((yyvsp[-5].astNode));
            (yyval.astNode)->add((yyvsp[-1].astNode));
      }
#line 2484 "src/generated/parser.cpp"
    break;

  case 94: /* class_block: class_block class_body  */
#line 400 "src/parser.y"
                                     {
                  (yyvsp[-1].astNode)->add((yyvsp[0].astNode));
                  (yyval.astNode) = (yyvsp[-1].astNode);
            }
#line 2493 "src/generated/parser.cpp"
    break;

  case 95: /* class_block: class_body  */
#line 404 "src/parser.y"
                         {
                  std::string name = "ClassBlock" + std::to_string(++n_nodes);
                  (yyval.astNode) = new ClassBlock(name);
                  (yyval.astNode)->add((yyvsp[0].astNode));
            }
#line 2503 "src/generated/parser.cpp"
    break;

  case 96: /* class_body: %empty  */
#line 411 "src/parser.y"
                          { 
                  std::string name = "Classbody" + std::to_string(++n_nodes);
                  (yyval.astNode) = new ClassBodyNode(name);
            }
#line 2512 "src/generated/parser.cpp"
    break;

  case 97: /* class_body: class_body function  */
#line 415 "src/parser.y"
                                  { 
                  (yyvsp[-1].astNode)->add((yyvsp[0].astNode));
                  (yyval.astNode) = (yyvsp[-1].astNode);
            }
#line 2521 "src/generated/parser.cpp"
    break;

  case 98: /* class_body: class_body assignment  */
#line 419 "src/parser.y"
                                    { 
                  (yyvsp[-1].astNode)->add((yyvsp[0].astNode));
                  (yyval.astNode) = (yyvsp[-1].astNode);
            }
#line 2530 "src/generated/parser.cpp"
    break;

  case 99: /* class_body: class_body NEWLINE  */
#line 423 "src/parser.y"
                                    {
                  std::string name = "Classbody" + std::to_string(++n_nodes);
                  (yyval.astNode) = new ClassBodyNode(name);
                  (yyval.astNode)->add((yyvsp[-1].astNode));
            }
#line 2540 "src/generated/parser.cpp"
    break;

  case 100: /* function_call: member_expression LEFT_PARENTHES args RIGHT_PARENTHES  */
#line 430 "src/parser.y"
                                                                          {
                        std::string name = "Call" + std::to_string(++n_nodes);
                        (yyval.astNode) = new FunctionCall(name, (yyvsp[-3].astNode));
                        (yyval.astNode)->add((yyvsp[-3].astNode));
                        (yyval.astNode)->add((yyvsp[-1].astNode));
                  }
#line 2551 "src/generated/parser.cpp"
    break;

  case 101: /* function: KEYWORD_DEF IDENTIFIER LEFT_PARENTHES parameters RIGHT_PARENTHES COLON block  */
#line 438 "src/parser.y"
                                                                                           {
                  IdentifierNode* idFunc = dynamic_cast<IdentifierNode*>((yyvsp[-5].astNode));
                  (yyval.astNode) = new FunctionNode(idFunc->value);
                  (yyval.astNode)->add((yyvsp[-3].astNode));
                  (yyval.astNode)->add((yyvsp[0].astNode));
            }
#line 2562 "src/generated/parser.cpp"
    break;

  case 102: /* block: NEWLINE INDENT statements DEDENT  */
#line 445 "src/parser.y"
                                          {     
            std::string name = "block" + std::to_string(++n_nodes);
            (yyval.astNode) = new BlockNode(name);
            (yyval.astNode)->add((yyvsp[-1].astNode));
      }
#line 2572 "src/generated/parser.cpp"
    break;

  case 103: /* parameters: %empty  */
#line 452 "src/parser.y"
                         {
                  (yyval.astNode) = new Args("Args" + std::to_string(++n_nodes));
            }
#line 2580 "src/generated/parser.cpp"
    break;

  case 104: /* parameters: parameter_list  */
#line 455 "src/parser.y"
                             { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2586 "src/generated/parser.cpp"
    break;

  case 105: /* parameter_list: parameter  */
#line 458 "src/parser.y"
                           {
                       (yyval.astNode) = new Args("Args" + std::to_string(++n_nodes));
                       (yyval.astNode)->add((yyvsp[0].astNode));
                 }
#line 2595 "src/generated/parser.cpp"
    break;

  case 106: /* parameter_list: parameter_list COMMA parameter  */
#line 462 "src/parser.y"
                                                  {
                       (yyvsp[-2].astNode)->add((yyvsp[0].astNode));
                       (yyval.astNode) = (yyvsp[-2].astNode);
                 }
#line 2604 "src/generated/parser.cpp"
    break;

  case 107: /* parameter_list: parameter_list COMMA  */
#line 466 "src/parser.y"
                                        { (yyval.astNode) = (yyvsp[-1].astNode); }
#line 2610 "src/generated/parser.cpp"
    break;

  case 108: /* parameter: IDENTIFIER  */
#line 469 "src/parser.y"
                       {
                  (yyval.astNode) = new Arg("Arg" + std::to_string(++n_nodes));
                  (yyval.astNode)->add((yyvsp[0].astNode));
            }
#line 2619 "src/generated/parser.cpp"
    break;

  case 109: /* parameter: IDENTIFIER COLON member_expression  */
#line 473 "src/parser.y"
                                                 {
                  (yyval.astNode) = new Arg("Arg" + std::to_string(++n_nodes));
                  (yyval.astNode)->add((yyvsp[-2].astNode));
                  (yyval.astNode)->add((yyvsp[0].astNode));
            }
#line 2629 "src/generated/parser.cpp"
    break;

  case 110: /* args: args arg  */
#line 480 "src/parser.y"
                 {
            (yyvsp[-1].astNode)->add((yyvsp[0].astNode));
            (yyval.astNode) = (yyvsp[-1].astNode);
      }
#line 2638 "src/generated/parser.cpp"
    break;

  case 111: /* args: arg  */
#line 484 "src/parser.y"
            { 
            std::string name = "Args" + std::to_string(++n_nodes);
            (yyval.astNode) = new Args(name);
            (yyval.astNode)->add((yyvsp[0].astNode));
      }
#line 2648 "src/generated/parser.cpp"
    break;

  case 112: /* arg: %empty  */
#line 491 "src/parser.y"
                     { 
            std::string name = "Arg" + std::to_string(++n_nodes);
            (yyval.astNode) = new Arg(name);
      }
#line 2657 "src/generated/parser.cpp"
    break;

  case 113: /* arg: arg expression  */
#line 495 "src/parser.y"
                       {
            (yyvsp[-1].astNode)->add((yyvsp[0].astNode));
            (yyval.astNode) = (yyvsp[-1].astNode);
      }
#line 2666 "src/generated/parser.cpp"
    break;

  case 114: /* arg: arg expression COMMA  */
#line 499 "src/parser.y"
                              {
            (yyvsp[-2].astNode)->add((yyvsp[-1].astNode));
            (yyval.astNode) = (yyvsp[-2].astNode);
      }
#line 2675 "src/generated/parser.cpp"
    break;

  case 115: /* member_expression: IDENTIFIER  */
#line 505 "src/parser.y"
                                    {
                        (yyval.astNode) = (yyvsp[0].astNode);
                  }
#line 2683 "src/generated/parser.cpp"
    break;

  case 116: /* member_expression: member_expression '.' IDENTIFIER  */
#line 508 "src/parser.y"
                                                      {
                        (yyval.astNode) = new MemberExpression((yyvsp[-2].astNode), (yyvsp[0].astNode));
                        (yyval.astNode)->add((yyvsp[-2].astNode)); 
                        (yyval.astNode)->add((yyvsp[0].astNode)); 
                  }
#line 2693 "src/generated/parser.cpp"
    break;

  case 117: /* logical_expression: logical_or  */
#line 515 "src/parser.y"
                                { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2699 "src/generated/parser.cpp"
    break;

  case 118: /* logical_or: logical_or KEYWORD_OR logical_and  */
#line 517 "src/parser.y"
                                               {
                  (yyval.astNode) = new BinaryLogicalExpression("or", (yyvsp[-2].astNode), (yyvsp[0].astNode));
            }
#line 2707 "src/generated/parser.cpp"
    break;

  case 119: /* logical_or: logical_and  */
#line 520 "src/parser.y"
                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2713 "src/generated/parser.cpp"
    break;

  case 120: /* logical_and: logical_and KEYWORD_AND logical_not  */
#line 523 "src/parser.y"
                                                  {
                   (yyval.astNode) = new BinaryLogicalExpression("and", (yyvsp[-2].astNode), (yyvsp[0].astNode));
            }
#line 2721 "src/generated/parser.cpp"
    break;

  case 121: /* logical_and: logical_not  */
#line 526 "src/parser.y"
                          { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2727 "src/generated/parser.cpp"
    break;

  case 122: /* logical_not: KEYWORD_NOT logical_not  */
#line 529 "src/parser.y"
                                      {
                  (yyval.astNode) = new UnaryExpressionNode("not", (yyvsp[0].astNode));
            }
#line 2735 "src/generated/parser.cpp"
    break;

  case 123: /* logical_not: comparison  */
#line 532 "src/parser.y"
                         { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2741 "src/generated/parser.cpp"
    break;

  case 124: /* comparison: expression  */
#line 535 "src/parser.y"
                        { (yyval.astNode) = (yyvsp[0].astNode); }
#line 2747 "src/generated/parser.cpp"
    break;

  case 125: /* comparison: comparison GREATEROREQUAL expression  */
#line 536 "src/parser.y"
                                                  { (yyval.astNode) = new BinaryLogicalExpression(">=", (yyvsp[-2].astNode), (yyvsp[0].astNode)); }
#line 2753 "src/generated/parser.cpp"
    break;

  case 126: /* comparison: comparison GREATERTHAN expression  */
#line 537 "src/parser.y"
                                               { (yyval.astNode) = new BinaryLogicalExpression(">", (yyvsp[-2].astNode), (yyvsp[0].astNode)); }
#line 2759 "src/generated/parser.cpp"
    break;

  case 127: /* comparison: comparison LESSOREQUAL expression  */
#line 538 "src/parser.y"
                                               { (yyval.astNode) = new BinaryLogicalExpression("<=", (yyvsp[-2].astNode), (yyvsp[0].astNode)); }
#line 2765 "src/generated/parser.cpp"
    break;

  case 128: /* comparison: comparison LESSTHAN expression  */
#line 539 "src/parser.y"
                                            { (yyval.astNode) = new BinaryLogicalExpression("<", (yyvsp[-2].astNode), (yyvsp[0].astNode)); }
#line 2771 "src/generated/parser.cpp"
    break;

  case 129: /* comparison: comparison EQUAL expression  */
#line 540 "src/parser.y"
                                         { (yyval.astNode) = new BinaryLogicalExpression("==", (yyvsp[-2].astNode), (yyvsp[0].astNode)); }
#line 2777 "src/generated/parser.cpp"
    break;

  case 130: /* comparison: comparison NOTEQUAL expression  */
#line 541 "src/parser.y"
                                            { (yyval.astNode) = new BinaryLogicalExpression("!=", (yyvsp[-2].astNode), (yyvsp[0].astNode)); }
#line 2783 "src/generated/parser.cpp"
    break;

  case 131: /* comparison: comparison KEYWORD_NOT KEYWORD_IN expression  */
#line 542 "src/parser.y"
                                                          { (yyval.astNode) = new BinaryLogicalExpression("not in", (yyvsp[-3].astNode), (yyvsp[0].astNode)); }
#line 2789 "src/generated/parser.cpp"
    break;

  case 132: /* comparison: comparison KEYWORD_IN expression  */
#line 543 "src/parser.y"
                                              { (yyval.astNode) = new BinaryLogicalExpression("in", (yyvsp[-2].astNode), (yyvsp[0].astNode)); }
#line 2795 "src/generated/parser.cpp"
    break;

  case 133: /* comparison: comparison KEYWORD_IS KEYWORD_NOT expression  */
#line 544 "src/parser.y"
                                                          { (yyval.astNode) = new BinaryLogicalExpression("is not", (yyvsp[-3].astNode), (yyvsp[0].astNode)); }
#line 2801 "src/generated/parser.cpp"
    break;

  case 134: /* comparison: comparison KEYWORD_IS expression  */
#line 545 "src/parser.y"
                                              { (yyval.astNode) = new BinaryLogicalExpression("is", (yyvsp[-2].astNode), (yyvsp[0].astNode)); }
#line 2807 "src/generated/parser.cpp"
    break;

  case 135: /* conditional_statement: if_statement elif_else  */
#line 548 "src/parser.y"
                                                      {
                              (yyvsp[-1].astNode)->add((yyvsp[0].astNode));
                              (yyval.astNode) = (yyvsp[-1].astNode);
                        }
#line 2816 "src/generated/parser.cpp"
    break;

  case 136: /* elif_else: %empty  */
#line 554 "src/parser.y"
                              { 
                  std::string name = "elif_else" + std::to_string(++n_nodes);
                  (yyval.astNode) = new EmptyNode(name); 
            }
#line 2825 "src/generated/parser.cpp"
    break;

  case 137: /* elif_else: elif_stmts else_statement  */
#line 558 "src/parser.y"
                                        {
                  (yyvsp[-1].astNode)->add((yyvsp[0].astNode));
                  (yyval.astNode) = (yyvsp[-1].astNode);
            }
#line 2834 "src/generated/parser.cpp"
    break;

  case 138: /* elif_else: elif_stmts  */
#line 562 "src/parser.y"
                              {
                  (yyval.astNode) = (yyvsp[0].astNode);
            }
#line 2842 "src/generated/parser.cpp"
    break;

  case 139: /* elif_else: else_statement  */
#line 565 "src/parser.y"
                              {
                  (yyval.astNode) = (yyvsp[0].astNode);
            }
#line 2850 "src/generated/parser.cpp"
    break;

  case 140: /* elif_stmts: elif_statement  */
#line 570 "src/parser.y"
                              {
                  (yyval.astNode) = (yyvsp[0].astNode);
            }
#line 2858 "src/generated/parser.cpp"
    break;

  case 141: /* elif_stmts: elif_stmts elif_statement  */
#line 573 "src/parser.y"
                                          {
                  (yyvsp[-1].astNode)->add((yyvsp[0].astNode));
                  (yyval.astNode) = (yyvsp[-1].astNode);
            }
#line 2867 "src/generated/parser.cpp"
    break;

  case 142: /* if_statement: KEYWORD_IF logical_expression COLON block  */
#line 579 "src/parser.y"
                                                                  {
                        std::string name = "if" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ConditionalStatement("if", name);
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2878 "src/generated/parser.cpp"
    break;

  case 143: /* if_statement: KEYWORD_IF LEFT_PARENTHES logical_expression RIGHT_PARENTHES COLON block  */
#line 585 "src/parser.y"
                                                                                             {
                        std::string name = "if" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ConditionalStatement("if", name);
                        (yyval.astNode)->add((yyvsp[-3].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2889 "src/generated/parser.cpp"
    break;

  case 144: /* else_statement: KEYWORD_ELSE COLON block  */
#line 593 "src/parser.y"
                                                {
                        std::string name = "else" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ConditionalStatement("else", name);
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2899 "src/generated/parser.cpp"
    break;

  case 145: /* elif_statement: KEYWORD_ELSE_IF logical_expression COLON block  */
#line 600 "src/parser.y"
                                                                        {
                        std::string name = "elif" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ConditionalStatement("elif", name);
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2910 "src/generated/parser.cpp"
    break;

  case 146: /* elif_statement: KEYWORD_ELSE_IF LEFT_PARENTHES logical_expression RIGHT_PARENTHES COLON block  */
#line 606 "src/parser.y"
                                                                                                      {
                        std::string name = "elif" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ConditionalStatement("elif", name);
                        (yyval.astNode)->add((yyvsp[-3].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2921 "src/generated/parser.cpp"
    break;

  case 147: /* for_statement: KEYWORD_FOR IDENTIFIER KEYWORD_IN function_call COLON block  */
#line 614 "src/parser.y"
                                                                                {
                        std::string name = "For" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ForNode(name);
                        (yyval.astNode)->add((yyvsp[-4].astNode));
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2933 "src/generated/parser.cpp"
    break;

  case 148: /* for_statement: KEYWORD_FOR IDENTIFIER KEYWORD_IN LIST COLON block  */
#line 621 "src/parser.y"
                                                                       {
                        std::string name = "For" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ForNode(name);
                        (yyval.astNode)->add((yyvsp[-4].astNode));
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2945 "src/generated/parser.cpp"
    break;

  case 149: /* for_statement: KEYWORD_FOR LEFT_PARENTHES args RIGHT_PARENTHES KEYWORD_IN function_call COLON block  */
#line 628 "src/parser.y"
                                                                                                         {
                        std::string name = "For" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ForNode(name);
                        (yyval.astNode)->add((yyvsp[-5].astNode));
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2957 "src/generated/parser.cpp"
    break;

  case 150: /* for_statement: KEYWORD_FOR IDENTIFIER KEYWORD_IN member_expression COLON block  */
#line 635 "src/parser.y"
                                                                                    {
                        std::string name = "For" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ForNode(name);
                        (yyval.astNode)->add((yyvsp[-4].astNode));
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2969 "src/generated/parser.cpp"
    break;

  case 151: /* for_statement: KEYWORD_FOR IDENTIFIER KEYWORD_IN member_expression function_call COLON block  */
#line 642 "src/parser.y"
                                                                                                  {
                        std::string name = "For" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ForNode(name);
                        (yyval.astNode)->add((yyvsp[-5].astNode));
                        (yyval.astNode)->add((yyvsp[-3].astNode));
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2982 "src/generated/parser.cpp"
    break;

  case 152: /* for_statement: KEYWORD_FOR IDENTIFIER KEYWORD_IN member_expression function_call '.' IDENTIFIER COLON block  */
#line 650 "src/parser.y"
                                                                                                                 {
                        std::string name = "For" + std::to_string(++n_nodes);
                        (yyval.astNode) = new ForNode(name);
                        (yyval.astNode)->add((yyvsp[-7].astNode));
                        (yyval.astNode)->add((yyvsp[-5].astNode));
                        (yyval.astNode)->add((yyvsp[-4].astNode));
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 2996 "src/generated/parser.cpp"
    break;

  case 153: /* while_statement: KEYWORD_WHILE logical_expression COLON block  */
#line 661 "src/parser.y"
                                                                 {
                        std::string name = "While" + std::to_string(++n_nodes);
                        (yyval.astNode) = new WhileNode(name);
                        (yyval.astNode)->add((yyvsp[-2].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 3007 "src/generated/parser.cpp"
    break;

  case 154: /* while_statement: KEYWORD_WHILE LEFT_PARENTHES logical_expression RIGHT_PARENTHES COLON block  */
#line 667 "src/parser.y"
                                                                                                {
                        std::string name = "While" + std::to_string(++n_nodes);
                        (yyval.astNode) = new WhileNode(name);
                        (yyval.astNode)->add((yyvsp[-3].astNode));
                        (yyval.astNode)->add((yyvsp[0].astNode));
                  }
#line 3018 "src/generated/parser.cpp"
    break;


#line 3022 "src/generated/parser.cpp"

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

#line 675 "src/parser.y"


int main(int argc, char **argv) {
      if (argc > 1) {
            yyin = fopen(argv[1], "r");
            if (yyin == nullptr) {
                  std::cerr << "Cannot open input file: " << argv[1] << std::endl;
                  return 1;
            }
      } else {
            yyin = stdin;
      }
      
      if (yyparse() != 0) {
            return 1;
      }

      if (root != NULL) {
            AST ast(root);
            ast.Print();
      }
      return 0;
}

void yyerror(const char* s) {
      std::cerr << "Parser error: " << s << std::endl;
}
