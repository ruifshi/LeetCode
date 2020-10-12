#include "stdafx.h"
#include "AllPathsFromSourceToTarget.h"

void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int cur) {
  path.push_back(cur);
  if (cur == graph.size() - 1)  // made it to the last vertex
    res.push_back(path);
  else 
    for (auto it : graph[cur])  // go through each path for this vertex
      dfs(graph, res, path, it);
  path.pop_back();
}

vector<vector<int>> Solution::allPathsSourceTarget(vector<vector<int>>& graph) {
  vector<vector<int>> paths;
  vector<int> path;
  dfs(graph, paths, path, 0);
  return paths;
}