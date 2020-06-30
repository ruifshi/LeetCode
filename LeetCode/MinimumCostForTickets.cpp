#include "stdafx.h"
#include "MinimumCostForTickets.h"

#include <unordered_set>
#include <algorithm>

/*
For each travel day, we can buy a one-day ticket, or use 7-day or 30-day pass as if we would have purchased it 7 or 30 days ago. We need to track rolling costs for at least 30 days back, and use them to pick the cheapest option for the next travel day.

Here, we can use two approaches: track cost for all calendar days, or process only travel days. The first approach is simpler to implement, but it's slower. Since the problem is limited to one calendar year, it does not make much of a difference; for a generalized problem I would recommend the second approach.

1. Track calendar days
We track the minimum cost for all calendar days in dp. For non-travel days, the cost stays the same as for the previous day. For travel days, it's a minimum of yesterday's cost plus single-day ticket, or cost for 8 days ago plus 7-day pass, or cost 31 days ago plus 30-day pass.
*/
int Solution::mincostTickets(vector<int>& days, vector<int>& costs) {
  unordered_set<int> travel(begin(days), end(days));
  int dp[366] = {};
  for (int i = 1; i < 366; ++i) {
    if (travel.find(i) == travel.end()) dp[i] = dp[i - 1];
    else dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2] });
  }
  return dp[365];
}