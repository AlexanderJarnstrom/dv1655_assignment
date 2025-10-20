#ifndef TAC_H
#define TAC_H

#include <fstream>
#include <string>

class TAC
{
public:
  TAC () {}
  virtual ~TAC () {}

  virtual void generate_tree_content (std::ofstream *) = 0;
  virtual void generate_code (std::ofstream *) = 0;
};

#endif // !TAC_H

#ifndef TAC_NODES_H
#define TAC_NODES_H

class ExpressionTAC : public TAC
{
  std::string m_target;
  std::string m_left;
  std::string m_right;
  std::string m_operator;

public:
  ExpressionTAC (std::string, std::string, std::string, std::string);
  ~ExpressionTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class UnaryExpressionTAC : public TAC
{
public:
  std::string m_target;
  std::string m_right;
  std::string m_operator;

  UnaryExpressionTAC (std::string, std::string, std::string);
  ~UnaryExpressionTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class CopyTAC : public TAC
{
public:
  std::string m_target;
  std::string m_right;

  CopyTAC (std::string, std::string);
  ~CopyTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class ArrayAccessTAC : public TAC
{
public:
  std::string m_target;
  std::string m_right;
  std::string m_index;
  bool m_pull;

  ArrayAccessTAC (std::string, std::string, std::string, bool);
  ~ArrayAccessTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class NewObjectTAC : public TAC
{
public:
  std::string m_target;
  std::string m_right;

  NewObjectTAC (std::string, std::string);
  ~NewObjectTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class ArrayNewTAC : public TAC
{
public:
  std::string m_target;
  std::string m_right;
  std::string m_size;

  ArrayNewTAC (std::string, std::string, std::string);
  ~ArrayNewTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class LengthTAC : public TAC
{
public:
  std::string m_target;
  std::string m_right;

  LengthTAC (std::string, std::string);
  ~LengthTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class ParameterTAC : public TAC
{
public:
  std::string m_target;

  ParameterTAC (std::string);
  ~ParameterTAC () {}
  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class MethodTAC : public TAC
{
public:
  std::string m_target;
  std::string m_right;
  unsigned int m_parameters;

  MethodTAC (std::string, std::string, unsigned int);
  ~MethodTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class ReturnTAC : public TAC
{
public:
  std::string m_target;

  ReturnTAC (std::string);
  ~ReturnTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class UnconditionalTAC : public TAC
{
public:
  std::string m_target;

  UnconditionalTAC (std::string);
  ~UnconditionalTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class ConditionalTAC : public TAC
{
public:
  std::string m_target;
  std::string m_right;

  ConditionalTAC (std::string, std::string);
  ~ConditionalTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

class PrintTAC : public TAC
{
public:
  PrintTAC ();
  ~PrintTAC () {}

  void generate_tree_content (std::ofstream *) override;
  void generate_code (std::ofstream *) override;
};

#endif // !TAC_NODES_H
