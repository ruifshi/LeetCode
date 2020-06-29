#include "stdafx.h"
#include "FindNUniqueIntegersSumUpToZero.h"

/*
Naive idea
n = 1, [0]
n = 2, [-1, 1]

Now write more based on this
n = 3, [-2, 0, 2]
n = 4, [-3, -1, 1, 3]
n = 5, [-4, -2, 0, 2, 4]

A[i] = i * 2 - n + 1
*/
vector<int> Solution::sumZero(int n) {
  vector<int> out(n);

  for (int i = 0; i < n; i++) {
    out[i] = i * 2 - n + 1;
  }

  return out;
}

/*
class Solution {
    public int[] sumZero(int n) {

        int start = -n/2;

        int[] ret = new int[n];

        for(int i = 0; i < n; i++){

            // skip the zero for even numbers
            if(start == 0 && n%2 == 0){
                start++;
            }
            ret[i] = start++;
        }
        return ret;
    }
}
*/