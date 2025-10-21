#ifndef RUNTIME_H
#define RUNTIME_H
#include <vector>

#include "byte_code.h"
#include "engine.h"
namespace Runtime
{
void run(const std::vector<ByteCode*>& code, Engine& engine);
}

#endif  // !RUNTIME_H
