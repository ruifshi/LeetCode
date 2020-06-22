#include "stdafx.h"
#include "KthSmallestElementInABST.h"

#include <vector>

using namespace std;

void helper(TreeNode* node, vector<int> &inOrder) {
  if (!node) return;

  helper(node->left, inOrder);

  inOrder.push_back(node->val);

  helper(node->right, inOrder);
}

int Solution::kthSmallest(TreeNode* root, int k) {
  vector<int> inOrder;

  helper(root, inOrder);

  return inOrder[k - 1];
}

/*
class Solution {
  public int kthSmallest(TreeNode root, int k) {
    LinkedList<TreeNode> stack = new LinkedList<TreeNode>();

    while (true) {
      while (root != null) {
        stack.add(root);
        root = root.left;
      }
      root = stack.removeLast();
      if (--k == 0) return root.val;
      root = root.right;
    }
  }
}
*/