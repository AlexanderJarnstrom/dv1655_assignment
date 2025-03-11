#include "SemanticFunctions.h"
#include "SymbolTable.h"
#include <stdexcept>
#include <string>

std::string update_scope(std::string scope, Node* node);
void statement_check(Node* node, const std::string& scope, SymbolTable* table);
std::string expression_check(Node* node, std::string scope, SymbolTable* table);
std::string get_type(Node* node, const std::string& scope, SymbolTable* table);
std::string expression_operator(Node* node, const std::string& scope, SymbolTable* table);
void method_check(Node* node, const std::string& scope, SymbolTable* table);

std::string update_scope(std::string scope, Node* node) {
  if (node->type == "class_decl" || node->type == "main_class") {
    return (*node)[0]->value;    
  } else if (node->type == "method_decl") {
    return (*node)[1]->value;    
  }

  return scope;
}

void statement_check(Node* node, const std::string& scope, SymbolTable* table) {
  if (node->value == "assign") {
    if (!table->is_in_scope((*node)[0]->value, scope)) {
      printf("Error at line %d.\n", node->lineno);
      throw runtime_error("Variable hasn't been declared.");
    }
  } else if (node->value == "if") {
    if (get_type((*node)[0], scope, table) != "boolean") {
      printf("Error at line %d.\n", (*node)[0]->lineno);
      throw runtime_error("Expression of wrong type."); 
    }
  }
}

std::string expression_check(Node* node, std::string scope, SymbolTable* table) {
  if (node->value == "operator") {
    return expression_operator(node, scope, table);
  } else if (node->value == "id") {
    if (table->is_in_scope((*node)[0]->value, scope)) {
      SymbolTable* value = table->get((*node)[0]->value); 
      return value->get_exp_type();
    } else {
      throw runtime_error("Out of scope.");
    }
  } else if (node->value == "brackets") {
    return expression_check((*node)[0], scope, table);
  } else if (node->value == "not") {
    if (get_type((*node)[0], scope, table) != "boolean") {
      printf("Error at line %d.\n", (*node)[0]->lineno);
      throw runtime_error("Expression of wrong type."); 
    } else {
      return "boolean";
    }
  }

  return "";
}

std::string expression_operator(Node* node, const std::string& scope, SymbolTable* table) {
  if ((*node)[1]->value == "add") {
    std::string left_type = get_type((*node)[0], scope, table);
    std::string right_type = get_type((*node)[2], scope, table);

    if (left_type != right_type) {
      printf("Error at line %d.\n", node->lineno);
      throw runtime_error("Conflicting types");
    } else {
      return left_type;
    }
  } else if ((*node)[1]->value == "sub") {
    std::string left_type = get_type((*node)[0], scope, table);
    std::string right_type = get_type((*node)[2], scope, table);

    if (left_type != right_type) {
      printf("Error at line %d.\n", node->lineno);
      throw runtime_error("Conflicting types");
    } else {
      return left_type;
    }
  } else if ((*node)[1]->value == "mult") {
    std::string left_type = get_type((*node)[0], scope, table);
    std::string right_type = get_type((*node)[2], scope, table);

    if (left_type != right_type) {
      printf("Error at line %d.\n", node->lineno);
      throw runtime_error("Conflicting types");
    } else {
      return left_type;
    }
  } else if ((*node)[1]->value == "eq") {
    std::string left_type = get_type((*node)[0], scope, table);
    std::string right_type = get_type((*node)[2], scope, table);

    if (left_type != right_type) {
      printf("Error at line %d.\n", node->lineno);
      throw runtime_error("Conflicting types");
    } else {
      return "boolean";
    }
  } else if ((*node)[1]->value == "lt") {
    std::string left_type = get_type((*node)[0], scope, table);
    std::string right_type = get_type((*node)[2], scope, table);

    if (left_type != right_type) {
      printf("Error at line %d.\n", node->lineno);
      throw runtime_error("Conflicting types");
    } else {
      return "boolean";
    }
  } else if ((*node)[1]->value == "gt") {
    std::string left_type = get_type((*node)[0], scope, table);
    std::string right_type = get_type((*node)[2], scope, table);

    if (left_type != right_type) {
      printf("Error at line %d.\n", node->lineno);
      throw runtime_error("Conflicting types");
    } else {
      return "boolean";
    }
  }

  return "";
}

std::string get_type(Node* node, const std::string& scope, SymbolTable* table) {

  if (node->type == "number") {
    return "int";
  } else if (node->type == "bool") {
    return "boolean";
  } else if (node->type == "string") {
    return "string";
  } else if (node->type == "expression") {
    return expression_check(node, scope, table);
  }

  return "";
}

void method_check(Node* node, const std::string& scope, SymbolTable* table) {
  
  std::string method_type = (*node)[0]->value;
  std::string return_type = get_type((*node)[4], scope, table);

  if (method_type != return_type) {
    printf("Error at line %d.\n", node->lineno);
    throw runtime_error("Return type doesn't match method type.");
  }
}

void analyse(Node *node, std::string scope, SymbolTable *table) {
  scope = update_scope(scope, node);

  if (node->type == "statement") {
    statement_check(node, scope, table);
  } else if (node->type == "expression") {
    expression_check(node, scope, table);
  } else if (node->type == "method_decl") {
    method_check(node, scope, table);
  }

  for (Node* child : node->children) {
    analyse(child, scope, table);
  }
}
