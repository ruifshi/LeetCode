#include "stdafx.h"
#include "HappyNumber.h"

#include <unordered_set>

using namespace std;

int getVal(int n) {
  int Sum = 0;
  while (n > 0) {
    int v = n % 10;
    n /= 10;
    Sum += v * v;
  }

  return Sum;
}

//use set to determine if we've seen the number before
bool Solution::isHappy(int n) {
  unordered_set<int> seen;

  while (n != 1 && seen.find(n) == seen.end()) {
    seen.insert(n);
    n = getVal(n);
  }

  return n == 1;
}