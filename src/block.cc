#include "../inc/block.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

TAC::TAC(int c, string l, string r, string o) :
  m_target("_t" + to_string(c)), m_left(l), m_right(r), m_operator(o)
{}

TAC::~TAC()
{}

void
TAC::generate_tree_content(ofstream* outStream)
{
  *outStream << this->m_target << " = " << this->m_left
    << " " << this->m_operator << " " << this->m_right << endl;
}

Block::Block(int n) :
  m_name("Block_" + to_string(n)), m_id(-1)
{}

Block::~Block()
{
  for (TAC* t : m_tacs)
    delete t;

  delete m_false_exit;
  delete m_true_exit;
}

void
Block::generate_tree_content(int &count, ofstream *outStream)
{
  m_id = count++;
  *outStream << "n" << m_id << " [label=\"" 
    << m_name << " : " << this->m_tacs.size() << endl << endl;

  for (TAC* tac : this->m_tacs)
    tac->generate_tree_content(outStream);

  *outStream << "\" shape=box];" << endl;

  if (m_false_exit)
  {
    if (m_false_exit->m_id == -1)
      m_false_exit->generate_tree_content(count, outStream);
    *outStream << "n" << m_id << " -> n" << m_false_exit->m_id << endl;
  }

  if (m_true_exit)
  {
    if (m_true_exit->m_id == -1)
      m_true_exit->generate_tree_content(count, outStream);
    *outStream << "n" << m_id << " -> n" << m_true_exit->m_id << endl;
  }
}

void
BlockHandler::generate_tree_content(int &count, ofstream *outStream)
{
  for (Block *c : m_blocks)
    c->generate_tree_content(count, outStream);
}

BlockHandler::BlockHandler(SymbolTable *t) :
  m_counter(0), m_tac_counter(0), m_table(t), m_in_statement(false)
{
  m_current = new Block(m_counter);
}

BlockHandler::~BlockHandler()
{
  for (Block *c : m_blocks)
    delete c;
}

Block*
BlockHandler::add_root()
{
  Block *temp;
  temp = new Block(m_counter);
  m_counter++;
  m_current = temp;
  m_blocks.push_back(temp);

  return temp;
}

Block*
BlockHandler::add_next()
{
  Block *temp;
  temp = new Block(m_counter);
  m_counter++;
  return temp;
}

void
BlockHandler::generate_tree()
{
  ofstream outStream;
  const char* filename = "blocks.dot";
  outStream.open(filename);

  int count = 0;
  outStream << "digraph {" << std::endl;
  generate_tree_content(count, &outStream);
  outStream << "}" << std::endl;
  outStream.close();
}
