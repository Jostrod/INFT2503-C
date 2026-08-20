#include <iostream>
#include <string>

int main() {

  const int LENGTH = 5;
  double temps[LENGTH];

  int overTwenty = 0;
  int overTen = 0;
  int overOne = 0;

  std::cout << "Enter " << LENGTH << " temperatures\n";

  for (int i = 0; i < LENGTH; i++) {
    std::cout << "Temperature " << i + 1 << " : ";
    std::cin >> temps[i];
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
