#include "stdafx.h"
#include "ShuffleAnArray.h"

//vector<int> nums;

Solution::Solution(vector<int>& nums) {
  this->nums = nums;
}

/** Resets the array to its original configuration and return it. */
vector<int> Solution::reset() {
  return this->nums;
}

/** Returns a random shuffling of the array. */
vector<int> Solution::shuffle() {
  vector<int> result(nums);
  for (int i = 0;i < result.size();i++) {
    int pos = rand() % (result.size() - i);
    swap(result[i + pos], result[i]);
  }
  return result;
}