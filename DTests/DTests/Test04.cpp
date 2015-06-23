#include "DTests.h"

/* Test 04:
A valid customer number:
- contains exactly 6 digits from 0 - 9
- starts with 4 or 5, and
- the sum of the digits is divisible by 10
Check if a string contains a valid customer number.
*/

const int CUSTOMER_ID_LENGTH = 6;
const array<char, 2> VALID_INITIALS = {'4', '5'};

typedef bool(*ConditionFunctionPtr)(string);

//Define condition functions
bool IsCorrectLength(string number) {
  return (number.length() == CUSTOMER_ID_LENGTH);
}

bool IsCorrectInitial(string number) {
  for (int i = 0; i < VALID_INITIALS.size(); i++) {
    if (number[0] == VALID_INITIALS[i])
      return true;
  }
  return false;
}

bool IsDigitSumDivisibleBy10(string number) {
  int sum = 0;
  for (int i = 0; i < number.length(); i++) {
    sum = sum + (number[i] - '0');
  }
  return sum % 10 == 0;
}


//Define check functions
bool IsValidCustomerNumber(string number, ConditionVector conditions) {
  for (auto it = conditions.begin(); it != conditions.end(); it++) {
    if (!(*it)(number))
    return false;
  }
  return true;
}

bool ContainsValidCustomerNumber(string s, ConditionVector conditions) {
  for (int i = 0; i < s.length() - CUSTOMER_ID_LENGTH; ++i) {
    string subs = s.substr(i, CUSTOMER_ID_LENGTH);
    if (IsValidCustomerNumber(subs, conditions))
      return true;
  }
  return false;
}
