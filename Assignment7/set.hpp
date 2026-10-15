#pragma once
#include <vector>

class Set {
public:
  Set();
  explicit Set(std::vector<int> start);

  Set operator|(const Set &other) const;

private:
  std::vector<int> numbers;
};
