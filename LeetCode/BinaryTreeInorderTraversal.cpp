#include "stdafx.h"
#include "BinaryTreeInorderTraversal.h"

#include <stack>

vector<int> Solution::inorderTraversal(TreeNode* root) {
  if (!root) return {};

  vector<int> out;
  stack<TreeNode*> stk;
  TreeNode* curr = root;

  while (curr || !stk.empty()) {
    // use stk to keep track of left nodes until no more, then move to right
    while (curr) {
      stk.push(curr);
      curr = curr->left;
    }

    curr = stk.top();
    stk.pop();
    out.push_back(curr->val);

    curr = curr->right;
  }

  return out;
}