#pragma once

#include <stack>

using namespace std;

class StockSpanner {
private:
  stack<pair<int, int>> stk;
public:
  StockSpanner();

  int next(int price);
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */