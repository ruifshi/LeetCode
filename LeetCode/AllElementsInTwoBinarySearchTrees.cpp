#include "stdafx.h"
#include "AllElementsInTwoBinarySearchTrees.h"

void elementshelper(TreeNode* node, vector<int> &v) {
  if (!node) return;

  elementshelper(node->left, v);

  v.push_back(node->val);

  elementshelper(node->right, v);
}

vector<int> Solution::getAllElements(TreeNode* root1, TreeNode* root2) {
  vector<int> v1, v2, out;

  elementshelper(root1, v1);
  elementshelper(root2, v2);

  int p1 = 0, p2 = 0;
  while (p1 < v1.size() && p2 < v2.size()) {
    if (v1[p1] < v2[p2]) {
      out.push_back(v1[p1]);
      p1++;
    }
    else {
      out.push_back(v2[p2]);
      p2++;
    }
  }

  while (p1 < v1.size()) {
    out.push_back(v1[p1]);
    p1++;
  }
  while (p2 < v2.size()) {
    out.push_back(v2[p2]);
    p2++;
  }

  return out;
}