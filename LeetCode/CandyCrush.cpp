#include "stdafx.h"
#include "CandyCrush.h"

vector<vector<int>> Solution::candyCrush(vector<vector<int>>& board) {
  int RowSize = board.size(), ColSize = board[0].size();
  bool todo = false;

  // check for horizontal matches
  for (int r = 0; r < RowSize; r++) {
    for (int c = 0; c < ColSize - 2; c++) {
      int v = abs(board[r][c]);
      if (v != 0 && v == abs(board[r][c + 1]) && v == abs(board[r][c + 2])) {
        board[r][c] = board[r][c + 1] = board[r][c + 2] = -v;
        todo = true;
      }
    }
  }

  // check for vertical matches
  for (int r = 0; r < RowSize - 2; r++) {
    for (int c = 0; c < ColSize; c++) {
      int v = abs(board[r][c]);
      if (v != 0 && v == abs(board[r + 1][c]) && v == abs(board[r + 2][c])) {
        board[r][c] = board[r + 1][c] = board[r + 2][c] = -v;
        todo = true;
      }
    }
  }

  // iterate for each column, go up the rows to see
  // which items are valid. wr is the pointer that keeps
  // track of where valid numbers should drop to after 
  // candies are crushed
  for (int c = 0; c < ColSize; c++) {
    int wr = RowSize - 1;
    for (int r = RowSize - 1; r >= 0; r--) {
      if (board[r][c] > 0) {
        board[wr--][c] = board[r][c];
      }
    }
    while (wr >= 0) {
      board[wr--][c] = 0;
    }
  }

  return todo ? candyCrush(board) : board;
}