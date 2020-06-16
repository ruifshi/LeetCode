#include "stdafx.h"
#include "SquaresOfASortedArray.h"

vector<int> Solution::sortedSquares(vector<int>& A) {
  //populate larger elements first
  //check the 2 extremes and put in the bigger one first
  vector<int> res(A.size());
  int l = 0, r = A.size() - 1;
  for (int k = A.size() - 1; k >= 0; k--) {
    if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--];
    else res[k] = A[l] * A[l++];
  }
  return res;
}

/*
class Solution {
    public int[] sortedSquares(int[] A) {
        int N = A.length;
        int[] ans = new int[N];
        for (int i = 0; i < N; ++i)
            ans[i] = A[i] * A[i];

        Arrays.sort(ans);
        return ans;
    }
}
*/