#ifndef NODE_EXECUTE
#define NODE_EXECUTE

#include <iostream>
#include "block.h"
#include "node.h"
#include "symbol_table.h"

class SyRoot : public Node
{
  public:
    SyRoot(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyRoot() : Node() {}
    ~SyRoot() {}

    void pre_execute(SymbolTable*) override;
};

class SyMainClass : public Node
{
  public:
    SyMainClass(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyMainClass() : Node() {}
    ~SyMainClass() {}

    void pre_execute(SymbolTable*) override;
};


class SyClass : public Node
{
  public:
    SyClass(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyClass() : Node() {}
    ~SyClass() {}

    void pre_execute(SymbolTable*) override;
};

class SyMethod : public Node
{
  public:
    SyMethod(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyMethod() : Node() {}
    ~SyMethod() {}

    void pre_execute(SymbolTable*) override;
    void post_execute(SymbolTable*) override;
    void generate_block(BlockHandler*) override;
};

class SyVariable : public Node
{
  public:
    SyVariable(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyVariable() : Node() {}
    ~SyVariable() {}

    void pre_execute(SymbolTable*) override;
    void post_execute(SymbolTable*) override;
};

class SyAssign : public Node
{
  public:
    SyAssign(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyAssign() : Node() {}
    ~SyAssign() {}

    void in_execute(SymbolTable*) override;
    void post_execute(SymbolTable*) override;
    void generate_block(BlockHandler *) override;
};

class SyAttribute : public Node
{
  public:
    SyAttribute(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyAttribute() : Node() {}
    ~SyAttribute() {}


    void post_execute(SymbolTable*) override;
    std::string get_type(SymbolTable*) override;
};

class SyAssignArr : public Node
{
  public:
    SyAssignArr(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyAssignArr() : Node() {}
    ~SyAssignArr() {}

  void post_execute(SymbolTable*) override;
    void generate_block(BlockHandler *) override;
};

class SyOperator : public Node
{
  public:
    SyOperator(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyOperator() : Node() {}
    ~SyOperator() {}

    void post_execute(SymbolTable*) override;
    std::string get_type(SymbolTable*) override;
};

class SyLength : public Node
{
  public:
    SyLength(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyLength() : Node() {}
    ~SyLength() {}

    void post_execute(SymbolTable*) override;
    std::string get_type(SymbolTable*) override;
};

class SyArrayPull : public Node
{
  public:
    SyArrayPull(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyArrayPull() : Node() {}
    ~SyArrayPull() {}

    void post_execute(SymbolTable*) override;
    std::string get_type(SymbolTable*) override;
};

class SyParenthesis : public Node
{
  public:
    SyParenthesis(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyParenthesis() : Node() {}
    ~SyParenthesis() {}

    std::string get_type(SymbolTable*) override;
};

class SyNumber : public Node
{
  public:
    SyNumber(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyNumber() : Node() {}
    ~SyNumber() {}

    std::string get_type(SymbolTable*) override;
};

class SyBoolean : public Node
{
  public:
    SyBoolean(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyBoolean() : Node() {}
    ~SyBoolean() {}

    std::string get_type(SymbolTable*) override;
};

class SyIdentifier : public Node
{
  public:
    SyIdentifier(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyIdentifier() : Node() {}
    ~SyIdentifier() {}

    std::string get_type(SymbolTable*) override;
};

class SyThis : public Node
{
  public:
    SyThis(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyThis() : Node() {}
    ~SyThis() {}

    std::string get_type(SymbolTable*) override;
};

class SyArrayInit : public Node
{
  public:
    SyArrayInit(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyArrayInit() : Node() {}
    ~SyArrayInit() {}

    void post_execute(SymbolTable*) override;
    std::string get_type(SymbolTable*) override;
};

class SyObjectInit : public Node
{
  public:
    SyObjectInit(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyObjectInit() : Node() {}
    ~SyObjectInit() {}

    std::string get_type(SymbolTable*) override;
};

class SyNot : public Node
{
  public:
    SyNot(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyNot() : Node() {}
    ~SyNot() {}

    void post_execute(SymbolTable*) override;
    std::string get_type(SymbolTable*) override;
};

class SyExpressionList : public Node
{
  public:
    SyExpressionList(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyExpressionList() : Node() {}
    ~SyExpressionList() {}

    std::string get_type(SymbolTable*) override;
};

class SyIf : public Node 
{
  public:
    SyIf(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyIf() : Node() {}
    ~SyIf() {}

    void generate_block(BlockHandler *) override;
};

class SyIfElse : public Node 
{
  public:
    SyIfElse(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyIfElse() : Node() {}
    ~SyIfElse() {}

    void generate_block(BlockHandler *) override;
};

class SyWhile : public Node 
{
  public:
    SyWhile(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyWhile() : Node() {}
    ~SyWhile() {}

    void generate_block(BlockHandler *) override;
};

class SyPrint : public Node 
{
  public:
    SyPrint(std::string t, std::string v, int l) : Node(t, v, l) {}
    SyPrint() : Node() {}
    ~SyPrint() {}

    void generate_block(BlockHandler *) override;
};

#endif // !NODE_EXECUTE
