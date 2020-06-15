#include "stdafx.h"
#include "ClosestLeafInABinaryTree.h"

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

void makeGraph(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>> &graph, TreeNode* &start, int k) {
  if (!root) return;
  if (root->val == k) {
    start = root;
  }

  if (parent) {
    graph[parent].push_back(root);
    graph[root].push_back(parent);
  }
  makeGraph(root->left, root, graph, start, k);
  makeGraph(root->right, root, graph, start, k);
}

int Solution::findClosestLeaf(TreeNode* root, int k) {
  unordered_map<TreeNode*, vector<TreeNode*>> graph;
  TreeNode* start = nullptr;

  // use dfs to create a graph and find that target node
  makeGraph(root, nullptr, graph, start, k);

  // use bfs to find the closet left to target
  unordered_set<TreeNode*> visited;
  queue<TreeNode*> q;
  q.push(start);

  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();

    if (node->left == nullptr && node->right == nullptr) {
      return node->val;
    }

    visited.insert(node);

    for (auto &x : graph[node]) {
      if (visited.find(x) == visited.end()) {
        q.push(x);
      }
    }
  }

  return -1;
}