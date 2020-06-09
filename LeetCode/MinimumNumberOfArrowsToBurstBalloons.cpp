#include "stdafx.h"
#include "MinimumNumberOfArrowsToBurstBalloons.h"

#include <algorithm>

// merge intervals and return num of merged
int Solution::findMinArrowShots(vector<vector<int>>& points) {
  if (points.size() == 0) return 0;

  // sort according to start
  sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {return a[1] < b[1];});  // sort by end

  int arrows = 1;
  int start = points[0][0], cur_end;  // start and end of current points
  int end = points[0][1]; // last end

  for (int i = 1; i < points.size(); i++) {
    start = points[i][0];
    cur_end = points[i][1];

    if (end < start) {  // if current start is not intersecting, then need more arrows
      arrows++;
      end = cur_end;
    }
  }

  return arrows;
}