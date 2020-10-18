#include "stdafx.h"
#include "HowManyNumbersAreSmallerThanTheCurrent Number.h"

#include <unordered_map>

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
  int n = (int)nums.size(), max = 0;
  unordered_map<int, int> freq;
  unordered_map<int, int> pref;
  for (auto &val : nums) {
    freq[val] += 1;
    max = max > val ? max : val;
  }

  // take prefix sum of freq array
  // then preq[i] will tell us number of element that 
  // are less than it in the nums array 
  for (int i = 1; i <= max; i++) {
    pref[i] = pref[i - 1] + freq[i - 1];
  }

  vector<int> ans(n);
  // now we care for only those indices in freq
  // that occur in nums
  for (int i = 0; i < n; i++) {
    ans[i] = pref[nums[i]];
  }

  return ans;
}

/*
    vector<int> smallerNumbersThanCurrent(vector<int>& nums)
    {
      vector<int>v;
      int c=0;
      for(int i=0;i<nums.size();i++)
      {
        for(int j=0;j<nums.size();j++)
        {
          if(nums[i]>nums[j])
            c++;
        }
         v.push_back(c);
        c=0;
      }
      return v;
    }
*/