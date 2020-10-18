#include "stdafx.h"
#include "MajorityElementII.h"

// use hashmap to calculate occurance and output

/*
The idea is to split the array into three parts according to the selected pivot: left, middle and right.

Let's say we have two indices m and n, so that all elements in [0 ... m-1] are less than the pivot, elements in [m...n] are equal to the pivot (two ends inclusive), [n+1 ... end] contains elements greater than the pivot. Then there are some facts:

if n - m + 1 >= 1 + nums.size()/3, nums[m] must be added to the
results.
If m - 1 < 1 + nums.size()/3, we can simply abandon the left part, otherwise we have to consider it.
if nums.size()-n < 1+nums.size()/3, the right part can be dropped, otherwise it has to be checked.
*/
void split(vector<int>& nums, int left, int right, int len, vector<int>& ans) {
  if (left >= right) return;
  int idx = (left + right) / 2, val = nums[idx], i = left + 1, j = left, k = left;
  swap(nums[idx], nums[left]);
  while (i < nums.size()) {
    if (nums[i] < val) {
      swap(nums[k++], nums[i]);
      swap(nums[++j], nums[i++]);
    }
    else if (nums[i] == val) {
      swap(nums[i++], nums[++j]);
    }
    else i++;
  }
  if (j - k + 1 >= len) ans.push_back(nums[k]);
  if (k - left >= len) split(nums, left, k, len, ans);
  if (right - j >= len) split(nums, j + 1, right, len, ans);
}

vector<int> Solution::majorityElement(vector<int>& nums) {
  vector<int> ans;
  if (nums.empty()) return ans;
  split(nums, 0, nums.size(), 1 + nums.size() / 3, ans);
  return ans;
}