#include "stdafx.h"
#include "FindACorrespondingNodeOfABinaryTreeInACloneOfThatTree.h"

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
  if (original == target) return cloned;

  if (!original) {
    return nullptr;
  }

  // already found in left subtree, don't need to go further
  TreeNode* left = getTargetCopy(original->left, cloned->left, target);
  if (left) return left;

  return getTargetCopy(original->right, cloned->right, target);
}