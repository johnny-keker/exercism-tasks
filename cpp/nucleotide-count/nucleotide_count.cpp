#include "nucleotide_count.h"

using namespace std;

namespace nucleotide_count {

void validate_nucleotide(char a) {
  if (a != 'A' && a != 'T' && a != 'G' && a != 'C')
    throw std::invalid_argument("invalid nucleotide");
}

counter::counter(string a) {
  for (int i = 0; i < (int)a.length(); ++i)
    validate_nucleotide(a[i]);
  dna = a;
}

int counter::count(char a) const {
  validate_nucleotide(a);
  int res = 0;
  for (int i = 0; i < (int)dna.length(); ++i)
    if (dna[i] == a)
      res++;
  return res;
}

map<char, int> counter::nucleotide_counts() const {
  map<char, int> res;
  res.insert(pair<char, int>('A', count('A')));
  res.insert(pair<char, int>('T', count('T')));
  res.insert(pair<char, int>('G', count('G')));
  res.insert(pair<char, int>('C', count('C')));
  return res;
}

}  // namespace nucleotide_count
