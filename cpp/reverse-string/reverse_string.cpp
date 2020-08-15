#include "reverse_string.h"
#include<bits/stdc++.h>

namespace reverse_string {

std::string reverse_string(std::string s) {
  reverse(s.begin(), s.end());
  return s;
}

}  // namespace reverse_string
