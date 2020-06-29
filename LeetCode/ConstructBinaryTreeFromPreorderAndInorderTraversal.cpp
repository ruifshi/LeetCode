#include "stdafx.h"
#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.h"

TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
  if (left > right) return NULL;
  int mid = left;  // find the root from inorder

  // search for this root node rom preorder in inorder to find left and right splits
  while (inorder[mid] != preorder[rootIdx]) mid++;

  rootIdx++;
  TreeNode* newNode = new TreeNode(inorder[mid]);
  newNode->left = buildTreeHelper(preorder, inorder, rootIdx, left, mid - 1);
  newNode->right = buildTreeHelper(preorder, inorder, rootIdx, mid + 1, right);
  return newNode;
}

/*
In a Preorder sequence, leftmost element is the root of the tree. So we know ‘A’ is root for given sequences. 
By searching ‘A’ in Inorder sequence, we can find out all elements on left side of ‘A’ are in left subtree and 
elements on right are in right subtree. So we know below structure now.
*/
TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
  int rootIdx = 0;
  return buildTreeHelper(preorder, inorder, rootIdx, 0, inorder.size() - 1);
}