#include "stdafx.h"
#include "OnlineStockSpan.h"

//stack<pair<int, int>> stk;
// keeps track of cumlative lower prices before current price
// elements are poped if it's lower bc you know this one is smallest in chain (higher ones are kept for future values)
// first element is the price 
// second element is the number of stocks less than or equal to current before

StockSpanner::StockSpanner() {

}

int StockSpanner::next(int price) {
  int res = 1;
  while (!stk.empty() && stk.top().first <= price) {
    res += stk.top().second;
    stk.pop();
  }

  stk.push({ price, res });
  return res;
}