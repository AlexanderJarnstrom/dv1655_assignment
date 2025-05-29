#include "../inc/symanticFunction.h"
#include <iostream>
#include <string>
#include <vector>

#define STATEMENT "statement"
#define EXPRESSION "expression"

#define OPERATOR "operator"
#define ASSIGN "assign"
#define ID "id"
#define ATTRIBUTE "attr"

using namespace std;

bool is_name_present(vector<sym::SymNode*> nodes, string name) {
  for (sym::SymNode* n : nodes) {
    if (n->get_name() == name)
      return true;
  }

  return false;
}

void treverse_scope_check(Node* node, sym::SymbolTable& table, vector<string> scopes) {
  if (node->type == "id") {
    string name = node->value; 
    bool found = false;

    // Check objects.
    vector<sym::SymNode*> holder = table.get_classes();
    found = is_name_present(holder, name);

    // Check global variables.
    if (!found) {
      holder = table.get_global_variables(scopes[0]);
      found = is_name_present(holder, name);
    }

    // Check local variables.
    if (!found) {
      holder = table.get_local_variables(scopes);
      found = is_name_present(holder, name);
    }

    if (!found) {
      cerr << "@error at line " << node->lineno
        << " '" << name << "' is not in scope '"
        << scopes[scopes.size() - 1] << "'\n";
    }

    return;
  } else if (node->type == EXPRESSION && node->value == ATTRIBUTE) {
    // Check attributes
    return;
  } else if (node->type == METHOD) {
    scopes.push_back((*node)[1]->value);  
  } else if (node->type == CLASS ||  node->type == MAIN_CLASS) {
    scopes.push_back((*node)[0]->value);  
  }
  

  for (Node* n : node->children) {
    treverse_scope_check(n, table, scopes);
  }
}

void scope_check(Node *root, sym::SymbolTable& table) {
  treverse_scope_check(root, table, vector<string>());
}

void treverse_definition_check(Node* node, sym::SymbolTable& table) {
  if (node->type == "id") {
    bool found = false;

    for (sym::SymNode* n : table.get_nodes_flat()) {
      if (n->get_name() == node->value) {
        
        found = true;
        break;
      }
    }

    if (!found) {
      cerr << "@error at line " << node->lineno
        << ": " << node->value << " is not declared." << endl;
    }
  }

  for (Node* c : node->children) {
    treverse_definition_check(c, table);
  }
}

void definition_check(Node *root, sym::SymbolTable &table) {
  treverse_definition_check(root, table);
}

void type_check(Node *root, sym::SymbolTable& table) {

}
