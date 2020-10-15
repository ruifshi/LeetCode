#include "stdafx.h"
#include "ScoreOfParentheses.h"

#include <stack>
#include <algorithm>

/*
If we meet '(',
we push the current score to stack,
enter the next inner layer level,
and reset cur = 0.

If we meet ')',
the cur score will be doubled and will be at least 1.
We exit the current layer level,
and set cur = stack.pop() + cur

Complexity: O(N) time and O(N) space
*/
int Solution::scoreOfParentheses(string S) {
  stack<int> stack;
  int cur = 0;
  for (char i : S)
    if (i == '(') {
      stack.push(cur);
      cur = 0;
    }
    else {
      cur += stack.top() + max(cur, 1);
      stack.pop();
    }
  return cur;
}

/*
We count the number of layers.
If we meet '(' layers number l++
else we meet ')' layers number l--

If we meet "()", we know the number of layer outside,
so we can calculate the score res += 1 << l.
*/
/*
int scoreOfParentheses(string S) {
  int res = 0, l = 0;
  for (int i = 0; i < S.length(); ++i) {
    if (S[i] == '(') l++; else l--;
    if (S[i] == ')' && S[i - 1] == '(') res += 1 << l;
  }
  return res;
}
*/