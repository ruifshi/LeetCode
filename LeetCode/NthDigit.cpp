#include "stdafx.h"
#include "NthDigit.h"

#include <algorithm>
#include <string>

using namespace std;

/*
1-------9 9*1 = 9 digits
10-----99 90 *2 = 180 digits
100---999 900 *3 = 2700 digits
...

After step 1, you will find that the 250th digit must belong to a 3-digit number, 
since 1~9 can only provide 9 digits and 10~99 can only provide 180 digits. 
Here, n = 250 - 9 - 90 * 2 = 61, and digits = 3.

In step 2, we will find the target number, which named as number in my code. 
From step 1, the n becomes to 61, which means "the 61st digit in 3-digit number is the 
digit we are looking for ." Easily, we know the 61st digit in 3-digit number belongs to 
number = 100 + 61 / 3 = 100 + 20 = 120. index is the index of the target digit in number. 
If index equals to 0, it means the target digit is the last digit of number.

Step 3, from step 2, we know index = n % digits = 61 % 3 = 1, which means the 
target digit is the 1st digit in number. Then, return 1.
*/
int Solution::findNthDigit(int n) {
  // find out how many digits the number has
  long digits = 1, base = 9;

  while (n > base * digits) {
    n -= base * digits;
    base *= 10;
    digits++;
  }

  // find the number
  // n at this point gives you the nth digit in x digit number (x = digit)
  int num = pow(10, digits - 1) + (n - 1) / digits; // n-1 since 0 indexed
  string s = to_string(num);

  return s[(n - 1) % digits] - '0'; // n-1 since 0 indexed
}