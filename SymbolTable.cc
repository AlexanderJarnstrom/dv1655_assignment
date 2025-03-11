#include "SymbolTable.h"

bool SymbolTable::check_scope(std::string searched, SymbolTable* start) {
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

void SymbolTable::print(int level) {
  for (int i = 0; i < level; i++) {
    printf("  ");
  }

  printf("[%d] %s %s\n", this->type, this->name.c_str(), this->exp_type.c_str());

  for (SymbolTable* child : this->children) {
    child->print(level + 1);
  }
}

void SymbolTable::build_table(Node* parse_node) {
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

void SymbolTable::insert(SymbolTable* node) {
  children.push_back(node);
}

void SymbolTable::remove(const std::string& name) {
  for (SymbolTable* child : children) {
    if (name == child->name) {
      children.erase(std::find(children.begin(), children.end(), child));
    }
  }
}

SymbolTable* SymbolTable::get() {
  return nullptr;
}

bool SymbolTable::is_in_scope(std::string at, std::string searched, std::string scope) {
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

