#include "stdafx.h"
#include "BinaryTreeLongestConsecutiveSequenceII.h"

#include <vector>
#include <algorithm>

using namespace std;

// returns an array of 2 elements. [0] = # of increasing nodes underneath
// [1] = # of decreasing nodes underneath
vector<int> dfs(TreeNode * node, TreeNode * parent, int & longest) {
  if (NULL == node) {
    return { 0, 0 };
  }
  vector<int> left = dfs(node->left, node, longest);
  vector<int> right = dfs(node->right, node, longest);

  // path of increasing left to node to right
  longest = max(longest, left[0] + right[1] + 1);

  // path of decreasing left to node to right
  longest = max(longest, left[1] + right[0] + 1);

  int inc = 0, dec = 0;
  // save max of increasing
  if (node->val == parent->val + 1) {
    inc = max(left[0], right[0]) + 1;
  }
  // save max of decreasing
  if (node->val == parent->val - 1) {
    dec = max(left[1], right[1]) + 1;
  }
  return {inc, dec };
}

int Solution::longestConsecutive(TreeNode* root) {
  int longest = 0;
  dfs(root, root, longest);
  return longest;
}