#include "stdafx.h"
#include "KokoEatingBananas.h"

#include <algorithm>

bool canEatAll(vector<int> &piles, int K, int H) {
  int countHour = 0; // Hours take to eat all bananas at speed K.

  for (int pile : piles) {
    countHour += pile / K;
    if (pile % K != 0)
      countHour++;
  }
  return countHour <= H;
}

int Solution::minEatingSpeed(vector<int>& piles, int H) {
  int left = 1; //minimum speed Koko can eat
  int right = 1; // maximum speed Koko can eat which is max value in piles
  for (int i = 0; i < piles.size(); i++) {
    right = max(right, piles[i]);
  }

  // do binary search. If choosen K results in less hours than given, then it can be lowered
  while (left <= right) {
    int K = left + ((right - left) / 2);
    if (canEatAll(piles, K, H)) {
      right = K - 1;
    }
    else {
      left = K + 1;
    }
  }

  return left;
}