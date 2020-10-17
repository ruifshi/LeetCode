#include "stdafx.h"
#include "DesignAStackWithIncrementOperation.h"

#include <algorithm>

// brute force can just iterate through vector and increment to all up to k

//vector<int> stk;
//vector<int> incHist;  means stk[0] to stk[i] increases by incHist[i]
//int maxSize;

CustomStack::CustomStack(int maxSize) {
  this->maxSize = maxSize;
}

void CustomStack::push(int x) {
  if (stk.size() == maxSize) return;

  stk.push_back(x);
  incHist.push_back(0);
}

int CustomStack::pop() {
  int i = stk.size() - 1;
  if (i < 0) return -1;
  if (i > 0) incHist[i - 1] += incHist[i];  // need to propagate future adds to past elements
  int res = stk[i] + incHist[i];
  stk.pop_back();
  incHist.pop_back();
  return res;
}

void CustomStack::increment(int k, int val) {
  int i = min(k, (int)stk.size()) - 1;
  if (i >= 0) incHist[i] += val;
}