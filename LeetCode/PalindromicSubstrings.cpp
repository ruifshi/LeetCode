#include "stdafx.h"
#include "PalindromicSubstrings.h"


void isPalindrome(string &s, int left, int right, int &count) {
  while (left >= 0 && right < s.length() && s[left] == s[right]) {
    left--;
    right++;
  }
}

int Solution::countSubstrings(string s) {
  if (s == " ") return 0;

  int count = 0;

  for (int i = 0; i < s.size(); i++) {
    //expand around middle for odd and even substrings
    isPalindrome(s, i, i, count);
    isPalindrome(s, i, i + 1, count);
  }

  return count;
}