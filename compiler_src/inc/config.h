#ifndef CONFIG_H
#define CONFIG_H

#include <string>
namespace Config
{
enum Flags
{
  DEBUG = 1,
  OUTPUT = 1 << 1,
  INPUT_File = 1 << 2,
  TREE = 1 << 3,
  BLOCKS = 1 << 4,
};

extern int flags;
extern std::string output_name;
extern std::string input_name;

/**
 * @brief Extracts all argument and places them in the config.
 *
 * Loops through all the entrys in argv adding them in the global config
 * variables while enabling related flags.
 *
 * @param argc number of arguments.
 * @param argv argument array.
 *
 * @see Flags for potential flag values.
 * */
void extract_arguments(int argc, char** argv);

}  // namespace Config

#endif  // !CONFIG_H
