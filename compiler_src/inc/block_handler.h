#ifndef BLOCK_HANDLER_H
#define BLOCK_HANDLER_H

#include "block.h"

class BlockHandler
{
  void generate_tree_content(int&, std::ofstream*);

 public:
  int m_counter;
  int m_tac_counter;

  bool m_in_statement;

  std::shared_ptr<Block> m_current;
  SymbolTable* m_table;

  std::vector<std::shared_ptr<Block>> m_blocks;
  std::vector<std::shared_ptr<Block>> m_endless;

  BlockHandler(SymbolTable*);
  ~BlockHandler();

  /**
   * @brief Creates a root block.
   *
   * Create a root for a new IR tree.
   *
   * @param name Name of the block.
   */
  std::shared_ptr<Block> add_root(std::string name);
  /**
   * @brief Gets a block in the given scope.
   *
   * @param scope Scope name.
   * @param name Symbol name.
   */
  std::shared_ptr<Block> get_block(std::string scope, std::string name);
  /**
   * @brief Simple create.
   */
  std::shared_ptr<Block> add_next();

  /**
   * @brief Write byte code to file.
   *
   * @param out file stream.
   */
  void generate_code(std::ofstream* out);

  /**
   * @brief Generate dot file.
   */
  void generate_tree();
};

#endif  // !BLOCK_HANDLER_H
