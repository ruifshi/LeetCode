#include "stdafx.h"
#include "CompareVersionNumbers.h"

int Solution::compareVersion(string version1, string version2) {
  int ver1 = 0, ver2 = 0;
  int i = 0, j = 0;
  while ((i < version1.length()) || (j < version2.length())) {
    // calc each version num
    while (isdigit(version1[i]) && (i < version1.length()))
      ver1 = ver1 * 10 + version1[i++] - '0';
    while (isdigit(version2[j]) && (j < version2.length()))
      ver2 = ver2 * 10 + version2[j++] - '0';
    if (ver1 < ver2)
      return -1;
    if (ver1 > ver2)
      return 1;
    ver1 = 0, ver2 = 0;
    if (i < version1.length()) i++; // get rid of '.'
    if (j < version2.length()) j++;
  }
  return 0;
}