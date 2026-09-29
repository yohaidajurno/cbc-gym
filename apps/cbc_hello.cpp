#include <iostream>

#include "cbc/version.hpp"

int main() {
  std::cout << "cbc-gym " << cbc::version() << '\n';
  return 0;
}
