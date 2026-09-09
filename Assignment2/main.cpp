#include <cstring>
#include <iostream>

void assignment1a();

void assignment1b();

void assignment4();

void assignment5();

int find_sum(const int *table, int length);

int main() {

  // Oppggave 1 a:

  std::cout << "Oppgave 1 a:\n";
  assignment1a();

  // Oppgave 1 b:

  std::cout << "\nOppgave 1 b:\n";
  assignment1b();

  // Oppgave 4

  std::cout << "\nOppgave 4:\n";
  assignment4();

  // Oppgave 5
  std::cout << "\nOppgave 5:\n";

  assignment5();

  int table[20];

  for (int i = 0; i < 20; i++) {
    table[i] = (i + 1);
  }

  // Oppgave 6:

  std::cout << "\nOppgave 6:\n";

  int sum1 = find_sum(table, 10);

  std::cout << "Summen fra 0 til 10 er: " << sum1 << "\n";

  int sum2 = find_sum(&table[10], 5);

  std::cout << "Summen fra 11 til 15 er: " << sum2 << "\n";

  int sum3 = find_sum(&table[15], 5);

  std::cout << "Summen fra 16 til 20 er: " << sum3 << "\n";

  return 0;
}

void assignment1a() {

  int i = 3;   // I settes lik 3
  int j = 5;   // j settes lik 5
  int *p = &i; // pekeren p peker på adressen til i
  int *q = &j; // Pekeren q peker på adressen til j

  std::cout << "Verdier:\n";

  std::cout << i << "\n";
  std::cout << *p << "\n"; // Derefererer p og gir verdien som ligger på adressen p peker til(i)
  std::cout << *q << "\n"; // Derefererer q og gir verdien som ligger på adressen q peker til(j)
  std::cout << j << "\n\n";

  std::cout << "Adresser:\n";

  std::cout << &i << "\n"; // p inneholder adressen til i, så &i og p er de samme
  std::cout << p << "\n";

  std::cout << q << "\n"; // q inneholder adressen til j
  std::cout << &j << "\n";
  // p og q er egne variabler med egne plasser i minne
  std::cout << &p << "\n";
  std::cout << &q << "\n";
}

void assignment1b() {

  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  *p = 7;      // Verdien til i (det p peker på) settes til 7
  *q += 4;     // Verdien til j (det q peker på) settes til &j + 4 ---> 5 + 4 = 9
  *q = *p + 1; // Verdien j settes til *p + 1, altså verdien til i (7) + 1 = 8
  p = q;       // Her endres faktisk pekeren p, som nå peker på dit q peker (j) ikke lenger på i

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

  std::cout << "Oppgave 4 kompilerer\n";
}

void assignment5() {

  double number;
  double *pNumber = &number;
  double &rNumber = number;

  number = 25;   // Måte 1 - sette number = 25 direkte
  *pNumber = 25; // Måte 2 - Sette via pekeren
  rNumber = 25;  // Måte 3 - Sette via referansen

  std::cout << number << "\n";
  std::cout << *pNumber << "\n";
  std::cout << rNumber << "\n";
}

int find_sum(const int *table, int length) {

  int sum = 0;

  for (int i = 0; i < length; i++) {
    sum += table[i];
  }

  return sum;
}
