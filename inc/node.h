#ifndef NODE_H
#define NODE_H

#include "block.h"
#include "symbol.h"
#include "symbol_table.h"
#include <fstream>
#include <iostream>
#include <list>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

class Node {
public:
  int id, lineno;
  std::string type, value;

  std::list<Node *> children;

  Node(std::string t, std::string v, int l);
  Node();

  virtual ~Node();

  virtual void pre_execute(SymbolTable *);
  virtual void in_execute(SymbolTable *);
  virtual void post_execute(SymbolTable *);
  virtual void generate_block(BlockHandler *);
  virtual void generate_tacs(std::vector<TAC *> &, std::string &);

  virtual std::string get_type(SymbolTable *);

  void print_tree(int depth = 0);
  Node *operator[](const int &i);

  void generate_tree();
  void generate_tree_content(int &count, std::ofstream *outStream);
};

#endif
