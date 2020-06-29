#include "stdafx.h"
#include "BinaryTreeLevelOrderTraversal.h"

#include <queue>;

vector<vector<int>> levelOrder(TreeNode* root) {
  if (!root) return {};

  vector<vector<int>> levels;
  queue<TreeNode*> q;

  q.push(root);

  while (!q.empty()) {
    int qSize = q.size();
    vector<int> level;
    for (int i = 0; i < qSize; i++) {
      TreeNode* node = q.front();
      q.pop();
      level.push_back(node->val);

      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }

    levels.push_back(level);
  }

  return levels;
}