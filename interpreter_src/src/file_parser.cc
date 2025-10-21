#include "../inc/file_parser.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void FileParser::read_file(std::string file_path, std::vector<ByteCode*>& code,
                           Engine& engine)
{
  std::ifstream file(file_path);

  if (!file)
  {
    std::cerr << "Could not open file: " << file_path << std::endl;
    return;
  }

  std::string content, line;
  std::vector<std::string> words;
  std::map<std::string, unsigned>& labels = engine.get_labels();
  unsigned row = 0;

  while (std::getline(file, line))
  {
    split_line(line, words);
    if (words.empty()) continue;

    if (is_label(words[0]))
    {
      labels.insert({words[0].substr(0, words[0].size() - 1), row});
    }

    ByteCodeUtil::create_byte_code(words, code);
    row++;
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

bool FileParser::is_label(const std::string& word)
{
  return word.find("Block") != std::string::npos;
}
