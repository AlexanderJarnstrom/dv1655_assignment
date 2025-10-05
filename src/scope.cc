#include "../inc/scope.h"
#include <iostream>

using namespace std;

Scope::Scope (Symbol *s, Scope *p) : m_parent (p), m_id (s->m_id)
{
  if (s->m_record != Record::CLASS)
    return;

  Symbol *t = new Symbol ("this", s->m_type, s->m_record);
  m_symbols.push_back (t);
}

Scope::~Scope ()
{
  for (Scope *c : m_scopes)
    delete c;

  for (Symbol *c : m_symbols)
    delete c;
}

Symbol *
Scope::find (string id, Record r)
{
  Symbol *t = nullptr;

  for (Symbol *c : m_symbols)
    {
      if (c->m_id == id && r == Record::ROOT)
        {
          t = c;
          break;
        }
      else if (c->m_id == id && c->m_record == r)
        {
          t = c;
          break;
        }
      else if (c->m_id == id && r == Record::VARIABLE && c->m_record == Record::ARGUMENT)
        {
          t = c;
          break;
        }
    }

  if (t)
    return t;

  for (Scope *c : m_scopes)
    {
      t = c->find (id, r);
      if (t)
        break;
    }

  return t;
}

vector<Symbol *>
Scope::find_all (Record r)
{
  vector<Symbol *> children;

  for (Symbol *c : m_symbols)
    if (c->m_record == r)
      children.push_back (c);

  return children;
}

Scope *
Scope::get_scope (std::string id)
{
  for (auto it = m_scopes.rbegin (); it != m_scopes.rend (); it++)
    {
      if ((*it)->m_id == id)
        return (*it);
    }

  return nullptr;
}

Scope *
Scope::get_parrent_class ()
{
  Symbol *t = nullptr;

  for (Symbol *c : m_symbols)
    {
      if (c->m_id == "this")
        {
          t = c;
          break;
        }
    }

  if (t)
    {
      return m_parent->get_scope (t->m_type);
    }

  if (m_parent)
    return m_parent->get_parrent_class ();

  return nullptr;
}

void
Scope::remove_symbol (string id)
{
  auto it = m_symbols.begin ();
  for (; it < m_symbols.end (); it++)
    {
      if ((*it)->m_id == id)
        {
          break;
        }
    }

  Symbol *t = (*it);

  if (t->m_id == id)
    {
      m_symbols.erase (it);
      delete t;
    }
}

void
Scope::add_symbol (Symbol *n)
{
  m_symbols.push_back (n);
}

void
Scope::remove_scope (std::string id)
{
  auto it = m_scopes.begin ();
  for (; it < m_scopes.end (); it++)
    {
      if ((*it)->m_id == id)
        {
          break;
        }
    }

  Scope *t = (*it);

  if (t->m_id == id)
    {
      m_scopes.erase (it);
      delete t;
    }
}

void
Scope::add_scope (Scope *s)
{
  m_scopes.push_back (s);
}

void
Scope::print (int l)
{
  for (int i = 0; i < l; i++)
    cout << "  ";

  cout << "\e[1m" << m_id << ":\033[0m" << endl;
  for (Symbol *c : m_symbols)
    {
      for (int i = 0; i < l + 1; i++)
        cout << "  ";

      cout << "- \033[36m" << c->m_id << "\033[0m ["
           << "r: " << c->m_record << " t: " << c->m_type;

      if (!c->m_block.empty ())
        cout << " b: " << c->m_block;

      cout << "]" << endl;
    }

  cout << endl;

  for (Scope *c : m_scopes)
    {
      c->print (l + 1);
    }
}
