#include "stdafx.h"
#include "RunningSumOf1dArray.h"

vector<int> Solution::runningSum(vector<int>& nums) {
  for (int i = 1; i < nums.size(); ++i)
    nums[i] += nums[i - 1];

  return nums;
}