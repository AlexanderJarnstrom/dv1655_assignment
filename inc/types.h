#pragma once

#include <string>

namespace comp {

enum NodeType {
  Method,
  Class,
  MainClass,
  Variable,
  Root,
  Expression,
  Statement,
  Uninitialized,
  Error,
};

enum ValueType {
  Int,
  String,
  Bool,
  IntArr,
  User,
  ArgArr,
  None,
};

NodeType to_node_type(std::string);
std::string to_string(NodeType);
}

