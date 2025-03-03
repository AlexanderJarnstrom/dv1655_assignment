#include "sympol_table.h"
#include <cstdio>
    
void SymbolTable::push(const std::string& scope) {
  this->arr.push_back(scope);
}

void SymbolTable::pop() {
  this->arr.pop_back();
}

std::string SymbolTable::operator[](const int& i) {
  return arr[i];
}

std::string SymbolTable::operator[](const std::string& scope) {
  for (std::string inner_scope : this->arr) {
    if (scope == inner_scope) {
      return inner_scope;
    }
  }

  return "";
}

void SymbolTable::print() {
  for (std::string scope : this->arr) {
    printf("%s\n", scope.c_str());
  }
}


void SymbolTable::extract_symbols(Node* root) {
  if (root == nullptr) {
    return;
  }

  if (root->type == "main_class" || root->type == "class_decl" || root->type == "method_decl") {
    printf("%s\n", root->value.c_str());
    this->push(root->value); 
  }

  for (Node* node : root->children) {
    this->extract_symbols(node);
  }
}
