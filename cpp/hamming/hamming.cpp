#include "hamming.h"
#include <stdexcept>

namespace hamming {

int compute(std::string a, std::string b) {
  int len = a.length();
  if (len != (int)b.length())
    throw std::domain_error("the length of two strings must be equal");

  int distance = 0;
  for (int i = 0; i < len; ++i)
    if (a[i] != b[i])
      distance++;

  return distance;
}

}  // namespace hamming
