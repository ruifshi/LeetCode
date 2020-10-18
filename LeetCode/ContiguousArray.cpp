#include "stdafx.h"
#include "ContiguousArray.h"

#include <unordered_map>
#include <algorithm>

int Solution::findMaxLength(vector<int>& nums) {
  unordered_map<int, int> mp;
  int maxlen = 0, count = 0;
  for (int i = 0;i < nums.size();i++) {
    count += (nums[i] == 1) ? 1 : -1;
    // Array from index 0 to i contains equal number of 0's and 1's
    if (count == 0)
      maxlen = max(maxlen, i + 1);
    if (mp.find(count) != mp.end()) { // if we get back to same level as previously found, that means the stretch was = 0
      maxlen = max(maxlen, i - mp[count]);
    }
    else
      mp[count] = i;
  }
  return maxlen;
}