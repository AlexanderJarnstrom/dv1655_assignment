#include "../inc/block_handler.h"

#include <string>

using namespace std;

void BlockHandler::generate_tree_content(int& count, ofstream* outStream)
{
  for (Block* c : m_blocks) c->generate_tree_content(count, outStream);
}

BlockHandler::BlockHandler(SymbolTable* t)
    : m_counter(0), m_tac_counter(0), m_table(t), m_in_statement(false)
{
  m_current = add_next();
}

BlockHandler::~BlockHandler()
{
  for (Block* c : m_blocks) delete c;
}

Block* BlockHandler::add_root(string name)
{
  Symbol* method_obj;
  Block* temp;

  method_obj = m_table->m_scope->find(name, Record::METHOD);
  if (method_obj->m_block.empty())
    method_obj->m_block = "Block_" + to_string(m_counter);

  if (name == "main")
    temp = new MainBlock(method_obj->m_block);
  else
    temp = new MethodBlock(method_obj->m_block);
  m_counter++;
  m_blocks.push_back(temp);

  return temp;
}

Block* BlockHandler::get_block(string scope, string name)
{
  Block* temp;
  Scope* m_scope;
  Symbol* m_symbol;

  m_scope = m_table->m_root->get_scope(scope);
  m_symbol = m_scope->find(name, Record::METHOD);

  temp = nullptr;

  for (Block* c : m_blocks)
    if (c->m_name == m_symbol->m_block)
    {
      temp = c;
      break;
    }

  return temp;
}

Block* BlockHandler::add_next()
{
  Block* temp;
  temp = new Block("Block_" + to_string(m_counter));
  m_counter++;
  return temp;
}

void BlockHandler::generate_code(ofstream* out)
{
  for (Block* c : m_blocks)
  {
    *out << c->m_name << ":" << endl;
    c->generate_code(out, m_table);
    *out << endl;
  }
}

void BlockHandler::generate_tree()
{
  ofstream outStream;
  const char* filename = "blocks.dot";
  outStream.open(filename);

  int count = 0;
  outStream << "digraph {" << endl;
  outStream << "graph [ splines = ortho ]" << endl;
  outStream << "node [ shape = box ];" << endl;
  generate_tree_content(count, &outStream);
  outStream << "}" << endl;
  outStream.close();
}
