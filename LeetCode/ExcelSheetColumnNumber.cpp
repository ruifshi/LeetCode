#include "stdafx.h"
#include "ExcelSheetColumnNumber.h"

int Solution::titleToNumber(string s) {
  int result = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    result = result * 26;
    // +1 since A-->1
    result += s[i] - 'A' + 1;
  }
  return result;
}