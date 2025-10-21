#include "../inc/byte_code.h"

#include <iostream>
#include <vector>

ByteCode::ByteCode(std::string type)
{
  if (type == "iload")
    m_type = Type::ILOAD;
  else if (type == "istore")
    m_type = Type::ISTORE;
  else if (type == "iconst")
    m_type = Type::ICONST;
  else if (type == "iadd")
    m_type = Type::IADD;
  else if (type == "isub")
    m_type = Type::ISUB;
  else if (type == "imul")
    m_type = Type::IMUL;
  else if (type == "ilt")
    m_type = Type::ILT;
  else if (type == "igt")
    m_type = Type::IGT;
  else if (type == "iand")
    m_type = Type::IAND;
  else if (type == "ior")
    m_type = Type::IOR;
  else if (type == "inot")
    m_type = Type::INOT;
  else if (type == "ieq")
    m_type = Type::IEQ;
  else if (type == "goto")
    m_type = Type::IGOTO;
  else if (type == "iffalse")
    m_type = Type::IFFALSE;
  else if (type == "invokevirtual")
    m_type = Type::INVOKEVIRTUAL;
  else if (type == "ireturn")
    m_type = Type::IRETURN;
  else if (type == "print")
    m_type = Type::PRINT;
  else if (type == "stop")
    m_type = Type::STOP;
  else
    m_type = Type::NONE;
}

ByteCode& ByteCode::operator=(const ByteCode& other)
{
  if (this == &other) return *this;

  this->m_type = other.m_type;

  return *this;
}

void ByteCode::execute(Stack& stack, Heap& heap) {}

void ILoad::execute(Stack& stack, Heap& heap)
{
  int value = heap.load(m_target);
  stack.push(value);
}

void IStore::execute(Stack& stack, Heap& heap)
{
  int value = stack.pop();
  heap.store(m_target, value);
}

void IConst::execute(Stack& stack, Heap& heap) { stack.push(m_value); }

void IAdd::execute(Stack& stack, Heap& heap)
{
  int b = stack.pop();
  int a = stack.pop();

  stack.push(a + b);
}

void ISub::execute(Stack& stack, Heap& heap)
{
  int b = stack.pop();
  int a = stack.pop();

  stack.push(a - b);
}

void IMul::execute(Stack& stack, Heap& heap)
{
  int b = stack.pop();
  int a = stack.pop();

  stack.push(a * b);
}

void ILt::execute(Stack& stack, Heap& heap)
{
  int b = stack.pop();
  int a = stack.pop();

  stack.push(a < b);
}

void IGt::execute(Stack& stack, Heap& heap)
{
  int b = stack.pop();
  int a = stack.pop();

  stack.push(a > b);
}

void IAnd::execute(Stack& stack, Heap& heap)
{
  int b = stack.pop();
  int a = stack.pop();

  stack.push(a && b);
}

void IOr::execute(Stack& stack, Heap& heap)
{
  int b = stack.pop();
  int a = stack.pop();

  stack.push(a || b);
}

void INot::execute(Stack& stack, Heap& heap)
{
  int a = stack.pop();

  stack.push(!a);
}

void IEq::execute(Stack& stack, Heap& heap)
{
  int b = stack.pop();
  int a = stack.pop();

  stack.push(a == b);
}

void IGoto::execute(Stack& stack, Heap& heap) {}

void IFFalse::execute(Stack& stack, Heap& heap) {}

void InvokeVirtual::execute(Stack& stack, Heap& heap) {}

void IReturn::execute(Stack& stack, Heap& heap) {}

void IPrint::execute(Stack& stack, Heap& heap)
{
  int a = stack.pop();
  std::cout << a << std::endl;
}

void IStop::execute(Stack& stack, Heap& heap) {}

void ByteCodeUtil::create_byte_code(std::vector<std::string>& words,
                                    std::vector<ByteCode*>& code)
{
  ByteCode base(words[0]);

  switch (base.get_type())
  {
    case ByteCode::ILOAD:
      code.push_back(new ILoad(base, words[1]));
      break;
    case ByteCode::ISTORE:
      code.push_back(new IStore(base, words[1]));
      break;
    case ByteCode::ICONST:
      code.push_back(new IConst(base, words[1]));
      break;
    case ByteCode::IADD:
      code.push_back(new IAdd(base));
      break;
    case ByteCode::ISUB:
      code.push_back(new ISub(base));
      break;
    case ByteCode::IMUL:
      code.push_back(new IMul(base));
      break;
    case ByteCode::ILT:
      code.push_back(new ILt(base));
      break;
    case ByteCode::IGT:
      code.push_back(new IGt(base));
      break;
    case ByteCode::IAND:
      code.push_back(new IAnd(base));
      break;
    case ByteCode::IOR:
      code.push_back(new IOr(base));
      break;
    case ByteCode::IEQ:
      code.push_back(new IEq(base));
      break;
    case ByteCode::INOT:
      code.push_back(new INot(base));
      break;
    case ByteCode::IGOTO:
      code.push_back(new IGoto(base, words[1]));
      break;
    case ByteCode::IFFALSE:
      code.push_back(new IFFalse(base, words[1]));
      break;
    case ByteCode::INVOKEVIRTUAL:
      code.push_back(new InvokeVirtual(base, words[1]));
      break;
    case ByteCode::IRETURN:
      code.push_back(new IReturn(base));
      break;
    case ByteCode::PRINT:
      code.push_back(new IPrint(base));
      break;
    case ByteCode::STOP:
      code.push_back(new IStop(base));
      break;
    case ByteCode::NONE:
      break;
  }
}

void ByteCodeUtil::delete_byte_code(std::vector<ByteCode*>& code)
{
  for (ByteCode* b : code) delete b;
  code.clear();
}
