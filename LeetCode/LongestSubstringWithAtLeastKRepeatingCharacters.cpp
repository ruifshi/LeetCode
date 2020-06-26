#include "stdafx.h"
#include "LongestSubstringWithAtLeastKRepeatingCharacters.h"

#include <algorithm>

int Solution::longestSubstring(string s, int k) {
  int max_len = 0;
  // iterate over all subsequences
  for (int first = 0; first + k <= s.size();) {
    int count[26] = { 0 };
    int mask = 0;
    int max_last = first;
    // keep track of the number of characters previously seen in count
    // and unique chars in mask
    // once a character reaches k limit, we check if there exists another
    // char in mask that's under the limit to continue
    // once mask is 0, then we calculate the max length
    for (int last = first; last < s.size(); ++last) {
      int i = s[last] - 'a';
      count[i]++;
      if (count[i] < k) mask |= (1 << i);
      else   mask &= (~(1 << i));

      if (mask == 0) {
        max_len = max(max_len, last - first + 1);
        max_last = last;
      }
    }
    // if a locally longest substr is found, there's no need to check substrs overlapping it
    first = max_last + 1;
  }
  return max_len;
}

/*
//in the first pass I record counts of every character in a hashmap
//in the second pass I locate the first character that appear less than k times in the string. this character is definitely not included in the result, and that separates the string into two parts.
//keep doing this recursively and the maximum of the left/right part is the answer.

int longestSubstring(string s, int k) {
  if (s.size() == 0 || k > s.size())   return 0;
  if (k == 0)  return s.size();

  int Map[26] = { 0 };
  for (int i = 0; i < s.size(); i++) {
    Map[s[i] - 'a']++;
  }

  int idx = 0;
  while (idx < s.size() && Map[s[idx] - 'a'] >= k)    idx++;
  if (idx == s.size()) return s.size();

  int left = longestSubstring(s.substr(0, idx), k);
  int right = longestSubstring(s.substr(idx + 1), k);

  return max(left, right);
}
*/