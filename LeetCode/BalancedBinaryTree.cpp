#include "stdafx.h"
#include "BalancedBinaryTree.h"

#include <algorithm>

using namespace std;


// Recursively obtain the height of a tree. An empty tree has -1 height
int height(TreeNode* root) {
  // An empty tree has height -1
  if (root == NULL) {
    return -1;
  }
  return 1 + max(height(root->left), height(root->right));
}

bool Solution::isBalanced(TreeNode* root) {
  // An empty tree satisfies the definition of a balanced tree
  if (root == NULL) {
    return true;
  }

  // Check if subtrees have height within 1. If they do, check if the
  // subtrees are balanced
  return abs(height(root->left) - height(root->right)) < 2 &&
    isBalanced(root->left) &&
    isBalanced(root->right);
}

/*
class Solution {
private:
  // Return whether or not the tree at root is balanced while also storing
  // the tree's height in a reference variable.
  bool isBalancedTreeHelper(TreeNode* root, int& height) {
    // An empty tree is balanced and has height = -1
    if (root == NULL) {
      height = -1;
      return true;
    }

    // Check subtrees to see if they are balanced. If they are, check if the
    // current node is also balanced using the heights obtained from the
    // recursive calls.
    int left, right;
    if (isBalancedTreeHelper(root->left, left)  &&
        isBalancedTreeHelper(root->right, right) &&
        abs(left - right) < 2) {
      // Store the current tree's height
      height = max(left, right) + 1;
      return true;
    }
    return false;
  }
public:
  bool isBalanced(TreeNode* root) {
    int height;
    return isBalancedTreeHelper(root, height);
  }
};
*/