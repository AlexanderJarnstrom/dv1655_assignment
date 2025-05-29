#include "../inc/types.h"

using namespace comp;

namespace comp {
#define TYPE_N 8

const std::string types[TYPE_N] = {
  "method_decl",
  "class_decl",
  "main_class",
  "var_decl",
  "Root",
  "expression",
  "statement",
  "uninitialised"
};

NodeType to_node_type(std::string type) {
  for (int i = 0; i < TYPE_N; i++) {
    if (types[i] == type) {
      return (NodeType) i;
    }
  }

  return NodeType::Error;
}

std::string to_string(NodeType type) {
  if ((int) type < 0 || (int) type > TYPE_N) {
    return "";
  }

  return types[(int) type];
}
}

