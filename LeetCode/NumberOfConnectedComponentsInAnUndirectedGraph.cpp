#include "stdafx.h"
#include "NumberOfConnectedComponentsInAnUndirectedGraph.h"

void countComponentsHelper(vector<vector<int>> &graph, vector<bool> &visited, int node) {
  if (visited[node]) return;

  visited[node] = true;

  for (int i = 0; i < graph[node].size(); i++) {
    countComponentsHelper(graph, visited, graph[node][i]);
  }
}

int Solution::countComponents(int n, vector<vector<int>>& edges) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  vector<vector<int>> graph(n);
  vector<bool> visited(n, false);
  int componenets = 0;

  for (int i = 0; i < edges.size(); i++) {
    graph[edges[i][0]].push_back(edges[i][1]);
    graph[edges[i][1]].push_back(edges[i][0]);
  }

  for (int i = 0; i < graph.size(); i++) {
    if (visited[i] == false) {
      countComponentsHelper(graph, visited, i);
      componenets++;
    }
  }

  return componenets;
}