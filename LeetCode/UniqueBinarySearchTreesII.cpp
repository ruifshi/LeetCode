#include "stdafx.h"
#include "UniqueBinarySearchTreesII.h"

// pick a root node and find the left and right subtrees
vector<TreeNode*> helper(int start, int end) {
  vector<TreeNode*> res;
  if (start > end) {
    res.push_back(NULL);
    return res;
  }
  for (int i = start; i <= end; i++) {
    vector<TreeNode*> lefts = helper(start, i - 1);
    vector<TreeNode*> rights = helper(i + 1, end);
    for (int j = 0; j < (int)lefts.size(); j++) {
      for (int k = 0; k < (int)rights.size(); k++) {
        TreeNode* root = new TreeNode(i);
        root->left = lefts[j];
        root->right = rights[k];
        res.push_back(root);
      }
    }
  }
  return res;
}

vector<TreeNode*> Solution::generateTrees(int n) {
  if (n == 0) return vector<TreeNode*>(0);
  return helper(1, n);
}