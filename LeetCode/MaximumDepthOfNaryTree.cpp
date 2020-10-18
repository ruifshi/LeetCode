#include "stdafx.h"
#include "MaximumDepthOfNaryTree.h"

#include <algorithm>

int Solution::maxDepth(Node* root) {
  if (root == nullptr) return 0;
  int depth = 0;
  for (auto child : root->children) depth = max(depth, maxDepth(child));
  return 1 + depth;
}