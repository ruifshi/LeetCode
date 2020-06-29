#include "stdafx.h"
#include "PalindromePermutation.h"

#include <unordered_set>

// O(n), O(1) space since only bounded number of letters
bool Solution::canPermutePalindrome(string s) {
  unordered_set<char> charSet;

  for (auto &c : s) {
    if (charSet.find(c) != charSet.end()) {
      charSet.erase(c);
    }
    else {
      charSet.insert(c);
    }
  }

  return charSet.size() <= 1;
}