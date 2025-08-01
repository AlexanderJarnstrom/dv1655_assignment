#include "../../inc/symbol_table/table.h"
#include "../../inc/symbol_table/class.h"
#include "../../inc/symbol_table/method.h"
#include "../../inc/symbol_table/variable.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace SymbolTable;
using namespace std;

void
Table::add_error(int line, string text)
{
  stringstream s;
  s << "@error at line " << line << ": " << text << endl;
  m_errors.push_back(s.str());
}

Children*
Table::children_cast(Record* n)
{
  Children* node = nullptr;

  switch (n->get_record_type())
  {
    case RecordType::TABLE:
      node = static_cast<Children*>(static_cast<Table*>(n));
      break;
    case RecordType::CLASS:
      node = static_cast<Children*>(static_cast<Class*>(n));
      break;
    case RecordType::METHOD:
      node = static_cast<Children*>(static_cast<Method*>(n));
      break;
    default:
      break;
  }

  return node;
}

Record*
Table::search(Record* p, string id, RecordType rt)
{
  Children* n = children_cast(p);

  if (!n)
    return nullptr;

  Record* s = n->get(id);

  if (s && (rt == RecordType::NONE || s->get_record_type() == rt))
  {
    return s;
  }

  for (Record *c : n->get_children()) 
  {
    s = search(c, id, rt);
    if (s) return s;
  }

  return nullptr;
}

void
Table::build_global_table(Node* n)
{
  Record* node = nullptr;

  string type_s = n->type;

  if (type_s == "main_class" || type_s == "class_decl")
    node = new Class(n, m_scope);
  else if (type_s == "method_decl" && n->value == "declaration")
    node = new Method(n, m_scope);
  else if (type_s == "var_decl" || type_s == "method_arg")
    node = new Variable(n, m_scope);

  if (node)
  {
    switch (m_scope->get_record_type()) {
      case RecordType::TABLE:
        static_cast<Table*>(m_scope)->insert(node);
        break;
      case RecordType::CLASS:  
        static_cast<Class*>(m_scope)->insert(node);
        break;
      case RecordType::METHOD:  
        static_cast<Method*>(m_scope)->insert(node);
        break;
      default:
        break;
    }

    enter_scope(node);
  }

  for (Node* c : n->children)
  {
    build_global_table(c);
  }

  if (node)
    exit_scope();
}

void 
Table::check_global_declerations(Node* n)
{
  Record* node = nullptr;
  Record* temp;
  string value_s, type_s, id_s;

  type_s = n->type;

  if (type_s == "main_class" || type_s == "class_decl")
    node = new Class(n, m_scope);
  else if (type_s == "method_decl" && n->value == "declaration")
    node = new Method(n, m_scope);
  else if (type_s == "var_decl" || type_s == "method_arg")
    node = new Variable(n, m_scope);

  if (node && node->get_record_type() != RecordType::VARIABLE)
    enter_scope(children_cast(m_scope)->get(node->get_id()));

  if (type_s == "expression")
  {
    value_s = n->value;
    if (value_s == "attr" && (*n)[0]->value == "id")
    {
      id_s = (*(*n)[0])[0]->value;

      temp = search(m_scope->get_parent(), id_s, RecordType::VARIABLE);

      if (temp)
      {
        Record* obj = search(this, static_cast<Variable*>(temp)->get_value_type(), RecordType::CLASS);
        if (!obj)
        {
          add_error(n->lineno, "class does not exist.");
          return;
        }

        id_s = (*n)[1]->value;
        if (!search(obj, id_s, RecordType::METHOD))
          add_error(n->lineno, obj->get_id() + " does not have method " + id_s + ".");
      }
    }
    else if (value_s == "attr" && (*n)[0]->value == "this")
    {
      Record* obj = m_scope->get_parent();
      if (!obj)
      {
        add_error(n->lineno, "class does not exist.");
        return;
      }


      id_s = (*n)[1]->value;
      if (!search(obj, id_s, RecordType::METHOD))
        add_error(n->lineno, obj->get_id() + " does not have method " + id_s + ".");
    }
  }

  for(Node* c : n->children)
    check_global_declerations(c);

  if (node && node->get_id() == m_scope->get_id())
    m_scope = m_scope->get_parent();
}

void
Table::check_local_declerations(Node* n)
{
  Record* node = nullptr;
  string type_s = n->type;
  string value_s, id_s;

  if (type_s == "main_class" || type_s == "class_decl")
    node = new Class(n, m_scope);
  else if (type_s == "method_decl" && n->value == "declaration")
    node = new Method(n, m_scope);
  else if (type_s == "var_decl" || type_s == "method_arg")
    node = new Variable(n, m_scope);
  else if (type_s == "expression")
  {
    value_s = (*n).value;

    if (value_s == "id")
    {
      id_s = (*n)[0]->value;
      if (!search(m_scope->get_parent(), id_s))
        add_error((*n)[0]->lineno, id_s + " is not defined.");
    }
  }
  else if (type_s  == "statement")
  {
    value_s = (*n).value;


    if (value_s == "assign" || value_s == "assign_arr")
    {
      id_s = (*n)[0]->value;
      if (!search(m_scope->get_parent(), id_s, RecordType::VARIABLE))
        add_error((*n)[0]->lineno, id_s + " is not defined.");
    }
  }

  if (node)
  {
    switch (m_scope->get_record_type()) {
      case RecordType::TABLE:
        static_cast<Table*>(m_scope)->insert(node);
        break;
      case RecordType::CLASS:  
        static_cast<Class*>(m_scope)->insert(node);
        break;
      case RecordType::METHOD:  
        static_cast<Method*>(m_scope)->insert(node);
        break;
      default:
        break;
    }

    enter_scope(node);
  }

  for (Node* c : n->children)
  {
    check_local_declerations(c);
  }

  if (node)
    exit_scope();
}

Table::Table() 
  : Record(nullptr, RecordType::TABLE), Children(), m_scope(this)
{
  set_id("root");
}

Table::~Table()
{}

void 
Table::enter_scope(Record* n)
{
  m_scope = n;
}

void
Table::exit_scope()
{
  if (!m_scope->get_parent())
    return;

  if (m_scope->get_record_type() == RecordType::CLASS)
  {
    m_scope = m_scope->get_parent();
    return;
  }

  Children* c = children_cast(m_scope);
  if (c)
    c->clear();

  m_scope = m_scope->get_parent();
}

void
Table::build_table(Node* n)
{
  Record* node = nullptr;

  string type_s = n->type;

  if (type_s == "main_class" || type_s == "class_decl")
    node = new Class(n, m_scope);
  else if (type_s == "method_decl" && n->value == "declaration")
    node = new Method(n, m_scope);
  else if (type_s == "var_decl" || type_s == "method_arg")
    node = new Variable(n, m_scope);

  if (node)
  {
    switch (m_scope->get_record_type()) {
      case RecordType::TABLE:
        static_cast<Table*>(m_scope)->insert(node);
        break;
      case RecordType::CLASS:  
        static_cast<Class*>(m_scope)->insert(node);
        break;
      case RecordType::METHOD:  
        static_cast<Method*>(m_scope)->insert(node);
        break;
      default:
        break;
    }

    enter_scope(node);
  }

  for (Node* c : n->children)
  {
    build_table(c);
  }

  if (node)
    m_scope = node->get_parent();
}

void
Table::check_identifiers(Node* n)
{
  Record* node = nullptr;
  string type_s = n->type;

  if (type_s == "main_class" || type_s == "class_decl")
    node = new Class(n, m_scope);
  else if (type_s == "method_decl" && n->value == "declaration")
    node = new Method(n, m_scope);
  else if (type_s == "var_decl" || type_s == "method_arg")
    node = new Variable(n, m_scope);

  if (node)
  {
    if (search(m_scope, node->get_id(), node->get_record_type()))
    {
      int line = (*n)[0]->lineno;
      add_error(line, "Non-unique id: " + node->get_id());
    }
    switch (m_scope->get_record_type()) {
      case RecordType::TABLE:
        static_cast<Table*>(m_scope)->insert(node);
        break;
      case RecordType::CLASS:  
        static_cast<Class*>(m_scope)->insert(node);
        break;
      case RecordType::METHOD:  
        static_cast<Method*>(m_scope)->insert(node);
        break;
      default:
        break;
    }

    enter_scope(node);
  }

  for (Node* c : n->children)
  {
    check_identifiers(c);
  }

  if (node)
    exit_scope();
}

void
Table::check_declerations(Node* n)
{
  reset();
  check_local_declerations(n);
  reset();
  build_table(n);
  check_global_declerations(n);
  print();
  reset();
}
Record*
Table::find(string id)
{
  return search(m_scope, id);
}

void
Table::print(const int l)
{
  cout << "Printing symbol table:" << endl;
  cout << "- \e[0;36m" << get_id() << "\e[0m: Table [rt: " 
    << get_record_type() << "]" << endl;

  for (Record* child : get_children())
  {
    child->print(l + 1);
  }
}

void 
Table::print_errors()
{
  for (string s : m_errors)
    cerr << s;
}

void
Table::reset()
{
  m_scope = this;
  clear();
  cout << "table has been reset." << endl;
}

Record*
Table::get_scope()
{
  return m_scope;
}
