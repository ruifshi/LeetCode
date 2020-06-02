#include "stdafx.h"
#include "ConvertANumberToHexadecimal.h"

string Solution::toHex(int num) {
  if (num == 0) return "0";

  // handle negative case
  // twos complement = flip bits + 1
  // same as casting negtaive to unsigned int
  unsigned int n = (unsigned int)num;

  int hex[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };

  string s;
  while (n) {
    s += hex[n % 16];
    n /= 16;
  }

  reverse(s.begin(), s.end());
  return s;
}