#include "stdafx.h"
#include "MaximumLengthOfPairChain.h"

#include <algorithm>

bool mycomp(const vector<int> &pair1, const vector<int> &pair2) {
  return pair1[1] < pair2[1];
}

int findLongestChain(vector<vector<int>>& pairs) {
  // sort according to end of the pairs then we check
  // if end if smaller than next begin
  sort(pairs.begin(), pairs.end(), mycomp);
  int cur = INT_MIN, ans = 0;

  for (auto &p : pairs) {
    if (cur < p[0]) {
      cur = p[1];
      ans++;
    }
  }

  return ans;
}