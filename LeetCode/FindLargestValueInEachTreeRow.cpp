#include "stdafx.h"
#include "FindLargestValueInEachTreeRow.h"

#include <queue>

vector<int> Solution::largestValues(TreeNode* root) {
  if (root == nullptr) return {};

  queue<TreeNode*> q;
  vector<int> largest;

  q.push(root);

  while (!q.empty()) {
    int q_size = q.size();
    int max = INT_MIN;

    for (int i = 0; i < q_size; i++) {
      TreeNode* node = q.front();
      q.pop();

      max = max > node->val ? max : node->val;

      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }

    largest.push_back(max);
  }

  return largest;
}