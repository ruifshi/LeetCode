#include "stdafx.h"
#include "CourseScheduleII.h"

bool acyclic(vector<vector<int>>& g, vector<bool>& todo, vector<bool>& done, int node, vector<int>& order) {
  if (todo[node]) {
    return false;
  }
  if (done[node]) {
    return true;
  }
  todo[node] = done[node] = true;
  for (int neigh : g[node]) {
    if (!acyclic(g, todo, done, neigh, order)) {
      return false;
    }
  }
  order.push_back(node);
  todo[node] = false;
  return true;
}

vector<int> Solution::findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  vector<vector<int>> g(numCourses);

  for (auto p : prerequisites) {
    g[p[0]].push_back(p[1]);
  }

  vector<int> order;
  vector<bool> todo(numCourses, false), done(numCourses, false);
  for (int i = 0; i < numCourses; i++) {
    if (!done[i] && !acyclic(g, todo, done, i, order)) {
      return {};
    }
  }

  return order;
}