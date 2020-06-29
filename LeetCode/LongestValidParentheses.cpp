#include "stdafx.h"
#include "LongestValidParentheses.h"

#include <stack>
#include <algorithm>

int Solution::longestValidParentheses(string s) {
  if (s.size() == 0) return 0;

  int maxP = 0;
  // keeps track of index of previous '('
  // and not valid ')'
  stack<int> stk;

  stk.push(-1); // base case index 0 and 1 are valid so 2

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      stk.push(i);
    }
    else {
      stk.pop();
      if (stk.empty()) {  // not valid
        stk.push(i);
      }
      else {
        maxP = max(maxP, i - stk.top());
      }
    }
  }

  return maxP;
}

/*
public class Solution {
    public int longestValidParentheses(String s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * right);
            } else if (right >= left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * left);
            } else if (left >= right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
}
*/