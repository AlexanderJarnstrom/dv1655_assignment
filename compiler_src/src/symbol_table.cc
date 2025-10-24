#include "../inc/symbol_table.h"

#include <iostream>

#include "../inc/symbol.h"

using namespace std;

SymbolTable::SymbolTable() : m_root(nullptr), m_scope(nullptr) {}

SymbolTable::~SymbolTable()
{
  delete m_root;
  for (sy_error* err : m_errors) delete err;
}

void SymbolTable::add_error(int l, std::string e)
{
  for (sy_error* err : m_errors)
  {
    if (err->line == l)
    {
      err->errors.push_back(e);
      return;
    }
  }

  sy_error* err = new sy_error;
  err->line = l;
  err->errors.push_back(e);
  m_errors.push_back(err);
}

void SymbolTable::enter_scope(std::string id)
{
  Scope* n;
  Symbol* t;

  n = m_scope->get_scope(id);

  if (n) m_scope = n;

  return;
}

void SymbolTable::exit_scope()
{
  if (!m_scope->m_parent) return;

  m_scope = m_scope->m_parent;
}

void SymbolTable::add_scope(Symbol* n)
{
  m_scope->add_scope(new Scope(n, m_scope));
}

void SymbolTable::add_symbol(Symbol* n) { m_scope->add_symbol(n); }

Symbol* SymbolTable::find_symbol(std::string id)
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

Symbol* SymbolTable::check_scope(std::string id, Record r)
{
  Scope* c = m_scope->get_parrent_class();
  if (c)
  {
    return c->find(id, r);
  }

  return m_scope->find(id, r);
}

void SymbolTable::remove_symbol(std::string id) { m_scope->remove_symbol(id); }

void SymbolTable::reset() { m_scope = m_root; }

void SymbolTable::print_root()
{
  if (m_root) m_root->print(0);
}

void SymbolTable::print_scope()
{
  if (m_scope) m_scope->print(0);
}

void SymbolTable::print_errors()
{
  vector<sy_error*> sorted;

  for (sy_error* err : m_errors)
  {
    if (sorted.empty())
    {
      sorted.push_back(err);
      continue;
    }

    auto it = sorted.begin();
    for (; it != sorted.end(); it++)
      if ((*it)->line > err->line) break;

    if (it != sorted.end())
      sorted.insert(it, err);
    else
      sorted.push_back(err);
  }

  for (sy_error* err : sorted)
  {
    cerr << "@error at line " << err->line << ": ";
    if (err->errors.size() == 1)
      cerr << err->errors[0] << endl;
    else
    {
      cerr << endl;
      for (string s_err : err->errors) cerr << "  " << s_err << endl;
    }
  }
}
