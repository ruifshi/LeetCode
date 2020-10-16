#include "stdafx.h"
#include "MaximumProductOfThreeNumbers.h"

#include <algorithm>

//first 2 numbers can be neg so answer is min1 * min2 * max1 or max1 * max2 * max3 (1 is biggest)
int Solution::maximumProduct(vector<int>& nums) {
  int min1 = INT_MAX, min2 = INT_MAX;
  int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
  for (int n : nums) {
    if (n <= min1) {
      min2 = min1;
      min1 = n;
    }
    else if (n <= min2) {     // n lies between min1 and min2
      min2 = n;
    }
    if (n >= max1) {            // n is greater than max1, max2 and max3
      max3 = max2;
      max2 = max1;
      max1 = n;
    }
    else if (n >= max2) {     // n lies betweeen max1 and max2
      max3 = max2;
      max2 = n;
    }
    else if (n >= max3) {     // n lies betwen max2 and max3
      max3 = n;
    }
  }
  return max(min1 * min2 * max1, max1 * max2 * max3);
}

/*
public class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        return Math.max(nums[0] * nums[1] * nums[nums.length - 1], nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length - 3]);
    }
}
*/