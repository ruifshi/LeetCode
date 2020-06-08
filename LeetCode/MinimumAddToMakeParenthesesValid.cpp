#include "stdafx.h"
#include "MinimumAddToMakeParenthesesValid.h"

#include <stack>

int Solution::minAddToMakeValid(string S) {
  int left = 0, right = 0;

  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '(') left++;
    if (S[i] == ')') {
      if (left == 0)
        right++;
      else
        left--;
    }
  }

  return left + right;

/*
  stack<int> indicies;
  int missing = 0;

  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '(') {
      indicies.push(S[i]);
    }
    else if (S[i] == ')') {
      if (!indicies.empty()) {  // remove all pairs
        indicies.pop();
      }
      else {
        missing++;  // keeps track of missing ')' and indices has missing '('
      }
    }
  }

  return missing + indicies.size();
*/
}