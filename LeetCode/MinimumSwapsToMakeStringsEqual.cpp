#include "stdafx.h"
#include "MinimumSwapsToMakeStringsEqual.h"

/*
Get the count of "x_y" and "y_x"
If sum of both counts is odd then return -1. We need a pair to make the strings equal
Each 2 count of "x_y" needs just 1 swap. So add half of "x_y" count to the result
Each 2 count of "y_x" needs just 1 swap. So add half of "y_x" count to the result
if we still have 1 count of "x_y" and 1 count of "y_x" then they need 2 swaps so add 2 in result.
*/
int Solution::minimumSwap(string s1, string s2) {
  if (s1.size() != s2.size()) return -1;
  int xy = 0, yx = 0;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == 'x' && s2[i] == 'y') xy++;
    else if (s1[i] == 'y' && s2[i] == 'x') yx++;
  }
  if (xy % 2 != yx % 2) return -1;
  return xy / 2 + yx / 2 + (xy % 2) * 2;
}