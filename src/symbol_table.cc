#include "../inc/symbol_table.h"
#include "../inc/symbol.h"
#include <iostream>
#include <sstream>

using namespace std;

SymbolTable::SymbolTable()
  : m_root(nullptr), m_scope(nullptr)
{}

SymbolTable::~SymbolTable()
{
  delete m_root;
}

void
SymbolTable::add_error(int l, std::string e)
{
  stringstream s;
  s << "@error at line " << l
    << ": " << e << endl;

  m_errors.push_back(sy_error {s.str(), l});
}

void 
SymbolTable::enter_scope(std::string id)
{
  Scope* n;
  Symbol* t;

  n = m_scope->get_scope(id);

  if (n) 
  {
    m_scope = n;
    return;
  }
 
  t = find_symbol(id);
  n = new Scope(t, m_scope);
  m_scope->m_scopes.push_back(n);
  m_scope = n;
}

void 
SymbolTable::exit_scope()
{
  if (!m_scope->m_parent)
    return;

  m_scope = m_scope->m_parent;

  // Symbol* t = m_scope->m_parent->find(m_scope->m_id);
  //
  // if (!t)
  //   throw runtime_error("Could not find scope.");
  //
  // if (t->m_record != Record::METHOD)
  // {
  //   m_scope = m_scope->m_parent;
  //   return;
  // }
  //
  // Scope* p = m_scope->m_parent;
  // m_scope->m_parent->remove_scope(t->m_id);
  // m_scope = p;
}

void
SymbolTable::add_symbol(Symbol* n)
{
  m_scope->add_symbol(n);
}

Symbol*
SymbolTable::find_symbol(std::string id)
{
  Symbol* n = nullptr;

  for (Symbol* c : m_scope->m_symbols)
  {
    if (c->m_id == id)
    {
      n = c;
      break;
    }
  }

  return n;
}

Symbol*
SymbolTable::check_scope(std::string id, Record r)
{
  Scope* c = m_scope->get_parrent_class();
  if (c)
  {
    return c->find(id, r);
  }

  return m_scope->find(id, r);
}

void
SymbolTable::remvove_symbol(std::string id)
{
  m_scope->remove_symbol(id); 
}

void
SymbolTable::reset()
{
  m_scope = m_root;
}

void
SymbolTable::print_root()
{
  if (m_root)
    m_root->print(0);
}

void
SymbolTable::print_scope()
{
  if (m_scope)
    m_scope->print(0);
}

void
SymbolTable::print_errors()
{
  vector<sy_error> sorted;

  for (sy_error err : m_errors)
  {
    if (sorted.empty())   
    {
      sorted.push_back(err);
      continue;
    }

    auto it = sorted.begin();
    for (; it != sorted.end(); it++) 
      if (it->line > err.line)
        break;

    if (it != sorted.end())
      sorted.insert(it, err);
    else
      sorted.push_back(err);
  }

  for (sy_error err : sorted)
    cerr << err.error;
}
