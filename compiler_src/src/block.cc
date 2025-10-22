#include "../inc/block.h"

#include <fstream>
#include <iostream>
#include <string>

#include "../inc/byte_code.h"

using namespace std;

/*
 * Block class
 * */

Block::Block(string name)
    : m_name(name), m_id(-1), m_true_exit(nullptr), m_false_exit(nullptr)
{
}

Block::~Block()
{
  for (TAC* t : m_tacs) delete t;

  delete m_false_exit;
  delete m_true_exit;
}

void Block::generate_code(ofstream* out, SymbolTable* table)
{
  for (TAC* t : m_tacs) t->generate_code(out);

  if (m_true_exit) m_true_exit->generate_code(out, table);

  if (m_false_exit) m_false_exit->generate_code(out, table);
}

void Block::generate_tree_content(int& count, ofstream* outStream)
{
  m_id = count++;
  *outStream << "n" << m_id << " [label=\"" << m_name << " : "
             << this->m_tacs.size() << endl
             << endl;

  for (TAC* tac : this->m_tacs) tac->generate_tree_content(outStream);

  *outStream << "\" shape=box];" << endl;

  if (m_false_exit)
  {
    if (m_false_exit->m_id == -1)
      m_false_exit->generate_tree_content(count, outStream);
    *outStream << "n" << m_id << " -> n" << m_false_exit->m_id
               << " [ xlabel = \" false \" ]" << endl;
  }

  if (m_true_exit)
  {
    if (m_true_exit->m_id == -1)
      m_true_exit->generate_tree_content(count, outStream);
    *outStream << "n" << m_id << " -> n" << m_true_exit->m_id
               << " [ xlabel = \" true \" ] " << endl;
  }
}

/*
 * Block nodes
 * */

/*
void
AssignBlock::generate_code (std::ofstream *)
{
}
*/

void MainBlock::generate_code(std::ofstream* out, SymbolTable* table)
{
  Scope* scope;
  Symbol* method = nullptr;

  for (Scope* c : table->m_root->m_scopes)
  {
    for (Symbol* s : c->m_symbols)
    {
      if (s->m_block == m_name)
      {
        method = s;
        break;
      }
    }

    if (method)
    {
      scope = c->get_scope(method->m_id);
      break;
    }
  }

  for (int i = method->m_args - 1; i >= 0; i--)
  {
    string name = scope->m_symbols[i]->m_id;
    ByteCode::istore(name, out);
  }

  if (m_true_exit) m_true_exit->generate_code(out, table);

  *out << "stop\n";
}

void IfBlock::generate_code(std::ofstream* out, SymbolTable* table)
{
  for (TAC* t : m_tacs) t->generate_code(out);

  if (m_true_exit) m_true_exit->generate_code(out, table);

  *out << m_false_exit->m_name << ":\n";

  if (m_false_exit) m_false_exit->generate_code(out, table);
}

void IfElseBlock::generate_code(std::ofstream* out, SymbolTable* table)
{
  for (TAC* t : m_tacs) t->generate_code(out);

  if (m_true_exit) m_true_exit->generate_code(out, table);

  *out << m_false_exit->m_name << ":\n";

  if (m_false_exit) m_false_exit->generate_code(out, table);
}

void WhileBlock::generate_code(std::ofstream* out, SymbolTable* table)
{
  cout << "Doing " << m_name << endl;

  if (m_true_exit && !m_passed)
  {
    m_passed = true;

    *out << m_name << ":\n";

    for (TAC* t : m_tacs) t->generate_code(out);

    m_true_exit->generate_code(out, table);
  }
  else
  {
    *out << m_false_exit->m_name << ":\n";

    if (m_false_exit) m_false_exit->generate_code(out, table);
  }
}

void MethodBlock::generate_code(std::ofstream* out, SymbolTable* table)
{
  Scope* scope;
  Symbol* method = nullptr;

  for (Scope* c : table->m_root->m_scopes)
  {
    for (Symbol* s : c->m_symbols)
    {
      if (s->m_block == m_name)
      {
        method = s;
        break;
      }
    }

    if (method)
    {
      scope = c->get_scope(method->m_id);
      break;
    }
  }

  for (int i = method->m_args - 1; i >= 0; i--)
  {
    string name = scope->m_symbols[i]->m_id;
    ByteCode::istore(name, out);
  }

  if (m_true_exit) m_true_exit->generate_code(out, table);
}

/*
void
PrintBlock::generate_code (std::ofstream *)
{
}
*/

void JoinBlock::generate_code(std::ofstream* out, SymbolTable* table)
{
  m_counter++;

  if (m_counter == 2)
  {
    *out << m_name << ":" << endl;
    m_true_exit->generate_code(out, table);
  }
}
