#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <string>
#include <vector>

using namespace std;

namespace anagram {

class anagram {
  private:
  int letter_map[26];
  int letter_count;
  string anagram_word;

  bool word_check(string word);


  public:
  anagram(string s);
  vector<string> matches(vector<string> m);

}; // class anagram

}  // namespace anagram

#endif // ANAGRAM_H