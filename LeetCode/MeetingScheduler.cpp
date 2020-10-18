#include "stdafx.h"
#include "MeetingScheduler.h"

#include <algorithm>

vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
  sort(slots1.begin(), slots1.end()); // sort increasing by start time (default sorting by first value)
  sort(slots2.begin(), slots2.end()); // sort increasing by start time (default sorting by first value)

  int i = 0, j = 0;
  int n1 = slots1.size(), n2 = slots2.size();
  while (i < n1 && j < n2) {
    // Find intersect between slots1[i] and slots2[j]
    int intersectStart = max(slots1[i][0], slots2[j][0]);
    int intersectEnd = min(slots1[i][1], slots2[j][1]);

    if (intersectStart + duration <= intersectEnd) // Found the result
      return { intersectStart, intersectStart + duration };
    else if (slots1[i][1] < slots2[j][1])
      i++;
    else
      j++;
  }
  return {};
}

/*
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (auto s : slots1) {
        if (s[1] - s[0] >= duration) q.push({ s[0], s[1] });
    }
    for (auto s : slots2) {
        if (s[1] - s[0] >= duration) q.push({ s[0], s[1] });
    }
    while (q.size() > 1) {
        auto end1 = q.top().second;
        q.pop();
        auto start2 = q.top().first;
        if (end1 >= start2 + duration)
            return { start2, start2 + duration };
    }
    return {};
*/