#include "stdafx.h"
#include "MaximumProductSubarray.h"

#include <algorithm>

using namespace std;

int Solution::maxProduct(vector<int>& nums) {
  int curMax = nums[0], curMin = nums[0], res = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    int mx = curMax, mn = curMin;
    curMax = max(max(mx * nums[i], mn * nums[i]), nums[i]);
    curMin = min(min(mx * nums[i], mn * nums[i]), nums[i]);
    res = max(res, curMax);
  }
  return res;
}

/*
//When iterating the array, each element has two possibilities: positive number or negative number. 
//We need to track a minimum value, so that when a negative number is given, it can also find the 
//maximum value. We define two local variables, one tracks the maximum and the other tracks the minimum.
int maxProduct(vector<int>& nums) {
  vector<int> maxN(nums.size());
  vector<int> minN(nums.size());

  maxN[0] = minN[0] = nums[0];
  int result = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > 0) {
      maxN[i] = max(nums[i], maxN[i - 1] * nums[i]);
      minN[i] = min(nums[i], minN[i - 1] * nums[i]);
    }
    else {
      maxN[i] = max(nums[i], minN[i - 1] * nums[i]);
      minN[i] = min(nums[i], maxN[i - 1] * nums[i]);
    }

    result = max(result, maxN[i]);
  }

  return result;
}
*/