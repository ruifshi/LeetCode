#include "stdafx.h"
#include "NextGreaterElementII.h"

vector<int> Solution::nextGreaterElements(vector<int>& nums) {
  vector<int> res(nums.size(), -1);

  for (int i = 0; i < nums.size(); i++) {
    // iterate for all elements past i and looping back
    for (int j = 1; j < nums.size(); j++) {
      if (nums[(i + j) % nums.size()] > nums[i]) {
        res[i] = nums[(i + j) % nums.size()];
        break;
      }
    }
  }

  return res;
}