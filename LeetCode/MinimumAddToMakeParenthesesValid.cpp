#include "stdafx.h"
#include "MinimumAddToMakeParenthesesValid.h"

#include <stack>

int Solution::minAddToMakeValid(string S) {
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
}