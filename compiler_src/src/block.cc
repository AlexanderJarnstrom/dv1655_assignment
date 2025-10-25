#include "../inc/block.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "../inc/byte_code.h"

using namespace std;

/*
 * Block class
 * */

Block::Block(string name)
    : m_name(name),
      m_id(-1),
      m_true_exit(nullptr),
      m_false_exit(nullptr),
      m_weak_false_exit(),
      m_weak_true_exit()
{
}

Block::~Block()
{
  for (TAC* t : m_tacs) delete t;
}

void Block::generate_code(ofstream* out, SymbolTable* table)
{
  for (TAC* t : m_tacs) t->generate_code(out);

  shared_ptr<Block> false_exit = get_false_exit();
  shared_ptr<Block> true_exit = get_true_exit();

  if (true_exit) true_exit->generate_code(out, table);

  if (false_exit) false_exit->generate_code(out, table);
}

void Block::generate_tree_content(int& count, ofstream* outStream)
{
  m_id = count++;
  *outStream << "n" << m_id << " [label=\"" << m_name << " : "
             << this->m_tacs.size() << endl
             << endl;

  for (TAC* tac : this->m_tacs) tac->generate_tree_content(outStream);

  *outStream << "\" shape=box];" << endl;

  shared_ptr<Block> false_exit = get_false_exit();
  shared_ptr<Block> true_exit = get_true_exit();

  if (false_exit)
  {
    if (false_exit->m_id == -1)
      false_exit->generate_tree_content(count, outStream);
    *outStream << "n" << m_id << " -> n" << false_exit->m_id
               << " [ xlabel = \" false \" ]" << endl;
  }

  if (true_exit)
  {
    if (true_exit->m_id == -1)
      true_exit->generate_tree_content(count, outStream);
    *outStream << "n" << m_id << " -> n" << true_exit->m_id
               << " [ xlabel = \" true \" ] " << endl;
  }
}

std::shared_ptr<Block> Block::get_true_exit()
{
  if (m_weak_true_exit.use_count()) return m_weak_true_exit.lock();

  return m_true_exit;
}

std::shared_ptr<Block> Block::get_false_exit()
{
  if (m_weak_false_exit.use_count()) return m_weak_false_exit.lock();

  return m_false_exit;
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

  if (get_true_exit()) get_true_exit()->generate_code(out, table);

  *out << "stop\n";
}

void IfBlock::generate_code(std::ofstream* out, SymbolTable* table)
{
  for (TAC* t : m_tacs) t->generate_code(out);

  if (get_true_exit()) get_true_exit()->generate_code(out, table);

  if (get_false_exit())
  {
    get_false_exit()->generate_code(out, table);
    *out << get_false_exit()->m_name << ":\n";
  }
}

void IfElseBlock::generate_code(std::ofstream* out, SymbolTable* table)
{
  for (TAC* t : m_tacs) t->generate_code(out);

  if (get_true_exit()) get_true_exit()->generate_code(out, table);

  *out << get_false_exit()->m_name << ":\n";

  if (get_false_exit()) get_false_exit()->generate_code(out, table);
}

void WhileBlock::generate_code(std::ofstream* out, SymbolTable* table)
{
  if (get_true_exit() && !m_passed)
  {
    m_passed = true;

    *out << m_name << ":\n";

    for (TAC* t : m_tacs) t->generate_code(out);

    get_true_exit()->generate_code(out, table);
  }
  else
  {
    *out << get_false_exit()->m_name << ":\n";

    if (get_false_exit()) get_false_exit()->generate_code(out, table);
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

  if (get_true_exit()) get_true_exit()->generate_code(out, table);
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
    get_true_exit()->generate_code(out, table);
  }
}
