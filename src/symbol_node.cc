#include "../inc/symbol_node.h"
#include <cstdio>
#include <exception>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

#include "../inc/utils.h"

using namespace std;

SymbolNode*
SymbolNode::find_node(const hash_t h)
{
  if (m_hash == h)
  {
    return this;
  }

  if (m_hash < h && mp_right)
  {
    return mp_right->find_node(h);
  }

  if (m_hash > h && mp_left)
  {
    return mp_left->find_node(h);
  }

  return nullptr;
}

SymbolNode::SymbolNode(string n, node_t nt, value_t vt, int l) :
  m_name(n), m_node_type(nt), m_value_type(vt), m_line_nbr(l), m_user_type(""),
  mp_left(nullptr), mp_right(nullptr), mp_table(nullptr)
{
  m_hash = hash<string>{}(n + to_string(nt));
}

SymbolNode::SymbolNode(SymbolNode* n) :
  m_name(n->m_name), m_node_type(n->m_node_type), m_value_type(n->m_value_type), 
  m_line_nbr(n->m_line_nbr), m_hash(n->m_hash),
  mp_left(nullptr), mp_right(nullptr), mp_table(nullptr)
{}

SymbolNode::~SymbolNode()
{
  if (mp_right) delete mp_right;
  if (mp_left) delete mp_left;
  if (mp_table) delete mp_table;
}

const string
SymbolNode::get_name()
{
  return m_name;
}

const node_t
SymbolNode::get_node_type()
{
  return m_node_type;
}

const value_t
SymbolNode::get_value_type()
{
  return m_value_type;
}

const int
SymbolNode::get_line_number()
{
  return m_line_nbr;
}

const string
SymbolNode::get_user_type()
{
  return m_user_type;
}

SymbolNode*
SymbolNode::get_table()
{
  return mp_table;
}

void
SymbolNode::set_user_type(string user_type)
{
  m_user_type = user_type;
}

void
SymbolNode::generate_table(Node* n, int &counter)
{
  SymbolNode *root = this;
  SymbolNode *node;

  switch (n->node_type) {
    case CLASS:
      extract_class(n, &node);
      node->mp_table = new SymbolNode(node);
      root->isnert_node(node);
      root = node->mp_table;
      break;
    case MAIN_CLASS:
      extract_main_class(n, &node);
      node->mp_table = new SymbolNode(node);
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
      node->mp_table = new SymbolNode(node);
      root->isnert_node(node);
      root = node->mp_table;
      break;
    case VARIABLE:
      extract_variable(n, &node);
      root->isnert_node(node);
      break;
    case METHOD:
      extract_method(n, &node);
      node->mp_table = new SymbolNode(node);
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
    cout << n->get_name() << " taken by " << this->get_name() << endl;
    throw exception();
  }
}

SymbolNode*
SymbolNode::get_node(const std::string name, const node_t nt)
{
  hash_t h = hash<string>{}(name + to_string(nt));

  return find_node(h);
}

void
SymbolNode::print(int level)
{
  for (int i = 0; i < level; i++)
    cout << "  ";

  if (mp_table)
    cout << "~";

  cout << "\e[0;32m" << m_name << "\e[0m" 
    << ": [n:" << m_node_type 
    << ", v:" << m_value_type;

  if (m_value_type == USER_DEF)
    cout << ":" << m_user_type;

  cout << ", l:" << m_line_nbr 
    <<"]\n";


  if (mp_left)
    mp_left->print(1);

  if (mp_right)
    mp_right->print(1);

  if (mp_table)
  {
    cout << endl;
    mp_table->print();
  }
}

vector<SymbolNode*>
SymbolNode::get_classes(bool started)
{
  vector<SymbolNode*> vec, temp;

  if (m_node_type != ROOT && !started)
  {
    cerr << "Node of wrong type, expected ROOT.\n";
    return vec;
  }
    
  if (m_node_type == CLASS)
    vec.push_back(this->mp_table);

  if (mp_left)
  {
    temp = mp_left->get_classes(true);
    vec.insert(end(vec), begin(temp), end(temp));
  }

  if (mp_right)
  {
    temp = mp_right->get_classes(true);
    vec.insert(end(vec), begin(temp), end(temp));
  }

  return vec;
}

vector<SymbolNode*>
SymbolNode::get_methods(bool started)
{
  vector<SymbolNode*> vec, temp;

  if (m_node_type != CLASS && !started)
  {
    cerr << "Node of wrong type, expected CLASS.\n";
    return vec;
  }

  if (m_node_type == METHOD)
    vec.push_back(this->mp_table);

  if (mp_left)
  {
    temp = mp_left->get_methods(true);
    vec.insert(end(vec), begin(temp), end(temp));
  }

  if (mp_right)
  {
    temp = mp_right->get_methods(true);
    vec.insert(end(vec), begin(temp), end(temp));
  }

  return vec;
}

vector<SymbolNode*>
SymbolNode::get_blocks(bool started)
{
  vector<SymbolNode*> vec, temp;

  if (m_node_type != METHOD && !started)
  {
    cerr << "Node of wrong type, expected METHOD.\n";
    return vec;
  }
  if (m_node_type == STATEMENT)
    vec.push_back(this->mp_table);

  if (mp_left)
  {
    temp = mp_left->get_blocks(true);
    vec.insert(end(vec), begin(temp), end(temp));
  }

  if (mp_right)
  {
    temp = mp_right->get_blocks(true);
    vec.insert(end(vec), begin(temp), end(temp));
  }

  if (mp_table)
  {
    if (mp_table->mp_left)
    {
      temp = mp_table->mp_left->get_blocks(true);
      vec.insert(end(vec), begin(temp), end(temp));
    }

    if (mp_table->mp_right)
    {
      temp = mp_table->mp_right->get_blocks(true);
      vec.insert(end(vec), begin(temp), end(temp));
    }
  }

  return vec;
}

