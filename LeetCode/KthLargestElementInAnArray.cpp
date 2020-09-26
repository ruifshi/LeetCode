#include "stdafx.h"
#include "KthLargestElementInAnArray.h"

#include <queue>

// O(nlogn) due to sorting
int Solution::findKthLargest(vector<int>& nums, int k) {
	/*
  priority_queue<int, vector<int>, greater<int>> q;

  for(int i = 0; i < nums.size(); i++) {
    q.push(nums[i]);
    if(q.size() > k) q.pop();
  }

  return q.top();
	*/

	sort (nums.begin(), nums.end());
        
  return nums[nums.size()-k];
}

/*
int kClosestHelper(vector<int>& nums, int l, int r) {
  // choose a pivot
  int pivot = nums[l];

  while (l < r) {
    // iterate right until we find element smaller
    while (l < r && pivot < nums[r])
      r--;

    // found a element in right half smaller, move it to left
    nums[l] = nums[r];

    // iterate left until we find element bigger, skip same elements
    while (l < r && nums[l] <= pivot)
      l++;

    // found element in left half bigger, move to right
    nums[r] = nums[l];
  }

  // left now points to largest element smaller than pivot
  // add pivot back
  nums[l] = pivot;
  return l;
}

int findKthLargest(vector<int>& nums, int k) {
    int len = nums.size(), l = 0, r = nums.size() - 1, mid = 0;
    int target = len - k;

    while(l<=r) {
        // binary search until we find pivot that is kth element
        mid = kClosestHelper(nums, l, r);
        if (mid == target) break;
        if (mid < target) {
          l = mid + 1;
        }
        else {
          r = mid - 1;
        }
    }

    return nums[mid];
}
*/