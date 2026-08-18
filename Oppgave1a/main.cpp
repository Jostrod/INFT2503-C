#include <iostream>
#include <string>

using namespace std;

int main() {

  const int LENGTH = 5;
  double temps[LENGTH];

  int overTwenty = 0;
  int overTen = 0;
  int overOne = 0;

  cout << "Skriv inn " << LENGTH << " temperaturer:\n";

  for (int i = 0; i < LENGTH; i++) {
    cout << "Temperature " << i + 1 << " : ";
    cin >> temps[i];
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

  cout << "Antall under 10 er: " << overOne << "\n";
  cout << "Antall mellom 10 og 20 er: " << overTen << "\n";
  cout << "Antall over 20 er: " << overTwenty << "\n";

  return 0;
}
