/**
 * @file
 * @brief Containing the symbol table class and symbol error struct.
 */

#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include <string>
#include <vector>

#include "scope.h"
#include "symbol.h"

/**
 * @struct sy_error
 * @brief Symbole error
 *
 */
struct sy_error
{
  std::vector<std::string> errors;
  int line;
};

/**
 * @class SymbolTable
 * @brief Holding all scopes and symbols
 *
 */
class SymbolTable
{
 public:
  Scope* m_scope;
  Scope* m_root;
  Scope* m_intrest;

  std::vector<sy_error*> m_errors;

  SymbolTable();
  ~SymbolTable();

  /**
   * @brief Adds error to error vector.
   *
   * @param line Line where the error occured.
   * @param error The error.
   */
  void add_error(int line, std::string error);

  /**
   * @brief Enter a scope.
   *
   * @param name Name of scope.
   */
  void enter_scope(std::string name);
  /**
   * @brief Exit current scope.
   */
  void exit_scope();

  /**
   * @brief Add symbol to current scope.
   *
   * @param s Symbol pointer.
   */
  void add_symbol(Symbol* s);
  /**
   * @brief Add scope to current scope.
   *
   * @param s Scope pointer.
   */
  void add_scope(Symbol* s);
  /**
   * @brief Find symbol in current scope's children.
   *
   * Only checks in the current scope's children.
   *
   * @param name Name of the searched symbol.
   * @return Symbol* found symbol or nullptr.
   */
  Symbol* find_symbol(std::string name);
  /**
   * @brief Find symbol in the current scope.
   *
   * Checks the whole scope from parrent class perspective.
   *
   * @param name Name of symbol
   * @param r Symbol type.
   * @return Symbol * or nullptr.
   */
  Symbol* check_scope(std::string name, Record r = Record::ROOT);
  /**
   * @brief Remove symbol.
   *
   * @param name Symbol name.
   */
  void remove_symbol(std::string name);

  /**
   * @brief Sets scymbol tables root as the current scope.
   */
  void reset();

  /**
   * @brief Prints the table from the root node.
   */
  void print_root();
  /**
   * @brief Prints the table from the current scope.
   */
  void print_scope();
  /**
   * @brief Prints all the error messages.
   */
  void print_errors();
};

#endif  // !SYMBOL_TABLE
