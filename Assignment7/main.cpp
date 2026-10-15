#include "fraction.hpp"
#include "set.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

void printSet(const string &text, const Set &set) {
}

int main() {

  std::cout << "### OPPGAVE 1 ### \n"
            << std::endl;

  Fraction a(1, 2);
  Fraction b(3, 4);
  Fraction c;

  print("A: ", a);
  print("B: ", b);

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

  Fraction fraction1(1, 2);

  print("fraction1 = ", fraction1);

  Fraction fraction2 = fraction1 - 5;

  print("Fraction1 - 5 = ", fraction2);

  Fraction fraction3 = 5 - fraction1;

  print("5 - Fraction1 = ", fraction3);

  std::cout << "\n";

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);

  std::cout << "\n#######\n";
  std::cout << "### OPPGAVE 2 ### \n"
            << std::endl;

  Set set1({1, 2, 3, 4});
  Set set2({2, 3, 4});

  Set set3 = set1 | set2;
}
