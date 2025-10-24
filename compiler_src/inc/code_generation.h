#ifndef CODE_GENERATION_H
#define CODE_GENERATION_H

#include <string>

#include "block_handler.h"

namespace CodeGeneration
{
/**
 * @brief generate and write the bytecode.
 *
 * @param bh BlockHandler*
 */
void generate_code(BlockHandler* bh);
/**
 * @brief Format the filename for the output.
 *
 * @param name std::string& file name.
 */
void format_filename(std::string& name);
}  // namespace CodeGeneration

#endif  // !CODE_GENERATION_H
