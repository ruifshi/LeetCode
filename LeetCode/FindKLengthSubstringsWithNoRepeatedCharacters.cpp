#include "stdafx.h"
#include "FindKLengthSubstringsWithNoRepeatedCharacters.h"

#include <unordered_set>

int Solution::numKLenSubstrNoRepeats(string S, int K) {
  unordered_set<char> seen;
  int ans = 0;

  for (int start = 0, end = 0; end < S.length(); end++) {
    while (seen.find(S[end]) != seen.end()) { // if duplicate char in window, shrink the window
      seen.erase(S[start++]);
    }

    seen.insert(S[end]);  //insert unique char

    if (seen.size() > K) {  //window too big, shrink it
      seen.erase(S[start++]);
    }

    if (seen.size() == K) {  //current window found
      ans++;
    }
  }

  return ans;
}