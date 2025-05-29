#ifndef SYM_NODE
#define SYM_NODE

#include "Node.h"
#include "types.h"
#include <string>
#include <vector>

#define METHOD "method_decl"
#define CLASS "class_decl"
#define VARIABLE "var_decl"
#define MAIN_CLASS "main_class"
#define METHOD_ARG "method_arg"

#define INT "int"
#define STRING "string"
#define BOOL "boolean"
#define INT_ARR "int_arr"
#define ARG_ARR "arg_arr"
#define NONE ""

namespace sym {
using namespace comp;

class SymNode {
private:
  std::string name;
  std::string scope;
  std::string value_type;
  NodeType node_type;
  int line_nr;
  SymNode* parent;

  std::vector<SymNode*> nodes;

  void add_from_main_class(Node*, std::string);
  void add_from_class(Node*, std::string);
  void add_from_method(Node*, std::string);
  void add_from_variable(Node*, std::string);
  void add_from_node(Node*, std::string);
  void print_node(int);
  bool is_declared(std::string);

public:
  SymNode(std::string, std::string, std::string, NodeType);
  ~SymNode();

  std::string get_name();
  std::vector<SymNode*> get_nodes_flat();
  std::vector<SymNode*> get_classes();
  std::vector<SymNode*> get_global_variables(std::string);
  std::vector<SymNode*> get_local_variables(std::vector<std::string>);

  void generate_table(Node* n);
  void print();
  void add_node(SymNode*);

  std::vector<SymNode*>::iterator begin();
  std::vector<SymNode*>::iterator end();
};

typedef SymNode SymbolTable ;

SymbolTable create_table();
}

#endif // !SYM_NODE
