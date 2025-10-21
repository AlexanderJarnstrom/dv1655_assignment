#ifndef SYMBOL
#define SYMBOL

#include <string>

enum Record
{
  CLASS,
  VARIABLE,
  METHOD,
  ARGUMENT,
  ROOT
};

class Symbol
{
public:
  std::string m_id;
  std::string m_type;
  std::string m_block;
  unsigned m_args;
  Record m_record;

  Symbol (std::string, std::string, Record);
  ~Symbol ();
};

#endif // !SYMBOL
