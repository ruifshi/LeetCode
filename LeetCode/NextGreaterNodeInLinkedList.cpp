#include "stdafx.h"
#include "NextGreaterNodeInLinkedList.h"

#include <stack>

// stack will save the indices of elements that need to find next greater element.
// out vector store node values according to order
// In the end, we reset 0 to all elements that have no next greater elements.
vector<int> Solution::nextLargerNodes(ListNode* head) {
  stack<int> indices;
  vector<int> out;

  for (ListNode* node = head; node; node = node->next) {
    while (!indices.empty() && out[indices.top()] < node->val) {
      out[indices.top()] = node->val;
      indices.pop();
    }

    indices.push(out.size());
    out.push_back(node->val);
  }

  while (!indices.empty()) {
    out[indices.top()] = 0;
    indices.pop();
  }

  return out;
}