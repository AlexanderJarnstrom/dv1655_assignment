/* Skeleton and definitions for generating a LALR(1) parser in C++ */
%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

/* Required code included before the parser definition begins */
%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
  #define DEBUG true
}

/* Code included in the parser implementation file */
%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

/* Token definitions for the grammar */
/* Tokens represent the smallest units of the language, like operators and parentheses */
%token <std::string> BOOLEAN LENGTH SEP LP RP LB RB LS RS VOID STRING NEW INT PUBLIC CLASS STATIC MAIN RETURN THIS DELI
%token <std::string> WHILE IF ELSE PRINT
%token <int> NUMBER
%token <bool> BOOL
%token <std::string> ID;
%token END 0 "end of file"

/* Operator precedence and associativity rules */
/* Used to resolve ambiguities in parsing expressions See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl */ 

%left <std::string> ADD_OP SUB_OP MULT_OP
%left <std::string> EQ_OP LT_OP GT_OP NOT_OP
%left <std::string> AND_OP OR_OP ASSIGN_OP ATTR_OP

/* Specify types for non-terminals in the grammar */
/* The type specifies the data type of the values associated with these non-terminals */
%type <Node *> root main_class id statement expression number bool type operator
%type <Node *> class_declaration var_declaration method_declaration
%type <Node *> class_declaration_list var_declaration_list method_declaration_list statement_list statement_else
%type <Node *> method_arguments method_content

/* Grammar rules section */
/* This section defines the production rules for the language being parsed */
%%
root
  : main_class class_declaration_list END { 
      root = new Node("Root", "", yylineno); 
      root->children.push_back($1);
      root->children.push_back($2);
  }
  ;

main_class
  : PUBLIC CLASS id LB PUBLIC STATIC VOID MAIN LP STRING LS RS id RP LB statement_list RB RB {
    $$ = new Node("Main Class", "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($13);
    $$->children.push_back($16);
  }
  ;

class_declaration_list
  : class_declaration class_declaration_list {
    $$ = new Node("Class Declaration List", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node("", "", yylineno); }

class_declaration
  : CLASS id LB var_declaration_list method_declaration_list RB {
    $$ = new Node("Class Declaration", "", yylineno);
    $$->children.push_back($2);
    $$->children.push_back($4);
    $$->children.push_back($5);
  }
  ;

var_declaration_list
  : var_declaration var_declaration_list {
    $$ = new Node("Variable Declaration List", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node("", "", yylineno); }
  ;

var_declaration
  : type id DELI {
    $$ = new Node("Variable Declaration", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  ;

method_declaration_list
  : method_declaration method_declaration_list {
    $$ = new Node("Method Declaration List", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node("", "", yylineno); }
  ;

method_declaration
  : PUBLIC type id LP method_arguments RP LB method_content RETURN expression DELI RB {
    $$ = new Node("Method", "", yylineno);
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back($5);
    $$->children.push_back($8);
    $$->children.push_back($10);
  }
  ;

method_arguments
  : type id {
    $$ = new Node("Method Argument", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | method_arguments SEP method_arguments {
    $$ = new Node("Method Arguments", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | /* empty */ { $$ = new Node("", "", yylineno); }
  ;

method_content
  : var_declaration method_content {
    $$ = new Node("Method Content", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | statement method_content {
    $$ = new Node("Method Content", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node("", "", yylineno); }
  ;

type
  : INT LS RS { $$ = new Node("Type", "Int arr", yylineno); }
  | BOOLEAN { $$ = new Node("Type", "Boolean", yylineno); }
  | INT { $$ = new Node("Type", "Int", yylineno); }
  | id { 
    $$ = new Node("Type", "", yylineno); 
    $$->children.push_back($1);
  }
  ;

statement_list
  : statement statement_list {
    $$ = new Node("Statement List", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node("", "", yylineno); }
  ;

statement_else
  : ELSE statement {
    $$ = new Node("Else statement", "", yylineno);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node("", "", yylineno); }
  ;

statement
  : LB statement_list RB {
    $$ = new Node("Statement", "", yylineno); 
    $$->children.push_back($2);
  }
  | IF LP expression RP statement statement_else {
    $$ = new Node("IF Statement", "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
    $$->children.push_back($6);
  }
  | WHILE LP expression RP statement {
    $$ = new Node("While Statement", "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
  } 
  | PRINT LP expression RP DELI {
    $$ = new Node("Print Statement", "", yylineno);
    $$->children.push_back($3);
  }
  | id ASSIGN_OP expression DELI {
    $$ = new Node("Assign Statement", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | id LS expression RS ASSIGN_OP expression DELI {
    $$ = new Node("Assign Arr Statement", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($6);
  }
  ;

expression 
  : expression operator expression {
    $$ = new Node("Operator Expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
  }
  | expression SEP expression {
    $$ = new Node("Expression List", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression LS expression RS {
    $$ = new Node("Array Expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression ATTR_OP LENGTH {
    $$ = new Node("Expression Length", "", yylineno);
    $$->children.push_back($1);
  }
  | expression ATTR_OP id LP expression RP {
    $$ = new Node("Expression Attr", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($5);
  }
  | number {
    $$ = new Node("Expression Number", "", yylineno);
    $$->children.push_back($1);
  }
  | bool {
    $$ = new Node("Expression Bool", "", yylineno);
    $$->children.push_back($1);
  }
  | id {
    $$ = new Node("Expression ID", "", yylineno);
    $$->children.push_back($1);
  }
  | THIS {
    $$ = new Node("This", "", yylineno);
  }
  | NEW INT LS expression RS {
    $$ = new Node("Expression Array", "", yylineno);
    $$->children.push_back($4);
  }
  | NEW id LP RP {
    $$ = new Node("Init", "", yylineno);
    $$->children.push_back($2);
  }
  | NOT_OP expression {
    $$ = new Node("Neg Expression", "", yylineno);
    $$->children.push_back($2);
  }
  | LP expression RP {
    $$ = new Node("()", "", yylineno);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node("", "", yylineno); }
  ;

operator
  : ADD_OP { $$ = new Node("Operator", $1, yylineno); }
  | SUB_OP { $$ = new Node("Operator", $1, yylineno); }
  | EQ_OP { $$ = new Node("Operator", $1, yylineno); }
  | GT_OP { $$ = new Node("Operator", $1, yylineno); }
  | LT_OP { $$ = new Node("Operator", $1, yylineno); }
  | MULT_OP { $$ = new Node("Operator", $1, yylineno); }
  ;

number 
  : NUMBER { $$ = new Node("Number", std::to_string($1),  yylineno); }
  ;

bool 
  : BOOL { 
    std::string val;
    if ($1) {
      val = "true";
    } else {
      val = "false";
    }

    $$ = new Node("Bool", val,  yylineno);
  }
  ;

id 
  : ID { $$ = new Node("Id", $1,  yylineno); }
  ;
