#pragma once

#include <vector>

using namespace std;

class CustomStack {
private:
  vector<int> stk;
  vector<int> incHist;
  int maxSize;

public:
  CustomStack(int maxSize);

  void push(int x);

  int pop();

  void increment(int k, int val);
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */