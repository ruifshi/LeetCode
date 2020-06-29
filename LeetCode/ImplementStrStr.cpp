#include "stdafx.h"
#include "ImplementStrStr.h"

int Solution::strStr(string haystack, string needle) {
  // iterate through haystack and find first match. Return once all
  // of needle is iterated
  for (int i = 0; i < (int)(haystack.size() - needle.size() + 1); i++) {
    int j = 0;
    while (j < needle.size() && haystack[i + j] == needle[j])
      j++;
    if (j == needle.size())
      return i;
  }
  return -1;
}