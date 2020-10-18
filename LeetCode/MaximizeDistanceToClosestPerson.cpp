#include "stdafx.h"
#include "MaximizeDistanceToClosestPerson.h"

#include <algorithm>

/*
As we iterate through seats, we'll update the closest person sitting to our left, 
and closest person sitting to our right.

Algorithm

Keep track of prev, the filled seat at or to the left of i, and future, the filled seat at or to 
the right of i.

Then at seat i, the closest person is min(i - prev, future - i), with one exception. i - prev 
should be considered infinite if there is no person to the left of seat i, and similarly future - i 
is infinite if there is no one to the right of seat i.
*/
int maxDistToClosest(vector<int>& seats) {
  int N = seats.size();
  int prev = -1, future = 0;
  int ans = 0;

  for (int i = 0; i < N; ++i) {
    if (seats[i] == 1) {
      prev = i;
    }
    else {
      while (future < N && seats[future] == 0 || future < i)
        future++;

      int left = prev == -1 ? N : i - prev;
      int right = future == N ? N : future - i;
      ans = max(ans, min(left, right));
    }
  }

  return ans;
}