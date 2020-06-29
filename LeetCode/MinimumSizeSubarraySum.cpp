#include "stdafx.h"
#include "MinimumSizeSubarraySum.h"

#include <algorithm>

// use a sliding window. As soon as we find a sum, shorten left side and calculate
// the size of the subarray
int Solution::minSubArrayLen(int s, vector<int>& nums) {
  int out = INT_MAX;  // size of minimum subarray
  int sum = 0;

  for (int i = 0, start = 0; i < nums.size(); i++) {
    sum += nums[i];
    while (sum >= s) {
      out = min(out, i - start + 1);
      sum -= nums[start];
      start++;
    }
  }

  return out == INT_MAX ? 0 : out;
}