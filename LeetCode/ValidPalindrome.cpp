#include "stdafx.h"
#include "ValidPalindrome.h"

bool Solution::isPalindrome(string s) {
  int front = 0, end = s.size() - 1;

  while (front < end) {
    if (!isalnum(s[front])) { front++; continue; }
    if (!isalnum(s[end])) { end--; continue; }

    if (tolower(s[front]) == tolower(s[end])) {
      front++;
      end--;
    }
    else
    {
      return false;
    }
  }

  return true;
}