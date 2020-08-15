#include "gigasecond.h"

namespace gigasecond {

ptime advance(ptime time) {
  return time + seconds((int)std::pow(10, 9));
}

}  // namespace gigasecond
