#include <cstring>
#include <iostream>

void assignment1a();

void assignment1b();

void assignment4();

void assignment5();

int main() {
  /*
    assignment1a();
    std::cout << "\n";


    assignment1b();



  // Oppgave 2
  char *line = nullptr;
  strcpy(line, "This is a string"); // Segfault

  */

  assignment5();

  return 0;
}

void assignment1a() {

  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  std::cout << i << "\n";
  std::cout << *p << "\n";
  std::cout << *q << "\n";
  std::cout << j << "\n\n";

  std::cout << p << "\n";
  std::cout << q << "\n";
  std::cout << &i << "\n";
  std::cout << &j << "\n";
}

void assignment1b() {

  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;

  std::cout << *p << " " << *q << std::endl;
}

void assignment4() {

  /*
   * Original
   *
  int a = 5;
  int &b;
  int *c;
  c = &b;
  *a = *b + *c;
  &b = 2;

  */

  // Fix

  int a = 5;
  int &b = a; // Må sette adressen til b til en verdi, setter den lik a her. Så b er nå bare et annet navn på a. Samme verdi og samme adresse i minne
  int *c;
  c = &b;
  a = b + *c; // Setter a lik b (som er a) + verdien på adressen til c (som er b, som igjen er a).
              // Fjernet * fordi b ikke er en peker, det er ingen adresse som må dereferensieres.

  b = 2; // Kan ikke sette adressen til b = 2. Men verdien på adressen kan settes til 2
}

void assignment5() {

  double number;
  double *pNumber = &number;

  // number = 25; // Måte 1
  *pNumber = 25; // Måte 2

  std::cout << *pNumber << "\n";
}
