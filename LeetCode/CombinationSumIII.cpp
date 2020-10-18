#include "stdafx.h"
#include "CombinationSumIII.h"

void combinationSum3Util(int l, int k, int n, vector<int>& v, vector<vector<int>>& ans) {

  if (v.size() == k && n == 0) {
    ans.push_back(v);
    return;
  }

  for (int i = l; i < 9; i++) {
    v.push_back(i);
    combinationSum3Util(i + 1, k, n - i, v, ans);
    v.pop_back();
  }
}

vector<vector<int>> Solution::combinationSum3(int k, int n) {
  vector<int>v;
  vector<vector<int>>ans;

  combinationSum3Util(1, k, n, v, ans);
  return ans;
}