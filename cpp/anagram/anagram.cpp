#include "anagram.h"
#include <algorithm>

using namespace std;

namespace anagram {

anagram::anagram(string s) {
  std::for_each(s.begin(), s.end(), [](char & c) {
      c = ::tolower(c);
  });

  anagram_word = s;

  for (int i = 0; i < 26; ++i)
    letter_map[i] = 0;

  letter_count = s.length();
  for (int i = 0; i < letter_count; ++i) {
    letter_map[s[i] - 97]++;
  }
}

bool anagram::word_check(string word) {
  std::for_each(word.begin(), word.end(), [](char & c) {
      c = ::tolower(c);
  });

  if ((int)word.length() != letter_count || word == anagram_word) return false;

  int word_letter_map[26];
  for (int i = 0; i < 26; ++i)
    word_letter_map[i] = 0;

  for (int i = 0; i < letter_count; ++i)
  {
    word_letter_map[word[i] - 97]++;
  }

  for (int i = 0; i < 26; ++i)
    if (word_letter_map[i] != letter_map[i])
      return false;
  
  return true;
}

vector<string> anagram::matches(vector<string> m) {
  //if (m.empty())
  //  return vector<string>();
  
  vector<string> res;
  for (int i = 0; i < (int)m.size(); ++i)
    if (word_check(m[i]))
      res.push_back(m[i]);

  return res;
}

}  // namespace anagram
