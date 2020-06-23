#include "stdafx.h"
#include "LongestContinuousIncreasingSubsequence.h"

int findLengthOfLCIS(vector<int>& nums) {
  if (nums.size() == 0) return 0;

  int max = 1;
  int count = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > nums[i - 1]) {
      count++;
    }
    else {
      count = 1;
    }

    max = max > count ? max : count;
  }

  return max;
}