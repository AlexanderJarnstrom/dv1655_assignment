#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include <cstdio>
#include <string>
#include <vector>

#include "Node.h"
#include "symbol_linked_list.h"

class SymbolStack {
private:

  std::vector<SymbolLinkedList*> arr;

public:

  ~SymbolStack() {
    for (SymbolLinkedList* node : this->arr) {
      delete node;
    }
  }

  /*
     * Pushes a scope onto the stack.
     *
     * @param scope name of scope.
     * */
  void push(std::string& name, enum node_type type, std::string return_type);

  /*
     * Pops the scope on the top from the stack.
     * */
  void pop();

  /*
     * Gets the value with the given scope.
     *
     * @param scope name of scope.
     * @return hash table.
     * */
  SymbolLinkedList* find(const std::string& scope, const std::string& name);

  /*
   * Get top node.
   *
   * @return node at top.
   * */
  SymbolLinkedList* top();

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
