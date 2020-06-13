#include "stdafx.h"
#include "IntersectionOfTwoArraysII.h"

#include <unordered_map>

// use hashmap to keep track of number of same numbers
vector<int> Solution::intersect(vector<int>& nums1, vector<int>& nums2) {
  if (nums1.size() == 0 || nums2.size() == 0) return {};

  unordered_map<int, int> table;
  vector<int> res;

  for (int i = 0; i < nums1.size(); i++) {
    table[nums1[i]]++;
  }

  for (int i = 0; i < nums2.size(); i++) {
    if (table[nums2[i]] > 0) {
      table[nums2[i]]--;
      res.push_back(nums2[i]);
    }
  }

  return res;
}