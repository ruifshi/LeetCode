#include "stdafx.h"
#include "SumOfRootToLeafBinaryNumbers.h"

void helper(TreeNode* root, int curr, int &sum) {
  if (root) {
    curr = (curr << 1) | root->val;
    if (root->left == nullptr && root->right == nullptr) {
      sum += curr;
    }

    helper(root->left, curr, sum);
    helper(root->right, curr, sum);
  }
}

int Solution::sumRootToLeaf(TreeNode* root) {
  int curr = 0;
  int sum = 0;

  helper(root, curr, sum);

  return sum;
}