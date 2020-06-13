#include "stdafx.h"
#include "SimplifyPath.h"

#include <vector>
#include <stack>
#include <string>
#include <sstream>

string Solution::simplifyPath(string path) {
  string res, s;
  stack<string>stk;
  //stringstream ss(path);
  //while(getline(ss, s, '/')) {  // gets sub with deliminator or until null char is reached
  path += '/';
  while (path.find('/') != string::npos) {
    s = path.substr(0, path.find('/'));
    path = path.substr(path.find('/') + 1);

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
