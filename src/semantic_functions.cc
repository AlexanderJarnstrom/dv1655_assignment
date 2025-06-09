#include "../inc/semantic_functions.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
 
using namespace std;

vector<string>
check_scope(SymbolNode* table, string scope, string name, int line_nbr)
{
  vector<string> msgs;
  SymbolNode* found_node;
  bool found = false;

  for (SymbolNode* c : table->get_classes())
  {
    found_node = c->get_node(name);
    if(found_node) 
    {
      found = true;
      break;
    }

    for (SymbolNode* m : c->get_methods())
    {
      found_node = m->get_node(name);
      if (found_node && found_node->get_line_number() < line_nbr)
      {
        found = true;
        break;
      }

      for (SymbolNode* b : m->get_blocks())
      {
        found_node = b->get_node(name);
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
  {
    stringstream msg;
    msg << "@error at line: " << line_nbr
      << ": '" << name << "'" << " does not exist in current scope.";
    msgs.push_back(msg.str());
  }
  return msgs;
}

vector<string>
def_val_walker(Node* n, SymbolNode* table, string scope, int& count)
{
  vector<string> msgs, temp;

  // Update scope
  if (n->node_type == CLASS || n->node_type == MAIN_CLASS)
    scope = (*n)[0]->value;
  else if (n->node_type == METHOD)
    scope = (*(*n)[0])[1]->value;
  else if (n->node_type == STATEMENT && n->value == "block")
  {
    scope = "Block_" + to_string(count);
    count++;
  }

  // Checks
  if (n->node_type == STATEMENT && n->value == "assign")
  {
    string name = (*n)[0]->value;
    temp = check_scope(table, scope, name, n->lineno);
    msgs.insert(end(msgs), begin(temp), end(temp));
  }
  else if (n->node_type == EXPRESION && n->value == "id")
  {
    string name = (*n)[0]->value;
    temp = check_scope(table, scope, name, n->lineno);
    msgs.insert(end(msgs), begin(temp), end(temp));
  }
  else if (n->node_type == EXPRESION && n->value == "attr")
  {
    string name = (*n)[1]->value;
    temp = check_scope(table, scope, name, n->lineno);
    msgs.insert(end(msgs), begin(temp), end(temp));
  }

  // Go through children
  for (Node* c : n->children)
  {
    temp = def_val_walker(c, table, scope, count);
    msgs.insert(end(msgs), begin(temp), end(temp));
  }

  return msgs;
}

vector<string>
type_val_walker(Node* n, SymbolNode *table, string scope, int& counter)
{
  vector<string> msgs;

  return msgs;  
}

void
definition_validation(Node* n, SymbolNode* table)
{
  cout << "Checking definitions...";

  int counter = 0;
  vector<string> res = def_val_walker(n, table, "root", counter);

  cout << "done.\n";

  if (res.size() != 0)
  {
    cout << "Found errors:\n";
    for (string msg : res)
    {
      cout << "  " << msg << endl;
    }
  }
}

void
type_validation(Node* n, SymbolNode* table)
{
  cout << "Checking types...";

  int counter = 0;
  vector<string> res = type_val_walker(n, table, "root", counter);

  cout << "done.\n";

  if (res.size() != 0)
  {
    cout << "Found errors:\n";
    for (string msg : res)
    {
      cout << "  " << msg << endl;
    }
  }
}

