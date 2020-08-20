#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <string>
#include <map>

namespace nucleotide_count {

class counter {
  private:
  std::string dna;

  public:
  counter(std::string a);
  int count(char a) const;
  std::map<char, int> nucleotide_counts() const; 
}; // class counter

}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H