#include <cmath>
#include <iomanip>
#include <iostream>

// Oppgave 1
template <typename Type>
bool equal(Type a, Type b) {
  std::cout << "Result from template:\n"
            << std::setprecision(20) << a << " vs " << b << std::endl;
  return a == b;
}

bool equal(double a, double b) {
  std::cout << "Result from double:\n"
            << std::setprecision(20) << a << " vs " << b << std::endl;
  return std::fabs(a - b) < 0.00001;
}

// Oppgave 2

// Forutsetninger om krav:
// I operator+ må Type + Type finnes, samt Type2 + Type2. Resiøtatet må kunne tilordnes henholdsvis Type og Type2
//
// i operator>: må Type + Type2 finnes, og resultatet av Type + Type2 må kunne sammenlignes med >
template <typename Type, typename Type2>
class Pair {
public:
  Type first;
  Type2 second;

  Pair(Type x, Type2 y) : first(x), second(y) {}
  Pair() {}

  Pair operator+(const Pair &other) const {
    Pair pair = *this;
    pair.first = pair.first + other.first;
    pair.second = pair.second + other.second;
    return pair;
  }

  bool operator>(const Pair &other) const {
    auto pairSum = first + second;
    auto otherSum = other.first + other.second;
    return pairSum > otherSum;
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

  cout << boolalpha << equal(0.1 + 0.2, 0.3) << "\n";
  cout << boolalpha << equal(5, 5) << "\n";
}
