#include "stdafx.h"
#include "RemoveAllAdjacentDuplicatesInString.h"

// bubble non duplicates to the front
string Solution::removeDuplicates(string S) {
  int start = 0, n = S.length();
  for (int end = 0; end < n; ++end, ++start) {
    S[start] = S[end];
    if (start > 0 && S[start - 1] == S[start]) // count = 2
      start -= 2;
  }
  return S.substr(0, start);
}

/* Keep a res as a characters stack.
// Iterate characters of S one by one.

// If the next character is same as the last character in res,
// pop the last character from res.
// In this way, we remove a pair of adjacent duplicates characters.

// If the next character is different,
// we append it to the end of res.
 string removeDuplicates(string S) {
     string res = "";
     for (char& c : S)
         if (res.size() && c == res.back())
             res.pop_back();
         else
             res.push_back(c);
     return res;
 }
*/