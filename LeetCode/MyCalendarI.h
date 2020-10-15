#pragma once

#include <map>

using namespace std;

class MyCalendar {
private:
  map<int, int> Map;

public:
  MyCalendar();

  bool book(int start, int end);
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */