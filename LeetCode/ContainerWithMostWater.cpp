#include "stdafx.h"
#include "ContainerWithMostWater.h"

#include <algorithm>

/*
We starts with the widest container, l = 0 and r = n - 1. Let's say the left one is shorter: h[l] < h[r]. 
Then, this is already the largest container the left one can possibly form. There's no need to consider it again. 
Therefore, we just throw it away and start again with l = 1 and r = n -1.
*/
int Solution::maxArea(vector<int>& height) {
  int maxarea = 0, l = 0, r = height.size() - 1;
  while (l < r) {
    maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
    if (height[l] < height[r])
      l++;
    else
      r--;
  }
  return maxarea;
}

/* brute force, check area of each rectangle formed
public class Solution {
    public int maxArea(int[] height) {
        int maxarea = 0;
        for (int i = 0; i < height.length; i++)
            for (int j = i + 1; j < height.length; j++)
                maxarea = Math.max(maxarea, Math.min(height[i], height[j]) * (j - i));
        return maxarea;
    }
}
*/