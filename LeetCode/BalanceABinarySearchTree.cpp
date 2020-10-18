#include "stdafx.h"
#include "BalanceABinarySearchTree.h"

#include <vector>

using namespace std;

// use inorder traversal to get nodes in ascending order
// then middle will be the root and we can separate first and second halves
// recurse for subtrees
void findInorder(TreeNode* root, vector<TreeNode*> &inorder)
{
  if (root == NULL)
    return;
  findInorder(root->left, inorder);
  inorder.push_back(root);
  findInorder(root->right, inorder);
}

TreeNode* buildTree(int start, int end, vector<TreeNode*> &inorder)
{
  if (start > end)
    return NULL;
  int mid = start + (end - start) / 2;
  TreeNode* root = inorder[mid];
  root->left = buildTree(start, mid - 1, inorder);
  root->right = buildTree(mid + 1, end, inorder);
  return root;
}

TreeNode* Solution::balanceBST(TreeNode* root) {
  if (!root)
    return nullptr;
  vector<TreeNode*> inorder;

  findInorder(root, inorder);
  int n = inorder.size();
  root = buildTree(0, n - 1, inorder);
  return root;
}