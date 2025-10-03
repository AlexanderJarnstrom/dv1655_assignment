#include "../inc/block.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Block::Block (int n) : m_name ("Block_" + to_string (n)), m_id (-1) {}

Block::~Block ()
{
  for (TAC *t : m_tacs)
    delete t;

  delete m_false_exit;
  delete m_true_exit;
}

void
Block::generate_tree_content (int &count, ofstream *outStream)
{
  m_id = count++;
  *outStream << "n" << m_id << " [label=\"" << m_name << " : " << this->m_tacs.size () << endl
             << endl;

  for (TAC *tac : this->m_tacs)
    tac->generate_tree_content (outStream);

  *outStream << "\" shape=box];" << endl;

  if (m_false_exit)
    {
      if (m_false_exit->m_id == -1)
        m_false_exit->generate_tree_content (count, outStream);
      *outStream << "n" << m_id << " -> n" << m_false_exit->m_id << endl;
    }

  if (m_true_exit)
    {
      if (m_true_exit->m_id == -1)
        m_true_exit->generate_tree_content (count, outStream);
      *outStream << "n" << m_id << " -> n" << m_true_exit->m_id << endl;
    }
}
