#include "../inc/file_parser.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void FileParser::read_file(std::string file_path, std::vector<ByteCode*>& code)
{
  std::ifstream file(file_path);

  if (!file)
  {
    std::cerr << "Could not open file: " << file_path << std::endl;
    return;
  }

  std::string content, line;
  std::vector<std::string> words;

  while (std::getline(file, line))
  {
    split_line(line, words);
    if (!words.empty()) ByteCodeUtil::create_byte_code(words, code);
  }

  file.close();
}

void FileParser::split_line(std::string& line, std::vector<std::string>& words)
{
  std::string temp;

  words.clear();

  for (char c : line)
  {
    if (c == ' ')
    {
      words.push_back(temp);
      temp.clear();
    }
    else
    {
      temp += c;
    }
  }

  words.push_back(temp);
}
