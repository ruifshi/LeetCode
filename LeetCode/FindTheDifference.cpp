#include "stdafx.h"
#include "FindTheDifference.h"

char Solution::findTheDifference(string s, string t) {
  char r = 0;
  for (char c : s) r ^= c;
  for (char c : t) r ^= c;
  return r;
}