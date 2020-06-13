#include "stdafx.h"
#include "MaxConsecutiveOnesIII.h"

int longestOnes(vector<int>& A, int K) {
  int left = 0, right = 0;
  while (right < A.size()) {
    // If we included a zero in the window we reduce the value of K.
    // Since K is the maximum zeros allowed in a window.
    if (A[right] == 0) K--;
    // A negative K denotes we have consumed all allowed flips and window has
    // more than allowed zeros, thus increment left pointer by 1 to keep the window size same.
    if (K < 0) {
      // If the left element to be thrown out is zero we increase K.
      if (A[left] == 0) K++;
      left++;
    }

    right++;
  }

  // the size of the window also gets expanded to the max subarray
  return right - left;
}