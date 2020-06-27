#include "stdafx.h"
#include "ValidTriangleNumber.h"

#include <algorithm>

// fix 2 numbers and find the 3rd
// But, only one condition a + b > ca+b>c would suffice. This happens because c ≥ b and c ≥ a. Thus, 
// adding any number to cc will always produce a sum which is greater than either aa or bb considered alone. 
// Thus, the inequalities c + a > bc+a>b and c + b > ac+b>a are satisfied implicitly by virtue of the property a < b < ca<b<c.
int Solution::triangleNumber(vector<int>& nums) {
  if (nums.size() < 3) return 0;

  int count = 0;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 2; i++) {
    for (int j = i + 1; j < nums.size() - 1; j++) {
      int k = j + 1;

      // Thus, if we are able to find this right limit value of kk(indicating the element just greater than nums[i] + nums[j]nums[i]+nums[j]),
      // we can conclude that all the elements in numsnums array in the range (j+1, k-1)(j+1,k−1)(both included) satisfy the required inequality. 
      // Thus, the countcount of elements satisfying the inequality will be given by (k-1) - (j+1) + 1 = k - j - 1(k−1)−(j+1)+1=k−j−1.
      while (k < nums.size() && nums[i] + nums[j] > nums[k])
        k++;
      count += k - j - 1;
    }
  }

  return count;
}

/* brute force 
// to form a valid triangle, is that the sum of any two sides should always be greater than the third side alone. 
// i.e. a + b > ca+b>c, b + c > ab+c>a, a + c > ba+c>b.
public class Solution {
    public int triangleNumber(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            for (int j = i + 1; j < nums.length - 1; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    if (nums[i] + nums[j] > nums[k] && nums[i] + nums[k] > nums[j] && nums[j] + nums[k] > nums[i])
                        count++;
                }
            }
        }
        return count;
    }
}
*/