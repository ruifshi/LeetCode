#include "stdafx.h"
#include "FlipStringToMonotoneIncreasing.h"

#include <algorithm>
/*
Skip 0's until we encounter the first 1.
Keep track of number of 1's in onesCount (Prefix).
Any 0 that comes after we encounter 1 can be a potential candidate for flip.Keep track of it in flipCount.
If flipCount exceeds oneCount - (Prefix 1's flipped to 0's)
a.Then we are trying to flip more 0's (suffix) than number of 1's(prefix) we have.
b.Its better to flip the 1's instead.
*/
int minFlipsMonoIncr(string S) {
  if (S == "" || S.length() <= 0)
    return 0;

  int flipCount = 0;
  int onesCount = 0;

  for (int i = 0; i < S.length(); i++) {
    if (S[i] == '0') {
      if (onesCount == 0) continue;
      else flipCount++;
    }
    else {
      onesCount++;
    }
    if (flipCount > onesCount) {
      flipCount = onesCount;
    }
  }
  return flipCount;
}