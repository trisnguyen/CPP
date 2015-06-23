#include <iostream>
#include <string>
using namespace std;

void FizzBuzz(int min, int max) {

  for (int i = min; i <= max; i++) {
    string sOutput = "";
    if (i % 3 == 0)
      sOutput += "Fizz";
    if (i % 5 == 0)
      sOutput += "Buzz";
    //... add more condition as needed

    if (sOutput.length() == 0)
      sOutput += to_string(i);
    cout << sOutput << endl;
  }
}

int main() {
  FizzBuzz(1, 20);
  cin.get();
  return 0;
}