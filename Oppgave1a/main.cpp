#include <iostream>
#include <limits>
#include <string>

int main() {

  const int LENGTH = 5;
  double temps[LENGTH];

  int overTwenty = 0;
  int overTen = 0;
  int overOne = 0;

  int data;

  std::cout << "Enter " << LENGTH << " temperatures";

  for (int i = 0; i < LENGTH; i++) {

    std::cout << "\nTemperature number " << i + 1 << ": ";

    while (!(std::cin >> data)) {
      std::cout << "Invalid input\n";
      std::cin.clear();
      std::cin.ignore(100000, '\n'); // 100 000 burde holde
    }

    temps[i] = data;
  }

  for (int i = 0; i < LENGTH; i++) {
    if (temps[i] >= 1 && temps[i] < 10) {
      overOne++;
    } else if (temps[i] >= 10 && temps[i] < 20) {
      overTen++;
    } else {
      overTwenty++;
    }
  }

  std::cout << "Antall under 10 er: " << overOne << "\n";
  std::cout << "Antall mellom 10 og 20 er: " << overTen << "\n";
  std::cout << "Antall over 20 er: " << overTwenty << "\n";

  return 0;
}
