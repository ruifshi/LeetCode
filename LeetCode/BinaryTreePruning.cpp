#include "stdafx.h"
#include "BinaryTreePruning.h"

TreeNode* Solution::pruneTree(TreeNode* root) {
  if (!root) return nullptr;
  root->left = pruneTree(root->left);
  root->right = pruneTree(root->right);
  if (!root->left && !root->right && root->val == 0) return nullptr;  //can delete node if we want to free memory
  return root;
}