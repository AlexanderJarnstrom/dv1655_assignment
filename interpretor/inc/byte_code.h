#ifndef BYTE_CODE_H
#define BYTE_CODE_H

#include <cstdlib>
#include <string>
#include <vector>

#include "heap.h"
#include "stack.h"

class ByteCode
{
 public:
  enum Type
  {
    ILOAD,
    ISTORE,
    ICONST,
    IADD,
    ISUB,
    IMUL,
    ILT,
    IGT,
    IAND,
    IOR,
    IEQ,
    INOT,
    IGOTO,
    IFFALSE,
    INVOKEVIRTUAL,
    IRETURN,
    PRINT,
    STOP,
    NONE
  };

 private:
  Type m_type;

 public:
  ByteCode(std::string type);
  ByteCode(const ByteCode& other) : m_type(other.m_type) {}

  virtual ~ByteCode() {};

  ByteCode& operator=(const ByteCode& other);

  Type get_type() const { return m_type; }

  virtual void execute(Stack& stack, Heap& heap);
};

class ILoad : public ByteCode
{
  std::string m_target;

 public:
  ILoad(const ByteCode& base, std::string target)
      : ByteCode(base), m_target(target)
  {
  }
  ILoad(const ILoad& other) : m_target(other.m_target), ByteCode(other) {}
  ~ILoad() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IStore : public ByteCode
{
  std::string m_target;

 public:
  IStore(const ByteCode& base, std::string target)
      : ByteCode(base), m_target(target)
  {
  }
  IStore(const IStore& other) : m_target(other.m_target), ByteCode(other) {}
  ~IStore() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IConst : public ByteCode
{
  int m_value;

 public:
  IConst(const ByteCode& base, std::string value)
      : ByteCode(base), m_value(atoi(value.c_str()))
  {
  }
  IConst(const IConst& other) : m_value(other.m_value), ByteCode(other) {}
  ~IConst() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IAdd : public ByteCode
{
 public:
  IAdd(const ByteCode& base) : ByteCode(base) {}
  IAdd(const IAdd& other) : ByteCode(other) {}
  ~IAdd() {}

  void execute(Stack& stack, Heap& heap) override;
};

class ISub : public ByteCode
{
 public:
  ISub(const ByteCode& base) : ByteCode(base) {}
  ISub(const ISub& other) : ByteCode(other) {}
  ~ISub() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IMul : public ByteCode
{
 public:
  IMul(const ByteCode& base) : ByteCode(base) {}
  IMul(const IMul& other) : ByteCode(other) {}
  ~IMul() {}

  void execute(Stack& stack, Heap& heap) override;
};

class ILt : public ByteCode
{
 public:
  ILt(const ByteCode& base) : ByteCode(base) {}
  ILt(const ILt& other) : ByteCode(other) {}
  ~ILt() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IGt : public ByteCode
{
 public:
  IGt(const ByteCode& base) : ByteCode(base) {}
  IGt(const IGt& other) : ByteCode(other) {}
  ~IGt() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IAnd : public ByteCode
{
 public:
  IAnd(const ByteCode& base) : ByteCode(base) {}
  IAnd(const IAnd& other) : ByteCode(other) {}
  ~IAnd() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IOr : public ByteCode
{
 public:
  IOr(const ByteCode& base) : ByteCode(base) {}
  IOr(const IOr& other) : ByteCode(other) {}
  ~IOr() {}

  void execute(Stack& stack, Heap& heap) override;
};

class INot : public ByteCode
{
 public:
  INot(const ByteCode& base) : ByteCode(base) {}
  INot(const INot& other) : ByteCode(other) {}
  ~INot() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IEq : public ByteCode
{
 public:
  IEq(const ByteCode& base) : ByteCode(base) {}
  IEq(const IEq& other) : ByteCode(other) {}
  ~IEq() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IGoto : public ByteCode
{
  std::string m_target;

 public:
  IGoto(const ByteCode& base, std::string target)
      : ByteCode(base), m_target(target)
  {
  }
  IGoto(const IGoto& other) : m_target(other.m_target), ByteCode(other) {}
  ~IGoto() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IFFalse : public ByteCode
{
  std::string m_target;

 public:
  IFFalse(const ByteCode& base, std::string target)
      : ByteCode(base), m_target(target)
  {
  }
  IFFalse(const IFFalse& other) : m_target(other.m_target), ByteCode(other) {}
  ~IFFalse() {}

  void execute(Stack& stack, Heap& heap) override;
};

class InvokeVirtual : public ByteCode
{
  std::string m_target;

 public:
  InvokeVirtual(const ByteCode& base, std::string target)
      : ByteCode(base), m_target(target)
  {
  }
  InvokeVirtual(const InvokeVirtual& other)
      : m_target(other.m_target), ByteCode(other)
  {
  }
  ~InvokeVirtual() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IReturn : public ByteCode
{
 public:
  IReturn(const ByteCode& base) : ByteCode(base) {}
  IReturn(const IReturn& other) : ByteCode(other) {}
  ~IReturn() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IPrint : public ByteCode
{
 public:
  IPrint(const ByteCode& base) : ByteCode(base) {}
  IPrint(const IPrint& other) : ByteCode(other) {}
  ~IPrint() {}

  void execute(Stack& stack, Heap& heap) override;
};

class IStop : public ByteCode
{
 public:
  IStop(const ByteCode& base) : ByteCode(base) {}
  IStop(const IStop& other) : ByteCode(other) {}
  ~IStop() {}

  void execute(Stack& stack, Heap& heap) override;
};

namespace ByteCodeUtil
{
void create_byte_code(std::vector<std::string>& words,
                      std::vector<ByteCode*>& code);
void delete_byte_code(std::vector<ByteCode*>& code);
}  // namespace ByteCodeUtil

#endif  // !BYTE_CODE_H
