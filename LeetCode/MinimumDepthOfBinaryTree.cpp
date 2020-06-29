#include "stdafx.h"
#include "MinimumDepthOfBinaryTree.h"

#include <limits>
#include <algorithm>

using namespace std;

int minDepth(TreeNode* root) {
  if (!root) return 0;

  int left = minDepth(root->left);
  int right = minDepth(root->right);

  // We need to add the smaller one of the child depths - except if that's zero, 
  // then add the larger one.
  return 1 + (min(left, right) ? min(left, right) : max(left, right));
}