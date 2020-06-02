#include "stdafx.h"
#include "MinimumTimeToCollectAllApplesInATree.h"

#include <unordered_map>

int dfs(int node, vector<bool>& hasApple, unordered_map<int, vector<int>> &g, unordered_map<int, bool> &visited) {
  if (visited[node]) {
    return 0;
  }
  visited[node] = true;

  int childrenCost = 0; // cost of traversing all children. 
  for (auto x : g[node]) {
    childrenCost += dfs(x, hasApple, g, visited);  // check recursively for all apples.
  }

  if (childrenCost == 0 && hasApple[node] == false) {
    // If no child has apples, then we won't traverse the subtree, so cost will be zero.
    // similarly, if current node also does not have the apple, we won't traverse this branch at all, so cost will be zero.
    return 0;
  }

  // Children has at least one apple or the current node has an apple, so add those costs.
  return (childrenCost + 2);
}

int Solution::minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
  unordered_map<int, vector<int>> g; // to store the graph
  unordered_map<int, bool> visited; // to stop exploring same nodes again and again.

  // construct the graph first.
  for (auto e : edges) {
    g[e[0]].push_back(e[1]); // adjecency list representation
    g[e[1]].push_back(e[0]); // adjecency list representation
  }

  int apples = dfs(0, hasApple, g, visited);
  return apples > 0 ? apples - 2 : 0;  // cost of reaching the root is 0. For all others, its 2.
}