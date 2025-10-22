#include "../inc/runtime.h"

#include <iostream>

void Runtime::run(const std::vector<ByteCode*>& code, Engine& engine)
{
  ByteCode* current = code[engine.get_program_counter()];

  while (current->get_type() != ByteCode::STOP)
  {
    current->execute(engine);
    current = code[engine.get_program_counter()];
  }
}
