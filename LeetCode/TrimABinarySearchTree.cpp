#include "stdafx.h"
#include "TrimABinarySearchTree.h"

/*
If the root value in the range [L, R]
      we need return the root, but trim its left and right subtree;
else if the root value < L
      because of binary search tree property, the root and the left subtree are not in range;
      we need return trimmed right subtree.
else
      similarly we need return trimmed left subtree.
*/
TreeNode* Solution::trimBST(TreeNode* root, int L, int R) {
  if (!root) return root;

  if (root->val > R) return trimBST(root->left, L, R);
  if (root->val < L) return trimBST(root->right, L, R);

  root->left = trimBST(root->left, L, R);
  root->right = trimBST(root->right, L, R);

  return root;
}