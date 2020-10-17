#include "stdafx.h"
#include "ValidSudoku.h"

#include <unordered_set>
#include <string>

/*
'4' in row 7 is encoded as "(4)7".
'4' in column 7 is encoded as "7(4)".
'4' in the top-right block is encoded as "0(4)2".
*/
bool isValidSudoku(vector<vector<char>>& board) {
  unordered_set<string> seen;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        string s = '(' + to_string(board[i][j]) + ')';
        string row = s + to_string(i);
        string col = to_string(j) + s;
        string box = to_string(i / 3) + s + to_string(j / 3);
        if (seen.find(row) != seen.end() ||
          seen.find(col) != seen.end() ||
          seen.find(box) != seen.end()) {
          return false;
        }

        seen.insert(row);
        seen.insert(col);
        seen.insert(box);
      }
    }
  }

  return true;
}