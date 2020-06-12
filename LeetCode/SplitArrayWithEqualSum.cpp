#include "stdafx.h"
#include "SplitArrayWithEqualSum.h"

#include <unordered_set>

bool Solution::splitArray(vector<int>& nums) {
  if (nums.size() < 7) return false;  // need at least 7 elements to satisfy conditions

  vector<int> cumulative_sum(nums.size());

  cumulative_sum[0] = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    cumulative_sum[i] += cumulative_sum[i - 1] + nums[i];
  }

  // fix j and find i and k
  for (int j = 3; j < nums.size() - 3; j++) {
    unordered_set<int> found_sum;

    // find equal sum in 2 subarrays
    for (int i = 1; i < j - 1; i++) {
      if (cumulative_sum[i - 1] == cumulative_sum[j - 1] - cumulative_sum[i]) {
        found_sum.insert(cumulative_sum[i - 1]);
      }
    }

    // now find other 2 (k)
    for (int k = j + 2; k < nums.size() - 1; k++) {
      if (cumulative_sum[nums.size() - 1] - cumulative_sum[k] == cumulative_sum[k - 1] - cumulative_sum[j] && 
          found_sum.count(cumulative_sum[k - 1] - cumulative_sum[j])) {
        return true;
      }
    }
  }

  return false;
}

/* brute force n^4
public class Solution {

    public int sum(int[] nums, int l, int r) {
        int summ = 0;
        for (int i = l; i < r; i++)
            summ += nums[i];
        return summ;
    }

    public boolean splitArray(int[] nums) {
        if (nums.length < 7)
            return false;
        for (int i = 1; i < nums.length - 5; i++) {
            int sum1 = sum(nums, 0, i);
            for (int j = i + 2; j < nums.length - 3; j++) {
                int sum2 = sum(nums, i + 1, j);
                for (int k = j + 2; k < nums.length - 1; k++) {
                    int sum3 = sum(nums, j + 1, k);
                    int sum4 = sum(nums, k + 1, nums.length);
                    if (sum1 == sum2 && sum3 == sum4 && sum2 == sum4)
                        return true;
                }
            }
        }
        return false;
    }
}
*/

/* n^3 cumulative sum
public class Solution {
  public boolean splitArray(int[] nums) {
    if (nums.length < 7)
      return false;

    int[] sum = new int[nums.length];
    sum[0] = nums[0];
    for (int i = 1; i < nums.length; i++) {
      sum[i] = sum[i - 1] + nums[i];
    }
    for (int i = 1; i < nums.length - 5; i++) {
      int sum1 = sum[i - 1];
      for (int j = i + 2; j < nums.length - 3; j++) {
        int sum2 = sum[j - 1] - sum[i];
        if (sum1 != sum2)
          continue;
        for (int k = j + 2; k < nums.length - 1; k++) {
          int sum3 = sum[k - 1] - sum[j];
          int sum4 = sum[nums.length - 1] - sum[k];
          if (sum3 == sum4 && sum2 == sum4)
            return true;
        }
      }
    }
    return false;
  }
}
*/
