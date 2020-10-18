#include "stdafx.h"
#include "JewelsAndStones.h"

#include <unordered_set>

int Solution::numJewelsInStones(string J, string S) {
  unordered_set<char> Jset;
  int count = 0;
  
  for (auto &c : J) {
    Jset.insert(c);
  }

  for (auto &c : S) {
    if (Jset.find(c) != Jset.end()) count++;
  }

  return count;
}