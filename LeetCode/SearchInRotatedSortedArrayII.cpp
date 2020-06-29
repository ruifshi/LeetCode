#include "stdafx.h"
#include "SearchInRotatedSortedArrayII.h"

bool Solution::search2(vector<int>& nums, int target) {
  int l = 0, r = nums.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (target == nums[mid])
      return true;

    // the only difference from the first one, trickly case, just updat left and right
    if ((nums[l] == nums[mid]) && (nums[r] == nums[mid])) { ++l; --r; }
    // there exists rotation; the middle element is in the left part of the array
    else if (nums[mid] > nums[r]) {
      if (target < nums[mid] && target >= nums[l])
        r = mid - 1;
      else
        l = mid + 1;
    }
    // there exists rotation; the middle element is in the right part of the array
    else if (nums[mid] < nums[l]) {
      if (target > nums[mid] && target <= nums[r])
        l = mid + 1;
      else
        r = mid - 1;
    }
    // there is no rotation; just like normal binary search
    else {
      if (target < nums[mid])
        r = mid - 1;
      else
        l = mid + 1;
    }
  }
  return false;
}