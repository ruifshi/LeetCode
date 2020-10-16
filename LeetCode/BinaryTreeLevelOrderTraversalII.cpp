#include "stdafx.h"
#include "BinaryTreeLevelOrderTraversalII.h"

#include <queue>

vector<vector<int>> Solution::levelOrderBottom(TreeNode* root) {
  if (!root) return {};

  queue<TreeNode*> q;
  vector<vector<int>> levels;

  q.push(root);

  while (!q.empty()) {
    int qsize = q.size();
    vector<int> level;

    for (int i = 0; i < qsize; i++) {
      TreeNode* node = q.front();
      q.pop();
      level.push_back(node->val);

      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }

    levels.push_back(level);
  }

  reverse(levels.begin(), levels.end());

  return levels;
}