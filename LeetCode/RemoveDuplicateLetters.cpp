#include "stdafx.h"
#include "RemoveDuplicateLetters.h"

#include <unordered_set>
#include <stack>

/*
Always make the element in the stack top as small as possible
Everytime you push the element, if the top element is larger than the current element and the top element can be found in the future, pop it.
*/
string Solution::removeDuplicateLetters(string s) {
  int cnt[26] = { 0 };
  for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;

  unordered_set<char> uset;
  stack<char> stk;
  for (int i = 0; i < s.size(); i++) {
    char now = s[i];
    cnt[s[i] - 'a']--;
    if (uset.count(now))continue;
    uset.insert(now);
    if (stk.size() == 0)stk.push(now);
    else {
      while (stk.size() && stk.top() > now && cnt[stk.top() - 'a']) {
        uset.erase(uset.find(stk.top()));
        stk.pop();
      }
      stk.push(now);
    }
  }
  string ret = "";
  while (stk.size()) {
    ret = stk.top() + ret;
    stk.pop();
  }
  return ret;
}