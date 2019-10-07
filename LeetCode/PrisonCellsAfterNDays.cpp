#include "stdafx.h"
#include "PrisonCellsAfterNDays.h"

#include <map>

vector<int> Solution::prisonAfterNDays(vector<int>& cells, int N) {
	map<vector<int>, int> seen;
	while (N > 0) {
		vector<int> cells2(8, 0);
		seen[cells] = N--;
		for (int i = 1; i < 7; ++i)
			cells2[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
		cells = cells2;

		//since you only have 6 bits that are changing (first and last bit changes to 0 and stays 0). Total max possible distinct states are 2 ^ 6 = 64.
		//Then when you see the same state again, you know that you have passed (lastSeen - currVal) state in between.
		//So now you know your states repeat every (lastSeen - currVal) times. So finally you can mod the current N with that value to not repeat the same steps.
		if (seen.find(cells) != seen.end()) {	
			N %= seen[cells] - N;
		}
	}
	return cells;
}