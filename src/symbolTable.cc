#include "../inc/symbolTable.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace sym;

/* * * * * * * * * * * * * * * * * *
 *            Private              *
 * * * * * * * * * * * * * * * * * */

void SymNode::add_from_main_class(Node *n, string scope) {
  string c_name = (*n)[0]->value;
  string a_name = (*n)[1]->value;

  if (this->is_declared(a_name))
    cerr << "error [" << n->lineno
      << "]: Redefinition of: " << a_name << endl;

  if (this->is_declared(c_name))
    cerr << "error [" << n->lineno
      << "]: Redefinition of: " << c_name << endl;

  SymNode* class_node = new SymNode(c_name, scope, NONE, NodeType::MainClass);
  SymNode* arg_node = new SymNode(a_name, scope, ARG_ARR, NodeType::Variable);

  class_node->add_node(arg_node);
  this->add_node(class_node);
}

void SymNode::add_from_class(Node *n, string scope) {
  string name = (*n)[0]->value;

  if (this->is_declared(name))
    cerr << "error [" << n->lineno
      << "]: Redefinition of: " << name  << endl;

  SymNode *node = new SymNode(name, scope, NONE, NodeType::Class);

  this->add_node(node);

  for (Node* c : n->children)
    node->add_from_node(c, node->name);
}

void SymNode::add_from_method(Node *n, string scope) {
  string type = (*n)[0]->value;
  string name = (*n)[1]->value;

  if (this->is_declared(name))
    cerr << "error [" << n->lineno
      << "]: Redefinition of: " << name << endl;

  if (type == "id") {
    type = (*(*n)[0])[0]->value;
  }

  SymNode *node = new SymNode(name, scope, type, NodeType::Method);

  this->add_node(node);

  for (Node* c : n->children)
    node->add_from_node(c, node->name);
}

void SymNode::add_from_variable(Node *n, string scope) {
  string type = (*n)[0]->value;
  string name = (*n)[1]->value;

  if (this->is_declared(name))
    cerr << "error [" << n->lineno
      << "]: Redefinition of: " << name << endl;

  if (type == "id")
    type = (*((*n)[0]))[0]->value;

  SymNode *node = new SymNode(name, scope, type, NodeType::Variable);

  this->add_node(node);
}

void SymNode::add_from_node(Node *p_node, string scope) {
  if (p_node->type == MAIN_CLASS)
    this->add_from_main_class(p_node, scope);
  else if (p_node->type == CLASS)
    this->add_from_class(p_node, scope);
  else if (p_node->type == METHOD)
    this->add_from_method(p_node, scope);
  else if (p_node->type == VARIABLE || p_node->type == METHOD_ARG)
    this->add_from_variable(p_node, scope);
  else
    for (Node* child : p_node->children)
      this->add_from_node(child, scope);
}

void SymNode::print_node(int level) {
   for (int i = 0; i < level; i++) cout << "  ";

  cout << "\x1B[34m" << this->name << "\033[0m: [ v: " 
    << this->value_type << ", n: " 
    << this->node_type << ", s: " 
    << this->scope << " ]"<< endl;

  for (SymNode *n : this->nodes) n->print_node(level + 1);
}

bool SymNode::is_declared(std::string name) {
  SymNode* temp = this;
  while (temp) {
    for (SymNode* n : temp->nodes) {
      if (n->name == name)
        return true;
    }

    temp = temp->parent;
  }

  return false;
}

/* * * * * * * * * * * * * * * * * *
 *            Public               *
 * * * * * * * * * * * * * * * * * */

SymNode::SymNode(string n, string s, string vt, NodeType nt) :
  name(n), scope(s), value_type(vt), node_type(nt), parent(nullptr) {}

SymNode::~SymNode() {
  for (SymNode* n : nodes) delete n;
}

string SymNode::get_name() {
  return this->name;
}

vector<SymNode*> SymNode::get_nodes_flat() {
  vector<SymNode*> vec;
  vec.push_back(this);
  for (SymNode* n : this->nodes) {
    auto temp = n->get_nodes_flat();
    for (SymNode* c : temp) {
      vec.push_back(c);
    }
  }

  return vec;
}

vector<SymNode*> SymNode::get_classes() {
  if (this->name != "root") {
    return vector<SymNode*>();
  }

  return this->nodes;
}

vector<SymNode*> SymNode::get_global_variables(string class_name) {
  vector<SymNode*> v;

  if (this->name != "root") {
    return v;
  }

  for (SymNode* n : *this) {
    if (n->name == class_name) {
      for (SymNode* c : *n) {
        if (c->node_type == NodeType::Variable) {
          v.push_back(c);
        }
      }

      break;
    }
  }

  return v;
}

vector<SymNode*> SymNode::get_local_variables(vector<string> scopes) {
  SymNode* method;

  for (SymNode* n : *this) {
    if (n->name == scopes[0]) {
      for (SymNode* c : *n) {
        if (c->name == scopes[1]) {
          method = c;
          break;
        }
      }

      break;
    }
  }

  return method->get_nodes_flat();
}

void SymNode::generate_table(Node* n) {
  this->add_from_node(n, "root");
}

void SymNode::print() {
  this->print_node(0);
}

void SymNode::add_node(SymNode* n) {
  n->parent = this;
  this->nodes.push_back(n);
}

vector<SymNode*>::iterator SymNode::begin() {
  return this->nodes.begin();
}

vector<SymNode*>::iterator SymNode::end() {
  return this->nodes.end();
}

/* * * * * * * * * * * * * * * * * *
 *            Other                *
 * * * * * * * * * * * * * * * * * */

SymbolTable sym::create_table() {
  return SymNode("root", "root", "", NodeType::Root);
}

