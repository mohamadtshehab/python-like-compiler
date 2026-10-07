%option noyywrap
%{
#ifdef _MSC_VER
#pragma warning (disable: 4005)
#endif
#include "parser.hpp"
#include "python_ast_node.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
using namespace std;
extern int yylex();
int number_of_nodes = 0;
string name = "";
char firstChar;
char *copyyytext;
%}

/* Regular expressions to match tokens */
LETTER                  [_a-zA-Z]
ALPHANUM                {LETTER}|[0-9]
IDENTIFIER              {LETTER}{ALPHANUM}*
LIST                    (\[\s*([^,\[\]]+)\s*(,\s*([^,\[\]]+)\s*)*\])
LITERALSTRING           \"([^\"\\\\]|\\\\.)*\" 
LITERALCHAR             \"([^\"]|\\\\.)\" 
KEYWORD_FALSE           False
KEYWORD_TRUE            True
KEYWORD_AWAIT           await           
KEYWORD_IF              if
KEYWORD_ELSE            else
KEYWORD_ELSE_IF         elif|"else if"
KEYWORD_IMPORT          import
KEYWORD_PASS            pass
KEYWORD_NONE            None
KEYWORD_BREAK           break
KEYWORD_EXCEPT          except
KEYWORD_IN              in
KEYWORD_RAISE           raise
KEYWORD_CLASS           class
KEYWORD_FINALLY         finally
KEYWORD_IS              is
KEYWORD_RETURN          return
KEYWORD_AND             and
KEYWORD_CONTINUE        continue
KEYWORD_FOR             for
KEYWORD_LAMBDA          lambda
KEYWORD_TRY             try
KEYWORD_AS              as
KEYWORD_DEF             def
KEYWORD_FROM            from    
KEYWORD_NONLOCAL        nonlocal
KEYWORD_WHILE           while
KEYWORD_ASSERT          assert
KEYWORD_DEL             del
KEYWORD_GLOBAL          global
KEYWORD_NOT             not
KEYWORD_WITH            with
KEYWORD_ASYNC           async
KEYWORD_OR              or
KEYWORD_YIELD           yield
KEYWORD_MATCH           match
KEYWORD_CASE            case
OPERATORS               [+\-*/=(){}\[\]:,;<>!]=?
COMMENT                 "#".*
ADD                     "+"
MINUS                   "-"
MULTIPLY                "*"
DIVIDE                  "/"
POWER                   "**"
MODULO                  "%"
ASSIGN                  "="
ASSIGNADD               "+="
ASSIGNMINUS             "-="
ASSIGNMULTIPLY          "*="
ASSIGNDIVIDE            "/="
ASSIGNMODULO            "%="
ASSIGNFLOORDIVISION     "//="
ASSIGNEXPONINTIATION    "**="
ASSIGNBITWISEAND        "&="
ASSIGNBITWISEOR         "|="
ASSIGNBITWISEXOR        "^="
ASSIGNRIGHTSHIFT        ">>="
ASSIGNLEFTSHIFT         "<<="
EQUAL                   "=="
NOT                     "!"
NOTEQUAL                "!="
GREATERTHAN             ">"
GREATEROREQUAL          ">="
LESSTHAN                "<"
LESSOREQUAL             "<="
LEFT_PARENTHES          "("
RIGHT_PARENTHES         ")"
LEFT_BRACES             "{"
RIGHT_BRACES            "}"
LEFT_BRACKETS           "["
RIGHT_BRACKETS          "]"
COLON                   ":"
COMMA                   ","
SEMICOLON               ";"
INTEGER                 [0-9]+
FLOAT                   [0-9]+"."[0-9]+([Ee][+-]?[0-9]+)?


%{
int nodeNumber = 0;
int grouping_depth = 0;
typedef struct stack {
    int data;
    struct stack *next;
} stack;

stack *top = NULL;

void push(int value) {
    stack *new_node = (stack *) malloc(sizeof(stack));
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

int pop() {
    if (top == NULL) 
        return -1;
    int value = top->data;
    stack *temp = top;
    top = top->next;
    free(temp);
    return value;
}

int peek() {
    if (top == NULL) 
        return -1;
    return top->data;
}

int count_spaces(char *str) {
    int count = 0;
    while (*str == ' ' || *str == '\t') {
        count++;
        str++;
    }
    return count;
}
%}

/* start state for parsing the indentation */
%x indent
%x comment
%x string
/* normal start state for everything else */
%s normal 

%%

<indent>[ ]+ { 
    int current = count_spaces(yytext);
    if (current > peek()) {
        push(current);
        return INDENT;
    }else if(current < peek()) {
        pop();
        return DEDENT;
    }
}

<indent>"\n" {
    BEGIN (indent);
    return NEWLINE;
}

<indent>[\"|\']{3} { 
    BEGIN (comment);
}

<indent>. {
    unput(*yytext);
    BEGIN (normal);
}

<comment>[^\\\\|\"|\']+         { }
<comment>\\\\(.|\\n)            { } 
<comment>[\"|\'][\"|\']?        { } 
<comment>[\"|\']{3}             { BEGIN (indent); return MULTILINECOMMENT; }

"\n" {
    if (grouping_depth == 0) {
        BEGIN (indent);
        return NEWLINE;
    }
    BEGIN (normal);
}
[	 ]+                  { }
<normal>[\"|\']{3} {
    BEGIN (string);
}

<string>[^\\\\|\"|\']+         { }
<string>\\\\(.|\\n)            { }
<string>[\"|\'][\"|\']?        { }
<string>[\"|\']{3}             { BEGIN (indent); return MULTILINESTRING; }

{ADD}                   {/*printf("ADD: %s\n", yytext);*/return ADD;}
{MINUS}                 {/*printf("MINUS: %s\n", yytext);*/return MINUS;}
{MULTIPLY}              {/*printf("MULTIPLY: %s\n", yytext);*/return MULTIPLY;}
{DIVIDE}                {/*printf("DIVIDE: %s\n", yytext);*/return DIVIDE;}
{POWER}                 {/*printf("POWER: %s\n", yytext);*/return POWER;}
{MODULO}                {/*printf("MODULO: %s\n", yytext);*/return MODULO;}
{ASSIGN}                {/*printf("ASSIGN: %s\n", yytext);*/return ASSIGN;}
{ASSIGNADD}             {/*printf("ASSIGN_ADD: %s\n", yytext);*/return ASSIGNADD;}
{ASSIGNMINUS}           {/*printf("ASSIGN_MINUS: %s\n", yytext);*/return ASSIGNMINUS;}
{ASSIGNMULTIPLY}        {/*printf("ASSIGN_MULTIPLY: %s\n", yytext);*/return ASSIGNMULTIPLY;}
{ASSIGNDIVIDE}          {/*printf("ASSIGN_DIVIDE: %s\n", yytext);*/return ASSIGNDIVIDE;}
{ASSIGNMODULO}          {/*printf("ASSIGN_MODULO: %s\n", yytext);*/return ASSIGNMODULO;}
{ASSIGNFLOORDIVISION}   {/*printf("ASSIGN_FLOOR_DIVISION: %s\n", yytext);*/return ASSIGNFLOORDIVISION;}
{ASSIGNEXPONINTIATION}  {/*printf("ASSIGN_EXPONINTIATION: %s\n", yytext);*/return ASSIGNEXPONINTIATION;}
{ASSIGNBITWISEAND}      {/*printf("ASSIGN_BITWISE_AND: %s\n", yytext);*/return ASSIGNBITWISEAND;}
{ASSIGNBITWISEOR}       {/*printf("ASSIGN_BITWISE_OR: %s\n", yytext);*/return ASSIGNBITWISEOR;}
{ASSIGNBITWISEXOR}      {/*printf("ASSIGN_BITWISE_XOR: %s\n", yytext);*/return ASSIGNBITWISEXOR;}
{ASSIGNRIGHTSHIFT}      {/*printf("ASSIGN_RIGHT_SHIFT: %s\n", yytext);*/return ASSIGNRIGHTSHIFT;}
{ASSIGNLEFTSHIFT}       {/*printf("ASSIGN_LEFT_SHIFT: %s\n", yytext);*/return ASSIGNLEFTSHIFT;}
{EQUAL}                 {/*printf("EQUAL: %s\n", yytext);*/return EQUAL;}    
{NOT}                   {/*printf("NOT: %s\n", yytext);*/return NOT;}
{NOTEQUAL}              {/*printf("NOT_EQUAL: %s\n", yytext);*/return NOTEQUAL;}
{GREATERTHAN}           {/*printf("GREATER_THAN: %s\n", yytext);*/return GREATERTHAN;}
{GREATEROREQUAL}        {/*printf("GREATER_OR_EQUAL: %s\n", yytext);*/return GREATEROREQUAL;}
{LESSTHAN}              {/*printf("LESS_THAN: %s\n", yytext);*/return LESSTHAN;}
{LESSOREQUAL}           {/*printf("LESS_OR_EQUAL: %s\n", yytext);*/return LESSOREQUAL;}
{LEFT_PARENTHES}        { ++grouping_depth; return LEFT_PARENTHES; }
{RIGHT_PARENTHES}       { if (grouping_depth > 0) --grouping_depth; return RIGHT_PARENTHES; }
{LEFT_BRACES}           { ++grouping_depth; return LEFT_BRACES; }
{RIGHT_BRACES}          { if (grouping_depth > 0) --grouping_depth; return RIGHT_BRACES; }
{LEFT_BRACKETS}         { ++grouping_depth; return LEFT_BRACKETS; }
{RIGHT_BRACKETS}        { if (grouping_depth > 0) --grouping_depth; return RIGHT_BRACKETS; }
{COLON}                 {/*printf("COLON: %s\n", yytext);*/return COLON;}
{COMMA}                 {/*printf("COMMA: %s\n", yytext);*/return COMMA;}
{SEMICOLON}             {/*printf("SEMICOLON: %s\n", yytext);*/return SEMICOLON;}
"."                     { return '.'; }
{COMMENT}               {
                            yylval.astNode = new CommentNode("COMMENT" + to_string(++nodeNumber), "COMMENT", yytext);
                            return COMMENT;
                        }
{OPERATORS}		        {/*printf("OPERATOR: %s\n", yytext);*/return OPERATORS;}
{KEYWORD_FALSE}         {
                            yylval.astNode = new KeywordNode("Keyword_FALSE" + to_string(++nodeNumber), "Keyword_FALSE", yytext);
                            return KEYWORD_FALSE;
                        }
{KEYWORD_TRUE}          {
                            yylval.astNode = new KeywordNode("Keyword_TRUE" + to_string(++nodeNumber), "Keyword_TRUE", yytext);
                            return KEYWORD_TRUE;
                        }
{KEYWORD_IF}            {/*printf("KEYWORD_IF: %s \n",yytext);*/return KEYWORD_IF;}
{KEYWORD_ELSE}          {/*printf("KEYWORD_ELSE: %s \n",yytext);*/return KEYWORD_ELSE;}
{KEYWORD_ELSE_IF}       {/*printf("KEYWORD_ELSE_IF: %s \n",yytext);*/return KEYWORD_ELSE_IF;}
{KEYWORD_IMPORT}        {/*printf("KEYWORD_IMPORT: %s \n",yytext);*/return KEYWORD_IMPORT;}
{KEYWORD_PASS}          {
                            
                            yylval.astNode = new KeywordNode("Keyword_PASS" + to_string(++nodeNumber), "Keyword_PASS", yytext);
                            return KEYWORD_PASS;
                        }
{KEYWORD_NONE}          {/*printf("NONE: %s \n",yytext);*/return KEYWORD_NONE;}
{KEYWORD_BREAK}         {
                            yylval.astNode = new KeywordNode("Keyword_BREAK" + to_string(++nodeNumber), "Keyword_BREAK", yytext);
                            return KEYWORD_BREAK;
                        }
{KEYWORD_EXCEPT}        {/*printf("KEYWORD_PASS: %s \n",yytext);*/return KEYWORD_EXCEPT;}
{KEYWORD_IN}            {/*printf("KEYWORD_IN: %s \n",yytext);*/return KEYWORD_IN;}
{KEYWORD_RAISE}         {/*printf("KEYWORD_RAISE: %s \n",yytext);*/return KEYWORD_RAISE;}
{KEYWORD_CLASS}         {/*printf("KEYWORD_CLASS: %s \n",yytext);*/return KEYWORD_CLASS;}
{KEYWORD_FINALLY}       {/*printf("KEYWORD_FINALLY: %s \n",yytext);*/return KEYWORD_FINALLY;}
{KEYWORD_IS}            {/*printf("KEYWORD_IS: %s \n",yytext);*/return KEYWORD_IS;}
{KEYWORD_RETURN}        {/*printf("KEYWORD_RETURN: %s \n",yytext);*/return KEYWORD_RETURN;}
{KEYWORD_AND}           {/*printf("KEYWORD_AND: %s \n",yytext);*/return KEYWORD_AND;}
{KEYWORD_CONTINUE}      {/*printf("KEYWORD_CONTINUE: %s \n",yytext);*/return KEYWORD_CONTINUE;}
{KEYWORD_FOR}           {/*printf("KEYWORD_FOR: %s \n",yytext);*/return KEYWORD_FOR;}
{KEYWORD_TRY}           {/*printf("KEYWORD_TRY: %s \n",yytext);*/return KEYWORD_TRY;}
{KEYWORD_AS}            {/*printf("KEYWORD_AS: %s \n",yytext);*/return KEYWORD_AS;}
{KEYWORD_DEF}           {/*printf("KEYWORD_DEF: %s \n",yytext);*/return KEYWORD_DEF;}
{KEYWORD_FROM}          {/*printf("KEYWORD_FROM: %s \n",yytext);*/return KEYWORD_FROM;}
{KEYWORD_NONLOCAL}      {/*printf("KEYWORD_NONLOCAL: %s \n",yytext);*/return KEYWORD_NONLOCAL;}
{KEYWORD_WHILE}         {/*printf("KEYWORD_WHILE: %s \n",yytext);*/return KEYWORD_WHILE;}
{KEYWORD_ASSERT}        {/*printf("KEYWORD_ASSERT: %s \n",yytext);*/return KEYWORD_ASSERT;}
{KEYWORD_DEL}           {/*printf("KEYWORD_DEL: %s \n",yytext);*/return KEYWORD_DEL;}
{KEYWORD_GLOBAL}        {/*printf("KEYWORD_GLOBAL: %s \n",yytext);*/return KEYWORD_GLOBAL;}
{KEYWORD_NOT}           {/*printf("KEYWORD_NOT: %s \n",yytext);*/return KEYWORD_NOT;}
{KEYWORD_WITH}          {/*printf("KEYWORD_WITH: %s \n",yytext);*/return KEYWORD_WITH;}
{KEYWORD_ASYNC}         {/*printf("KEYWORD_ASYNC: %s \n",yytext);*/return KEYWORD_ASYNC;}
{KEYWORD_OR}            {/*printf("KEYWORD_OR: %s \n",yytext);*/return KEYWORD_OR;}
{KEYWORD_YIELD}         {/*printf("KEYWORD_YIELD: %s \n",yytext);*/return KEYWORD_YIELD;}
{KEYWORD_MATCH}         {/*printf("KEYWORD_MATCH: %s \n",yytext);*/return KEYWORD_MATCH;}
{KEYWORD_CASE}          {/*printf("KEYWORD_CASE: %s \n",yytext);*/return KEYWORD_CASE;}
{LITERALSTRING}         {
                            yylval.astNode = new StringNode("String" + to_string(++nodeNumber), "String", yytext);
                            return LITERALSTRING;
                        }
{LITERALCHAR}           {/*printf("CHAR_LITERAL: %s\n", yytext);*/return LITERALCHAR;}
{LIST}                  {/*printf("list: %s \n",yytext);*/return LIST;}
{IDENTIFIER}            {/*printf("IDENTIFIER: %s \n",yytext);*/
                            name = "IDENTIFIER" + to_string(number_of_nodes);
                            ++number_of_nodes;
                            yylval.astNode = new IdentifierNode(name, "Identifier", yytext);
                            return IDENTIFIER;
                        }
{INTEGER}               {   
                            name = "INTEGER" + to_string(number_of_nodes);
                            ++number_of_nodes;
                            yylval.astNode = new NumberNode(name, "Integer", atoi(yytext));
                            return INTEGER;
                        }
{FLOAT}                 {
                            name = "FLOAT" + to_string(number_of_nodes);
                            ++number_of_nodes;
                            yylval.astNode = new NumberNode(name, "Float", atoi(yytext));
                            return FLOAT;
                        }
. 			            {/* Ignore everything else. */ BEGIN (indent);}
<<EOF>>                 {
                            if (peek() != -1) {
                                pop();
                                return DEDENT;
                            }
                            yyterminate();
                        }

%%
