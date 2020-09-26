#include "stdafx.h"
#include "MaximumAverageSubtree.h"

#include <vector>

using namespace std;

// vec[0] = current sum of sub tree starting at this node
// vec[1] = number of nodes in this subtree
vector<int> dfs(TreeNode* node, double &ans) {
  if (!node) return { 0,0 };

  vector<int> left = dfs(node->left, ans);
  vector<int> right = dfs(node->right, ans);

  int sum = node->val + left[0] + right[0];
  int count = 1 + left[1] + right[1];

  double cur_ans = double(sum) / count;
  ans = ans > cur_ans ? ans : cur_ans;
  return { sum, count };
}

double Solution::maximumAverageSubtree(TreeNode* root) {
  if (!root) return 0.0;

  double ans = 0.0;
  dfs(root, ans);
  return ans;
}