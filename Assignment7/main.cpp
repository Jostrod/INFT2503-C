#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
  Fraction a(1, 2);
  Fraction b(3, 4);
  Fraction c;

  print("A: ", a);
  print("B: ", b);

  Fraction q = a - b;

  print("A - B: ", q);

  c.set(5);
  Fraction d = a / b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  std::cout << "\n";
  print("a = ", a);

  Fraction fraction1 = a - 7; // a = this
                              // 1 = other

  print("fraction1 = ", fraction1);

  std::cout << "\n";

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);
}
