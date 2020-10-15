#include "stdafx.h"
#include "PartitionArrayIntoThreePartsWithEqualSum.h"

// sum all values and divide by 3 to find target sum
// then see if target sum happens 3 times
bool canThreePartsEqualSum(vector<int>& A) {
  int total = 0;
  for(auto &d : A) {
    total += d;
  }

  int sum = 0, parts = 0;
  for (auto &d : A) {
    sum += d;
    if (sum == total / 3) {
      parts++;
      sum = 0;
    }
  }

  return parts >= 3;
}