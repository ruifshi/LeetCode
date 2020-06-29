#include "stdafx.h"
#include "RomanToInteger.h"

int Solution::romanToInt(string s) {
  if (s.empty()) return 0;

  int roman[24] = {};
  roman['I' - 'A'] = 1;
  roman['V' - 'A'] = 5;
  roman['X' - 'A'] = 10;
  roman['L' - 'A'] = 50;
  roman['C' - 'A'] = 100;
  roman['D' - 'A'] = 500;
  roman['M' - 'A'] = 1000;

  // keep track of right
  // if right is bigger than left (curr), then need to subtract
  // if right is smaller or equal to left, then need to add
  int sum = 0;
  int right = roman[s.front() - 'A'];
  for (int i = 1; i < s.size(); ++i) {
    int curr = right;
    right = roman[s[i] - 'A'];
    if (right > curr)
      sum -= curr;
    else
      sum += curr;
  }

  return sum + right;
}