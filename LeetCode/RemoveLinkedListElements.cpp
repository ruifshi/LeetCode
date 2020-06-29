#include "stdafx.h"
#include "RemoveLinkedListElements.h"

ListNode* Solution::removeElements(ListNode* head, int val) {
  ListNode dummy;
  dummy.next = head;

  ListNode *prev = &dummy, *curr = head, *toDelete = nullptr;
  while (curr != nullptr) {
    if (curr->val == val) {
      prev->next = curr->next;
      toDelete = curr;
    }
    else {
      prev = curr;
    }

    curr = curr->next;

    if (toDelete != nullptr) {
      delete toDelete;
      toDelete = nullptr;
    }
  }

  return dummy.next;
}