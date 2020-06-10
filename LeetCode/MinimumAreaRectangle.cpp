#include "stdafx.h"
#include "MinimumAreaRectangle.h"

#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

int Solution::minAreaRect(vector<vector<int>>& points) {
/**
* Base case: we need at least 4 points to form a rectangle
*/
  if (points.size() < 4)
    return 0;

  /**
  * minArea: result
  * pointSet: stores all the points
  *   (we can use unordered_set here to reduce the time complexity,
  *    but be aware that in C++ unordered_set doesn't not take type of vector or pair
  *    unless you create a hasher)
  *   referenes:
  *       unordered_set<vector<int>>: https://stackoverflow.com/questions/29855908/c-unordered-set-of-vectors
  *       unordered_set<pair<int, int>>: https://stackoverflow.com/questions/15160889/how-to-make-unordered-set-of-pairs-of-integers-in-c
  */
  int minArea = INT_MAX;
  //set<vector<int>> pointSet;
  unordered_set<int> pointSet;

  for (auto point : points) {
    int code = 40001 * point[0] + point[1];
    pointSet.insert(code);
  }

  for (int i = 0; i < points.size(); i++) {
    for (int j = i + 1; j < points.size(); j++) {
      /**
      * Check if current points pair (<x1, y1> & <x2, y2>) can form a diagonal
      *   If (true):
      *       check if point <x1, y2> && point <x2, y1> exists
      *           If yes:
      *               1. calculate the curArea
      *               2. update the minArea if curArea > minArea
      *           Else:
      *               continue checking next possible pair;
      *   Else:
      *       continue checking next possible pair;
      */
      int xOne = points[i][0], yOne = points[i][1];
      int xTwo = points[j][0], yTwo = points[j][1];

      if (xOne != xTwo && yOne != yTwo && xOne != yTwo && yOne != xTwo) {
        //if (pointSet.count({ xOne, yTwo }) && pointSet.count({ xTwo, yOne })) {
        if (pointSet.count(40001 * xOne + yTwo) && pointSet.count(40001 * xTwo + yOne)) {
          int curArea = (abs(xTwo - xOne) * abs(yTwo - yOne));
          minArea = min(minArea, curArea);
        }
      }
    }
  }

  return minArea == INT_MAX ? 0 : minArea;
}

/*
int Solution::minAreaRect(vector<vector<int>>& points) {
  // creating empty columns 
  // need to use map since smaller x's need to be
  // processed first as y pairs may lead to same key
  map<int, vector<int>> columns;

  // fill columns with coordinates 
  for (auto i : points)
    columns[i[0]].push_back(i[1]);

  // map to find next x with same y pairs
  // can use unordered_map if we create our own hasher
  //map<pair<int, int>, int > lastx;
  unordered_map<int, int > lastx;

  int ans = INT_MAX;

  for (auto x : columns)
  {
    vector<int> column = x.second;
    sort(column.begin(), column.end());

    // iterate through all the y pairs for a given x and save the
    // y pairs to a given x in a hash map.
    // If we find another same y pair in the map, that means this 
    // x can form a rectangle.
    for (int i = 0; i < column.size(); i++)
    {
      for (int j = i + 1; j < column.size(); j++)
      {
        int y1 = column[i];
        int y2 = column[j];
        int code = 40001 * y1 + y2;

        // check if rectangle can be formed 
        //if (lastx.find({ y1, y2 }) != lastx.end())
        if (lastx.find(code) != lastx.end())
        {
          //ans = min(ans, (x.first - lastx[{y1, y2}]) * (y2 - y1));
          ans = min(ans, (x.first - lastx[code]) * (y2 - y1));
        }
        //lastx[{y1, y2}] = x.first;
        lastx[code] = x.first;
      }
    }
  }

  if (ans < INT_MAX)
    return ans;
  else
    return 0;
}
*/