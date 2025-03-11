#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include "Node.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

enum search_results {
  SEARCHED,
  AT,
  OUTSIDE,
  INSIDE,
  BOTTOM,
};

enum node_type {
  METHOD,
  CLASS,
  VARIABLE,
  METHOD_VAR,
  MAIN_CLASS,
  ROOT
};

enum symbole_table_error {
  DUPLICATE
};

class SymbolTable {
private:

  std::string name;
  enum node_type type;
  std::string exp_type;

  std::vector<SymbolTable*> children;
  SymbolTable* parent;

  bool check_scope(std::string searched, SymbolTable* start);

public:

  SymbolTable(std::string name, enum node_type type, std::string exp_type) :
    name(name), type(type), exp_type(exp_type) {}

  ~SymbolTable() {
    for (SymbolTable* child : this->children) {
      delete child;
    }
  }

  void print(int level = 0);

  void build_table(Node* parse_node);

  void insert(SymbolTable* node);

  void remove(const std::string& name);

  SymbolTable* get();

  bool is_in_scope(std::string at, std::string searched, std::string scope);
};

#endif // !SYMBOL_TABLE
