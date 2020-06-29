#include "stdafx.h"
#include "ThirdMaximumNumber.h"

#include <set>

int Solution::thirdMax(vector<int>& nums) {
  // use set to keep track of 3 largest numbers
  set<int> top3;
  for (int num : nums) {
    top3.insert(num);
    if (top3.size() > 3)
      top3.erase(top3.begin());
  }
  return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}