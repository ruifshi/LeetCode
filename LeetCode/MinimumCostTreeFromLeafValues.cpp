#include "stdafx.h"
#include "MinimumCostTreeFromLeafValues.h"

#include <algorithm>

/*
https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/340489/Summary-and-reasoning-of-different-solutions
*/

int mctFromLeafValues(vector<int>& arr) {
  int res = 0;
  vector<int> stack = { INT_MAX };
  for (int a : arr) {
    while (stack.back() <= a) {
      int mid = stack.back();
      stack.pop_back();
      res += mid * min(stack.back(), a);
    }
    stack.push_back(a);
  }
  for (int i = 2; i < stack.size(); ++i) {
    res += stack[i] * stack[i - 1];
  }
  return res;
}