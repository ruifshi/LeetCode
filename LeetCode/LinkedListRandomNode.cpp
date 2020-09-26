#include "stdafx.h"
#include "LinkedListRandomNode.h"

//unordered_map<int, ListNode*> umap;
//int key
//assigns key to each node so we can use the integer to randomize

/** @param head The linked list's head.
    Note that the head is guaranteed to be not null, so it contains at least one node. */
Solution::Solution(ListNode* head) {
  int key = 0;
  while (head) {
    umap[key] = head;
    head = head->next;
    key++;
  }
}

/** Returns a random node's value. */
int Solution::getRandom() {
  return umap[rand() % key]->val;
}