#include "stdafx.h"
#include "ClosestBinarySearchTreeValueII.h"

#include <queue>

void closestKValuesHelper(TreeNode* node, double target, int k, priority_queue<pair<double, int>>& pq) {
  if (!node) return;

  pq.push({ fabs(target - double(node->val)), node->val });

  if (pq.size() > k) {
    pq.pop();
  }

  closestKValuesHelper(node->left, target, k, pq);
  closestKValuesHelper(node->right, target, k, pq);
}

vector<int> Solution::closestKValues(TreeNode* root, double target, int k) {
  if (!root) return {};

  priority_queue<pair<double, int>> pq;
  vector<int> res;
  closestKValuesHelper(root, target, k, pq);

  while (!pq.empty()) {
    res.push_back(pq.top().second);
    pq.pop();
  }

  return res;
}