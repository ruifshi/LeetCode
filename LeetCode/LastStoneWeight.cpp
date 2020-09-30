#include "stdafx.h"
#include "LastStoneWeight.h"

#include <queue>

int Solution::lastStoneWeight(vector<int>& stones) {
  priority_queue<int> q(stones.begin(), stones.end());

  // While there is more than one stone left, we need to remove the two largest
  // and smash them together. If there is a resulting stone, we need to put into
  // the heap.
  while (q.size() > 1) {
    int stone1 = q.top(); 
    q.pop();
    int stone2 = q.top();
    q.pop();

    if (stone1 != stone2) {
      q.push(stone1 - stone2);
    }
  }

  return q.empty() ? 0 : q.top();
}