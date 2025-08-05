#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include "scope.h"
#include "symbol.h"
#include <string>
#include <vector>

struct sy_error {
  std::string error;
  int line;
};

class SymbolTable
{
public:
  Scope* m_scope;
  Scope* m_root;
  Scope* m_intrest;

  std::vector<sy_error> m_errors;

  SymbolTable();
  ~SymbolTable();

  void add_error(int, std::string);

  void enter_scope(std::string);
  void exit_scope();

  void add_symbol(Symbol*);
  Symbol* find_symbol(std::string);
  Symbol* check_scope(std::string, Record r = Record::ROOT);
  void remvove_symbol(std::string);

  void reset();

  void print_root();
  void print_scope();
  void print_errors();
};

#endif // !SYMBOL_TABLE
