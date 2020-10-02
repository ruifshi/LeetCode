#include "stdafx.h"
#include "LineReflection.h"

#include <set>
#include <algorithm>

using namespace std;

/*
Notice that if there is a valid symmetry line, the two points with max x and min x must be symmetric about it.
After finding out the line, iterate through each point and look for its symmetric counterpart. If symmetric point cannot be found, return false.
*/

bool Solution::isReflected(vector<vector<int>>& points) {
  set<vector<int>> set_points;  // can use unordered if have custom hashing function
  int max_x = INT_MIN;
  int min_x = INT_MAX;
  for (const auto& p : points) {
    max_x = max(max_x, p[0]);
    min_x = min(min_x, p[0]);
    set_points.insert(p);
  }

  int symmetric_x_doubled = max_x + min_x;
  for (auto p : set_points) {
    auto reflect = { symmetric_x_doubled - p[0], p[1] };
    if (set_points.count(reflect) == 0) {
      return false;
    }
  }
  return true;
}