#ifndef NODE_H
#define NODE_H

#include <sys/wait.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <list>
#include <vector>

#include "block.h"
#include "block_handler.h"
#include "symbol.h"
#include "symbol_table.h"

/**
 * @class Node
 * @brief Generic AST node.
 *
 */
class Node
{
 public:
  int id, lineno;
  std::string type, value;

  std::list<Node*> children;

  Node(std::string t, std::string v, int l);
  Node();

  virtual ~Node();

  /**
   * @brief Run before symboltable entry is inserted.
   *
   * @param table Symbol table in use.
   */
  virtual void pre_execute(SymbolTable* table);

  /**
   * @brief Runs after pre exectution but before post exectution.
   *
   * @param table Symbol table
   */
  virtual void in_execute(SymbolTable* table);

  /**
   * @brief Runs after the table has been built.
   *
   * @param table Symbol table.
   */
  virtual void post_execute(SymbolTable* table);

  /**
   * @brief Generates the block for the node in the IR.
   *
   * @param bh Block Handler managing block layers.
   */
  virtual void generate_block(BlockHandler* bh);

  /**
   * @brief Generates the TACS related to the node.
   *
   * @param tacs Vector holding all the tacs in the right order.
   * @param target The last targeted variable name.
   * @param bh Block Handler.
   */
  virtual void generate_tacs(std::vector<TAC*>& tacs, std::string& target,
                             BlockHandler* bh);

  /**
   * @brief Gets the type of the closest valid node.
   *
   * @param table Symbol table.
   */
  virtual std::string get_type(SymbolTable* table);

  /**
   * @brief Prints the tree to stdout.
   *
   * @param depth tab depth.
   */
  void print_tree(int depth = 0);

  /**
   * @brief Get node child.
   *
   * @param i child index.
   * @return Node* pointer to node child.
   */
  Node* operator[](const int& i);

  /**
   * @brief Start printing the AST to file.
   */
  void generate_tree();

  /**
   * @brief Print node data to dot file.
   *
   * @param count node id.
   * @param outStream file stream.
   */
  void generate_tree_content(int& count, std::ofstream* outStream);
};

#endif
