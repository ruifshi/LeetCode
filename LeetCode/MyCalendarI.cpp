#include "stdafx.h"
#include "MyCalendarI.h"

MyCalendar::MyCalendar() {

}

bool MyCalendar::book(int start, int end) {
  auto iter = Map.upper_bound(start); // An iterator to the the first element in the container whose key is considered to go after k, or map::end if no keys are considered to go after k.
  if (iter != Map.begin())  // check if this range is within a range by looking at prev
  {
    auto iter2 = prev(iter, 1);
    if (start < iter2->second) return false;
  }
  if (iter != Map.end())  // check if this is intersecting upper bound range
  {
    if (end > iter->first) return false;
  }
  Map[start] = end;
  return true;
}

/* O(N)
class MyCalendar {
    vector<pair<int, int>> books;
public:
    bool book(int start, int end) {
        for (pair<int, int> p : books)
            if (max(p.first, start) < min(end, p.second)) return false;
        books.push_back({start, end});
        return true;
    }
};
*/