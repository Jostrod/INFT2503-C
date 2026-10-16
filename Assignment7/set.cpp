#include "set.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

Set::Set() {};

Set::Set(std::vector<int> start) {
  for (int n : start) {
    *this += n;
  }
}

Set Set::operator|(const Set &other) const {
  Set result = *this;
  for (int n : other.numbers) {
    result += n;
  }
  return result;
}

Set &Set::operator+=(int number) {
  auto it = std::find(numbers.begin(), numbers.end(), number);
  if (it == numbers.end()) {
    numbers.push_back(number);
  }
  return *this;
}

Set &Set::operator=(const Set &other) {

  numbers = other.numbers;

  return *this;
}

std::ostream &operator<<(std::ostream &os, const Set &set) {
  bool first = true;
  os << "{ ";
  for (int n : set.numbers) {
    if (!first) {
      os << ", ";
    }
    os << n;
    first = false;
  }
  os << " }";

  return os;
}
