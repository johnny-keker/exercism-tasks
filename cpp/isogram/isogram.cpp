#include "isogram.h"

namespace isogram {

bool is_isogram(std::string phrase) {
  int ph_len = phrase.length();
  char a, b;

  for (int i = 0; i < ph_len - 1; ++i) {
    for (int j = i + 1; j < ph_len; ++j) {
      a = tolower(phrase[i]);
      b = tolower(phrase[j]);
      
      if (isalpha(a) && isalpha(b) && a == b)
        return false;
    }
  }

  return true;
}

}  // namespace isogram
