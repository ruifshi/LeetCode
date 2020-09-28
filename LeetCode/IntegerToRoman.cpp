#include "stdafx.h"
#include "IntegerToRoman.h"

#include <vector>

vector<int> values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
vector<string> symbols = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

string Solution::intToRoman(int num) {
  string s;

  // Loop through each symbol, stopping if num becomes 0.
  for (int i = 0; i < values.size() && num >= 0; i++) {
    // Repeat while the current symbol still fits into num.
    while (values[i] <= num) {
      num -= values[i];
      s += symbols[i];
    }
  }

  reverse(s.begin(), s.end());
  return s;
}