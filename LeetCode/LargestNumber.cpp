#include "stdafx.h"
#include "LargestNumber.h"

#include <algorithm>

bool comp(int &a, int &b) {
  return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string Solution::largestNumber(vector<int>& nums) {
  if (nums.size() == 0) return "";

  sort(nums.begin(), nums.end(), comp);

  string s;

  for (int i = 0; i < nums.size(); i++) {
    s += to_string(nums[i]);
  }

  if (s[0] == '0') return "0";

  return s;
}