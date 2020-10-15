#include "stdafx.h"
#include "MinimumMovesToEqualArrayElements.h"

#include <algorithm>

//Adding 1 to (n-1) elements is equivalent to subtracting 1 from one of the elements and adding 1 to all elements. 
//Adding 1 to all elements does not change anything in terms of equality. So we must find the min number of (subtract 1 from any element) operations. 
//The only way to make all elements equal this way is to make them all equal to the min element of the array.
int minMoves(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int count = 0;
  for (int i = nums.size() - 1; i > 0; i--) {
    count += nums[i] - nums[0];
  }
  return count;
}

/*
    public int minMoves(int[] nums) {
        int moves = 0, min = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            moves += nums[i];
            min = Math.min(min, nums[i]);
        }
        return moves - min * nums.length;
    }
*/