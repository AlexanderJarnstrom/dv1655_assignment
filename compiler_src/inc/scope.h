#ifndef SCOPE
#define SCOPE

#include <string>
#include <vector>

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

  /**
   * @brief Checks for the symbol in itself and all child scopes.
   *
   * @param r Record type to look for.
   * @return Symbol * the found symbol with the record type.
   */
  Symbol* find(std::string, Record r = Record::ROOT);

  /**
   * @brief Find all symbols of a type in the scope.
   *
   * @param r The record type.
   * @return std::vector<Symbol*> all found Symbols.
   */
  std::vector<Symbol*> find_all(Record r);

  /**
   * @brief Gets a child scope with a given name.
   *
   * @param name Scope name.
   * @return Scope* the search scope or nullptr.
   */
  Scope* get_scope(std::string name);

  /**
   * @brief Get the class scope above this scope.
   *
   * @return Scope* scope object for the class.
   */
  Scope* get_parrent_class();

  void remove_symbol(std::string name);
  void add_symbol(Symbol* s);
  void remove_scope(std::string name);
  void add_scope(Scope* s);
  void print(int l);
};

#endif  // !SCOPE
