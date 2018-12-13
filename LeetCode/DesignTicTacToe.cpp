#include "stdafx.h"
#include "DesignTicTacToe.h"

/** Initialize your data structure here. */
TicTacToe::TicTacToe(int n) {
	rows.resize(n, 0), cols.resize(n, 0);
	diagonal = anti_diagonal = 0;
	sz = n;
}

/** Player {player} makes a move at ({row}, {col}).
	@param row The row of the board.
	@param col The column of the board.
	@param player The player, can be either 1 or 2.
	@return The current winning condition, can be either:
			0: No one wins.
			1: Player 1 wins.
			2: Player 2 wins. */
int TicTacToe::move(int row, int col, int player) {
	if (player == 1) {
		++rows[row], ++cols[col];
		if (row == col)
			++diagonal;
		if (row == sz - 1 - col)
			++anti_diagonal;
		if (rows[row] == sz || cols[col] == sz || diagonal == sz || anti_diagonal == sz)
			return 1;
	}
	else {
		--rows[row], --cols[col];
		if (row == col)
			--diagonal;
		if (row == sz - 1 - col)
			--anti_diagonal;
		if (rows[row] == -sz || cols[col] == -sz || diagonal == -sz || anti_diagonal == -sz)
			return 2;
	}
	return 0;
}