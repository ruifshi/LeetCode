#include "stdafx.h"
#include "LargestBSTSubtree.h"

#include <limits>
#include <algorithm>

using namespace std;

struct bstNode {
  int min;  // current min of subtree
  int max;  // current max of subtree
  int num_nodes;  // num of nodes in subtree
};

bstNode largestBSTSubtreeHelper(TreeNode* root) {
  if (!root) {
    return { INT_MAX, INT_MIN, 0 }; // satisfy BST condition
  }

  bstNode left = largestBSTSubtreeHelper(root->left);
  bstNode right = largestBSTSubtreeHelper(root->right);

  // maintain BST property
  if (root->val > left.max && root->val < right.min) {
    bstNode Node;
    Node.min = min(left.min, root->val);
    Node.max = max(right.max, root->val);
    Node.num_nodes = left.num_nodes + right.num_nodes + 1; // + current node
    return Node;
  }

  return { INT_MIN, INT_MAX, max(left.num_nodes, right.num_nodes) };
}

int Solution::largestBSTSubtree(TreeNode* root) {
  return largestBSTSubtreeHelper(root).num_nodes;
}