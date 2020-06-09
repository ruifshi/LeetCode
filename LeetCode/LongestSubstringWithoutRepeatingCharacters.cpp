#include "stdafx.h"
#include "LongestSubstringWithoutRepeatingCharacters.h"

#include <unordered_set>

int Solution::lengthOfLongestSubstring(string s) {
  unordered_set<char> char_count;

  int i = 0, j = 0, max = 0;

  while (i < s.size() && j < s.size()) {
    // have not seen this char before in this window
    // expand the window
    if (char_count.find(s[j]) == char_count.end()) {
      char_count.insert(s[j]);
      max = max > (j - i + 1) ? max : (j - i + 1);
      j++;
    }
    else {
      // already seen this char. shorten window and keep
      // checking
      char_count.erase(s[i]);
      i++;
    }
  }

  return max;
}