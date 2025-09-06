#ifndef BLOCK
#define BLOCK

#include "symbol_table.h"
#include <string>
#include <vector>

class TAC
{
public:
  std::string m_target;
  std::string m_left;
  std::string m_right;
  std::string m_operator;

  TAC(std::string, std::string, std::string, std::string);
  ~TAC();

  void dump();
};

class Block
{
public:
  int m_id;
  std::string m_name;
  std::vector<TAC*> m_tacs;

  Block* m_true_exit;
  Block* m_false_exit;

  Block(int);
  ~Block();

  void dump(int step = 0);
  void generate_tree_content(int&, std::ofstream*);
};

class BlockHandler
{
  void generate_tree_content(int&, std::ofstream*);

public:
  int m_counter;

  bool m_in_statement;

  Block *m_current;
  SymbolTable *m_table;

  std::vector<Block*> m_blocks;
  std::vector<Block*> m_endless;

  BlockHandler(SymbolTable *);
  ~BlockHandler();

  Block* add_root();
  Block* add_next();

  void generate_tree();
};

#endif // !BLOCK
