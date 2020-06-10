#include "stdafx.h"
#include "BinaryTreePaths.h"

#include <string>

// pass path as value so it recursively constructs
void binaryTreePathsHelper(TreeNode* node, vector<string> &out, string path) {
  if (node) {
    path += to_string(node->val);

    if (node->left == nullptr && node->right == nullptr) {
      out.push_back(path);
    }
    else {
      path += "->";
      binaryTreePathsHelper(node->left, out, path);
      binaryTreePathsHelper(node->right, out, path);
    }
  }
}

vector<string> Solution::binaryTreePaths(TreeNode* root) {
  vector<string> out;
  
  binaryTreePathsHelper(root, out, "");

  return out;
}