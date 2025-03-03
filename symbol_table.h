#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include <cstdio>
#include <string>
#include <vector>
#include "Node.h"

enum node_type {
  CLASS,
  METHOD,
  VAR_DECL
};

enum node_return_type {
  INT,
  BOOL,
  STRING
};

class SymbolTable {
private:
  
  std::vector<std::string> arr;

public:

  /*
   * Pushes a scope onto the stack.
   *
   * @param scope name of scope.
   * */
  void push(const std::string& scope);

  /*
   * Pops the scope on the top from the stack.
   * */
  void pop();

  /*
   * Gets the value at the given index.
   *
   * @param i index.
   * @return value at index.
   * */
  std::string operator[](const int& i);

  /*
   * Gets the value with the given scope.
   *
   * @param scope name of scope.
   * @return hash table.
   * */
  std::string operator[](const std::string& scope);

  /*
   * Prints all the content of the symbol table.
   * */
  void print();

  /*
   * Takes the root node and extract the symbols from the tree.
   *
   * @param root The root node.
   * */
  void extract_symbols(Node* root);
};

#endif // !SYMBOL_TABLE
