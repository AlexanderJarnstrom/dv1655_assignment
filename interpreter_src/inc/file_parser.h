#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <string>
#include <vector>

#include "byte_code.h"
namespace FileParser
{
/**
 * @brief Read the given file path.
 *
 * @param file_path string file path.
 * @param code vector with the byte code.
 * @param engine Engine.
 */
void read_file(std::string file_path, std::vector<ByteCode*>& code,
               Engine& engine);
/**
 * @brief Splits the line into words.
 *
 * @param line string to split.
 * @param words vector of strings.
 */
void split_line(std::string& line, std::vector<std::string>& words);
/**
 * @brief Check if the given string is a label.
 *
 * @param word string to check.
 * @return true if label else false.
 */
bool is_label(const std::string& word);
}  // namespace FileParser

#endif  // !FILE_PARSER_H
