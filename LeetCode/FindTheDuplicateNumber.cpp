#include "stdafx.h"
#include "FindTheDuplicateNumber.h"

#include <unordered_set>
#include <algorithm>

int Solution::findDuplicate(vector<int>& nums) {
  /*
  unordered_set<int> seen;

  for (auto &num : nums) {
    if (seen.count(num)) {
      return num;
    }
    seen.insert(num);
  }

  return -1;
  */

  sort(nums.begin(), nums.end());
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i - 1]) {
      return nums[i];
    }
  }

  return -1;
}