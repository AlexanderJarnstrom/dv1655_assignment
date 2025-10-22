#include "../inc/byte_code.h"

#include <iostream>
#include <map>
#include <string>
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

void ByteCode::execute(Engine& engine) { engine.increment_counter(); }

void ILoad::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();
  Heap& heap = engine.get_local_variables();
  int value = heap.load(m_target);
  stack.push(value);
  engine.increment_counter();
}

void IStore::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();
  Heap& heap = engine.get_local_variables();
  int value = stack.pop();
  heap.store(m_target, value);
  engine.increment_counter();
}

void IConst::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();
  stack.push(m_value);
  engine.increment_counter();
}

void IAdd::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();

  int b = stack.pop();
  int a = stack.pop();

  stack.push(a + b);
  engine.increment_counter();
}

void ISub::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();

  int b = stack.pop();
  int a = stack.pop();

  stack.push(a - b);
  engine.increment_counter();
}

void IMul::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();

  int b = stack.pop();
  int a = stack.pop();

  stack.push(a * b);
  engine.increment_counter();
}

void ILt::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();

  int b = stack.pop();
  int a = stack.pop();

  stack.push(a < b);
  engine.increment_counter();
}

void IGt::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();

  int b = stack.pop();
  int a = stack.pop();

  stack.push(a > b);
  engine.increment_counter();
}

void IAnd::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();

  int b = stack.pop();
  int a = stack.pop();

  stack.push(a && b);
  engine.increment_counter();
}

void IOr::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();

  int b = stack.pop();
  int a = stack.pop();

  stack.push(a || b);
  engine.increment_counter();
}

void INot::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();

  int a = stack.pop();

  stack.push(!a);
  engine.increment_counter();
}

void IEq::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();

  int b = stack.pop();
  int a = stack.pop();

  stack.push(a == b);
  engine.increment_counter();
}

void IGoto::execute(Engine& engine) { engine.jump(m_target); }

void IFFalse::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();
  int value = stack.pop();

  if (value)
    engine.increment_counter();
  else
    engine.jump(m_target);
}

void InvokeVirtual::execute(Engine& engine)
{
  engine.push_activation(m_target);
}

void IReturn::execute(Engine& engine) { engine.pop_activation(); }

void IPrint::execute(Engine& engine)
{
  Stack& stack = engine.get_stack();

  int a = stack.pop();
  std::cout << a << std::endl;
  engine.increment_counter();
}

void IStop::execute(Engine& engine) {}

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
      code.push_back(new ByteCode(base));
      break;
  }
}

void ByteCodeUtil::delete_byte_code(std::vector<ByteCode*>& code)
{
  for (ByteCode* b : code) delete b;
  code.clear();
}
