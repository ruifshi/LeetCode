#include "stdafx.h"
#include "ConstructBinaryTreeFromPreorderAndPostorderTraversal.h"

/*
When we traverse the post and visit post[i], it means all child nodes in the tree of post[i] is visited already.
Thus, we can use pre to construct the tree while use post to figure out whether the node we visit still has unvisited children.
*/

int preIndex = 0, posIndex = 0;
TreeNode* Solution::constructFromPrePost(vector<int>& pre, vector<int>& post) {
  TreeNode* root = new TreeNode(pre[preIndex++]);
  if (root->val != post[posIndex])
    root->left = constructFromPrePost(pre, post);
  if (root->val != post[posIndex])
    root->right = constructFromPrePost(pre, post);
  posIndex++;
  return root;
}