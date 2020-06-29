#include "stdafx.h"
#include "FibonacciNumber.h"

#include <vector>

using namespace std;

int Solution::fib(int N) {
  if (N < 2)
    return N;

  vector<int> memo(N + 1);
  memo[0] = 0;
  memo[1] = 1;
  for (int i = 2; i <= N; i++)
    memo[i] = memo[i - 1] + memo[i - 2];
  return memo[N];
}

/*
class Solution {
  int fib(int N) {
    vector<int> memo(N + 1);
    return helper(N, memo);
  }

  int helper(int N, vector<int> &memo) {

    if (N == 0) {
      return 0;
    }

    if (N == 1) {
      return 1;
    }

    if (memo[N] != 0) {
      return memo[N];
    }
    memo[N] = fib(N - 1) + fib(N - 2);
    return memo[N];
  }
}
*/