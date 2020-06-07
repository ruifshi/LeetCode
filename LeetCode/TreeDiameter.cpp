#include "stdafx.h"
#include "TreeDiameter.h"

#include <algorithm>

int treeDiameterHelper(vector<vector<int>> &adjacency, vector<bool> &visited, int v, int &diameter) {
  visited[v] = true;
  int max_depth = 0;  // max depth of all nodes under this node

  // loop through all neighbors
  for (int i = 0; i < adjacency[v].size(); i++) {
    if (!visited[adjacency[v][i]]) {
      int depth = treeDiameterHelper(adjacency, visited, adjacency[v][i], diameter);  // find depth of nodes under this node
      diameter = max(diameter, depth + max_depth);  // depth + max_depth to keep track of current path
      max_depth = max(depth, max_depth);  // find max depth of all nodes under this one
    }
  }

  return max_depth + 1; // return the max depth of all nodes under including this one
}

int Solution::treeDiameter(vector<vector<int>>& edges) {
  int diameter = 0;
  vector<bool> visited(edges.size() + 1);
  vector<vector<int>> adjacency(edges.size() + 1);

  // create graph and neighbors of each node
  for (int i = 0; i < edges.size(); i++) {
    adjacency[edges[i][0]].push_back(edges[i][1]);
    adjacency[edges[i][1]].push_back(edges[i][0]);
  }

  treeDiameterHelper(adjacency, visited, 0, diameter);

  return diameter;
}