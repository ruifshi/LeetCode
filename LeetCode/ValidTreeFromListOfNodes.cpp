#include "stdafx.h"

#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
};

bool isValid(vector<TreeNode*> nodes) {
  unordered_set<TreeNode*> children;
  // child node only has one parent node
  for (TreeNode* &node : nodes) {
    if (node->left != nullptr) {
      if (children.count(node->left)) return false;
      children.insert(node->left);
    }
    if (node->right != nullptr) {
      if (children.count(node->right)) return false;
      children.insert(node->right);
    }
  }

  TreeNode *start = nullptr;
  int count = 0;
  for (TreeNode* &node : nodes) {
    if (!children.count(node)) {
      start = node;
      count++;
    }
  }
  // only has one root node
  if (count > 1) return false;

  // running bfs to make sure all nodes can be constructed as a binary tree 
  queue<TreeNode*> q;
  q.push(start);
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      TreeNode *cur = q.front();
      q.pop();
      if (cur->left != nullptr) {
        q.push(cur->left);
        children.erase(cur->left);
      }
      if (cur->right != nullptr) {
        q.push(cur->right);
        children.erase(cur->right);
      }
    }
  }
  return children.size() == 0;
}