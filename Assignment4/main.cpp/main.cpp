#include <iostream>
#include <vector>

int main() {

  std::vector<int> numbers{1, 2, 3, 4, 5};

  numbers.insert(numbers.begin() + 3, {4, 5});

  std::cout << numbers.front() << "\n";
  std::cout << numbers.back() << "\n";

  return 0;
}
