#include "stdafx.h"
#include "JumpGame.h"

bool Solution::canJump(vector<int>& nums) {
  int lastIdx = nums.size() - 1;

  // start from end and see previous steps can reach
  for (int i = nums.size() - 1; i >= 0; i--) {
    if (i + nums[i] >= lastIdx) {
      lastIdx = i;
    }
  }

  return lastIdx == 0;
}