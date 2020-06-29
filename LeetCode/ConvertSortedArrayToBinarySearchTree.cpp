#include "stdafx.h"
#include "ConvertSortedArrayToBinarySearchTree.h"

TreeNode* sortedArrayToBSTHelper(vector<int> &nums, int start, int end) {
  if (start > end) {  // invalid case
    return nullptr;
  }

  int mid = start + (end - start) / 2;
  TreeNode *node = new TreeNode(nums[mid]);

  if (start == end) return node; // last node left

  node->left = sortedArrayToBSTHelper(nums, start, mid - 1);
  node->right = sortedArrayToBSTHelper(nums, mid + 1, end);

  return node;
}

TreeNode* Solution::sortedArrayToBST(vector<int>& nums) {
  return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}