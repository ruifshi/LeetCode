#include "stdafx.h"
#include "IncreasingOrderSearchTree.h"

TreeNode* newroot, *curr;

TreeNode* increasingBST(TreeNode* root) {
  if (root == NULL) return NULL;
  increasingBST(root->left);

  if (newroot == NULL) {  // find root
    newroot = new TreeNode(root->val);
    curr = newroot;
  }
  else {
    curr->right = new TreeNode(root->val);  // connect other in order
    curr = curr->right;
  }

  increasingBST(root->right);
  return newroot;
}