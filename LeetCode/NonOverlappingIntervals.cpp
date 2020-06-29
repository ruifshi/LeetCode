#include "stdafx.h"
#include "NonOverlappingIntervals.h"

#include <algorithm>

// sort by start
bool mycomp(vector<int> &a, vector<int> &b) {
  return a[0] < b[0];
}

int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals) {
  if (intervals.size() == 0 || intervals.size() == 1) return 0;

  sort(intervals.begin(), intervals.end(), mycomp);

  int count = 0, prev = 0;
  for (int i = 1; i < intervals.size(); i++) {
    // prev block extends into next
    if (intervals[prev][1] > intervals[i][0]) {
      // if previous block completely covers next,
      // we choose the smaller one (next)
      if (intervals[prev][1] > intervals[i][1]) {
        prev = i;
      }
      // otherwise we keep the first one because the
      // later pieces would extend further
      count++;
    }
    // no intersections
    else {
      prev = i;
    }
  }
  
  return count;
}