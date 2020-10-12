#include "stdafx.h"
#include "PairsOfSongsWithTotalDurationsDivisibleBy60.h"

#include <unordered_set>

int Solution::numPairsDivisibleBy60(vector<int>& time) {
  int m[60] = {}; //keeps track of how many times x % 60 occurs
  int ret = 0;
  for (auto x : time) {
    int t = x % 60;
    int y = (60 - t) % 60;  //find the compliment number to t
    ret += m[y];  //how many times the compliment exists
    m[t]++;
  }
  return ret;
}