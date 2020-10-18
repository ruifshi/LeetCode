#include "stdafx.h"
#include "FlipEquivalentBinaryTrees.h"

bool Solution::flipEquiv(TreeNode* root1, TreeNode* root2) {
  // 3 base cases for recursion

  // If both root are NULL then it is valid and we return true
  if (!root1 && !root2) return true;

  // If only one root is NULL then it is not valid and we return false
  if (!root1 || !root2) return false;

  // If both root has value mismatch then it is not valid and we return false
  if (root1->val != root2->val) return false;

  // If root1 and root2 value match then we check in their child nodes
  // Their child nodes can be flip equivalent only in 2 ways, either No Flip or Flip
      // Either both root1->left == root2->left and root1->right == root2->right => No Flip
      // Or both root1->left == root2->right and root1->right == root2->left => Flip 

  return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
}