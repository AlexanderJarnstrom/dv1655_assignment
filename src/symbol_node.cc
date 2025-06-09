#include "../inc/symbol_node.h"
#include <exception>
#include <functional>
#include <iterator>
#include <string>

#include "../inc/utils.h"

using namespace std;

SymbolNode::SymbolNode(string n, node_t nt, value_t vt) :
  m_name(n), m_node_type(nt), m_value_type(vt),
  mp_left(nullptr), mp_right(nullptr), mp_table(nullptr)
{
  m_hash = hash<string>{}(n);
}

SymbolNode::~SymbolNode()
{
  if (mp_right) delete mp_right;
  if (mp_left) delete mp_left;
  if (mp_table) delete mp_table;
}

void
SymbolNode::generate_table(Node* n, int &counter)
{
  SymbolNode *root = this;
  SymbolNode *node;

  switch (n->node_type) {
    case CLASS:
      extract_class(n, &node);
      node->mp_table = new SymbolNode(node->m_name, CLASS, NONE);
      root->isnert_node(node);
      root = node->mp_table;
      break;
    case MAIN_CLASS:
      extract_main_class(n, &node);
      node->mp_table = new SymbolNode(node->m_name, MAIN_CLASS, NONE);
      root->isnert_node(node);
      root = node->mp_table;
      extract_main_class_args(n, &node);
      root->isnert_node(node);
      break;
    case STATEMENT:
      extract_statement(n, &node, counter);

      if (!node)
        break;

      counter++;
      node->mp_table = new SymbolNode(node->m_name, STATEMENT, NONE);
      root->isnert_node(node);
      root = node->mp_table;
      break;
    case VARIABLE:
      extract_variable(n, &node);
      root->isnert_node(node);
      break;
    case METHOD:
      extract_method(n, &node);
      node->mp_table = new SymbolNode(node->m_name, METHOD, NONE);
      root->isnert_node(node);
      root = node->mp_table;
      break;
    default:
      break;
  }

  for (Node* c : n->children)
    root->generate_table(c, counter);
}

void
SymbolNode::isnert_node(SymbolNode* n)
{
  if (m_hash < n->m_hash)
  {
    if (mp_right)
      mp_right->isnert_node(n);
    else 
      mp_right = n;
  } 
  else if (m_hash > n->m_hash)
  {
    if (mp_left)
      mp_left->isnert_node(n);
    else
      mp_left = n;
  }
  else
  {
    throw exception();
  }
}


void
SymbolNode::print(int level)
{
  for (int i = 0; i < level; i++)
    cout << "  ";

  if (mp_table)
    cout << "~";

  cout << "\e[0;32m" << m_name << "\e[0m" << ": [" 
    << m_node_type << ", "
    << m_value_type << "]" << endl;

  if (mp_left)
    mp_left->print(1);

  if (mp_right)
    mp_right->print(1);

  if (mp_table)
  {
    if (!mp_table->mp_right && !mp_table->mp_left)
      return;

    cout << endl;
    mp_table->print();
  }
}

vector<SymbolNode*>
SymbolNode::get_scopes()
{
  vector<SymbolNode*> scopes;  
  vector<SymbolNode*> temp;  

  if (mp_table)
  {
    scopes.push_back(mp_table);
  }

  if (mp_left)
  {
    temp = mp_left->get_scopes();
    scopes.insert(end(scopes), begin(temp), end(temp));
    temp.clear();
  }

  if (mp_right)
  {
    temp = mp_right->get_scopes();
    scopes.insert(end(scopes), begin(temp), end(temp));
    temp.clear();
  }

  return scopes;
}
