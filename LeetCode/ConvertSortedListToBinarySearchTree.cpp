#include "stdafx.h"
#include "ConvertSortedListToBinarySearchTree.h"

#include <vector>

using namespace std;

TreeNode* sortedListToBSTHelper(vector<int> &listArray, int start, int end) {
  if (start > end) {  // invalid case
    return nullptr;
  }

  int mid = start + (end - start) / 2;
  TreeNode *node = new TreeNode(listArray[mid]);

  if (start == end) return node; // last node left

  node->left = sortedListToBSTHelper(listArray, start, mid - 1);
  node->right = sortedListToBSTHelper(listArray, mid + 1, end);

  return node;
}

TreeNode* Solution::sortedListToBST(ListNode* head) {
  if (head == nullptr) return nullptr;

  vector<int> listArray;

  ListNode* node = head;
  while (node) {
    listArray.push_back(node->val);
    node = node->next;
  }

  return sortedListToBSTHelper(listArray, 0, listArray.size() - 1);
}