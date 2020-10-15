#include "stdafx.h"
#include "SumOfNodesWithEvenValuedGrandparent.h"

int helper(TreeNode* current, TreeNode* parent, TreeNode* grandParent) {
  int sum = 0;
  if (!current) return 0;
  if (grandParent && grandParent->val % 2 == 0) {
    sum += current->val;
  }
  sum += helper(current->left, current, parent);
  sum += helper(current->right, current, parent);
  return sum;

}

int Solution::sumEvenGrandparent(TreeNode* root) {
  return helper(root, nullptr, nullptr); //Perform DFS
}