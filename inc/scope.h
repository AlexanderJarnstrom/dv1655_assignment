#ifndef SCOPE
#define SCOPE

#include <vector>
#include <string>
#include "symbol.h"

class Scope 
{
public:
  std::string m_id;
  Scope* m_parent;

  std::vector<Scope*> m_scopes;
  std::vector<Symbol*> m_symbols;

  Scope(Symbol*, Scope*);
  ~Scope();

  Symbol* find(std::string, Record r = Record::ROOT);
  Scope* get_scope(std::string);
  Scope* get_parrent_class();

  void remove_symbol(std::string);
  void add_symbol(Symbol*);
  void remove_scope(std::string);
  void add_scope(Scope*);
  void print(int);
};

#endif // !SCOPE
