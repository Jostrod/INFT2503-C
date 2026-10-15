#include "set.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Set::Set() {};

Set::Set(std::vector<int> start) : numbers(start) {}

Set Set::operator|(const Set &other) const {
  Set result = *this;
  for (int n : other.numbers) {
    result.numbers.push_back(n);
  }
  return result;
}
