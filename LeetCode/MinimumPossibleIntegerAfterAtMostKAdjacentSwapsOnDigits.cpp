#include "stdafx.h"
#include "MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigits.h"

#include <algorithm>

string Solution::minInteger(string num, int k) {
  if (k <= 0)
    return num;
  int n = num.size();
  if (k >= n * (n + 1) / 2) { // sum of all numbers to n, you have more moves than needed
    sort(num.begin(), num.end());
    return num;
  }

  for (int i = 0; i < 10; i++) {  // bubble lowest numbers to front if it exists
    int idx = num.find(to_string(i));
    if (idx >= 0 && idx <= k)
      return num[idx] + minInteger(num.substr(0, idx) + num.substr(idx + 1), k - idx);  // remove lowest found to front and research new string
  }
  return num;
}