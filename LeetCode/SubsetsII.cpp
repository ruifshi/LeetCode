#include "stdafx.h"
#include "SubsetsII.h"

#include <algorithm>

void subsetsWithDupHelper(vector<vector<int> > &res, vector<int> &nums, vector<int> &vec, int begin) {
  res.push_back(vec);
  for (int i = begin; i != nums.size(); ++i)
    // for duplicate numbers, only process the first one
    if (i == begin || nums[i] != nums[i - 1]) {
      vec.push_back(nums[i]);
      subsetsWithDupHelper(res, nums, vec, i + 1);
      vec.pop_back();
    }
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
  // sort values so we can process duplicates in the recursion
  sort(nums.begin(), nums.end());
  vector<vector<int> > res;
  vector<int> vec;
  subsetsWithDupHelper(res, nums, vec, 0);
  return res;
}