#include "stdafx.h"
#include "RotateList.h"

ListNode* Solution::rotateRight(ListNode* head, int k) {
  if (head == nullptr) return nullptr;
  if (head->next == nullptr) return head;

  // close the list into a ring
  ListNode *oldTail = head;
  int nodeCnt;

  for (nodeCnt = 1; oldTail->next != nullptr; nodeCnt++) {
    oldTail = oldTail->next;
  }
  oldTail->next = head;

  /*
  Where is the new head?

  In the position n - k, where n is a number of nodes in the list. The new tail is just before, in the position n - k - 1.

  We were assuming that k < n. What about the case of k >= n?

  k could be rewritten as a sum k = (k // n) * n + k % n, where the first term doesn't result in any rotation.
  Hence one could simply replace k by k % n to always have number of rotation places smaller than n.
  */

  // find new tail : (n - k % n - 1)th node
  // and new head : (n - k % n)th node
  ListNode *newTail = head;
  for (int i = 0; i < nodeCnt - k % nodeCnt - 1; i++) {
    newTail = newTail->next;
  }
  head = newTail->next;

  //break ring
  newTail->next = nullptr;

  return head;
}