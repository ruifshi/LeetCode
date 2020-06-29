#include "stdafx.h"
#include "MaximumSumCircularSubarray.h"

#include <algorithm>

// find minimum sum in subarray and subtract it from the total sum of the subarray
// this gets you the maximum sum since you can wrap around
int Solution::maxSubarraySumCircular(vector<int>& A) {
  if (A.size() == 0) return 0;
  if (A.size() == 1) return A[0];

  // find total sum
  int sum = 0;
  for (int i = 0; i < A.size(); i++) {
    sum += A[i];
  }

  // find maximum sum using kadane
  int maxVal = A[0];
  int currSum = A[0];
  for (int i = 1; i < A.size(); i++) {
    currSum = max(currSum + A[i], A[i]);
    maxVal = max(maxVal, currSum);
  }

  // find minimum sum using kadane
  int minVal = A[0];
  currSum = A[0];
  for (int i = 1; i < A.size(); i++) {
    currSum = min(currSum + A[i], A[i]);
    minVal = min(minVal, currSum);
  }

  // if it's all negatives, then return the smallest
  // otherwise, the max is the max exisiting in the subarray or it's the 
  // wrap around which is sum - min subarray
  return maxVal < 0 ? maxVal : max(maxVal, sum - minVal);
}