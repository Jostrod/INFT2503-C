#include <algorithm>
#include <iostream>
#include <vector>

void assignment1();

void assignment2();

int main() {

  assignment1();

  return 0;
}

void assignment1() {

  std::vector<int> nums{1, 2, 3, 4, 6};

  std::cout << nums.front() << "\n";
  std::cout << nums.back() << "\n";

  std::cout << "\n";

  nums.emplace(nums.begin() + 4, 5);

  for (auto i : nums) {
    std::cout << i << "\n";
  }

  std::cout << "\n";

  auto it = find(nums.begin(), nums.end(), 7);

  if (it != nums.end()) {
    std::cout << distance(nums.begin(), it + 1) << "\n";

  } else {
    std::cout << "\nIkke funnet\n";
  }
}

void assignment2() {
}
