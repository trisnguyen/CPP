#include "DTests.h"

/* question 1 (15 marks)
Rotate a string n position to the left
For example, "ABCDEF" rotated 2 will result in "CDEFAB"
Assumption: n < 0 means rotate to the right; "ABCDEF" rotated -2 will result in "EFABCD"
*/
string rotateStringLeft(string pS, int pN) {

  int len = pS.length();
  if (len <= 0) return pS; //no rotation needed

  int n = pN % len;
  if (n < 0)
    n = len + n;  //the result is guaranteed to be positive
  return pS.substr(n, len - n) + pS.substr(0, n);

}
