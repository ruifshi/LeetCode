#include "stdafx.h"
#include "FindFirstAndLastPositionOfElementInSortedArray.h"

int binarySearch(vector<int>& nums, int target) {
  int l = 0, r = nums.size() - 1;

  while (l < r) {
    int mid = l + (r - l) / 2;
    if (nums[mid] < target) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  return l;
}

vector<int> Solution::searchRange(vector<int>& nums, int target) {
  int index1 = binarySearch(nums, target);
  int index2 = binarySearch(nums, target+1) - 1;

  if (index1 < nums.size() && nums[index1] == target) {
    return { index1, index2 };
  }
  
  return { -1,-1 };
}