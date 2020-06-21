#include "stdafx.h"
#include "DataStreamAsDisjointIntervals.h"

#include <algorithm>

/*
For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]  2 merges 1,3
[1, 3], [6, 7]  6 merges 7
*/

/** Initialize your data structure here. */
SummaryRanges::SummaryRanges() {

}

void SummaryRanges::addNum(int val) {
  nums.insert(val);
}

vector<vector<int>> SummaryRanges::getIntervals() {
  vector < vector <int> > ret;
  auto it = nums.begin();
  while (it != nums.end()) {
    int val = *it;

    // separate if not consecutive
    if (ret.empty() || ret.back()[1] + 1 < val) {
      ret.push_back({ val, val });
    }
    // merge if consecutive values
    else {
      ret.back()[1]++;
    }
    it++;
  }
  return ret;
}