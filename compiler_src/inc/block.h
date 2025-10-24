/**
 * @file
 * @brief Contains Block class and all the sub classes.
 */

#ifndef BLOCK_H
#define BLOCK_H

#include <memory>
#include <string>
#include <vector>

#include "symbol_table.h"
#include "tac.h"

/**
 * @class Block
 * @brief Parent class for the Blocks
 */
class Block
{
  std::shared_ptr<Block> m_true_exit;
  std::shared_ptr<Block> m_false_exit;

  // Mainly for the while block, which points back at itself creating a loop.
  std::weak_ptr<Block> m_weak_true_exit;
  std::weak_ptr<Block> m_weak_false_exit;

 public:
  int m_id;
  std::string m_name;
  std::vector<TAC*> m_tacs;

  Block(std::string);
  virtual ~Block();

  /**
   * @brief Write code to  file.
   *
   * @param out file stream.
   * @param table symbol table.
   */
  virtual void generate_code(std::ofstream* out, SymbolTable* table);
  /**
   * @brief Write to dot file.
   *
   * @param id id counter for the arrows.
   * @param out file stream.
   */
  void generate_tree_content(int& id, std::ofstream* out);

  /**
   * @brief Get the true path.
   *
   * If a weak_ptr is defined a refrence to it as a shared_ptr will be returned.
   *
   * @return shared_ptr<Block> the pointer to the true block.
   */
  std::shared_ptr<Block> get_true_exit();
  /**
   * @brief Get the false path.
   *
   * If a weak_ptr is defined a refrence to it as a shared_ptr will be returned.
   *
   * @return shared_ptr<Block> the pointer to the false block.
   */
  std::shared_ptr<Block> get_false_exit();

  void set_true_exit(std::shared_ptr<Block> e) { m_true_exit = e; }
  void set_false_exit(std::shared_ptr<Block> e) { m_false_exit = e; }
  void set_weak_true_exit(std::weak_ptr<Block> e) { m_weak_true_exit = e; }
  void set_weak_false_exit(std::weak_ptr<Block> e) { m_weak_false_exit = e; }
};

class AssignBlock : public Block
{
 public:
  AssignBlock(std::string name) : Block(name) {}
  ~AssignBlock() override {};

  // void generate_code (std::ofstream *, SymbolTable *) override;
};

class MainBlock : public Block
{
 public:
  MainBlock(std::string name) : Block(name) {}
  ~MainBlock() override {};

  void generate_code(std::ofstream*, SymbolTable*) override;
};

class IfBlock : public Block
{
 public:
  IfBlock(std::string name) : Block(name) {}
  ~IfBlock() override {};

  void generate_code(std::ofstream*, SymbolTable*) override;
};

class IfElseBlock : public Block
{
 public:
  IfElseBlock(std::string name) : Block(name) {}
  ~IfElseBlock() override {};

  void generate_code(std::ofstream*, SymbolTable*) override;
};

class WhileBlock : public Block
{
  bool m_passed;

 public:
  WhileBlock(std::string name) : Block(name), m_passed(false) {}
  ~WhileBlock() override {};

  void generate_code(std::ofstream*, SymbolTable*) override;
};

class MethodBlock : public Block
{
 public:
  MethodBlock(std::string name) : Block(name) {}
  ~MethodBlock() override {};

  void generate_code(std::ofstream*, SymbolTable*) override;
};

class PrintBlock : public Block
{
 public:
  PrintBlock(std::string name) : Block(name) {}
  ~PrintBlock() override {};

  // void generate_code (std::ofstream *, SymbolTable *) override;
};

class JoinBlock : public Block
{
  int m_counter;

 public:
  JoinBlock(std::string name) : Block(name), m_counter(0) {}
  ~JoinBlock() override {};

  void generate_code(std::ofstream*, SymbolTable*) override;
};
#endif  // !BLOCK_H
