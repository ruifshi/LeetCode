#include "stdafx.h"
#include "MissingRanges.h"

#include <vector>
#include <string>

string getRange(long start, long end) {
  return (start == end) ? to_string(start) : to_string(start) + "->" + to_string(end);
}

vector<string> Solution::findMissingRanges(vector<int>& nums, int lower, int upper) {
  vector<string> out;
  long prev = 0, curr = 0;

  for (int i = 0; i <= nums.size(); i++) {
    // lower end of the range, which is 1 more than previous number
    if (i == 0) {
      prev = lower;
    }
    else {
      prev = long(nums[i - 1]) + 1;
    }

    // higher end of the range, which is 1 less than current number
    if (i == nums.size()) {
      curr = upper;
    }
    else {
      curr = long(nums[i]) - 1;
    }

    // if previous number and current number have a difference, then there are missing number
    if (prev <= curr) {
      out.push_back(getRange(prev, curr));
    }
  }

  return out;
}