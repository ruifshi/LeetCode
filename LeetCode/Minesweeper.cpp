#include "stdafx.h"
#include "Minesweeper.h"

vector<vector<int>> dirs = { {0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {-1,-1}, {-1,1}, {1,-1} };

void updateBoardHelper(vector<vector<char>>& board, int i, int j) {
  // keeps track of mines in adjacent squares
  int mines = 0;

  // check if current location contains any mine in any of the 8 directions
  // increase mines if it's in bound. 
  for (auto dir : dirs) {
    int i2 = i + dir[0];
    int j2 = j + dir[1];
    if (i2 >= 0 && i2 < board.size() && j2 >= 0 && j2 < board[0].size() && board[i2][j2] == 'M') {
      mines++;
    }
  }

  // if our mine_cnt if greater than 0 means we found a mine in any 
  // of its adjacent location so we change value of board[r][c] i.e. of that location
  // and return because we can't go any further because we can go only if
  // it has unrevealed empty cell i.e. 'E'.
  if (mines > 0) {
    board[i][j] = mines + '0';
    return;
  }

  // if 0 mines then it's blank
  board[i][j] = 'B';

  // now we need to iterate through all directions and reveil any empty cells
  for (auto dir : dirs) {
    int i2 = i + dir[0];
    int j2 = j + dir[1];
    if (i2 >= 0 && i2 < board.size() && j2 >= 0 && j2 < board[0].size() && board[i2][j2] == 'E') {
      updateBoardHelper(board, i2, j2);;
    }
  }
}

vector<vector<char>> Solution::updateBoard(vector<vector<char>>& board, vector<int>& click) {
  // found mine, return
  if (board[click[0]][click[1]] == 'M') {
    board[click[0]][click[1]] = 'X';
    return board;
  }

  updateBoardHelper(board, click[0], click[1]);
  return board;
}