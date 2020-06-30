#include "stdafx.h"
#include "CheapestFlightsWithinKStops.h"

#include <unordered_map>

void dfs(int s, int d, int k, int cost, vector<int>& visited, int& ans, unordered_map<int, vector<pair<int, int>>>& g) {
  if (s == d) { ans = cost; return; }
  if (k == 0) return;
  visited[s] = 1;
  for (const auto& x : g[s]) {
    if (visited[x.first] == 0) {
      if (cost + x.second > ans) continue; // IMPORTANT!!! prunning 

      dfs(x.first, d, k - 1, cost + x.second, visited, ans, g);

    }
  }
  visited[s] = 0;
}

int Solution::findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
  unordered_map<int, vector<pair<int, int>>> g;
  for (const auto& e : flights)
    g[e[0]].emplace_back(e[1], e[2]);
  int ans = INT_MAX;
  vector<int> visited(n, 0);

  // + 1 for edges since k is in nodes
  dfs(src, dst, K + 1, 0, visited, ans, g);
  return ans == INT_MAX ? -1 : ans;
}