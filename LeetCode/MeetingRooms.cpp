#include "stdafx.h"
#include "MeetingRooms.h"

#include <algorithm>

bool mycomp2(const vector<int> & i1, const vector<int> & i2) {
  return i1[0] < i2[0];
}

// sort by starting times and see if there are intersections
bool Solution::canAttendMeetings(vector<vector<int>>& intervals) {
  if (intervals.size() == 0) return true;

  sort(intervals.begin(), intervals.end(), mycomp2);

  for (int i = 0; i < intervals.size() - 1; i++) {
    if (intervals[i][1] > intervals[i + 1][0]) {
      return false;
    }
  }

  return true;
}