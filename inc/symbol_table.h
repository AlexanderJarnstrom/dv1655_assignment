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

public:
  SymNode(std::string, std::string, std::string, NodeType);
  ~SymNode();
};
}

#endif // !SYM_NODE
