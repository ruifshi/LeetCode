#include "stdafx.h"
#include "BreakAPalindrome.h"

/*
Check half of the string,
replace a non 'a' character to 'a'.

If only one character, return empty string.
Otherwise repalce the last character to 'b'
*/
string Solution::breakPalindrome(string palindrome) {
  int n = palindrome.size();
  for (int i = 0; i < n / 2; ++i) {
    if (palindrome[i] != 'a') {
      palindrome[i] = 'a';
      return palindrome;
    }
  }
  palindrome[n - 1] = 'b';
  return n < 2 ? "" : palindrome;
}