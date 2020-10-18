#include "stdafx.h"
#include "MaximumSumOfTwoNonOverlappingSubarrays.h"

#include <algorithm>

int Solution::maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
  if (A.size() == 0) return 0;
  vector<int> preSums(A.size(), 0);      // preSums[i] is the sum of the first i+1 elements: sum(A[0, i])
  preSums[0] = A[0];
  for (int i = 1; i < A.size(); ++i) 
    preSums[i] = preSums[i - 1] + A[i];

  int result = preSums[M + L - 1];
  // Try out all possible L windows, add each L window sum with the greatest M window sum to its left and maintain the maximum sum.
  int maxM = preSums[M - 1];
  for (int i = L + M; i < A.size(); ++i) {
    // L + M window == M window, L window
    // i is the end of the window of size L + M
    // i - L - M + 1 is the start of the window of size L + M
    // i - L is the end of the M subwindow
    // i - L + 1 is the start of the L subwindow
    maxM = max(maxM, preSums[i - L] - preSums[i - L - M]);
    result = max(result, maxM + preSums[i] - preSums[i - L]);
  }

  // Try out all possible M windows, add each M window sum with the greatest L window sum to its left and maintain the maximum sum.
  int maxL = preSums[L - 1];
  for (int i = L + M; i < A.size(); ++i) {
    maxL = max(maxL, preSums[i - M] - preSums[i - L - M]);
    result = max(result, maxL + preSums[i] - preSums[i - M]);
  }
  return result;
}