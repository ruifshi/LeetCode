#include "stdafx.h"
#include "PossibleBipartition.h"

bool dfs(vector<vector<int>> &graph, vector<int> &colors, int index, int color) {
  if (colors[index] != 0) return colors[index] == color;
  colors[index] = color;

  for (int i : graph[index]) {
    if (!dfs(graph, colors, i, -color)) return false;
  }
  return true;
}

// If the first person is red, anyone disliked by this person must be blue. 
// Then, anyone disliked by a blue person is red, then anyone disliked by a red person is blue, and so on.
// 0: unvisited, 1: first group, -1: second group
bool Solution::possibleBipartition(int N, vector<vector<int>>& dislikes) {
  vector<vector<int>> graph(N);
  for (vector<int> d : dislikes) {
    graph[d[0] - 1].push_back(d[1] - 1);
    graph[d[1] - 1].push_back(d[0] - 1);
  }

  vector<int> colors(N);
  for (int i = 0; i < N; i++) {
    // not visited and conflict found
    if (colors[i] == 0 && !dfs(graph, colors, i, 1)) return false;
  }

  return true;
}