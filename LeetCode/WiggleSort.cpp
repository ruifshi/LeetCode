#include "stdafx.h"
#include "WiggleSort.h"

#include <utility>

// As we iterate through the array, we compare the current element to its next element and if the order is incorrect, we swap them.
// for even indices, first number needs to be smaller
// for odd, larger
void Solution::wiggleSort(vector<int>& nums) {
  if (nums.size() == 0) return;

  for (int i = 0; i < nums.size() - 1; i++) {
    if (((i % 2 == 0) && nums[i] > nums[i + 1])
      || ((i % 2 == 1) && nums[i] < nums[i + 1])) {
      swap(nums[i], nums[i + 1]);
    }
  }
}

/* brute force
public void wiggleSort(int[] nums) {
    Arrays.sort(nums);
    for (int i = 1; i < nums.length - 1; i += 2) {
        swap(nums, i, i + 1);
    }
}
*/