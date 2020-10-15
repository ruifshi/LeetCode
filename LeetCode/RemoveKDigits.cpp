#include "stdafx.h"
#include "RemoveKDigits.h"

#include <deque>

/*
Given a sequence of digits [D1 D2 D3...Dn], if the digit D2 is less than its left neighbor D1, 
then we should remove the left neighbor (D1) in order to obtain the minimum result.

see 425

case 1). when we get out of the main loop, we removed m digits, which is less than asked, i.e.(m < k). In the extreme case, we would not remove any digit for the 
         monotonic increasing sequence in the loop, i.e. m==0. In this case, we just need to remove the additional k-m digits from the tail of the sequence.

case 2). once we remove all the k digits from the sequence, there could be some leading zeros left. To format the final number, we need to strip off those leading zeros.

case 3). we might end up removing all numbers from the sequence. In this case, we should return zero, instead of empty string.


*/
string Solution::removeKdigits(string num, int k) {
  deque<char> stk;

  for (char &c : num) {
    while (stk.size() > 0 && k > 0 && stk.back() > c) {  // remove prev element if bigger than cur
      stk.pop_back();
      k--;
    }

    stk.push_back(c);
  }

  /* remove the remaining digits from the tail. */
  for (int i = 0; i < k; ++i) {
    stk.pop_back();
  }

  // build the final string, while removing the leading zeros.
  string s;
  bool leadingZero = true;
  while(!stk.empty()) {
    char c = stk.front();
    stk.pop_front();
    if (leadingZero && c == '0') continue;
    leadingZero = false;
    s += c;
  }

  if (s.size() == 0) return "0";

  return s;
}