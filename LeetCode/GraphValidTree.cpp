#include "stdafx.h"
#include "GraphValidTree.h"

/*
Recall that a graph, G, is a tree iff the following two conditions are met:

G is fully connected. In other words, for every pair of nodes in G, there is a path between them.
G contains no cycles. In other words, there is exactly one path between each pair of nodes in G.
*/
bool hasCycle(vector<vector<int>>& neighbors, int child, int parent, vector<bool>& visited) {
  if (visited[child]) return true;
  visited[child] = true;
  for (auto neigh : neighbors[child])
    if (neigh != parent && hasCycle(neighbors, neigh, child, visited))
      return true;
  return false;
}

bool Solution::validTree(int n, vector<vector<int>>& edges) {
  vector<vector<int>> neighbors(n);
  for (auto e : edges) {
    neighbors[e[0]].push_back(e[1]);
    neighbors[e[1]].push_back(e[0]);
  }
  vector<bool> visited(n, false);
  if (hasCycle(neighbors, 0, -1, visited))
    return false;
  for (bool v : visited)
    if (!v) return false;
  return true;
}