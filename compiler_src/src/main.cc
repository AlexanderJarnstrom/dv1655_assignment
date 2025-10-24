#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>

#include "../inc/code_generation.h"
#include "../inc/config.h"
#include "../inc/ir_generation.h"
#include "../inc/parser.tab.h"
#include "../inc/semantic.h"
#include "../inc/symbol_table.h"

extern Node* root;
extern FILE* yyin;
extern int yylineno;
extern int lexical_errors;
extern yy::parser::symbol_type yylex();

enum errCodes
{
  SUCCESS = 0,
  LEXICAL_ERROR = 1,
  SYNTAX_ERROR = 2,
  AST_ERROR = 3,
  SEMANTIC_ERROR = 4,
  SEGMENTATION_FAULT = 139
};

int errCode = errCodes::SUCCESS;

void build_table(SymbolTable*, Node*);

// Handling Syntax Errors
void yy::parser::error(std::string const& err)
{
  if (!lexical_errors)
  {
    std::cerr << "Syntax errors found! See the logs below:" << std::endl;
    std::cerr << "\t@error at line " << yylineno
              << ". Cannot generate a syntax for this input:" << err.c_str()
              << std::endl;
    std::cerr << "End of syntax errors!" << std::endl;
    errCode = errCodes::SYNTAX_ERROR;
  }
}

int main(int argc, char** argv)
{
  Config::extract_arguments(argc, argv);

  if (Config::flags & Config::Flags::INPUT_File)
  {
    if (!(yyin = fopen(Config::input_name.c_str(), "r")))
    {
      perror(argv[1]);
      return 1;
    }
  }

  if (USE_LEX_ONLY)
  {
    yylex();
  }
  else
  {
    yy::parser parser;

    bool parseSuccess = !parser.parse();

    if (lexical_errors) errCode = errCodes::LEXICAL_ERROR;
    if (parseSuccess && !lexical_errors)
    {
      if (Config::flags & Config::Flags::DEBUG) root->print_tree();
      if (Config::flags & Config::Flags::TREE) root->generate_tree();

      SymbolTable table;
      Semantic::semantic_analysis(root, &table);

      if (table.m_errors.size() != 0)
      {
        std::cerr << "Semantical errors found:" << std::endl;
        table.print_errors();
        errCode = errCodes::SEMANTIC_ERROR;
      }
      else
      {
        BlockHandler* bh = generate_ir(root, &table);
        if (Config::flags & Config::Flags::BLOCKS) bh->generate_tree();
        CodeGeneration::generate_code(bh);
        delete bh;
      }

      if (Config::flags & Config::Flags::DEBUG) table.print_root();
    }
  }

  delete root;

  return errCode;
}
