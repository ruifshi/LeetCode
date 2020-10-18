#include "stdafx.h"
#include "ReplaceElementsWithGreatestElementOnRight Side.h"

#include <algorithm>

vector<int> Solution::replaceElements(vector<int>& arr) {
  int size = arr.size();

  if (size == 0) {
    return {};
  }

  int maxV = arr[size - 1];

  for (int i = size - 1; i >= 0; i--) {
    int cur = arr[i];
    arr[i] = maxV;
    maxV = max(cur, maxV);
  }

  arr[size - 1] = -1;

  return arr;
}