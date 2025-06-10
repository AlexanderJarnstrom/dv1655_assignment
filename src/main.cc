#include <cstdio>
#include <iostream>
#include "../inc/symbol_node.h"
#include "../inc/parser.tab.h"
#include "../inc/semantic_functions.h"

extern Node *root;
extern FILE *yyin;
extern int yylineno;
extern int lexical_errors;
extern yy::parser::symbol_type yylex();

int errCode = errCodes::SUCCESS;

// Handling Syntax Errors
void yy::parser::error(std::string const &err)
{
  if (!lexical_errors)
  {
    std::cerr << "Syntax errors found! See the logs below:" << std::endl;
    std::cerr << "\t@error at line " << yylineno << ". Cannot generate a syntax for this input:" << err.c_str() << std::endl; std::cerr << "End of syntax errors!" << std::endl;
    errCode = errCodes::SYNTAX_ERROR;
  }
}

int main(int argc, char **argv)
{
  // Reads from file if a file name is passed as an argument. Otherwise, reads from stdin.
  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror(argv[1]);
      return 1;
    }
  }

  if (USE_LEX_ONLY) {
    yylex();
  } else {
    yy::parser parser;

    bool parseSuccess = !parser.parse();

    if (lexical_errors)
      errCode = errCodes::LEXICAL_ERROR;
    if (parseSuccess && !lexical_errors) {
      printf("\nThe compiler successfuly generated a syntax tree for the given input! \n");

      printf("\nPrint Tree:  \n");
      try {
        root->print_tree();
        root->generate_tree();

        SymbolNode table("root", ROOT, NONE, 0);
        int counter = 0;
        table.generate_table(root, counter);
        table.print();

        definition_validation(root, &table);
        type_validation(root, &table);
      } catch (...) {
        errCode = errCodes::AST_ERROR;
      }
    }
  }

  return errCode;
}
