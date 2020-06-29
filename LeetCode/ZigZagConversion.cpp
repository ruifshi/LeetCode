#include "stdafx.h"
#include "ZigZagConversion.h"

#include <vector>
#include <algorithm>

/*
We can use min(numRows,len(s)) lists to represent the non-empty rows of the Zig-Zag Pattern.

Iterate through ss from left to right, appending each character to the appropriate row. The appropriate row can be tracked using two variables: the current row and the current direction.

The current direction changes only when we moved up to the topmost row or moved down to the bottommost row.
*/
string convert(string s, int numRows) {

  if (numRows == 1) return s;

  vector<string> rows(min(numRows, int(s.size())));
  int curRow = 0;
  bool goingDown = false;

  for (char c : s) {
    rows[curRow] += c;
    if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
    curRow += goingDown ? 1 : -1;
  }

  string ret;
  for (string row : rows) ret += row;
  return ret;
}