#include "stdafx.h"
#include "LongestCommonPrefix.h"

string Solution::longestCommonPrefix(vector<string>& strs) {
  string prefix = "";
  if (strs.empty()) return prefix;

  // iterate over the first string and compare each letter with the strings
  // that follow. Keep adding to the prefix if they are the same.
  // once we find that it's not, return prefix
  for (int j = 0; j < strs[0].length(); ++j)
  {
    for (int i = 1; i < strs.size(); ++i) {
      if (j >= strs[i].size() || strs[i][j] != strs[0][j])
        return prefix;
    }
    prefix += strs[0][j];
  }
  return prefix;
}