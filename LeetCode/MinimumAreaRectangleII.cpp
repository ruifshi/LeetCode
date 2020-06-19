#include "stdafx.h"
#include "MinimumAreaRectangleII.h"

#include <unordered_set>
#include <string>

string createKey(int a, int b) {
  return to_string(a) + "_" + to_string(b);
}

/*
Say the first 3 points are p1, p2, p3, and that p2 and p3 are opposite corners of the final rectangle. 
The 4th point must be p4 = p2 + p3 - p1 (using vector notation) because p1, p2, p4, p3 
must form a parallelogram, and p1 + (p2 - p1) + (p3 - p1) = p4.

If this point exists in our collection (we can use a HashSet to check), 
then we should check that the angles of this parallelogram are 90 degrees. 
The easiest way is to check the dot product of the two vectors (p2 - p1) and (p3 - p1). 
(Another way is we could normalize the vectors to length 1, and check that one equals the other rotated by 90 degrees.)
*/
double Solution::minAreaFreeRect(vector<vector<int>>& points) {
  unordered_set<string> pointSet;

  for (auto &p : points) {
    pointSet.insert(createKey(p[0], p[1]));
  }

  double ans = INT_MAX;

  for (int i = 0; i < points.size(); i++) {
    int p1x = points[i][0];
    int p1y = points[i][1];

    for (int j = i + 1; j < points.size(); j++) {

      int p2x = points[j][0];
      int p2y = points[j][1];

      for (int k = j + 1; k < points.size(); k++) {

        int p3x = points[k][0];
        int p3y = points[k][1];

        int p4x = p2x + p3x - p1x;
        int p4y = p2y + p3y - p1y;

        if (pointSet.count(createKey(p4x, p4y))) {
          int dot = (p2x - p1x) * (p3x - p1x) + (p2y - p1y) * (p3y - p1y);

          if (dot == 0) {
            double w = pow(pow(p2x - p1x, 2) + pow(p2y - p1y, 2), 0.5);
            double l = pow(pow(p3x - p1x, 2) + pow(p3y - p1y, 2), 0.5);
            double area = w * l;

            ans = area > ans ? ans : area;
          }
        }
      }

    }
  }

  return ans < INT_MAX ? ans : 0;
}