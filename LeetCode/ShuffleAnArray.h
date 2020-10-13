#pragma once

#include <vector>

using namespace std;

class Solution {
private:
  vector<int> nums;
public:
  Solution(vector<int>& nums);

  /** Resets the array to its original configuration and return it. */
  vector<int> reset();

  /** Returns a random shuffling of the array. */
  vector<int> shuffle();
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */