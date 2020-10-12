#include "stdafx.h"
#include "CheckIfAStringIsAValidSequenceFromRootToLeavesPathInABinaryTree.h"

bool helper(TreeNode* root, string target, string path) {
  if (!root) return false;

  path.push_back(root->val + '0');

  if (root->left == nullptr && root->right == nullptr) {
    if (target == path) return true;
    else return false;
  }
  else {
    return helper(root->left, target, path) || helper(root->right, target, path);
  }
}

bool Solution::isValidSequence(TreeNode* root, vector<int>& arr) {
  string target;

  for (int i = 0; i < arr.size(); i++) {
    target += arr[i] + '0';
  }

  string path;
  return helper(root, target, path);
}