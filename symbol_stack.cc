#include "symbol_stack.h"
#include "symbol_linked_list.h"
#include <cstdio>

void SymbolStack::push(std::string& name, enum node_type type, std::string return_type) {
  SymbolLinkedList* scope;
  if (type == METHOD || type == CLASS) {
    this->arr.push_back(new SymbolLinkedList(name, type, return_type));    
  } else {
    scope = this->top();

    while (scope->next_node() != nullptr) {
      scope = scope->next_node();
    }

    scope->set_next_node(new SymbolLinkedList(name, type, return_type));
  }
}

void SymbolStack::pop() {
  this->arr.pop_back();
}

SymbolLinkedList* SymbolStack::find(const std::string& scope, const std::string& name) {
  for (SymbolLinkedList* row : this->arr) {
    if (scope == row->name) {
      return row->find(name);
    }
  }

  return nullptr;
}

SymbolLinkedList* SymbolStack::top() {
  return this->arr.back();
}

void SymbolStack::print() {
  for (SymbolLinkedList* row : this->arr) {
    printf("%s\n", row->name.c_str());
    row->next_node()->print();    
  }
}

void SymbolStack::extract_symbols(Node* root) {

  if (root == nullptr) {
    return;
  }

  if (root->type == "main_class" || root->type == "class_decl") {
    this->push(root->children.front()->value, CLASS, "");
  }

  if (root->type == "method_decl") {
    std::string type = root->children.front()->value;
    root->children.pop_front();
    std::string name = root->children.front()->value;
    root->children.pop_front();
    this->push(name, METHOD, type);
  }

  if (root->type == "var_decl") {
    std::string type = root->children.front()->value;
    root->children.pop_front();
    std::string name = root->children.front()->value;
    root->children.pop_front();
    this->push(name, VARIABLE, type);
  }

  for (Node* node : root->children) {
    this->extract_symbols(node);
  }
}
