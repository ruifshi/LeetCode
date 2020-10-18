#include "stdafx.h"
#include "DeleteLeavesWithAGivenValue.h"

/*
Recursively call removeLeafNodes on the left and right.
If root.left == root.right == null and root.val == target,
the root node is now a leaf with value = target, we return null.
Otherwise return root node itself.
*/
TreeNode* Solution::removeLeafNodes(TreeNode* root, int target) {
  if (!root) return nullptr;

  if (root->left) root->left = removeLeafNodes(root->left, target);
  if (root->right) root->right = removeLeafNodes(root->right, target);
  return root->left == root->right && root->val == target ? nullptr : root;
}