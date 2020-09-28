#include "stdafx.h"
#include "BusRoutes.h"

#include <unordered_map>
#include <queue>
#include <unordered_set>

/*
The first part loop on routes and record stop to routes mapping in to_route.
The second part is general bfs. Take a stop from queue and find all connected route.
The hashset seen record all visited stops and we won't check a stop for twice.
We can also use a hashset to record all visited routes, or just clear a route after visit.
*/

int Solution::numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
  unordered_map<int, vector<int>> to_routes;

  for (int i = 0; i < routes.size(); ++i)
    for (int j : routes[i])
      to_routes[j].push_back(i);

  queue<pair<int, int>> bfs;
  bfs.push({ S, 0 });
  unordered_set<int> seen = { S };

  while (!bfs.empty()) {
    int stop = bfs.front().first, bus = bfs.front().second;
    bfs.pop();
    if (stop == T)
      return bus;
    for (int i : to_routes[stop]) {
      for (int j : routes[i]) {
        if (seen.find(j) == seen.end()) {
          seen.insert(j);
          bfs.push({ j, bus + 1 });
        }
      }
      routes[i].clear();
    }
  }
  return -1;
}