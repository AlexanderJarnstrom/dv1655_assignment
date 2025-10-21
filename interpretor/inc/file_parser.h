#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <string>
#include <vector>

#include "byte_code.h"
namespace FileParser
{
void read_file(std::string file_path, std::vector<ByteCode*>& code);
void split_line(std::string& line, std::vector<std::string>& words);
}  // namespace FileParser

#endif  // !FILE_PARSER_H
