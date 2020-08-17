#include "etl.h"

using namespace std;

namespace etl {

map<char, int> transform(map<int, vector<char>> old) {
  map<char, int> res;

  char a;
  map<int, vector<char>>::iterator itr;
  for (itr = old.begin(); itr != old.end(); ++itr) {
    for (int i = 0; i < (int)(itr->second).size(); ++i) {
      a = tolower((itr->second)[i]);
      res.insert(pair<char, int>(a, itr->first));
    }
  }

  return res;
}

}  // namespace etl
