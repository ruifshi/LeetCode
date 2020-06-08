#include "stdafx.h"
#include "ExamRoom.h"

ExamRoom::ExamRoom(int N) {
  size = N;
}

int ExamRoom::seat() {
  //If seats are all availble, just seat at 0
  if (seats.empty()) {
    seats.insert(0);
    return 0;
  }

  //Consider middle seats 
  int res;
  auto it = seats.begin();
  //If no one seats at 0, initialize position 0 as result
  if (*it != 0) {
    res = 0;
  }
  int diff = *it - 0;                 //diff is the maximum distance to its closest neighbor
  it++;                               //Here it++, because we should calculate from second postion
  while (it != seats.end()) {
    int dis = *it - *prev(it);
    if (dis / 2 > diff) {           //If dis is greater than diff, just update res and diff
      res = *prev(it) + dis / 2;
      diff = dis / 2;
    }
    it++;
  }
  //Consider last seats
  if (size - 1 - *prev(it) > diff) {
    res = size - 1;
  }
  seats.insert(res);
  return res;
}

void ExamRoom::leave(int p) {
  seats.erase(p);
}