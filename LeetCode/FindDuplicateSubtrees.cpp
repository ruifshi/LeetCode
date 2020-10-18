#include "stdafx.h"
#include "FindDuplicateSubtrees.h"

#include <unordered_map>
#include <string>

string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& map) {
  if (!node) return "";
  string s = to_string(node->val) + "," + serialize(node->left, map) + "," + serialize(node->right, map);
  map[s].push_back(node);
  return s;
}

vector<TreeNode*> Solution::findDuplicateSubtrees(TreeNode* root) {
  unordered_map<string, vector<TreeNode*>> map;
  vector<TreeNode*> dups;
  serialize(root, map);
  for (auto it = map.begin(); it != map.end(); it++)
    if (it->second.size() > 1) dups.push_back(it->second[0]);
  return dups;
}