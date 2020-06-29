#include "stdafx.h"
#include "RectangleArea.h"

#include <algorithm>

using namespace std;

/*
First, let's think about when overlap will happen? Well, if one rectangle is completely to the left (or right/top/bottom) of the other, then no overlap will happen; otherwise, it will.

How do we know whether a rectangle is completely to the left of the other? Well, just make sure that the right boundary of it is to the left of the left boundary of the other. That is, C <= E. The right/top/bottom cases can be handled similarly by A >= G, D <= F, B >= H.

Now we know how to check for overlap. If overlap happens, how do we compute it? The key is to find the boundary of the overlap.

Take the image at the problem statement as an example. It can be seen that the left boundary of the overlap is max(A, E), the right boundary is min(C, G). The top and bottom boundaries are min(D, H) and max(B, F) similarly. So the area of the overlap is simply (min(C, G) - max(A, E)) * (min(D, H) - max(B, F)).

You should now convince yourself that all kind of overlapping cases can be handled by the above formula by drawing some examples on the paper.
*/
int Solution::computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  int Area1 = (C - A) * (D - B);
  int Area2 = (G - E) * (H - F);
  if (A >= G || C <= E || D <= F || B >= H)
    return Area1 + Area2;
  return Area1 - (min(G, C) - max(A, E)) * (min(D, H) - max(B, F)) + Area2;
}