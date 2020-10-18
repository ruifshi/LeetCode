#include "stdafx.h"
#include "RectangleOverlap.h"

//https://leetcode.com/problems/rectangle-overlap/discuss/133175/C%2B%2B-Solution-with-easy-explanation
bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
  int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
  int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
  return (x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2);

/*
  //Handle Invalid testcases like [-1,0,1,1] [0,-1,0,1]
  if(rec1[0]==rec1[2] || rec1[1]==rec1[3] || rec2[0]==rec2[2] || rec2[1]==rec2[3])
    return false;

        return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // top
*/
}