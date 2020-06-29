#include "stdafx.h"
#include "BinaryTreePostorderTraversal.h"

#include <stack>

vector<int> Solution::postorderTraversal(TreeNode* root) {
  if (!root) return {};

  vector<int> out;
  stack<TreeNode*> stk;

  stk.push(root);

  while (!stk.empty()) {
    TreeNode* node = stk.top();
    stk.pop();
    out.push_back(node->val);

    if (node->left) stk.push(node->left);
    if (node->right) stk.push(node->right);
  }

  reverse(out.begin(), out.end());

  return out;
}