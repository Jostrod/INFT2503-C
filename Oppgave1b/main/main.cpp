#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {

  const int length = 5;

  double temperatures[length];

  read_temperatures(temperatures, length);

  int lessThanTen = 0;
  int lessThanTwenty = 0;
  int overTwenty = 0;

  for (int i = 0; i < length; i++) {
    if (temperatures[i] < 10) {
      lessThanTen++;
    } else if (temperatures[i] >= 10 && temperatures[i] < 20) {
      lessThanTwenty++;
    } else {
      overTwenty++;
    }
  }

  cout << "Temperatures less than 10: " << lessThanTen << "\n";
  cout << "Temperatures between 10 an 20: " << lessThanTwenty << "\n";
  cout << "Temperatures over 20: " << overTwenty << "\n";

  return 0;
}

void read_temperatures(double temperatures[], int length) {

  const char filename[] = "tallfil.dat";

  ifstream file;

  file.open(filename);

  if (!file) {
    cout << "Could not open file." << endl;
    exit(EXIT_FAILURE);
  }
  int i = 0;

  while (file >> length) {
    temperatures[i] = length; // Ikke optimalt navn på length, siden dette er hver temperatur, men forsto det som at vi måtte sende length som parameter
    i++;
  }

  file.close();
}
