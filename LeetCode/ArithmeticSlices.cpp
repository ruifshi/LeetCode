#include "stdafx.h"
#include "ArithmeticSlices.h"

int helper(vector<int> A, int index, int &sum) {
  if (index < 2) return 0;

  int cur_sum = 0;
  if (A[index] - A[index - 1] == A[index - 1] - A[index - 2]) { // this sub array contains a slice
    cur_sum = 1 + helper(A, index - 1, sum);
    sum += cur_sum;
  }
  else {  // this sub array doesn't contain
    helper(A, index - 1, sum);
  }

  return cur_sum;
}

int Solution::numberOfArithmeticSlices(vector<int>& A) {
  int sum = 0;
  helper(A, A.size() - 1, sum);
  return sum;
}