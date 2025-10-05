#ifndef BLOCK_H
#define BLOCK_H

#include "symbol_table.h"
#include "tac.h"
#include <string>
#include <vector>

class Block
{
public:
  int m_id;
  std::string m_name;
  std::vector<TAC *> m_tacs;

  Block *m_true_exit;
  Block *m_false_exit;

  Block (std::string);
  ~Block ();

  void generate_tree_content (int &, std::ofstream *);
};
#endif // !BLOCK_H
