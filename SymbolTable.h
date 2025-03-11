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
  int line_nr;

  std::vector<SymbolTable*> children;
  SymbolTable* parent;

  bool check_scope(std::string searched, SymbolTable* start);

public:

  SymbolTable(std::string n, enum node_type t, std::string e, int r) :
    name(n), type(t), exp_type(e), line_nr(r) {}

  ~SymbolTable() {
    for (SymbolTable* child : this->children) {
      delete child;
    }
  }

  std::string get_name();

  enum node_type get_type();

  std::string get_exp_type();

  int get_line_number();

  void print(int level = 0);

  void build_table(Node* parse_node);

  void insert(SymbolTable* node);

  void remove(const std::string& name);

  SymbolTable* get(const std::string& name);

  bool is_in_scope(std::string searched, std::string scope);
};

#endif // !SYMBOL_TABLE
