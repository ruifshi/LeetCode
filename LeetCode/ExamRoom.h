#pragma once

#include <set>

using namespace std;

class ExamRoom {
private:
  set<int> seats;
  int size;

public:
  ExamRoom(int N);

  int seat();

  void leave(int p);
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */