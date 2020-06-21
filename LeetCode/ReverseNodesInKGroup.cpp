#include "stdafx.h"
#include "ReverseNodesInKGroup.h"

ListNode* reverseKGroup(ListNode* head, int k) {
  if (head == nullptr || k == 1 || k == 0) return head;

  ListNode dummy(-1);
  dummy.next = head;

  ListNode* cur = &dummy, *next = nullptr, *prev = &dummy;

  int count = 0;
  while (cur = cur->next) {
    count++;
  }

  while (count >= k) {
    cur = prev->next;
    next = cur->next;

    for (int i = 1; i < k; i++) {
      // bubbling next to the front of first cur
      cur->next = next->next;
      next->next = prev->next;
      prev->next = next;
      next = cur->next;
    }

    prev = cur;
    count -= k;
  }

  return dummy.next;
}