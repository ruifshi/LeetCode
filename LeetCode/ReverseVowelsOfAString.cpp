#include "stdafx.h"
#include "ReverseVowelsOfAString.h"

bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
      c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    return true;
  }

  return false;
}

string Solution::reverseVowels(string s) {
  if (s == "") return s;

  int i = 0, j = s.size() - 1;

  while (i < j) {
    while (i < j && !isVowel(s[i])) i++;
    while (i < j && !isVowel(s[j])) j--;

    swap(s[i++], s[j--]);
  }

  return s;
}