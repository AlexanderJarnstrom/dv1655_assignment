#include "../../inc/node_execute.h"
#include <string>

using namespace std;

void
SyMainClass::generate_block (BlockHandler *bh)
{
  string scope;

  scope = (*this)[0]->value;
  bh->m_table->enter_scope (scope);
  bh->m_current = bh->add_root ("main");

  (*this)[2]->generate_block (bh);
  bh->m_table->exit_scope ();
}

void
SyClass::generate_block (BlockHandler *bh)
{
  string scope;

  scope = (*this)[0]->value;

  bh->m_table->enter_scope (scope);

  for (Node *c : this->children)
    c->generate_block (bh);

  bh->m_table->exit_scope ();
}

void
SyMethod::generate_block (BlockHandler *bh)
{
  Block *return_block;
  Node *body, *return_statement;
  ReturnTAC *tac;
  string target, method_name;

  method_name = (*(*this)[0])[1]->value;
  bh->m_current = bh->add_root (method_name);

  for (Node *c : children)
    c->generate_block (bh);

  return_block = bh->add_next ();
  bh->m_current->m_true_exit = return_block;
  bh->m_current = return_block;

  if (this->children.size () < 3)
    body = (*this)[1];
  else
    body = (*this)[2];

  if (body->children.size () < 2)
    return_statement = (*body)[0];
  else
    return_statement = (*body)[1];

  return_statement->generate_tacs (bh->m_current->m_tacs, target, bh);

  tac = new ReturnTAC (target);
  bh->m_current->m_tacs.push_back (tac);
}

void
SyAssign::generate_block (BlockHandler *bh)
{
  string target;
  // Block *temp = bh->add_next ();
  Block *temp = new AssignBlock ("Block_" + to_string (bh->m_counter++));
  bh->m_current->m_true_exit = temp;
  bh->m_current = temp;

  target = (*this)[0]->value;
  (*this)[1]->generate_tacs (bh->m_current->m_tacs, target, bh);

  if (bh->m_current->m_tacs.empty ())
    {
      bh->m_current->m_tacs.push_back (
          new CopyTAC ((*this)[0]->value, target));
    }
}

void
SyAssignArr::generate_block (BlockHandler *bh)
{
  string target;

  Block *temp = new AssignBlock ("Block_" + to_string (bh->m_counter++));
  bh->m_current->m_true_exit = temp;
  bh->m_current = temp;

  this->generate_tacs (bh->m_current->m_tacs, target, bh);
}

void
SyIf::generate_block (BlockHandler *bh)
{
  Block *s_block, *t_block, *j_block;
  string target;

  s_block = new IfBlock ("Block_" + to_string (bh->m_counter++));
  bh->m_current->m_true_exit = s_block;

  t_block = new Block ("");
  bh->m_current = t_block;
  (*this)[1]->generate_block (bh);
  s_block->m_true_exit = t_block->m_true_exit;

  j_block = new JoinBlock ("Block_" + to_string (bh->m_counter++));
  s_block->m_false_exit = j_block;
  bh->m_current->m_true_exit = j_block;
  bh->m_current = j_block;

  (*this)[0]->generate_tacs (s_block->m_tacs, target, bh);
  ConditionalTAC *tac = new ConditionalTAC (j_block->m_name, target);
  s_block->m_tacs.push_back (tac);
}

void
SyIfElse::generate_block (BlockHandler *bh)
{
  Block *s_block, *t_block, *f_block, *j_block;
  string target;

  s_block = new IfElseBlock ("Block_" + to_string (bh->m_counter++));
  bh->m_current->m_true_exit = s_block;

  t_block = new Block ("");
  bh->m_current = t_block;
  (*this)[1]->generate_block (bh);
  s_block->m_true_exit = t_block->m_true_exit;

  t_block = bh->m_current;

  f_block = new Block ("");
  bh->m_current = f_block;

  (*this)[2]->generate_block (bh);
  s_block->m_false_exit = f_block->m_true_exit;

  f_block = bh->m_current;

  j_block = new JoinBlock ("Block_" + to_string (bh->m_counter++));

  t_block->m_true_exit = bh->add_next ();
  t_block = t_block->m_true_exit;

  t_block->m_tacs.push_back (new UnconditionalTAC (j_block->m_name));

  t_block->m_true_exit = j_block;
  f_block->m_true_exit = j_block;
  bh->m_current = j_block;

  (*this)[0]->generate_tacs (s_block->m_tacs, target, bh);
  ConditionalTAC *tac
      = new ConditionalTAC (s_block->m_false_exit->m_name, target);
  s_block->m_tacs.push_back (tac);
}

void
SyWhile::generate_block (BlockHandler *bh)
{
  Block *s_block, *t_block, *j_block;
  string target;

  s_block = new WhileBlock ("Block_" + to_string (bh->m_counter++));
  bh->m_current->m_true_exit = s_block;

  t_block = new Block ("");
  bh->m_current = t_block;
  (*this)[1]->generate_block (bh);
  s_block->m_true_exit = t_block->m_true_exit;

  t_block = bh->m_current;

  j_block = bh->add_next ();

  t_block->m_true_exit = bh->add_next ();
  t_block = t_block->m_true_exit;

  t_block->m_tacs.push_back (new UnconditionalTAC (j_block->m_name));

  s_block->m_false_exit = j_block;
  t_block->m_true_exit = s_block;
  bh->m_current = j_block;

  (*this)[0]->generate_tacs (s_block->m_tacs, target, bh);
  ConditionalTAC *tac
      = new ConditionalTAC (s_block->m_false_exit->m_name, target);
  s_block->m_tacs.push_back (tac);
}

void
SyPrint::generate_block (BlockHandler *bh)
{
  string target;

  Block *temp = new PrintBlock ("Block_" + to_string (bh->m_counter++));
  bh->m_current->m_true_exit = temp;
  bh->m_current = temp;

  (*this).generate_tacs (bh->m_current->m_tacs, target, bh);
  bh->m_current->m_tacs.push_back (new ParameterTAC (target));
  bh->m_current->m_tacs.push_back (new PrintTAC ());
}

void
SyEmpty::generate_block (BlockHandler *bh)
{
  Block *temp = new Block ("Block_" + to_string (bh->m_counter++));
  bh->m_current->m_true_exit = temp;
  bh->m_current = temp;
}
