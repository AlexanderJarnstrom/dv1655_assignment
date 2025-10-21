#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>

#include "symbol_table.h"
#include "tac.h"

class Block
{
 public:
  int m_id;
  std::string m_name;
  std::vector<TAC*> m_tacs;

  Block* m_true_exit;
  Block* m_false_exit;

  Block(std::string);
  virtual ~Block();

  virtual void generate_code(std::ofstream*, SymbolTable*);
  void generate_tree_content(int&, std::ofstream*);
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
