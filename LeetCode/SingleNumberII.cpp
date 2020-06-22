#include "stdafx.h"
#include "SingleNumberII.h"

#include "unordered_map"

int Solution::singleNumber2(vector<int>& nums) {
  unordered_map<int, int> mp;

  for (int i = 0; i < nums.size(); i++) {
    mp[nums[i]]++;
  }

  for (auto &x : mp) {
    if (x.second == 1) return x.first;
  }

  return -1;
}

/*
class Solution {
  public int singleNumber(int[] nums) {
    int seenOnce = 0, seenTwice = 0;

    for (int num : nums) {
      // first appearence:
      // add num to seen_once
      // don't add to seen_twice because of presence in seen_once

      // second appearance:
      // remove num from seen_once
      // add num to seen_twice

      // third appearance:
      // don't add to seen_once because of presence in seen_twice
      // remove num from seen_twice
      seenOnce = ~seenTwice & (seenOnce ^ num);
      seenTwice = ~seenOnce & (seenTwice ^ num);
    }

    return seenOnce;
  }
}
*/