#include "stdafx.h"
#include "SumRoottoLeafNumbers.h"

void sumNumbersHelper(TreeNode* node, int currentSum, int &total) {
  if (!node) return;

  currentSum = currentSum * 10 + node->val;

  if (!node->left && !node->right) {
    total += currentSum;
  }

  sumNumbersHelper(node->left, currentSum, total);
  sumNumbersHelper(node->right, currentSum, total);
}

int Solution::sumNumbers(TreeNode* root) {
  int total = 0;
  sumNumbersHelper(root, 0, total);
  return total;
}