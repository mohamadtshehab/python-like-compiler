%code requires {
      #include "python_ast_node.hpp"
      #include <iostream>
      #include <string>
}
%union{
	AstNode* astNode;
}
%{
      extern int yylex();
      extern int yyparse();
      extern FILE *yyin;
      void yyerror(const char *);
      AstNode* root = NULL;
      int n_nodes = 0;
%}
/* Tokens */
%token <astNode> WHITESPACE LETTER ALPHANUM IDENTIFIER LIST
%token <astNode> LITERALSTRING LITERALCHAR KEYWORD_FALSE KEYWORD_TRUE MULTILINESTRING
%token <astNode> KEYWORD_AWAIT KEYWORD_IF KEYWORD_ELSE KEYWORD_ELSE_IF 
%token <astNode> KEYWORD_IMPORT KEYWORD_PASS KEYWORD_NONE KEYWORD_BREAK
%token <astNode> KEYWORD_EXCEPT KEYWORD_IN KEYWORD_RAISE KEYWORD_CLASS
%token <astNode> KEYWORD_FINALLY KEYWORD_IS KEYWORD_RETURN KEYWORD_AND
%token <astNode> KEYWORD_CONTINUE KEYWORD_FOR KEYWORD_LAMBDA KEYWORD_TRY
%token <astNode> KEYWORD_AS KEYWORD_DEF KEYWORD_FROM KEYWORD_NONLOCAL
%token <astNode> KEYWORD_WHILE KEYWORD_ASSERT KEYWORD_DEL KEYWORD_GLOBAL
%token <astNode> KEYWORD_NOT KEYWORD_WITH KEYWORD_ASYNC KEYWORD_OR
%token <astNode> KEYWORD_YIELD OPERATORS COMMENT ADD MINUS MULTIPLY MULTILINECOMMENT 
%token <astNode> DIVIDE POWER MODULO ASSIGN ASSIGNADD ASSIGNMINUS 
%token <astNode> ASSIGNMULTIPLY ASSIGNDIVIDE ASSIGNMODULO ASSIGNFLOORDIVISION
%token <astNode> ASSIGNEXPONINTIATION ASSIGNBITWISEAND ASSIGNBITWISEOR
%token <astNode> ASSIGNBITWISEXOR ASSIGNRIGHTSHIFT ASSIGNLEFTSHIFT EQUAL NOT
%token <astNode> NOTEQUAL GREATERTHAN GREATEROREQUAL LESSTHAN LESSOREQUAL
%token <astNode> LEFT_PARENTHES RIGHT_PARENTHES LEFT_BRACES RIGHT_BRACES 
%token <astNode> LEFT_BRACKETS RIGHT_BRACKETS COLON COMMA SEMICOLON
%token <astNode> INTEGER FLOAT DEDENT INDENT NEWLINE KEYWORD_MATCH KEYWORD_CASE
%type  <astNode> prog statements statement simple_statement compound_statement import_statment
%type  <astNode> assignment expression number del_statment return_statement yield_statement assert_statement 
%type  <astNode> raise_statement global_statement nonlocal_statement global_nonlocal_targets match_statement match_block 
%type  <astNode> case try_statement try except finally except_statements with with_statements class 
%type  <astNode> class_block  class_body function_call function block args arg parameters parameter_list parameter member_expression logical_expression logical_or logical_and logical_not comparison
%type  <astNode> set_items
%type  <astNode> conditional_statement elif_else elif_stmts if_statement else_statement elif_statement for_statement while_statement
%define parse.error verbose
%nonassoc EQUAL
%left '+' '-'
%left '*' '/'
%nonassoc '|' UMINUS

%%

prog  : /*Empty*/ { 
            std::string name = "Program" + std::to_string(++n_nodes);
            $$ = new EmptyNode(name); 
      }
      | NEWLINE         {
            std::string name = "Program" + std::to_string(++n_nodes);
            $$ = new EmptyNode(name);
      }
      | prog statements {     
            std::string name = "Program" + std::to_string(++n_nodes);
            $$ = new StatementsNode(name);
            $$->add($1);
            $$->add($2);
            root = $$;
            YYACCEPT;
      }
      ;

statements  : /*Empty*/ {
                  std::string name = "Statement" + std::to_string(++n_nodes);
                  $$ = new StatementsNode(name);
            }
            | statements statement  { 
                  if ($2 != nullptr) $1->add($2);
                  $$ = $1; 
            }
            ;

statement   : compound_statement    { $$ = $1; }
            | simple_statement      { $$ = $1; }
            | NEWLINE             { $$ = nullptr; }
            | COMMENT             { $$ = $1; }
            | MULTILINECOMMENT    { $$ = nullptr; }
            ;

simple_statement  : assignment            { $$ = $1; }
                  | return_statement      { $$ = $1; }
                  | yield_statement       { $$ = $1; }
                  | assert_statement      { $$ = $1; }
                  | raise_statement       { $$ = $1; }
                  | global_statement      { $$ = $1; }
                  | nonlocal_statement    { $$ = $1; }
                  | del_statment          { $$ = $1; }
                  | import_statment       { $$ = $1; }
                  | function_call         { $$ = $1; }
                  | with                  { $$ = $1; }
                  | KEYWORD_PASS          { $$ = $1; }
                  | KEYWORD_BREAK         { $$ = $1; }
                  | KEYWORD_CONTINUE      { $$ = $1; }
                  ;

compound_statement: function                    { $$ = $1; }
                  | conditional_statement       { $$ = $1; }
                  | class                       { $$ = $1; }
                  | for_statement               { $$ = $1; }
                  | while_statement             { $$ = $1; }
                  | match_statement             { $$ = $1; }
                  | try_statement               { $$ = $1; }
                  ;


import_statment   : KEYWORD_IMPORT member_expression {
                        std::string name = "Import" + std::to_string(++n_nodes);
                        $$ = new ImportNode(name);
                        $$->add($2);
                  }
                  | KEYWORD_FROM member_expression KEYWORD_IMPORT IDENTIFIER {
                        std::string name = "Import" + std::to_string(++n_nodes);
                        $$ = new ImportNode(name);
                        $$->add($2);
                        $$->add($4);
                  }
                  | KEYWORD_FROM member_expression KEYWORD_IMPORT MULTIPLY {
                        std::string name = "Import" + std::to_string(++n_nodes);
                        $$ = new ImportNode(name);
                        $$->add($2);
                  }
                  | KEYWORD_IMPORT member_expression KEYWORD_AS IDENTIFIER {
                        std::string name = "Import" + std::to_string(++n_nodes);
                        $$ = new ImportNode(name);
                        $$->add($2);
                        $$->add($4);
                  }
                  | KEYWORD_FROM member_expression KEYWORD_IMPORT IDENTIFIER KEYWORD_AS IDENTIFIER {
                        std::string name = "Import" + std::to_string(++n_nodes);
                        $$ = new ImportNode(name);
                        $$->add($2);
                        $$->add($4);
                        $$->add($6);
                  }
                  ;

assignment  : member_expression ASSIGN expression {  
                  std::string name = "assignment" + std::to_string(++n_nodes);
                  $$ = new AssignmentStatement(name);
                  $$->add($1);
                  $$->add($3);
            }
            ;

expression  : expression ADD expression   { 
                  $$ = new BinaryExpressionNode("+", $1, $3);
            } 
            | expression MINUS expression       { 
                  $$ = new BinaryExpressionNode("-", $1, $3);
            }
            | expression MULTIPLY expression    { 
                  $$ = new BinaryExpressionNode("*", $1, $3);
            }
            | expression DIVIDE expression      { 
                  $$ = new BinaryExpressionNode("/", $1, $3);
            }
            | expression POWER expression       { 
                  $$ = new BinaryExpressionNode("**", $1, $3);
            }
            | expression MODULO expression      {
                  $$ = new BinaryExpressionNode("%", $1, $3);
            }
            | '|' expression  %prec UMINUS      { /*The rule for negation includes %prec UMINUS . The only operator in this rule is - , 
                                                      which has low precedence, but we want unary minus to have higher precedence than multiplication 
                                                      rather than lower. The %prec tells bison to use the precedence of UMINUS for this rule.*/
                                                }
            | LEFT_PARENTHES expression RIGHT_PARENTHES                {$$ = $2; }
            | MINUS expression %prec UMINUS       { }
            | LIST
            | KEYWORD_NONE                      { $$ = $1; }
            | number                            { $$ = $1; }
            | member_expression                 { $$ = $1; }
            | function_call                     { $$ = $1; }
            | LITERALSTRING                     { $$ = $1; }
            | LEFT_BRACES set_items RIGHT_BRACES { $$ = $2; }
            ;

set_items : expression {
                  $$ = new SetNode("Set" + std::to_string(++n_nodes));
                  $$->add($1);
            }
            | set_items COMMA expression {
                  $1->add($3);
                  $$ = $1;
            }
            | set_items COMMA { $$ = $1; }
            ;

number: INTEGER { $$ = $1; }
      | FLOAT   { $$ = $1; }
      ;

del_statment      : KEYWORD_DEL IDENTIFIER      {
                        std::string name = "Del" + std::to_string(++n_nodes);
                        $$ = new DelNode(name);
                        $$->add($2);
                  }
                  | KEYWORD_DEL IDENTIFIER LIST { 
                        std::string name = "Del" + std::to_string(++n_nodes);
                        $$ = new DelNode(name);
                        $$->add($2);
                        $$->add($3);
                  }
                  ;

return_statement  : KEYWORD_RETURN expression {
                        std::string name = "Return" + std::to_string(++n_nodes);
                        $$ = new ReturnNode(name);
                        $$->add($2);
                  }
                  | KEYWORD_RETURN logical_expression {
                        std::string name = "Return" + std::to_string(++n_nodes);
                        $$ = new ReturnNode(name);
                        $$->add($2);
                  }
                  ;

yield_statement  :  KEYWORD_YIELD expression    {
                        std::string name = "Yield" + std::to_string(++n_nodes);
                        $$ = new YieldNode(name);
                        $$->add($2);
                  }
                  ;

assert_statement  : KEYWORD_ASSERT logical_expression {
                        std::string name = "Assert" + std::to_string(++n_nodes);
                        $$ = new AssertNode(name);
                        $$->add($2);
                  }
                  | KEYWORD_ASSERT logical_expression COMMA LITERALSTRING {
                  }
                  ;

raise_statement   : KEYWORD_RAISE function_call {
                        std::string name = "Raise" + std::to_string(++n_nodes);
                        $$ = new RaiseNode(name);
                        $$->add($2);
                  }
                  | KEYWORD_RAISE function_call KEYWORD_FROM IDENTIFIER {
                        std::string name = "Raise" + std::to_string(++n_nodes);
                        $$ = new RaiseNode(name);
                        $$->add($2);
                        $$->add($4);
                  }
                  ;

global_statement  : KEYWORD_GLOBAL global_nonlocal_targets {
                        std::string name = "Global" + std::to_string(++n_nodes);
                        $$ = new GlobalNode(name);
                        $$->add($2);
                  }
                  ;

nonlocal_statement      : KEYWORD_NONLOCAL global_nonlocal_targets {
                              std::string name = "NonLocal" + std::to_string(++n_nodes);
                              $$ = new NonLocalNode(name);
                              $$->add($2);
                        }
                        ;

global_nonlocal_targets : IDENTIFIER {
                              $$ = $1;
                        }
                        | IDENTIFIER COMMA global_nonlocal_targets { 
                              $1->add($3);
                              $$ = $1;
                        }
                        ;

match_statement   : KEYWORD_MATCH IDENTIFIER COLON NEWLINE INDENT match_block DEDENT {
                        std::string name = dynamic_cast<IdentifierNode*>($2)->value;
                        $$ = new MatchNode(name);
                        $$->add($2);
                        $$->add($6);
                  }
                  ;

match_block : match_block case      { 
                  $1->add($2);
                  $$ = $1;
            }
            | case      {
                  std::string name = "MatchBlock" + std::to_string(++n_nodes);
                  $$ = new MatchBlock(name);
                  $$->add($1);
            }
            ;

case  : KEYWORD_CASE expression COLON block {
            std::string name = "Case" + std::to_string(++n_nodes);
            $$ = new CaseNode(name);
            $$->add($2);
            $$->add($4);
      }
      ;

try_statement     : try finally {
                        $$->add($1);
                        $$->add($2);
                  }
                  | try except_statements {
                        $$->add($1);
                        $$->add($2);
                  }
                  | try except_statements finally {
                        $$->add($1);
                        $$->add($2);
                        $$->add($3);
                  }
                  | try except_statements else_statement {
                        $$->add($1);
                        $$->add($2);
                        $$->add($3);
                  }
                  | try except_statements else_statement finally{
                        $$->add($1);
                        $$->add($2);
                        $$->add($3);
                        $$->add($4);
                  }
                  ;

try   : KEYWORD_TRY COLON block {
            std::string name = "Try" + std::to_string(++n_nodes);
            $$ = new TryNode(name);
            $$->add($3);
      }
      ;

except: KEYWORD_EXCEPT COLON block {
            std::string name = "Except" + std::to_string(++n_nodes);
            $$ = new ExceptNode(name);
            $$->add($3);
      }
      | KEYWORD_EXCEPT member_expression COLON block {
            std::string name = "Except" + std::to_string(++n_nodes);
            $$ = new ExceptNode(name);
            $$->add($4);
            $$->add($2);
      }
      | KEYWORD_EXCEPT member_expression KEYWORD_AS IDENTIFIER COLON block {
            std::string name = "Except" + std::to_string(++n_nodes);
            $$ = new ExceptNode(name);
            $$->add($4);
            $$->add($2);
            $$->add($6);
      }
      ;

finally     : KEYWORD_FINALLY COLON block {
                  std::string name = "Finally" + std::to_string(++n_nodes);
                  $$ = new FinallyNode(name);
                  $$->add($3);
            }
            ;

except_statements : except_statements except {
                        $1->add($2);
                        $$ = $1;
                  }
                  | except {
                        $$ = $1;
                  }
                  ;

with  : KEYWORD_WITH with_statements COLON block {
            std::string name = "With" + std::to_string(++n_nodes);
            $$ = new WithNode(name);
            $$->add($2);
            $$->add($4);
      }
      ;

with_statements   : function_call KEYWORD_AS IDENTIFIER
                  | with_statements COMMA function_call KEYWORD_AS IDENTIFIER
                  ;

class : KEYWORD_CLASS IDENTIFIER LEFT_PARENTHES args RIGHT_PARENTHES COLON NEWLINE INDENT class_block DEDENT   {
            std::string name = "classWithInheritance" + std::to_string(++n_nodes);
            $$ = new ClassNode(name);
            $$->add($2);
            $$->add($4);
            $$->add($9);
      }
      | KEYWORD_CLASS IDENTIFIER COLON NEWLINE INDENT class_block DEDENT {
            std::string name = "classWithoutInheritance" + std::to_string(++n_nodes);
            $$ = new ClassNode(name);
            $$->add($2);
            $$->add($6);
      }
      ;

class_block : class_block class_body {
                  $1->add($2);
                  $$ = $1;
            }
            | class_body {
                  std::string name = "ClassBlock" + std::to_string(++n_nodes);
                  $$ = new ClassBlock(name);
                  $$->add($1);
            }
            ;

class_body  : /* Empty */ { 
                  std::string name = "Classbody" + std::to_string(++n_nodes);
                  $$ = new ClassBodyNode(name);
            }
            | class_body function { 
                  $1->add($2);
                  $$ = $1;
            }
            | class_body assignment { 
                  $1->add($2);
                  $$ = $1;
            }
            | class_body NEWLINE    {
                  std::string name = "Classbody" + std::to_string(++n_nodes);
                  $$ = new ClassBodyNode(name);
                  $$->add($1);
            }
            ;

function_call     : member_expression LEFT_PARENTHES args RIGHT_PARENTHES {
                        std::string name = "Call" + std::to_string(++n_nodes);
                        $$ = new FunctionCall(name, $1);
                        $$->add($1);
                        $$->add($3);
                  }
                  ;

function    : KEYWORD_DEF IDENTIFIER LEFT_PARENTHES parameters RIGHT_PARENTHES COLON block {
                  IdentifierNode* idFunc = dynamic_cast<IdentifierNode*>($2);
                  $$ = new FunctionNode(idFunc->value);
                  $$->add($4);
                  $$->add($7);
            };

block : NEWLINE INDENT statements DEDENT  {     
            std::string name = "block" + std::to_string(++n_nodes);
            $$ = new BlockNode(name);
            $$->add($3);
      }
      ;

parameters : /* Empty */ {
                  $$ = new Args("Args" + std::to_string(++n_nodes));
            }
            | parameter_list { $$ = $1; }
            ;

parameter_list : parameter {
                       $$ = new Args("Args" + std::to_string(++n_nodes));
                       $$->add($1);
                 }
                 | parameter_list COMMA parameter {
                       $1->add($3);
                       $$ = $1;
                 }
                 | parameter_list COMMA { $$ = $1; }
                 ;

parameter : IDENTIFIER {
                  $$ = new Arg("Arg" + std::to_string(++n_nodes));
                  $$->add($1);
            }
            | IDENTIFIER COLON member_expression {
                  $$ = new Arg("Arg" + std::to_string(++n_nodes));
                  $$->add($1);
                  $$->add($3);
            }
            ;

args  : args arg {
            $1->add($2);
            $$ = $1;
      }
      | arg { 
            std::string name = "Args" + std::to_string(++n_nodes);
            $$ = new Args(name);
            $$->add($1);
      }
      ;

arg   : /*Empty*/    { 
            std::string name = "Arg" + std::to_string(++n_nodes);
            $$ = new Arg(name);
      }
      | arg expression {
            $1->add($2);
            $$ = $1;
      }
      | arg expression COMMA  {
            $1->add($2);
            $$ = $1;
      }
      ;

member_expression : IDENTIFIER      {
                        $$ = $1;
                  }
                  | member_expression '.' IDENTIFIER  {
                        $$ = new MemberExpression($1, $3);
                        $$->add($1); 
                        $$->add($3); 
                  }
                  ;

logical_expression : logical_or { $$ = $1; };

logical_or : logical_or KEYWORD_OR logical_and {
                  $$ = new BinaryLogicalExpression("or", $1, $3);
            }
            | logical_and { $$ = $1; }
            ;

logical_and : logical_and KEYWORD_AND logical_not {
                   $$ = new BinaryLogicalExpression("and", $1, $3);
            }
            | logical_not { $$ = $1; }
            ;

logical_not : KEYWORD_NOT logical_not {
                  $$ = new UnaryExpressionNode("not", $2);
            }
            | comparison { $$ = $1; }
            ;

comparison : expression { $$ = $1; }
           | comparison GREATEROREQUAL expression { $$ = new BinaryLogicalExpression(">=", $1, $3); }
           | comparison GREATERTHAN expression { $$ = new BinaryLogicalExpression(">", $1, $3); }
           | comparison LESSOREQUAL expression { $$ = new BinaryLogicalExpression("<=", $1, $3); }
           | comparison LESSTHAN expression { $$ = new BinaryLogicalExpression("<", $1, $3); }
           | comparison EQUAL expression { $$ = new BinaryLogicalExpression("==", $1, $3); }
           | comparison NOTEQUAL expression { $$ = new BinaryLogicalExpression("!=", $1, $3); }
           | comparison KEYWORD_NOT KEYWORD_IN expression { $$ = new BinaryLogicalExpression("not in", $1, $4); }
           | comparison KEYWORD_IN expression { $$ = new BinaryLogicalExpression("in", $1, $3); }
           | comparison KEYWORD_IS KEYWORD_NOT expression { $$ = new BinaryLogicalExpression("is not", $1, $4); }
           | comparison KEYWORD_IS expression { $$ = new BinaryLogicalExpression("is", $1, $3); }
           ;

conditional_statement   : if_statement elif_else      {
                              $1->add($2);
                              $$ = $1;
                        }
                        ;

elif_else   : /* EMPTY */     { 
                  std::string name = "elif_else" + std::to_string(++n_nodes);
                  $$ = new EmptyNode(name); 
            }
            | elif_stmts else_statement {
                  $1->add($2);
                  $$ = $1;
            }
            | elif_stmts      {
                  $$ = $1;
            }
            | else_statement  {
                  $$ = $1;
            }
            ;

elif_stmts  : elif_statement  {
                  $$ = $1;
            }
            | elif_stmts elif_statement   {
                  $1->add($2);
                  $$ = $1;
            }
            ;

if_statement      : KEYWORD_IF logical_expression COLON block     {
                        std::string name = "if" + std::to_string(++n_nodes);
                        $$ = new ConditionalStatement("if", name);
                        $$->add($2);
                        $$->add($4);
                  }
                  | KEYWORD_IF LEFT_PARENTHES logical_expression RIGHT_PARENTHES COLON block {
                        std::string name = "if" + std::to_string(++n_nodes);
                        $$ = new ConditionalStatement("if", name);
                        $$->add($3);
                        $$->add($6);
                  }
                  ;

else_statement    : KEYWORD_ELSE COLON block    {
                        std::string name = "else" + std::to_string(++n_nodes);
                        $$ = new ConditionalStatement("else", name);
                        $$->add($3);
                  }
                  ;

elif_statement    : KEYWORD_ELSE_IF logical_expression COLON block      {
                        std::string name = "elif" + std::to_string(++n_nodes);
                        $$ = new ConditionalStatement("elif", name);
                        $$->add($2);
                        $$->add($4);
                  }
                  | KEYWORD_ELSE_IF LEFT_PARENTHES logical_expression RIGHT_PARENTHES COLON block     {
                        std::string name = "elif" + std::to_string(++n_nodes);
                        $$ = new ConditionalStatement("elif", name);
                        $$->add($3);
                        $$->add($6);
                  }
                  ;

for_statement     : KEYWORD_FOR IDENTIFIER KEYWORD_IN function_call COLON block {
                        std::string name = "For" + std::to_string(++n_nodes);
                        $$ = new ForNode(name);
                        $$->add($2);
                        $$->add($4);
                        $$->add($6);
                  }
                  | KEYWORD_FOR IDENTIFIER KEYWORD_IN LIST COLON block {
                        std::string name = "For" + std::to_string(++n_nodes);
                        $$ = new ForNode(name);
                        $$->add($2);
                        $$->add($4);
                        $$->add($6);
                  }
                  | KEYWORD_FOR LEFT_PARENTHES args RIGHT_PARENTHES KEYWORD_IN function_call COLON block {
                        std::string name = "For" + std::to_string(++n_nodes);
                        $$ = new ForNode(name);
                        $$->add($3);
                        $$->add($6);
                        $$->add($8);
                  }
                  | KEYWORD_FOR IDENTIFIER KEYWORD_IN member_expression COLON block {
                        std::string name = "For" + std::to_string(++n_nodes);
                        $$ = new ForNode(name);
                        $$->add($2);
                        $$->add($4);
                        $$->add($6);
                  }
                  | KEYWORD_FOR IDENTIFIER KEYWORD_IN member_expression function_call COLON block {
                        std::string name = "For" + std::to_string(++n_nodes);
                        $$ = new ForNode(name);
                        $$->add($2);
                        $$->add($4);
                        $$->add($5);
                        $$->add($7);
                  }
                  | KEYWORD_FOR IDENTIFIER KEYWORD_IN member_expression function_call '.' IDENTIFIER COLON block {
                        std::string name = "For" + std::to_string(++n_nodes);
                        $$ = new ForNode(name);
                        $$->add($2);
                        $$->add($4);
                        $$->add($5);
                        $$->add($7);
                        $$->add($9);
                  }
                  ;

while_statement   : KEYWORD_WHILE logical_expression COLON block {
                        std::string name = "While" + std::to_string(++n_nodes);
                        $$ = new WhileNode(name);
                        $$->add($2);
                        $$->add($4);
                  }
                  | KEYWORD_WHILE LEFT_PARENTHES logical_expression RIGHT_PARENTHES COLON block {
                        std::string name = "While" + std::to_string(++n_nodes);
                        $$ = new WhileNode(name);
                        $$->add($3);
                        $$->add($6);
                  }
                  ;

%%

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
