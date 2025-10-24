#ifndef RUNTIME_H
#define RUNTIME_H
#include <vector>

#include "byte_code.h"
#include "engine.h"
namespace Runtime
{
/**
 * @brief Execute byte code.
 *
 * @param code vector with ByteCode.
 * @param engine memory Engine.
 */
void run(const std::vector<ByteCode*>& code, Engine& engine);
}  // namespace Runtime

#endif  // !RUNTIME_H
