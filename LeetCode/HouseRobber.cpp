#include "stdafx.h"
#include "HouseRobber.h"

#include <algorithm>

int Solution::rob1(vector<int>& nums) {
  int prevMax = 0;
  int currMax = 0;
  for (int x : nums) {
    int temp = currMax;
    currMax = max(prevMax + x, currMax);
    prevMax = temp;
  }
  return currMax;
}