#include "stdafx.h"
#include "MissingNumber.h"

#include <unordered_set>

int Solution::missingNumber(vector<int>& nums) {
  unordered_set<int> uniqueNums(nums.begin(), nums.end());

  for (int i = 0; i <= nums.size(); i++) {
    if (uniqueNums.find(i) == uniqueNums.end()) return i;
  }

  return -1;
}

/*
int missingNumber(vector<int>& nums) {
  int n = nums.size();
  int totalSum = n*(n+1)/2;

  int currSum = 0;
  for(auto &num : nums) currSum += num;
  return totalSum - currSum;
}
*/