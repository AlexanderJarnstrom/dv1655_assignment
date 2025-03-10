#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include "Node.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

enum search_results {
  SEARCHED,
  AT,
  OUTSIDE,
  INSIDE,
  BOTTOM,
};

enum node_type {
  METHOD,
  CLASS,
  VARIABLE,
  METHOD_VAR,
  MAIN_CLASS,
  ROOT
};

enum symbole_table_error {
  DUPLICATE
};

class SymbolTable {
private:

  std::string name;
  enum node_type type;
  std::string exp_type;

  std::vector<SymbolTable*> children;
  SymbolTable* parent;

  bool check_scope(std::string searched, SymbolTable* start) {
    for (
      auto node = std::find(this->children.rbegin(), this->children.rend(), start) + 1;
      node != this->children.rend();
      node++
    ) {
      if ((*node)->name == searched) {
        return true;
      }
    }

    if (this->parent == nullptr) {
      return false;
    }

    return this->parent->check_scope(searched, this);
  }

public:

  SymbolTable(std::string name, enum node_type type, std::string exp_type) :
    name(name), type(type), exp_type(exp_type) {}

  ~SymbolTable() {
    for (SymbolTable* child : this->children) {
      delete child;
    }
  }

  void print(int level = 0) {
    for (int i = 0; i < level; i++) {
      printf("  ");
    }

    printf("[%d] %s %s\n", this->type, this->name.c_str(), this->exp_type.c_str());

    for (SymbolTable* child : this->children) {
      child->print(level + 1);
    }
  }

  void build_table(Node* parse_node) {
    SymbolTable* node;

    if (parse_node->type == "main_class") {
      node = new SymbolTable(
        (*parse_node)[0]->value,
        node_type::MAIN_CLASS,
        ""
      );

      for (Node* parse_child : parse_node->children) {
        node->build_table(parse_child);
      }    

      node->parent = this;

      this->children.push_back(node);
    } else if (parse_node->type == "class_decl") {
      node = new SymbolTable(
        (*parse_node)[0]->value,
        node_type::CLASS,
        ""
      );

      node->parent = this;
      for (Node* parse_child : parse_node->children) {
        node->build_table(parse_child);
      }

      node->parent = this;

      this->children.push_back(node);
    } else if (parse_node->type == "method_decl") {
      node = new SymbolTable(
        (*parse_node)[1]->value,
        node_type::METHOD,
        (*parse_node)[0]->value
      );

      node->parent = this;
      for (Node* parse_child : parse_node->children) {
        node->build_table(parse_child);
      } 

      node->parent = this;

      this->children.push_back(node);
    } else if (parse_node->type == "method_arg") {
      node = new SymbolTable(
        (*parse_node)[1]->value,
        node_type::METHOD_VAR,
        (*parse_node)[0]->value
      );

      for (Node* parse_child : parse_node->children) {
        node->build_table(parse_child);
      } 

      node->parent = this;

      this->children.push_back(node);
    } else if (parse_node->type == "var_decl") {
      node = new SymbolTable(
        (*parse_node)[1]->value,
        node_type::VARIABLE,
        (*parse_node)[0]->value
      ); 

      node->parent = this;

      this->children.push_back(node);
    } else {
      node = this;

      for (Node* parse_child : parse_node->children) {
        node->build_table(parse_child);
      }
    }
  }

  void insert(SymbolTable* node) {
    children.push_back(node);
  }

  void remove(const std::string& name) {
    for (SymbolTable* child : children) {
      if (name == child->name) {
        children.erase(std::find(children.begin(), children.end(), child));
      }
    }
  }

  SymbolTable* get();

  bool is_in_scope(std::string at, std::string searched, std::string scope) {
    if (this->name == at && this->parent->name == scope) {
      return this->parent->check_scope(searched, this);
    }

    for (SymbolTable* child : this->children) {
      if (child->is_in_scope(at, searched, scope)) {
        return true;
      }
    }

    return false;
  }
};

#endif // !SYMBOL_TABLE
