#pragma once
#include <ostream>
#include <vector>

class Set {
public:
  Set();
  explicit Set(std::vector<int> start);

  Set operator|(const Set &other) const;
  Set &operator+=(int number);
  Set &operator=(const Set &other);

private:
  std::vector<int> numbers;
  friend std::ostream &operator<<(std::ostream &os, const Set &Set);
};
