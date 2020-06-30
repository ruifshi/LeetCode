#include "stdafx.h"
#include "FindMinimumInRotatedSortedArrayII.h"

/*
If we guess mi,
if nums[mi] > nums[hi], min should be always in [mi + 1, hi] (explained in Essence). To satisfy the invariant, lo = mi + 1;
else if nums[mi] < nums[lo], min should be always in [lo + 1, mi] (explained in Essence), to satisfy the assertion, hi = mi, lo = lo + 1;
else (nums[lo] <= nums[mi] <= nums[hi]) min should be always nums[lo].
After the loop, lo = hi, min should be in [lo, lo], to satisfy the assertion, min = lo.
*/
int Solution::findMin(vector<int>& nums) {
  int lo = 0, hi = nums.size() - 1;
  while (lo < hi) {
    int mi = lo + (hi - lo) / 2;
    if (nums[mi] > nums[hi]) {
      lo = mi + 1;
    }
    else if (nums[mi] < nums[lo]) {
      hi = mi;
      lo++;
    }
    else { // nums[lo] <= nums[mi] <= nums[hi] 
      hi--;
    }
  }

  return nums[lo];
}

/* O(n)
int findMin(vector<int>& nums) {
  int min = nums[0];
  for (int val : nums)
  {
    if (min > val)
    {
      min = val;
    }
  }

  return min;
}
*/