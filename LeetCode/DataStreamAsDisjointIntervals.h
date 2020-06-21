#pragma once

#include <vector>
#include <set>

using namespace std;

class SummaryRanges {
private:
  set <int> nums;
public:
  /** Initialize your data structure here. */
  SummaryRanges();

  void addNum(int val);

  vector<vector<int>> getIntervals();
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */