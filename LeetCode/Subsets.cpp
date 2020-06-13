#include "stdafx.h"
#include "Subsets.h"

// backtrack
// each loop will remove on element and try all other combos
void subsetsHelper(vector<int>& nums, vector<vector<int>> &res, vector<int> &curr, int pos) {
  res.push_back(curr);

  for (int i = pos; i < nums.size(); i++) {
    curr.push_back(nums[i]);
    subsetsHelper(nums, res, curr, i + 1);
    curr.pop_back();
  }
}

vector<vector<int>> Solution::subsets(vector<int>& nums) {
  vector<vector<int>> res;
  vector<int> curr;

  subsetsHelper(nums, res, curr, 0);

  return res;
}