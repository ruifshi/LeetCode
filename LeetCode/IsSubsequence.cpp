#include "stdafx.h"
#include "IsSubsequence.h"

bool isSubsequence(string s, string t) {
  int sptr = 0, tptr = 0;

  while (sptr < s.size() && tptr < t.size()) {
    // when we find a match, increment both pointers
    // else, just skip char in t
    if (s[sptr] == t[tptr]) {
      sptr++;
    }

    tptr++;
  }

  return sptr == s.size();
}