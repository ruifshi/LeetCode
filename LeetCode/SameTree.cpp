#include "stdafx.h"
#include "SameTree.h"

bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
  if (p == nullptr && q == nullptr) return true;
  if (p == nullptr || q == nullptr) return false;
  if (p->val != q->val) return false;

  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}