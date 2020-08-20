#include "word_count.h"

using namespace std;

namespace word_count {

map<string, int> update_res(map<string, int> res, string word) {
  if (word.length() != 0) {
    map<string, int>::iterator it = res.find(word);
    if (it == res.end())
      res.insert(pair<string, int>(word, 1));
    else
      it->second++;
  }
  return res;
}

map<string, int> words(string s) {
  map<string, int> res;
  
  if (s.length() == 0)
    return res;

  char c_char;
  string current_word;

  for (int i = 0; i < (int)s.length(); ++i) {
    c_char = tolower(s[i]);
    if (isalpha(c_char) || isdigit(c_char))
      current_word = current_word.append(1, c_char);
    else if (c_char == 39) {
      if (current_word.length() != 0 && i != (int)s.length() - 1 && isalpha(s[i + 1]))
        current_word = current_word.append(1, c_char);
    }
    else {
      res = update_res(res, current_word);
      current_word.clear();
    }
  }
  res = update_res(res, current_word);

  return res;
}

}  // namespace word_count
