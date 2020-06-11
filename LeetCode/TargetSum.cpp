#include "stdafx.h"
#include "TargetSum.h"

// O(nums.size() * number of sums)
int findTargetSumWaysHelper(vector<int>& nums, int &S, int index, int cur_sum, vector<vector<int>> &memo) {
  if (index == nums.size()) {
    if (cur_sum == S) {
      return 1;
    }
    return 0;
  }

  int col = cur_sum + 1000; // to offset negative numbers
  if (memo[index][col] != INT_MIN) {
    return memo[index][col];
  }

  int plus_cnt = findTargetSumWaysHelper(nums, S, index + 1, cur_sum + nums[index], memo);
  int minus_cnt = findTargetSumWaysHelper(nums, S, index + 1, cur_sum - nums[index], memo);
  memo[index][col] = plus_cnt + minus_cnt;
  return plus_cnt + minus_cnt;
}

int Solution::findTargetSumWays(vector<int>& nums, int S) {
  // row = current index in array, col = different sums you can have
  // sun range is [-1000, 1000] so 2001 entries
  // value stored is the count for that index/sum
  vector<vector<int>> memo(nums.size(), vector<int>(2001, INT_MIN));  
  return findTargetSumWaysHelper(nums, S, 0, 0, memo);
}

/* O(2^n)
void findTargetSumWaysHelper(vector<int>& nums, int &S, int index, int cur_sum, int &count) {
  if (index == nums.size()) {
    if (cur_sum == S) count++;
  }
  else {
    findTargetSumWaysHelper(nums, S, index + 1, cur_sum + nums[index], count);
    findTargetSumWaysHelper(nums, S, index + 1, cur_sum - nums[index], count);
  }
}

int Solution::findTargetSumWays(vector<int>& nums, int S) {
  int count = 0;
  findTargetSumWaysHelper(nums, S, 0, 0, count);
  return count;
}
*/