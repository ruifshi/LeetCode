#include "stdafx.h"
#include "DecodeString.h"

string helper(const string& s, int& i) {
  string res;

  while (i < s.length() && s[i] != ']') {
    if (!isdigit(s[i]))
      res += s[i++];
    else {
      int n = 0;
      while (i < s.length() && isdigit(s[i]))
        n = n * 10 + s[i++] - '0';

      i++; // '['
      string t = helper(s, i);
      i++; // ']'

      while (n-- > 0)
        res += t;
    }
  }

  return res;
}

string decodeString(string s) {
  int i = 0;
  return helper(s, i);
}