#ifndef SYMBOL_LINKED_LIST
#define SYMBOL_LINKED_LIST

#include <string>

enum node_type {
  METHOD,
  CLASS,
  VARIABLE
};

class SymbolLinkedList {
private:
  SymbolLinkedList* next;
  SymbolLinkedList* before;

public:

  std::string name;
  enum node_type node_type;
  std::string return_type;

  SymbolLinkedList(std::string name, enum node_type node_type, std::string return_type) :
    name(name), node_type(node_type), return_type(return_type), before(nullptr), next(nullptr) {}

  /*
       * Get the node after this.
       *
       * @return node.
       * */
  SymbolLinkedList* next_node();


  /*
       * Set the next node.
       *
       * @param node pointer to next node.
       * */
  void set_next_node(SymbolLinkedList* node);

  /*
       * Get the nodde before this.
       * */
  SymbolLinkedList* prev_node();

  /*
       * Set the previous node.
       *
       * @param node pointer to previous node.
       * */
  void set_prev_node(SymbolLinkedList* node);

  /*
       * Finds the node with the given name.
       *
       * @param name name of the node.
       * @return searched node or nullptr
       * */
  SymbolLinkedList* find(const std::string& name);

  /*
   * Print the full list from this node.
   * */
  void print();
};

#endif // !SYMBOL_HASH
