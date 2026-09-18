#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const double pi = 3.141592;
const double mva = 1.25;

void assignment4();

class Circle {

public:
  Circle(double radius_);
  double get_area() const;
  double get_circumference() const;

private:
  double radius;
};

// OPPGAVE 3

class Commodity {
public:
  Commodity(std::string name_, int id_, double price_);

  std::string get_name();

  int get_id();

  void set_price(double price_);

  double get_price();

  double get_price(double quantity);

  double get_price_with_sales_tax(double amount);

private:
  std::string name;
  int id;
  double price;
};

int main() {

  Circle sirkel = Circle(5);

  double areal = sirkel.get_area();

  std::cout << "\nArealet er lik " << areal << "\n";

  double circumference = sirkel.get_circumference();

  std::cout << "Omkretsen er lik " << circumference << "\n";

  cout << "\n";
  cout << "Oppgave 3 \n\n";

  const double quantity = 2.5;
  Commodity commodity("Norvegia", 123, 73.50);

  cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id()
       << " Pris pr enhet: " << commodity.get_price() << endl;

  cout << "Kilopris: " << commodity.get_price() << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
       << " uten moms" << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity)
       << " med moms" << endl;

  commodity.set_price(79.60);
  cout << "Ny kilopris: " << commodity.get_price() << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
       << " uten moms" << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity)
       << " med moms" << endl;

  assignment4();
}

Circle::Circle(double radius_) : radius(radius_) {};

double Circle::get_area() const {
  return pi * radius * radius;
};

double Circle::get_circumference() const {
  double circumference = 2.0 * pi * radius;
  return circumference;
};

Commodity::Commodity(std::string name_, int id_, double price_) : name(name_), id(id_), price(price_) {};

std::string Commodity::get_name() {
  return name;
};

int Commodity::get_id() {
  return id;
}

void Commodity::set_price(double price_) {
  price = price_;
}

double Commodity::get_price() {
  return price;
}

double Commodity::get_price(double quantity) {
  return price * quantity;
}

double Commodity::get_price_with_sales_tax(double amount) {
  return price * amount * mva;
}

void assignment4() {

  // Oppgave a

  string word1;

  string word2;

  string word3;

  cout << "\nOPPGAVE 4\nSkriv inn 3 ord:\n";

  cout << "Ord 1: \n";

  cin >> word1;

  cout << "Ord 2: \n";

  cin >> word2;

  cout << "Ord 3: \n";

  cin >> word3;

  // Oppgave b
  string sentence = word1 + " " + word2 + " " + word3 + ".";

  for (auto &x : sentence) { // Passer på alt er i lower case, for å gjøre livet lettere for meg selv
    x = tolower(x);
  }

  cout << sentence;

  // Oppgave c
  int word1Len = word1.length();
  int word2Len = word2.length();
  int word3Len = word3.length();

  int sentenceLen = sentence.length();

  cout << "\nLengden på ord 1 er: " << word1Len << endl;
  cout << "Lengden på ord 2 er: " << word2Len << endl;
  cout << "Lengden på ord 3 er: " << word3Len << endl;
  cout << "Lengden på hele setningen er: " << sentenceLen << endl;

  // Oppgave d
  string sentence2 = sentence;

  // Oppgave e

  if (sentence2.length() >= 12) {
    sentence2[9] = 'x';
    sentence2[11] = 'x';
    cout << "\n"
         << "Setning før modifisering: " << sentence
         << "\nSetning etter modifisering: " << sentence2;
  } else {
    cout << "Setningen er ikke lang nok til å bytte ut tegn nr 10 og 12";
  }

  // Oppgave f - Tolket det som at vi skulle telle med whitespace som en del av tegnene. Om dette ikke er tilfelle ville jeg gjort i prinsippet det samme,
  // men slått sammen alle ordene og fjernet whitespace.
  if (sentence2.length() >= 5) {
    char sentence_start[5];

    for (int i = 0; i < 5; i++) {
      sentence_start[i] = sentence2[i];
    }
    cout << "\nStarten på setningen: " << sentence_start
         << "\nHele setningen: " << sentence2;
  }

  // Oppgave g
  string word = "hallo";

  if (sentence.find(word) != string::npos) {
    cout << "\nHallo finnes i setningen.";
  } else {
    cout << "\nHallo finnes ikke i setningen.";
  }

  // Oppgave h - Tolket det som at "er" skulle være i ett ord, altså at <sendE Robot> ikke telles.

  int counter = 0;
  string::size_type pos = 0;
  string target = "er";

  while ((pos = sentence.find(target, pos)) != string::npos) {
    ++counter;
    pos += target.length();
  }

  cout << "\nEr finnes: " << counter << " Ganger i setningen.";
}
