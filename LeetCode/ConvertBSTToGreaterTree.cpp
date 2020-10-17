#include "stdafx.h"
#include "ConvertBSTToGreaterTree.h"

/*
We need to do the work from biggest to smallest, right to left.
pre will record the previous value the we get, which the total sum of bigger values.
*/

int prev = 0;
TreeNode* Solution::convertBST(TreeNode* root) {
  if (!root) return nullptr;

  if (root->right) convertBST(root->right);
  root->val = prev + root->val;
  prev = root->val;
  if (root->left) convertBST(root->left);
  return root;
}