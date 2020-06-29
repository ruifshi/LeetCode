#include "stdafx.h"
#include "PathSumIII.h"

int pathSumHelper(TreeNode* root, int pre, int& sum) {
  if (!root) return 0;
  int current = pre + root->val;
  return (current == sum) + pathSumHelper(root->left, current, sum) + pathSumHelper(root->right, current, sum);
}

int Solution::pathSum(TreeNode* root, int sum) {
  if (!root) return 0;
  // calculate the path sums from root
  // also need to recursively do left and right paths
  return pathSumHelper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}