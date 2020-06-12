#include "stdafx.h"
#include "BackspaceStringCompare.h"

string processString(string s) {
  int start = 0;

  // bubble valid chars to the front
  for (int i = 0; i < s.size(); i++) {
    // if not # then keep the character
    if (s[i] != '#') {
      s[start] = s[i];
      start++;
    }
    // if #, then override previous char
    else if (s[i] == '#' && start - 1 >= 0) {
      start--;
    }
  }

  return s.substr(0, start);
}

bool Solution::backspaceCompare(string S, string T) {
  return processString(S) == processString(T);
}