#include "../inc/hasher.h"

using namespace std;

hash_t
hash_string(string str)
{
  hash_t hash = 1;

  for (char letter : str) {
    hash *= letter;
  }

  hash = hash % 1511;

  return hash;
}
