#include "stdafx.h"
#include "BaseballGame.h"

#include <stack>

int Solution::calPoints(vector<string>& ops) {
  stack<int> stk;

  // stack keeps a history of previous valid rounds
  // after performing operations
  for (auto op : ops) {
    if (op == "+") {
      int top = stk.top();
      stk.pop();
      int newTop = top + stk.top();
      stk.push(top);
      stk.push(newTop);
    }
    else if (op == "C") {
      stk.pop();
    }
    else if (op == "D") {
      stk.push(2 * stk.top());
    }
    else {
      stk.push(stoi(op));
    }
  }

  int ans = 0;
  while (!stk.empty()) {
    ans += stk.top();
    stk.pop();
  }

  return ans;
}