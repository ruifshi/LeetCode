#include "stdafx.h"
#include "MajorityElement.h"

#include <unordered_map>
#include <algorithm>

int Solution::majorityElement(vector<int>& nums) {
  unordered_map<int, int> mp; // integer to count
  for (auto &n : nums) {
    mp[n]++;
  }

  int majority = nums.size() / 2;
  int ans = 0;
  for (auto &v : mp) {
    if (v.second > majority && v.second > ans) {
      ans = v.first;
    }
  }

  return ans;
}

/*
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}
*/