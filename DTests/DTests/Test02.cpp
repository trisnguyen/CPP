#include "DTests.h"

/* Problem:
- in a range from x to y
- find all integers that are divisible by 7 but not divisible by 3
*/

//An O(1) (constant complexity) algorithm
int calculateDiv7NotDiv3(int min, int max) {
  if (min > max)
    return 0;
  //find the first number that's divisible by 7
  int firstDiv7 = min;
  while (firstDiv7 % 7 != 0)  //maximum 6 loops
    firstDiv7++;

  //find the first number that's divisible by both 7 and 3
  int firstDiv7Div3 = firstDiv7;
  while (firstDiv7Div3 % 3 != 0)  //maximum 2 loops
    firstDiv7Div3 += 7;

  //return (max - firstDiv7) / 7 - (max - firstDiv7Div3) / 21;

  int countTotalDiv7 = (max - firstDiv7) / 7 + 1;
  if (max - firstDiv7 < 0)
    countTotalDiv7 = 0;
  int countTotalDiv7Div3 = (max - firstDiv7Div3) / 21 + 1;
  if (max - firstDiv7Div3 < 0)
    countTotalDiv7Div3 = 0;

  cout << "firstDiv7 = " << firstDiv7 << endl;
  cout << "firstDiv7Div3 = " << firstDiv7Div3 << endl;
  cout << "min = " << min << endl;
  cout << "max = " << max << endl;
  cout << "countTotalDiv7 = " << countTotalDiv7 << endl;
  cout << "countTotalDiv7Div3 = " << countTotalDiv7Div3 << endl;
  return countTotalDiv7 - countTotalDiv7Div3;
}

bool IsDiv3(int number) {
  int digitSum = 0;
  int n = number;
  while (n > 0) {
    digitSum += n % 10;
    n = n / 10;
  }
  return (digitSum % 3 == 0);
}

//An O(n) algorithm, manually counting the occurences
int countDiv7NotDiv3(int min, int max) {

  if (min > max)
    return 0;

  int first = min;
  while (first % 7 != 0)  //this can be improved
    first++;

  int count = 0;
  for (int i = first; i <= max; i+=7) {
    if (!IsDiv3(i)) {
      //cout << "accepted " << i << endl;
      count++;
    }
//    else       cout << "NOT accepted: " << i << endl;

  }
  return count;
}

