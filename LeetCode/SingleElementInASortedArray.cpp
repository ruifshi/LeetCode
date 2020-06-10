#include "stdafx.h"
#include "SingleElementInASortedArray.h"

/*
int singleNonDuplicate(vector<int>& nums) {
  for (int i = 0; i < nums.size() - 1; i += 2) {
    if (nums[i] != nums[i + 1]) {
      return nums[i];
    }
  }
  return nums.back();
}
*/

// We know the array contains an odd number of elements since
// all pairs + 1 non-pair.
// We can binary search only the even indices. If we find that
// a number does not equal the previous, then we know that
// the left side contained the single number
int Solution::singleNonDuplicate(vector<int>& nums) {
  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (mid % 2 == 1) mid--;
    if (nums[mid] == nums[mid + 1]) {
      left = mid + 2;
    }
    else {
      right = mid;
    }
  }

  return nums[left];
}