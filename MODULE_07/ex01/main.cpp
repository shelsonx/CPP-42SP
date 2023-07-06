#include "iter.hpp"

int main(void) {
  int numbers[4] = {1, 3, 5, 7};
  std::string names[4] = {"Davi", "Doriane", "Shelson", "Jesus"};
  
  float decimals[4] = {5.4, 34.2, 7.7, 21.42};
  const char *characteres = "@#$%";

  
  iter(numbers, 4, print<int>);
  iter(names, 4, print<std::string const>);

  iter(decimals, 4, print<float>);
  iter(characteres, 4, print<char const>);

  return 0;
}
