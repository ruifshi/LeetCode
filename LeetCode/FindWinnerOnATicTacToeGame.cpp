#include "stdafx.h"
#include "FindWinnerOnATicTacToeGame.h"

string Solution::tictactoe(vector<vector<int>>& moves) {
  int numMoves = moves.size();
  if (numMoves < 5) {
    return "Pending";  //not enough moves for a winner
  }

  int row[3] = { 0 }; // keep track of elements in each row/col
  int col[3] = { 0 };
  int diag = 0;
  int antiDiag = 0;

  // if last move resulted in win then whoever went last won
  string winner = numMoves & 1 ? "A" : "B";

  //start from last move
  for (int i = numMoves - 1; i >= 0; i -= 2) {
    vector<int> move = moves[i];

    if (++row[move[0]] == 3 || ++col[move[1]] == 3 || 
      (move[0] == move[1] && ++diag == 3) ||
      (move[0] + move[1] == 2 && ++antiDiag == 3)) {  // 3x3 grid so anti diag idx sum = 2
      return winner;
    }
  }

  if (numMoves == 9) {
    return "Draw";
  }

  return "Pending";
}