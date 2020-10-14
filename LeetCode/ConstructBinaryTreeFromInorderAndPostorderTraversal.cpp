#include "stdafx.h"
#include "ConstructBinaryTreeFromInorderAndPostorderTraversal.h"

// find the parent from postorder
// use inorder to split the left and right subtree
// left is to left of parent and right to right

//  unordered_map<int, int> hmap; maps val to index in inorder array
TreeNode* Solution::helper(int left, int right, int &postIdx, vector<int>& inorder, vector<int>& postorder) {
  // if there is no elements to construct subtrees
  if (left > right) return nullptr;

  // pick up post_idx element as a root
  int root_val = postorder[postIdx];
  TreeNode *root = new TreeNode(root_val);

  // root splits inorder list
  // into left and right subtrees
  int index = hmap[root_val];

  // build right subtree
  root->right = helper(index + 1, right, postIdx--, inorder, postorder);
  // build left subtree
  root->left = helper(left, index - 1, postIdx--, inorder, postorder);
  return root;
}

TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder) {
  if (inorder.size() == 0 || postorder.size() == 0) return nullptr;

  int postIdx = postorder.size() - 1; // This is the root

  for (int i = 0; i < inorder.size(); i++) {
    hmap[inorder[i]] = i;
  }

  return helper(0, postIdx, postIdx, inorder, postorder);
}