#include "stdafx.h"
#include "GameOfLife.h"
#include <algorithm>

// O(nm)
void Solution::gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = m ? board[0].size() : 0;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {

			// for each element on the board. Find the number
			// of surrounding cells
            int count = 0;
            for (int I=max(i-1, 0); I<min(i+2, m); I++) {
				for (int J=max(j-1, 0); J<min(j+2, n); J++) {
					// check only one bit as we're storing the result
					// in another
                    count += board[I][J] & 1;
				}
			}

			// check rules to see if current cell can live
            if (count == 3 || count - board[i][j] == 3) {
				// store the result in another bit to reduce space
                board[i][j] |= 2;
			}
        }
    }

	// shift bits over to get rid of initial state
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            board[i][j] >>= 1;
		}
	}

	return;
}