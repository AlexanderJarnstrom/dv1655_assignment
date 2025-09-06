#include "../../inc/node_execute.h"
#include <iostream>

using namespace std;

void
SyMethod::generate_block(BlockHandler *bh)
{
  bh->add_root();

  for (Node *c : children)
    c->generate_block(bh);
}

void
SyAssign::generate_block(BlockHandler* bh) 
{
  Block *temp = bh->add_next(); 
  bh->m_current->m_true_exit = temp;
  bh->m_current = temp;
}

void
SyAssignArr::generate_block(BlockHandler* bh) 
{
  Block *temp = bh->add_next(); 
  bh->m_current->m_true_exit = temp;
  bh->m_current = temp;
}

void
SyIf::generate_block(BlockHandler *bh) 
{
  Block *s_block, *t_block, *j_block;

  s_block = bh->add_next();

  bh->m_current->m_true_exit = s_block;

  t_block = new Block(-1);
  bh->m_current = t_block;
  (*this)[1]->generate_block(bh);
  s_block->m_true_exit = t_block->m_true_exit;

  j_block = bh->add_next();
  s_block->m_false_exit = j_block;
  bh->m_current->m_true_exit = j_block;
  bh->m_current = j_block;
}

void
SyIfElse::generate_block(BlockHandler *bh) 
{
  Block *s_block, *t_block, *f_block, *j_block;

  s_block = bh->add_next();
  bh->m_current->m_true_exit = s_block;

  t_block = new Block(-1);
  bh->m_current = t_block;
  (*this)[1]->generate_block(bh);
  s_block->m_true_exit = t_block->m_true_exit;

  t_block = bh->m_current;

  f_block = new Block(-1);
  bh->m_current = f_block;
  (*this)[2]->generate_block(bh);
  s_block->m_false_exit = f_block->m_true_exit;

  f_block = bh->m_current;

  j_block = bh->add_next();
  t_block->m_true_exit = j_block;
  f_block->m_true_exit = j_block;
  bh->m_current = j_block;
}

void
SyWhile::generate_block(BlockHandler *bh)
{
  Block *s_block, *t_block, *j_block;

  s_block = bh->add_next();

  bh->m_current->m_true_exit = s_block;

  t_block = new Block(-1);
  bh->m_current = t_block;
  (*this)[1]->generate_block(bh);
  s_block->m_true_exit = t_block->m_true_exit;

  t_block = bh->m_current;

  j_block = bh->add_next();
  s_block->m_false_exit = j_block;
  t_block->m_true_exit = s_block;
  bh->m_current = j_block;
}

void
SyPrint::generate_block(BlockHandler *bh)
{
  Block *temp = bh->add_next(); 
  bh->m_current->m_true_exit = temp;
  bh->m_current = temp;
}
