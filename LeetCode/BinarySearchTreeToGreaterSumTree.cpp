#include "stdafx.h"
#include "BinarySearchTreeToGreaterSumTree.h"

/*
We need to do the work from biggest to smallest, right to left.
pre will record the previous value the we get, which the total sum of bigger values.
*/

int pre = 0;
TreeNode* Solution::bstToGst(TreeNode* root) {
  if (root->right) bstToGst(root->right);
  root->val = pre + root->val;
  pre = root->val;
  if (root->left) bstToGst(root->left);
  return root;
}