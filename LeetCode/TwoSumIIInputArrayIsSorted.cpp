#include "stdafx.h"
#include "TwoSumIIInputArrayIsSorted.h"

vector<int> Solution::twoSum2(vector<int>& numbers, int target) {
  int low = 0, high = numbers.size() - 1;
  while (low < high) {
    int sum = numbers[low] + numbers[high];
    if (sum == target)
      return { low + 1, high + 1 };
    else if (sum < target)
      ++low;
    else
      --high;
  }
  return { -1, -1 };
}