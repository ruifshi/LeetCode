#include "stdafx.h"
#include "SlidingWindowMedian.h"

#include <algorithm>
#include <set>

/*
Adding number 41
MaxHeap lo: [41]           // MaxHeap stores the largest value at the top (index 0)
MinHeap hi: []             // MinHeap stores the smallest value at the top (index 0)
Median is 41
=======================
Adding number 35
MaxHeap lo: [35]
MinHeap hi: [41]
Median is 38
=======================
Adding number 62
MaxHeap lo: [41, 35]
MinHeap hi: [62]
Median is 41
=======================
Adding number 4
MaxHeap lo: [35, 4]
MinHeap hi: [41, 62]
Median is 38
=======================
Adding number 97
MaxHeap lo: [41, 35, 4]
MinHeap hi: [62, 97]
Median is 41
=======================
Adding number 108
MaxHeap lo: [41, 35, 4]
MinHeap hi: [62, 97, 108]
Median is 51.5
*/

// nlogk
vector<double> Solution::medianSlidingWindow(vector<int>& nums, int k) {
  vector<double> medians;
  multiset<int> lo, hi;

  for (int i = 0; i < nums.size(); i++) {
    //remove outgoing element
    if (i >= k) {
      if (nums[i - k] <= *lo.rbegin())
        lo.erase(lo.find(nums[i - k]));
      else
        hi.erase(hi.find(nums[i - k]));
    }

    // insert incoming element
    lo.insert(nums[i]);

    // balance the sets
    hi.insert(*lo.rbegin());
    lo.erase(prev(lo.end()));

    if (lo.size() < hi.size()) {
      lo.insert(*hi.begin());
      hi.erase(hi.begin());
    }

    // get median
    if (i >= k - 1) {
      medians.push_back(k & 1 ? *lo.rbegin() : ((double)(*lo.rbegin()) + (double)(*hi.begin())) * 0.5);
    }
  }

  return medians;
}

/* simple sorting n*klogk
vector<double> Solution::medianSlidingWindow(vector<int>& nums, int k) {
  vector<double> medians;

  for (int i = 0; i + k <= nums.size(); i++) {
    vector<int> window(nums.begin() + i, nums.begin() + i + k);

    sort(window.begin(), window.end());

    if (k & 1)
      medians.push_back(window[k / 2]);
    else
      medians.push_back((double)(window[k / 2 - 1] + (double)window[k / 2]) / 2.0);
  }

  return medians;
}
*/