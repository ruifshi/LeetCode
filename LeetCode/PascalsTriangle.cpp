#include "stdafx.h"
#include "PascalsTriangle.h"

//just do it in a straightforward, each time generate a new line, first push all 1 vector into res and then update the elements from 1 to i-1.
vector<vector<int>> generate(int numRows) {
  vector<vector<int>> res;
  for (auto i = 0;i < numRows;++i)
  {
    res.push_back(vector<int>(i + 1, 1));
    for (auto j = 1; j < i; ++j) res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
  }
  return res;
}