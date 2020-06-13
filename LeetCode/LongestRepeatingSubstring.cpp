#include "stdafx.h"
#include "LongestRepeatingSubstring.h"

#include <set>

int search(int L, int n, string S) {
  set<string> seen;
  string tmp;
  for (int start = 0; start < n - L + 1; ++start) {
    tmp = S.substr(start, L);
    if (seen.count(tmp)) return start;
    seen.insert(tmp);
  }
  return -1;
}

// O(n^2) time and space
int Solution::longestRepeatingSubstring(string S) {
  int n = S.length();
  // binary search, L = repeating string length
  // max repeating length if half of the string
  // search function iterates through all substrings
  // of length L to see if there are any repeats
  // if no, then L was too big so decrement
  int left = 1, right = n;
  int L;
  while (left <= right) {
    L = left + (right - left) / 2;
    if (search(L, n, S) != -1) left = L + 1;
    else right = L - 1;
  }

  return left - 1;
}