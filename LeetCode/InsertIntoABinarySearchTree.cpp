#include "stdafx.h"
#include "InsertIntoABinarySearchTree.h"

TreeNode* Solution::insertIntoBST(TreeNode* root, int val) {
  if (!root) return new TreeNode(val);

  // insert into the right subtree
  if (val > root->val) root->right = insertIntoBST(root->right, val);
  // insert into the left subtree
  else root->left = insertIntoBST(root->left, val);
  return root;
}