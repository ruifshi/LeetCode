#include "stdafx.h"
#include "MaximumVacationDays.h"

#include <algorithm>

int Solution::maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
	if (flights.size() == 0 || days.size() == 0) {
		return 0;
	}

	vector<vector<int>> table(days.size(), vector<int>(days[0].size() + 1, 0));	//+1 for base case, no vacations on week before

	for (int week = days[0].size() - 1; week >= 0; week--) {

		for (int curr_city = 0; curr_city < days.size(); curr_city++) {
			table[curr_city][week] = days[curr_city][week] + table[curr_city][week + 1];

			for (int city = 0; city < days.size(); city++) {
				if (flights[curr_city][city]) {
					table[curr_city][week] = max(days[city][week] + table[city][week + 1], table[curr_city][week]);
				}
			}
		}
	}

	return table[0][0];
}

/* DFS solution
public class Solution {
	public int maxVacationDays(int[][] flights, int[][] days) {
		return dfs(flights, days, 0, 0);
	}
	public int dfs(int[][] flights, int[][] days, int cur_city, int weekno) {
		if (weekno == days[0].length)
			return 0;
		int maxvac = 0;
		for (int i = 0; i < flights.length; i++) {
			if (flights[cur_city][i] == 1 || i == cur_city) {
				int vac = days[i][weekno] + dfs(flights, days, i, weekno + 1);
				maxvac = Math.max(maxvac, vac);
			}
		}
		return maxvac;
	}
}
*/

/* DFS with memo
public class Solution {
	public int maxVacationDays(int[][] flights, int[][] days) {
		int[][] memo = new int[flights.length][days[0].length];
		for (int[] l: memo)
			Arrays.fill(l, Integer.MIN_VALUE);
		return dfs(flights, days, 0, 0, memo);
	}
	public int dfs(int[][] flights, int[][] days, int cur_city, int weekno, int[][] memo) {
		if (weekno == days[0].length)
			return 0;
		if (memo[cur_city][weekno] != Integer.MIN_VALUE)
			return memo[cur_city][weekno];
		int maxvac = 0;
		for (int i = 0; i < flights.length; i++) {
			if (flights[cur_city][i] == 1 || i == cur_city) {
				int vac = days[i][weekno] + dfs(flights, days, i, weekno + 1, memo);
				maxvac = Math.max(maxvac, vac);
			}
		}
		memo[cur_city][weekno] = maxvac;
		return maxvac;
	}
}
*/