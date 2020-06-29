#include "stdafx.h"
#include "TwoSumIVInputIsABST.h"

#include <unordered_set>

using namespace std;

bool dfs(TreeNode* node, int k, unordered_set<int> &valSet) {
  if (!node) return false;
  if (valSet.find(k - node->val) != valSet.end()) {
    return true;
  }

  valSet.insert(node->val);

  return dfs(node->left, k, valSet) || dfs(node->right, k, valSet);
}

bool Solution::findTarget(TreeNode* root, int k) {
  if (!root) return false;

  unordered_set<int> valSet;

  return dfs(root, k, valSet);
}