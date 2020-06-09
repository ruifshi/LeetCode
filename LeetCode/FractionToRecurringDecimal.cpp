#include "stdafx.h"
#include "FractionToRecurringDecimal.h"

#include <unordered_map>

string Solution::fractionToDecimal(int numerator, int denominator) {
  if (numerator == 0) return "0";

  string ans;

  // find sign
  if (numerator > 0 ^ denominator > 0) {
    ans += '-';
  }

  long num = labs(numerator);
  long den = labs(denominator);
  long rem = num % den; // remainder

  ans += to_string(num / den);

  if (rem == 0) return ans; // no remainder

  ans += '.';

  // this keeps track of the remainder and location
  // of first occurance. We know a number if repeating
  // if the remainder repeats. When we see the first
  // instance of this, we can insert () at the saved location;
  unordered_map<long, int> rem_table;

  while (rem) {
    if (rem_table.find(rem) != rem_table.end()) {
      ans.insert(rem_table[rem], "(");
      ans += ')';
      break;
    }

    rem_table[rem] = ans.size(); // save location of remainder

    rem *= 10; // long division
    ans += to_string(rem / den);
    rem %= den;
  }

  return ans;
}