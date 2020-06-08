#include "stdafx.h"
#include "ValidParenthesisString.h"

#include <algorithm>

/*
upper counts the maximum open parenthesis,
which means the maximum number of unbalanced '(' that COULD be paired.
lower counts the minimum open parenthesis,
which means the number of unbalanced '(' that MUST be paired.

When you met "(", you know you need one only one ")", lower = 1 and upper = 1.
When you met "(*(", you know you need one/two/three ")", lower = 1 and upper = 3.

The string is valid for 2 condition:

upper will never be negative.
lower is 0 at the end.
*/
bool Solution::checkValidString(string s) {
  int lower = 0, upper = 0;
  for (char c : s) {
    if (c == '(') {
      lower++;
      upper++;
    }
    else if (c == ')') {
      lower--;
      upper--;
    }
    else { // * encountered
      lower--;
      upper++;
    }
    lower = max(lower, 0);
    if (upper < 0) // unmatched ')' found in the middle of string
      return false;
  }
  return lower == 0;
}