#include "stdafx.h"
#include "ReverseStringII.h"

#include <algorithm>

string Solution::reverseStr(string s, int k) {
  if (s.size() == 0) return s;
  if (k == 0) return s;

  for (int i = 0; i < s.length(); i += 2*k) {
    reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
  }

  return s;
}