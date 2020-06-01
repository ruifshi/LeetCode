#include "stdafx.h"
#include "SimplifyPath.h"

#include <vector>
#include <stack>
#include <string>
#include <sstream>

string Solution::simplifyPath(string path) {
  string res, s;
  stack<string>stk;
  stringstream ss(path);
  while (getline(ss, s, '/')) {
    if (s == "" || s == ".") continue;
    if (s == ".." && !stk.empty()) stk.pop();
    else if (s != "..") stk.push(s);
  }
  while (!stk.empty()) {
    res = "/" + stk.top() + res;
    stk.pop();
  }
  return res.empty() ? "/" : res;
}

/*
string simplifyPath(string path) {
  std::string ret;
  int skip = 0;
  for (auto it = path.rbegin(); it != path.rend(); ) {
    if ('.' == *it && '.' == *(it + 1) && '/' == *(it + 2)) {
      ++skip;
      it = it + 3;
    } else if ('.' == *it && '/' == *(it + 1)) {
      it = it + 2;
    } else if ('/' == *it) {
      ++it;
    } else if (skip) {
      it = std::find(it, path.rend(), '/');
      --skip;
    } else {
      do {
        ret.push_back(*it);
      }
      while ('/' != *it++);
    }
  }
  std::reverse(ret.begin(), ret.end());
  return ret.empty() ? "/" : ret;
}
*/