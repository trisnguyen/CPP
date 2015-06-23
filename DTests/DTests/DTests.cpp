#include "DTests.h"

//for demonstration
int main() {

//test 01
  {
    cout << endl << "Test 01" << endl;
    string s = "ABCDEF";
    int n = -2;
    cout << "String: " << s << "; rotated left by " << n << endl;
    cout << "Result: " << rotateStringLeft(s, n) << endl;
    //cin.get();
  }

//test 02
  {
    cout << endl << "Test 02, calculate the number of ints divisible by 7 but not by 3" << endl;
    int x = 8;
    int y = 12228;
    cout << "Range [" << x << ", " << y << "]" << endl;
    cout << "Count: " << countDiv7NotDiv3(x, y) << endl;
    cout << "Calculate: " << calculateDiv7NotDiv3(x, y) << endl;

    x = 3; //18343;
    y = 12; //18352;
    cout << "Range [" << x << ", " << y << "]" << endl;
    cout << "Count: " << countDiv7NotDiv3(x, y) << endl;
    cout << "Calculate: " << calculateDiv7NotDiv3(x, y) << endl;

    x = 1; //18343;
    y = 2; //18352;
    cout << "Range [" << x << ", " << y << "]" << endl;
    cout << "Count: " << countDiv7NotDiv3(x, y) << endl;
    cout << "Calculate: " << calculateDiv7NotDiv3(x, y) << endl;
    //cin.get();
  }

//test 04
  {
    cout << endl << "Test 04" << endl;
    //set condition functions
    ConditionVector conditions;
    conditions.push_back(IsCorrectLength);
    conditions.push_back(IsCorrectInitial);
    conditions.push_back(IsDigitSumDivisibleBy10);

    //tests
    array<string, 4> number = { "446772", "356772", "446771", "446781" };
    for (int i = 0; i < number.size(); i++)
      cout << number[i] << " is " << (IsValidCustomerNumber(number[i], conditions) ? "valid" : "invalid") << "." << endl;

    string s = "Dear John, 446781 is your new customer number.";
    cout << "The string is: \"" << s << "\"" << endl;
    cout << "The string " << (ContainsValidCustomerNumber(s, conditions) ? "contains" : "does not contain") << " a valid customer number." << endl;
  }

  //test 05
  {
    cout << endl << "Test 05" << endl;
    const int boardSize = 3;
    char testboard[boardSize][boardSize] = //row, col
    { { 1, 2, 3 },
    { 0, 5, 4 },
    { 0, 0, 0 } };

    char* board[boardSize];
    for (int i = 0; i < boardSize; i++)
      board[i] = testboard[i];

    for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
        cout << (board[i][j] + 0) << " ";
      }
      cout << endl;
    }
    cout << "The winner is : " << 0 + getWinner(boardSize, board) << endl;
  }


//miscellaneous
  {

  }

  cin.get();
  return 0;
}