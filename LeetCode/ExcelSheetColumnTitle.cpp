#include "stdafx.h"
#include "ExcelSheetColumnTitle.h"

string Solution::convertToTitle(int n) {
  string res;

  char c;

  while (n) {
    // need to do this since it's 1 based instead of 0
    //https://leetcode.com/problems/excel-sheet-column-title/discuss/441430/Detailed-Explanation-Here's-why-we-need-n-at-first-of-every-loop-(JavaPythonC%2B%2B)
    n--;
    c = 'A' + n % 26;
    res = res + c;
    n /= 26;
  }

  reverse(res.begin(), res.end());

  return res;
}