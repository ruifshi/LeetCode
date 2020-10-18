#include "stdafx.h"
#include "TimeBasedKeyValueStore.h"

/*
We use hash map to lookup ordered {timestamp, value} pairs by key in O(1). 
Then, we use binary search to find the value with a timestamp less or equal than the requested one.
*/
/** Initialize your data structure here. */
TimeMap::TimeMap() {

}

void TimeMap::set(string key, string value, int timestamp) {
  m[key].insert({ timestamp, value });
}

string TimeMap::get(string key, int timestamp) {
  auto it = m[key].upper_bound(timestamp);
  return it == m[key].begin() ? "" : prev(it)->second;
}

/*
Assuming n is the number of set operations, and m is the number of get operations:

Time Complexity:
Set: O(1) single operation, and total O(n).
Note: assuing timestamps are only increasing. If not, it's O(n log n).
Get: O(log n) for a single operation, and total O(m log n).
Space Complexity: O(n) (assuming every { timestamp, value } is unique).
*/