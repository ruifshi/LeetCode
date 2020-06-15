#include "stdafx.h"
#include "IncreasingTripletSubsequence.h"

bool Solution::increasingTriplet(vector<int>& nums) {
  if (nums.size() < 3) {
    return false;
  }

  int c1 = INT_MAX, c2 = INT_MAX;
  for (int x : nums) {
    if (x <= c1) {
      c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
    }
    else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
      c2 = x;           // x is better than the current c2, store it
    }
    else {              // here when we have/had c1 < c2 already and x > c2
      return true;      // the increasing subsequence of 3 elements exists
    }
  }
  return false;
}

/*
bool increasingTriplet(vector<int> nums) {
  int k = 3;
  vector<int> candidate(k-1, INT_MAX);

  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < k - 1; j++) {
      // populates 1st and 2nd numbers in ascending order
      if (nums[i] <= candidate[j]) {
        candidate[j] = nums[i];
        break;
      }
      else if (j == k - 2) return true; // if we get to this index, that means 1st 2 numbers were found
    }
  }
  return false;
}
*/