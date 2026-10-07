/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_GENERATED_PARSER_HPP_INCLUDED
# define YY_YY_SRC_GENERATED_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

      #include "python_ast_node.hpp"
      #include <iostream>
      #include <string>

#line 55 "src/generated/parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    WHITESPACE = 258,              /* WHITESPACE  */
    LETTER = 259,                  /* LETTER  */
    ALPHANUM = 260,                /* ALPHANUM  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    LIST = 262,                    /* LIST  */
    LITERALSTRING = 263,           /* LITERALSTRING  */
    LITERALCHAR = 264,             /* LITERALCHAR  */
    KEYWORD_FALSE = 265,           /* KEYWORD_FALSE  */
    KEYWORD_TRUE = 266,            /* KEYWORD_TRUE  */
    MULTILINESTRING = 267,         /* MULTILINESTRING  */
    KEYWORD_AWAIT = 268,           /* KEYWORD_AWAIT  */
    KEYWORD_IF = 269,              /* KEYWORD_IF  */
    KEYWORD_ELSE = 270,            /* KEYWORD_ELSE  */
    KEYWORD_ELSE_IF = 271,         /* KEYWORD_ELSE_IF  */
    KEYWORD_IMPORT = 272,          /* KEYWORD_IMPORT  */
    KEYWORD_PASS = 273,            /* KEYWORD_PASS  */
    KEYWORD_NONE = 274,            /* KEYWORD_NONE  */
    KEYWORD_BREAK = 275,           /* KEYWORD_BREAK  */
    KEYWORD_EXCEPT = 276,          /* KEYWORD_EXCEPT  */
    KEYWORD_IN = 277,              /* KEYWORD_IN  */
    KEYWORD_RAISE = 278,           /* KEYWORD_RAISE  */
    KEYWORD_CLASS = 279,           /* KEYWORD_CLASS  */
    KEYWORD_FINALLY = 280,         /* KEYWORD_FINALLY  */
    KEYWORD_IS = 281,              /* KEYWORD_IS  */
    KEYWORD_RETURN = 282,          /* KEYWORD_RETURN  */
    KEYWORD_AND = 283,             /* KEYWORD_AND  */
    KEYWORD_CONTINUE = 284,        /* KEYWORD_CONTINUE  */
    KEYWORD_FOR = 285,             /* KEYWORD_FOR  */
    KEYWORD_LAMBDA = 286,          /* KEYWORD_LAMBDA  */
    KEYWORD_TRY = 287,             /* KEYWORD_TRY  */
    KEYWORD_AS = 288,              /* KEYWORD_AS  */
    KEYWORD_DEF = 289,             /* KEYWORD_DEF  */
    KEYWORD_FROM = 290,            /* KEYWORD_FROM  */
    KEYWORD_NONLOCAL = 291,        /* KEYWORD_NONLOCAL  */
    KEYWORD_WHILE = 292,           /* KEYWORD_WHILE  */
    KEYWORD_ASSERT = 293,          /* KEYWORD_ASSERT  */
    KEYWORD_DEL = 294,             /* KEYWORD_DEL  */
    KEYWORD_GLOBAL = 295,          /* KEYWORD_GLOBAL  */
    KEYWORD_NOT = 296,             /* KEYWORD_NOT  */
    KEYWORD_WITH = 297,            /* KEYWORD_WITH  */
    KEYWORD_ASYNC = 298,           /* KEYWORD_ASYNC  */
    KEYWORD_OR = 299,              /* KEYWORD_OR  */
    KEYWORD_YIELD = 300,           /* KEYWORD_YIELD  */
    OPERATORS = 301,               /* OPERATORS  */
    COMMENT = 302,                 /* COMMENT  */
    ADD = 303,                     /* ADD  */
    MINUS = 304,                   /* MINUS  */
    MULTIPLY = 305,                /* MULTIPLY  */
    MULTILINECOMMENT = 306,        /* MULTILINECOMMENT  */
    DIVIDE = 307,                  /* DIVIDE  */
    POWER = 308,                   /* POWER  */
    MODULO = 309,                  /* MODULO  */
    ASSIGN = 310,                  /* ASSIGN  */
    ASSIGNADD = 311,               /* ASSIGNADD  */
    ASSIGNMINUS = 312,             /* ASSIGNMINUS  */
    ASSIGNMULTIPLY = 313,          /* ASSIGNMULTIPLY  */
    ASSIGNDIVIDE = 314,            /* ASSIGNDIVIDE  */
    ASSIGNMODULO = 315,            /* ASSIGNMODULO  */
    ASSIGNFLOORDIVISION = 316,     /* ASSIGNFLOORDIVISION  */
    ASSIGNEXPONINTIATION = 317,    /* ASSIGNEXPONINTIATION  */
    ASSIGNBITWISEAND = 318,        /* ASSIGNBITWISEAND  */
    ASSIGNBITWISEOR = 319,         /* ASSIGNBITWISEOR  */
    ASSIGNBITWISEXOR = 320,        /* ASSIGNBITWISEXOR  */
    ASSIGNRIGHTSHIFT = 321,        /* ASSIGNRIGHTSHIFT  */
    ASSIGNLEFTSHIFT = 322,         /* ASSIGNLEFTSHIFT  */
    EQUAL = 323,                   /* EQUAL  */
    NOT = 324,                     /* NOT  */
    NOTEQUAL = 325,                /* NOTEQUAL  */
    GREATERTHAN = 326,             /* GREATERTHAN  */
    GREATEROREQUAL = 327,          /* GREATEROREQUAL  */
    LESSTHAN = 328,                /* LESSTHAN  */
    LESSOREQUAL = 329,             /* LESSOREQUAL  */
    LEFT_PARENTHES = 330,          /* LEFT_PARENTHES  */
    RIGHT_PARENTHES = 331,         /* RIGHT_PARENTHES  */
    LEFT_BRACES = 332,             /* LEFT_BRACES  */
    RIGHT_BRACES = 333,            /* RIGHT_BRACES  */
    LEFT_BRACKETS = 334,           /* LEFT_BRACKETS  */
    RIGHT_BRACKETS = 335,          /* RIGHT_BRACKETS  */
    COLON = 336,                   /* COLON  */
    COMMA = 337,                   /* COMMA  */
    SEMICOLON = 338,               /* SEMICOLON  */
    INTEGER = 339,                 /* INTEGER  */
    FLOAT = 340,                   /* FLOAT  */
    DEDENT = 341,                  /* DEDENT  */
    INDENT = 342,                  /* INDENT  */
    NEWLINE = 343,                 /* NEWLINE  */
    KEYWORD_MATCH = 344,           /* KEYWORD_MATCH  */
    KEYWORD_CASE = 345,            /* KEYWORD_CASE  */
    UMINUS = 346                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 6 "src/parser.y"

	AstNode* astNode;

#line 167 "src/generated/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_GENERATED_PARSER_HPP_INCLUDED  */
