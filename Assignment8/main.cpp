#include <cmath>
#include <iostream>

// Oppgave 1
template <typename Type>
bool equal(Type a, Type b) {
  return a == b;
}

template <typename Type = double>
bool equal(double a, double b) {
  return fabs(a - b) < 0.0001;
}

// Oppgave 2
template <typename Type, typename Type2>
class Pair {
public:
  Type first, second;

  Pair(Type x, Type y) : first(x), second(y) {}
  Pair() {}

  Pair operator+(const Pair &other) {
    Pair pair = *this;
    pair.first += other.first;
    pair.second += other.second;
    return pair;
  }

  bool operator>(const Pair &other) {
    Pair pair = *this;
    double pairSum = pair.first + pair.second;
    double otherSum = other.first + other.second;
    if (pairSum > otherSum) {
      return pairSum;
    }
    return otherSum;
  }
};
using namespace std;

int main() {

  Pair<double, int> p1(3.5, 14);
  Pair<double, int> p2(2.1, 7);
  cout << "p1: " << p1.first << ", " << p1.second << endl;
  cout << "p2: " << p2.first << ", " << p2.second << endl;

  if (p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;

  auto sum = p1 + p2;
  cout << "Sum: " << sum.first << ", " << sum.second << endl;
}
