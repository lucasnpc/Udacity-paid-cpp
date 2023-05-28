#include "abstraction.hpp"
#include "date.hpp"

// Test
int main() {
  Date date(29, 8, 1981);
  assert(date.String() == "August 29, 1981");
}