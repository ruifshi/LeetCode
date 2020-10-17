#include "stdafx.h"
#include "ShortestUnsortedContinuousSubarray.h"

#include <stack>
#include <algorithm>

// From bottom, find num against order and set min index
// From top, findn um against order and set max index
int Solution::findUnsortedSubarray(vector<int>& nums) {
  stack<int> s;
  int l = nums.size();
  for (int i = 0; i < nums.size(); ++i) {
    while (!s.empty() && nums[i] < nums[s.top()]) {
      l = min(l, s.top());
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) s.pop();

  int r = -1;
  for (int i = nums.size() - 1; i >= 0; --i) {
    while (!s.empty() && nums[i] > nums[s.top()]) {
      r = max(r, s.top());
      s.pop();
    }
    s.push(i);
  }

  return (r - l > 0) ? r - l + 1 : 0;
}

/*
    public int findUnsortedSubarray(int[] nums) {
        int[] snums = nums.clone();
        Arrays.sort(snums);
        int start = snums.length, end = 0;
        for (int i = 0; i < snums.length; i++) {
            if (snums[i] != nums[i]) {
                start = Math.min(start, i);
                end = Math.max(end, i);
            }
        }
        return (end - start >= 0 ? end - start + 1 : 0);
*/

/*
find minv which against order
find maxv which against order
find lmost which bigger than minv
find rmost which smaller than maxv
*/
/*
    int findUnsortedSubarray_nospace(vector<int>& nums) {
        int n = nums.size();
        int minv = INT_MAX;
        int maxv = INT_MIN;

        for (int i=1; i<n; ++i) {
            if (nums[i] < nums[i-1]) {
                minv = min(minv, nums[i]);
            }
        }
        for (int i=n-2; i>=0; --i) {
            if (nums[i] > nums[i+1]) {
                maxv = max(maxv, nums[i]);
            }
        }

        int l = 0;
        for (; l<n; ++l) {
            if (minv < nums[l]) break;
        }

        int r = n-1;
        for (; r>=0; --r) {
            if (maxv > nums[r]) break;
        }

        return (r > l) ? r - l + 1 : 0;
    }
*/