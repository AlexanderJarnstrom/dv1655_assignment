#include "../inc/semantic_functions.h"

#include "../inc/utils.h"

#include <iostream>
#include <string>
#include <vector>

extern int errCode;

typedef enum {
  NOTHING,
  NOT_FOUND
} event_t;

event_t event;

typedef struct {
  value_t value_type;
  std::string user_type;
} node_val_t;

using namespace std;

void
update_scope(Node* n, string& scope, int& counter)
{
  // Update scope
  if (n->node_type == CLASS || n->node_type == MAIN_CLASS)
    scope = (*n)[0]->value;
  else if (n->node_type == METHOD)
    scope = (*(*n)[0])[1]->value;
  else if (n->node_type == STATEMENT && n->value == "block")
  {
    scope = "Block_" + to_string(counter);
    counter++;
  }
}

SymbolNode*
get_node(SymbolNode* table, string scope, string name, node_t nt, int line_nbr)
{
  SymbolNode* found_node;

  for (SymbolNode* c : table->get_classes())
  {
    found_node = c->get_node(name, nt);
    if(found_node) 
      return found_node;

    for (SymbolNode* m : c->get_methods())
    {
      found_node = m->get_node(name, nt);
      if (found_node && found_node->get_line_number() < line_nbr)
        return found_node;

      for (SymbolNode* b : m->get_blocks())
      {
        found_node = b->get_node(name, nt);
        if (found_node && found_node->get_line_number() < line_nbr)
          return found_node;

        if (scope == b->get_name())
          break;
      }

      if (scope == m->get_name())
        break;
    }

    if (scope == c->get_name())
      break;
  }

  return nullptr; 
}

SymbolNode*
get_current_object(SymbolNode* table, string scope)
{
  SymbolNode* found_node;

  for (SymbolNode* c : table->get_classes())
  {
    found_node = c->get_node(scope, METHOD);

    if (found_node)
      return c;

    for (SymbolNode* m : c->get_methods())
    {
      found_node = m->get_node(scope, STATEMENT);

      if (found_node)
        return c;
    }
  }

  return nullptr;
}

void
check_scope(SymbolNode* table, string scope, string name, node_t nt, int line_nbr)
{
  vector<string> msgs;
  SymbolNode* found_node;
  bool found = false;

  for (SymbolNode* c : table->get_classes())
  {
    found_node = c->get_node(name, nt);
    if(found_node) 
    {
      found = true;
      break;
    }

    for (SymbolNode* m : c->get_methods())
    {
      found_node = m->get_node(name, nt);
      if (found_node && found_node->get_line_number() < line_nbr)
      {
        found = true;
        break;
      }

      for (SymbolNode* b : m->get_blocks())
      {
        found_node = b->get_node(name, nt);
        if (found_node && found_node->get_line_number() < line_nbr)
        {
          found = true;
          break;
        }

        if (scope == b->get_name() || found)
          break;
      }

      if (scope == m->get_name() || found)
        break;
    }

    if (scope == c->get_name() || found)
      break;
  }

  if (!found)
    print_error(errCodes::SEMANTIC_ERROR, line_nbr, name + " does not exist in current scope.");
}

void
def_val_walker(Node* n, SymbolNode* table, string scope, int& counter)
{
  // TODO: check origin of custom types.
  update_scope(n, scope, counter);

  // Checks
  if (n->node_type == STATEMENT && n->value == "assign")
  {
    check_scope(table, scope, (*n)[0]->value, VARIABLE, n->lineno);
  }
  else if (n->node_type == EXPRESION && n->value == "id")
  {
    check_scope(table, scope, (*n)[0]->value, VARIABLE, n->lineno);
  }
  else if (n->node_type == EXPRESION && (n->value == "attr" || n->value == "attr_exp"))
  {
    string name = (*n)[1]->value;
    if ((*n)[0]->value == "this")
    {
      SymbolNode* c = get_current_object(table, scope);

      if (!c)
        print_error(errCodes::SEMANTIC_ERROR, n->lineno, "could not get 'this'.");

      SymbolNode* m = c->get_node(name, METHOD);

      if (!m)
        print_error(
          errCodes::SEMANTIC_ERROR,
          n->lineno,
          "method " + name + " it not under " + c->get_name() + "."
        );
    }
    else
    {
      check_scope(table, scope, name, METHOD, n->lineno);
    }
  }

  // Go through children
  for (Node* c : n->children)
  {
    def_val_walker(c, table, scope, counter);
  }
}

node_val_t
find_type(Node* n, SymbolNode* table, string scope)
{
  if (n->node_type == OTHER && n->type == "number")
  {
    return node_val_t{INT};
  }
  else if (n->node_type ==  OTHER && n->type == "bool")
  {
    return node_val_t{BOOL};
  }
  else if (n->node_type == OTHER && n->type == "id")
  {
    SymbolNode* node = get_node(table, scope, n->value, VARIABLE, n->lineno);

    if (!node)
    {
      event = NOT_FOUND;
      return node_val_t{NONE};
    }

    return node_val_t{node->get_value_type()};
  }
  else if (n->node_type == EXPRESION && n->value == "operator")
  {
    string op_type = (*n)[1]->value;
    node_val_t left = find_type((*n)[0], table, scope);
    node_val_t right = find_type((*n)[2], table, scope);

    if (left.value_type != right.value_type)
      return node_val_t{NONE};

    if (op_type == "mult" && (left.value_type != INT || right.value_type != INT))
      return node_val_t{NONE};
    else if (op_type == "sub" && (left.value_type != INT || right.value_type != INT))
      return node_val_t{NONE};
    else if (op_type == "add" && (left.value_type != INT || right.value_type != INT))
      return node_val_t{NONE};
    else if (op_type == "or" && (left.value_type != BOOL || right.value_type != BOOL))
      return node_val_t{NONE};
    else if (op_type == "and" && (left.value_type != BOOL || right.value_type != BOOL))
      return node_val_t{NONE};
    else if (op_type == "lt" && (left.value_type != INT || right.value_type != INT))
      return node_val_t{NONE};
    else if (op_type == "gt" && (left.value_type != INT || right.value_type != INT))
      return node_val_t{NONE};

    if (op_type == "mult" || op_type == "sub" || op_type == "add")
      return node_val_t{INT};
    else
      return node_val_t{BOOL};
  }
  else if (n->node_type == EXPRESION && n->value == "brackets")
  {
    return find_type((*n)[0], table, scope);
  }
  else if (n->node_type == EXPRESION && (n->value == "attr" || n->value == "attr_exp"))
  {
    Node* c = (*n)[0];

    SymbolNode* node;
    if (c->node_type == EXPRESION && c->value == "this")
    {
      node = get_node(table, scope, (*n)[1]->value, METHOD, n->lineno);
    }
    else if (c->node_type == EXPRESION && c->value == "id")
    {
      SymbolNode* obj = get_node(table, scope, (*c)[0]->value, VARIABLE, c->lineno);

      if (!obj)
      {
        event = NOT_FOUND;
        return node_val_t{NONE};
      }

      node = get_node(table, obj->get_user_type(), (*n)[1]->value, METHOD, c->lineno);
    }

    if (!node)
    {
      event = NOT_FOUND;
      return node_val_t{NONE};
    }
    
    return {node->get_value_type(), node->get_user_type()};
  }
  else if (n->node_type == EXPRESION && n->value == "id")
  {
    SymbolNode* node = get_node(table, scope, (*n)[0]->value, VARIABLE, n->lineno);

    if (!node)
    {
      event = NOT_FOUND;
      return  node_val_t{NONE};
    }

    return  node_val_t{node->get_value_type()};
  }

  return  node_val_t{NONE};
}

void
type_val_walker(Node* n, SymbolNode *table, string scope, int& counter)
{
  update_scope(n, scope, counter);
 
  if (n->node_type == STATEMENT && n->value == "assign")
  {
    string name = (*n)[0]->value;
    SymbolNode* node = get_node(table, scope, name, VARIABLE, n->lineno);
    node_val_t value_type = find_type((*n)[1], table, scope);

    if (node)
      cout << node->get_name() << " " << node->get_user_type() << " == " << value_type.user_type << endl;

    if (!node)
      event = NOT_FOUND;
    else if ((node->get_value_type() != value_type.value_type) && event != NOT_FOUND)
      print_error(errCodes::SEMANTIC_ERROR, n->lineno, "non-matching types.");
  }
  else if (n->node_type == STATEMENT && (n->value == "if" || n->value == "if-else" || n->value == "while"))
  {
    node_val_t value_type = find_type((*n)[0], table, scope);

    if (value_type.value_type != BOOL && event != NOT_FOUND)
      print_error(
        errCodes::SEMANTIC_ERROR,
        n->lineno, 
        "non-boolean in " + n->value + "-statement expression."
      );
  }

  event = NOTHING;

  for (Node* c : n->children)
    type_val_walker(c, table, scope, counter);
}

void
definition_validation(Node* n, SymbolNode* table)
{
  cout << "Checking definitions...\n";

  int counter = 0;
  def_val_walker(n, table, "root", counter);

  cout << "...done\n\n";
}

void
type_validation(Node* n, SymbolNode* table)
{
  cout << "Checking types...\n";

  int counter = 0;
  type_val_walker(n, table, "root", counter);

  cout << "...done\n\n";
}

