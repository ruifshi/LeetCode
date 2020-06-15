#include "stdafx.h"
#include "ConstructBinaryTreeFromString.h"

#include <stack>

TreeNode* Solution::str2tree(string s) {
  stack<TreeNode*> stk;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') continue;

    if (isdigit(s[i]) || s[i] == '-') {
      int num = 0;
      int sign = 1;

      if (s[i] == '-') {
        sign = -1;
        i++;
      }

      while (i < s.size() && isdigit(s[i])) {
        num = num * 10 + s[i] - '0';
        i++;
      }

      stk.push(new TreeNode(num * sign));
      // needed since previous while loop iterates to correct place but
      // for loop increments again
      i--;
    }
    else {  // ')'
      TreeNode *child = stk.top();
      stk.pop();
      TreeNode *parent = stk.top();

      // left always comes first
      if (parent->left == nullptr) {
        parent->left = child;
      }
      else {
        parent->right = child;
      }
    }
  }

  return stk.empty() ? nullptr : stk.top();
}