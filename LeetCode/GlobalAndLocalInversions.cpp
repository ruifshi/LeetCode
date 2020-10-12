#include "stdafx.h"
#include "GlobalAndLocalInversions.h"

/*
A local inversion is also a global inversion. So for true, we must only have local inversions

The original order should be [0, 1, 2, 3, 4...], the number i should be on the position i. We just check the offset of each number, if the absolute value 
is larger than 1, means the number of global inversion must be bigger than local inversion, because a local inversion is a global inversion, 
but a global one may not be local.
*/
bool Solution::isIdealPermutation(vector<int>& A) {
  for (int i = 0; i < A.size(); ++i) {
    if (abs(A[i] - i) > 1) return false;
  }
  return true;
}