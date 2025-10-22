#ifndef BLOCK_H
#define BLOCK_H

#include <memory>
#include <string>
#include <vector>

#include "symbol_table.h"
#include "tac.h"

class Block
{
  std::shared_ptr<Block> m_true_exit;
  std::shared_ptr<Block> m_false_exit;
  std::weak_ptr<Block> m_weak_true_exit;
  std::weak_ptr<Block> m_weak_false_exit;

 public:
  int m_id;
  std::string m_name;
  std::vector<TAC*> m_tacs;

  Block(std::string);
  virtual ~Block();

  virtual void generate_code(std::ofstream*, SymbolTable*);
  void generate_tree_content(int&, std::ofstream*);

  std::shared_ptr<Block> get_true_exit();
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
