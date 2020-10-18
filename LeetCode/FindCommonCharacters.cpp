#include "stdafx.h"
#include "FindCommonCharacters.h"

#include <algorithm>

/*
For each string, we count characters in cnt1. Then, we track the minimum count for each character in cnt.
only common chars will be nonzero
*/
vector<string> Solution::commonChars(vector<string>& A) {
  vector<int> cnt(26, INT_MAX);
  vector<string> res;
  for (auto s : A) {
    vector<int> cnt1(26, 0);
    for (auto c : s) ++cnt1[c - 'a'];
    for (auto i = 0; i < 26; ++i) cnt[i] = min(cnt[i], cnt1[i]);
  }
  for (auto i = 0; i < 26; ++i)
    for (auto j = 0; j < cnt[i]; ++j) res.push_back(string(1, i + 'a'));
  return res;
}