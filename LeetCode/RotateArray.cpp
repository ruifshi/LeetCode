#include "stdafx.h"
#include "RotateArray.h"

void reverse(vector<int> &nums, int start, int end) {
  while (start < end) {
    int temp = nums[start];
    nums[start] = nums[end];
    nums[end] = temp;
    start++;
    end--;
  }
}

void Solution::rotate(vector<int>& nums, int k) {
  /*
  vector<int> a(nums.size(), 0);

  // use extra array to store numbers in proper place
  for (int i = 0; i < nums.size(); i++) {
    a[(i + k) % nums.size()] = nums[i];
  }

  for (int i = 0; i < nums.size(); i++) {
    nums[i] = a[i];
  }
  */

  //This approach is based on the fact that when we rotate the array k times, k%nk elements from the back end of the array come to the front and the rest of the elements from the front shift backwards.
  k %= nums.size();
  reverse(nums, 0, nums.size() - 1);
  reverse(nums, 0, k - 1);
  reverse(nums, k, nums.size() - 1);
}