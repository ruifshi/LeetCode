#include "stdafx.h"
#include "PeakIndexInAMountainArray.h"

int Solution::peakIndexInMountainArray(vector<int>& A) {
  int low = 0, high = A.size() - 1;

  while (low < high) {
    int mid = low + (high - low) / 2;
    if (A[mid] < A[mid + 1]) {
      low = mid + 1;
    }
    else {
      high = mid;
    }
  }

  return low;
}

/*
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int i = 0;
        while (A[i] < A[i+1]) i++;
        return i;
    }
}
*/