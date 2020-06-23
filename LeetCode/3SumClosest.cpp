#include "stdafx.h"
#include "3SumClosest.h"

#include <algorithm>

int Solution::threeSumClosest(vector<int>& nums, int target) {
  int diff = INT_MAX;

  sort(nums.begin(), nums.end());

  // fix 2 numbers and find the 3rd
  for (int i = 0; i < nums.size(); i++) {
    int left = i + 1, right = nums.size() - 1;

    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];

      if (abs(target - sum) < abs(diff)) {
        diff = target - sum;
      }

      // since sorted
      if (sum < target) {
        left++;
      }
      else {
        right--;
      }
    }
  }

  return target - diff;
}