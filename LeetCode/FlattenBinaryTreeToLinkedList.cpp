#include "stdafx.h"
#include "FlattenBinaryTreeToLinkedList.h"

void Solution::flatten(TreeNode* root) {
  // base condition- return if root is NULL 
  // or if it is a leaf node 
  if (root == NULL || root->left == NULL &&
    root->right == NULL) {
    return;
  }

  // if root->left exists then we have  
  // to make it root->right 
  if (root->left != NULL) {

    // move left recursively 
    flatten(root->left);

    // root right is always the next node, which is the left
    // store the node root->right 
    struct TreeNode* tmpRight = root->right;
    root->right = root->left;
    root->left = NULL;

    // now we moved the old left node to the right,
    // we store the old right node to the end of the new right
    // find the position to insert 
    // the stored value    
    struct TreeNode* t = root->right;
    while (t->right != NULL) {
      t = t->right;
    }

    // insert the stored value 
    t->right = tmpRight;
  }

  // now call the same function 
  // for root->right 
  flatten(root->right);
}