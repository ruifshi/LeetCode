#include "stdafx.h"
#include "BasicCalculatorII.h"

#include <stack>

int Solution::calculate2(string s) {
  stack<int> myStack;
  char sign = '+';
  long res = 0, tmp = 0;
  for (unsigned int i = 0; i < s.size(); i++) {
    if (isdigit(s[i]))
      tmp = 10 * tmp + s[i] - '0';  // process numbers with multiple digit
    // decide how to process the signs
    // stack contains all the partial sums
    if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {  // process last digit
      if (sign == '-')
        myStack.push(-tmp);
      else if (sign == '+')
        myStack.push(tmp);
      else {
        int num;
        if (sign == '*')
          num = myStack.top()*tmp;
        else
          num = myStack.top() / tmp;
        myStack.pop();
        myStack.push(num);
      }
      sign = s[i];
      tmp = 0;
    }
  }
  while (!myStack.empty()) {
    res += myStack.top();
    myStack.pop();
  }
  return res;
}