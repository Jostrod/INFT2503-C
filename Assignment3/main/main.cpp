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

  /*
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
       */

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

  string word1;
  int wordOneCount;

  string word2;
  int wordTwoCount;

  string word3;
  int word3Count;

  cout << "Skriv inn 3 ord:\n";

  cout << "Ord 1: \n";

  cin >> word1;

  for (int i = 0; i < word1.)

    cout << "Ord 2: \n";

  cin >> word2;

  cout << "Ord 3: \n";

  cin >> word3;

  string sentence = word1 + " " + word2 + " " + word3 + ".";

  cout << sentence;
}
