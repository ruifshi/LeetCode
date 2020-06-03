#include "stdafx.h"
#include "CheckCompletenessOfABinaryTree.h"

#include <vector>
#include <queue>

using namespace std;

/*
Use BFS to do a level order traversal,
add childrens to the bfs queue,
until we met the first empty node.

For a complete binary tree,
there should not be any node after we met an empty one.
*/
bool Solution::isCompleteTree(TreeNode* root) {
  vector<TreeNode*> bfs;
  bfs.push_back(root);
  int i = 0;
  while (i < bfs.size() && bfs[i]) {
    bfs.push_back(bfs[i]->left);
    bfs.push_back(bfs[i]->right);
    i++;
  }
  while (i < bfs.size() && !bfs[i])
    i++;
  return i == bfs.size();
}