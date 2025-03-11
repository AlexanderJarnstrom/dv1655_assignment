#include "SymbolTable.h"

bool SymbolTable::check_scope(std::string searched, SymbolTable* start) {
  for (SymbolTable* node : this->children) {
    if (node->name == searched) {
      return true;
    }
  }

  if (this->parent == nullptr) {
    return false;
  }

  return this->parent->check_scope(searched, this);
}

std::string SymbolTable::get_name() {
  return this->name;
}

enum node_type SymbolTable::get_type() {
  return this->type;
}

std::string SymbolTable::get_exp_type() {
  return this->exp_type;
}

int SymbolTable::get_line_number() {
  return this->line_nr;
}

void SymbolTable::print(int level) {
  if (level == 0) {
    printf("\nPrint table ([<record>] <name> <type>):\n");
  }
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
      "",
      (*parse_node)[0]->lineno
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
      "",
      (*parse_node)[0]->lineno
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
      (*parse_node)[0]->value,
      (*parse_node)[0]->lineno
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
      (*parse_node)[0]->value,
      (*parse_node)[0]->lineno
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
      (*parse_node)[0]->value,
      (*parse_node)[0]->lineno
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

SymbolTable* SymbolTable::get(const std::string& name) {

  for (SymbolTable* child : this->children) {
    SymbolTable *found;
    if (child->name == name) {
      return child;
    } else {
      if ((found = child->get(name)) != nullptr) {
        return found;
      }
    }
  }

  return nullptr;
}

bool SymbolTable::is_in_scope(std::string searched, std::string scope) {
  if (this->name == scope) {
    return this->check_scope(searched, this);
  }

  for (SymbolTable* child : this->children) {
    if (child->is_in_scope(searched, scope)) {
      return true;
    }
  }

  return false;
}

