#include "stdafx.h"
#include "StrobogrammaticNumber.h"

#include <unordered_map>

bool Solution::isStrobogrammatic(string num) {
  unordered_map<int, int> mapping = { {'0','0'}, {'1','1'}, {'6','9'},{'8','8'},{'9','6'} };

  int i = 0, j = num.size() - 1;

  while (i <= j) {
    if (mapping[num[i]] != num[j]) return false;
    i++, j--;
  }

  return true;
}