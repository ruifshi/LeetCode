#include "stdafx.h"
#include "LongestIncreasingSubsequence.h"

#include <algorithm>

// returns length from prev indx to current
int lenHelper(vector<int> &nums, int prevIdx, int currIdx, vector<vector<int>> &memo) {
  if (currIdx == nums.size()) {
    return 0;
  }

  if (memo[prevIdx + 1][currIdx] >= 0) {
    return memo[prevIdx + 1][currIdx];
  }

  int taken = 0;
  if (prevIdx < 0 || nums[currIdx] > nums[prevIdx]) {
    taken = 1 + lenHelper(nums, currIdx, currIdx + 1, memo);
  }

  int notTaken = lenHelper(nums, prevIdx, currIdx + 1, memo);

  memo[prevIdx + 1][currIdx] = max(taken, notTaken);
  return memo[prevIdx + 1][currIdx];
}

/* O(n^2) for both since memo table
memo[i][j] represents the length of the LIS possible using nums[i] as the previous element considered to 
be included/not included in the LIS, with nums[j] as the current element considered to be included/not included in the LIS
*/
int Solution::lengthOfLIS(vector<int>& nums) {
  vector<vector<int>> memo(nums.size() + 1, vector<int>(nums.size(), -1));

  return lenHelper(nums, -1, 0, memo);
}

/* brute force, 2 cases
// include current number
// don't include current
// O(2^n)
// O(n^2) space
public class Solution {

    public int lengthOfLIS(int[] nums) {
        return lengthofLIS(nums, Integer.MIN_VALUE, 0);
    }

    public int lengthofLIS(int[] nums, int prev, int curpos) {
        if (curpos == nums.length) {
            return 0;
        }
        int taken = 0;
        if (nums[curpos] > prev) {
            taken = 1 + lengthofLIS(nums, nums[curpos], curpos + 1);
        }
        int nottaken = lengthofLIS(nums, prev, curpos + 1);
        return Math.max(taken, nottaken);
    }
}
*/