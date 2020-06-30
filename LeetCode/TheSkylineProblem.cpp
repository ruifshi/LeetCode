#include "stdafx.h"
#include "TheSkylineProblem.h"

#include <algorithm>
#include <set>

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
  vector<vector<int>> edges;
  int left, right, height;
  for (int i = 0; i < buildings.size(); i++) {
    left = buildings[i][0];
    right = buildings[i][1];
    height = buildings[i][2];
    /*** make sure : for the same left point we use the bigger height ***/
    edges.push_back({ left, -height }); // negative to specify beginning of building
    edges.push_back({ right, height });
  }

  // sort by x coordinate
  sort(edges.begin(), edges.end());
  vector<vector<int>> result;
  /*** use the multiset to store the max height util current pos ***/
  multiset<int> m;
  /*** left most height ***/
  m.insert(0);
  int pre = 0, cur = 0;
  for (int i = 0; i < edges.size(); i++) {
    vector<int> e = edges[i];

    // if a start, then add it to set to keep track of current tallest
    if (e[1] < 0)  m.insert(-e[1]);
    // if end, then we need to remove previous start
    else m.erase(m.find(e[1]));

    // cur is the tallest building seen so far
    // if this is overshadowing previous building, then we take the coordinate
    cur = *(m.rbegin());
    if (cur != pre) {
      result.push_back({ e[0], cur });
      pre = cur;
    }
  }
  return result;
}