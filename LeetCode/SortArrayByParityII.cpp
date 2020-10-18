#include "stdafx.h"
#include "SortArrayByParityII.h"

vector<int> sortArrayByParityII(vector<int>& A) {
  int j = 1;
  for (int i = 0; i < A.size(); i += 2)
    if (A[i] % 2 == 1) {  // for even spot, find next even and move it in
      while (A[j] % 2 == 1)
        j += 2;

      // Swap A[i] and A[j]
      swap(A[i], A[j]);
    }

  return A;
}

/*
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int N = A.length;
        int[] ans = new int[N];

        int t = 0;
        for (int x: A) if (x % 2 == 0) {
            ans[t] = x;
            t += 2;
        }

        t = 1;
        for (int x: A) if (x % 2 == 1) {
            ans[t] = x;
            t += 2;
        }

        return ans;
    }
}
*/