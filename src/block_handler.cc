#include "../inc/block_handler.h"

using namespace std;

void
BlockHandler::generate_tree_content (int &count, ofstream *outStream)
{
  for (Block *c : m_blocks)
    c->generate_tree_content (count, outStream);
}

BlockHandler::BlockHandler (SymbolTable *t)
    : m_counter (0), m_tac_counter (0), m_table (t), m_in_statement (false)
{
  m_current = new Block (m_counter);
}

BlockHandler::~BlockHandler ()
{
  for (Block *c : m_blocks)
    delete c;
}

Block *
BlockHandler::add_root ()
{
  Block *temp;
  temp = new Block (m_counter);
  m_counter++;
  m_current = temp;
  m_blocks.push_back (temp);

  return temp;
}

Block *
BlockHandler::add_next ()
{
  Block *temp;
  temp = new Block (m_counter);
  m_counter++;
  return temp;
}

void
BlockHandler::generate_tree ()
{
  ofstream outStream;
  const char *filename = "blocks.dot";
  outStream.open (filename);

  int count = 0;
  outStream << "digraph {" << std::endl;
  generate_tree_content (count, &outStream);
  outStream << "}" << std::endl;
  outStream.close ();
}
