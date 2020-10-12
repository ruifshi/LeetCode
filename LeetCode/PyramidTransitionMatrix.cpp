#include "stdafx.h"
#include "PyramidTransitionMatrix.h"

// Just check validity level by level. At each level, move char-by-char to check possibility, If all are satisfied, then return true.
bool dfs(string bottom, int start, vector<string>& allowed, string nextBottom) {
  if (nextBottom.size() == bottom.size() - 1) {
    if (nextBottom.size() == 1) return true;
    return dfs(nextBottom, 0, allowed, "");
  }

  string ab = bottom.substr(start, 2);
  for (auto candidate : allowed) {
    if (candidate[0] == ab[0] && candidate[1] == ab[1]) {
      if (dfs(bottom, start + 1, allowed, nextBottom + candidate[2])) return true;
    }
  }

  return false;
}

bool Solution::pyramidTransition(string bottom, vector<string>& allowed) {
  return dfs(bottom, 0, allowed, "");
}