#ifndef BLOCK_HANDLER_H
#define BLOCK_HANDLER_H

#include "block.h"

class BlockHandler
{
  void generate_tree_content (int &, std::ofstream *);

public:
  int m_counter;
  int m_tac_counter;

  bool m_in_statement;

  Block *m_current;
  SymbolTable *m_table;

  std::vector<Block *> m_blocks;
  std::vector<Block *> m_endless;

  BlockHandler (SymbolTable *);
  ~BlockHandler ();

  Block *add_root (std::string);
  Block *get_block (std::string, std::string);
  Block *add_next ();

  void generate_code (std::ofstream *);

  void generate_tree ();
};

#endif // !BLOCK_HANDLER_H
