#include "stdafx.h"
#include "BattleshipsInABoard.h"

// can also use BFS if size can be O(n)
int Solution::countBattleships(vector<vector<char>>& board) {
	if (board.size() == 0)
		return 0;

	int boats = 0;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			// if you see a ship add it for now.
			if (board[i][j] == 'X') {
				boats++;

				// it turns out that the ship we just added isn't a beginning of the ship. So we have already counted this ship!!!
				if ((i - 1 >= 0 && board[i - 1][j] == 'X') || (j - 1 >= 0 && board[i][j - 1] == 'X'))
					boats -= 1;
			}
		}
	}
	return boats;
}