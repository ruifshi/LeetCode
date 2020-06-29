#include "stdafx.h"
#include "WordSearch.h"

/*
time: O(N * 4^L)
where NN is the number of cells in the board and LL is the length of the word to be matched.
For the backtracking function, its execution trace would be visualized as a 4-ary tree, each 
of the branches represent a potential exploration in the corresponding direction. 
Therefore, in the worst case, the total number of invocation would be the number of nodes in a full 4-nary tree, which is about 4^L

space: O(L)
*/
bool existHelper(vector<vector<char>>& board, int i, int j, string& word) {
  if (!word.size())
    return true;
  if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
    return false;
  char c = board[i][j];
  board[i][j] = '*';
  // erase first letter since found
  string s = word.substr(1);
  bool ret = existHelper(board, i - 1, j, s) || existHelper(board, i + 1, j, s) || 
    existHelper(board, i, j - 1, s) || existHelper(board, i, j + 1, s);
  board[i][j] = c;
  return ret;
}

bool Solution::exist(vector<vector<char>>& board, string word) {
  for (unsigned int i = 0; i < board.size(); i++)
    for (unsigned int j = 0; j < board[0].size(); j++)
      if (existHelper(board, i, j, word))
        return true;
  return false;
}