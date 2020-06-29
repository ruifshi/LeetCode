#include "stdafx.h"
#include "ValidAnagram.h"

#include <algorithm>
#include <vector>

bool Solution::isAnagram(string s, string t) {
  if (s.size() != t.size()) return false;

  /*
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  return s == t;
  */

  vector<int> table(26, 0);

  for (auto &c : s) {
    table[c - 'a']++;
  }

  for (auto &c : t) {
    table[c - 'a']--;
    if (table[c - 'a'] < 0) {
      return false;
    }
  }

  return true;
}