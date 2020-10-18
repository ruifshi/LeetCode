#include "stdafx.h"
#include "RotateString.h"

bool Solution::rotateString(string A, string B) {
  if (A.size() != B.size()) return false;
  return((A + A).find(B) != string::npos);
}