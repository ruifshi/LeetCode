#include "stdafx.h"
#include "LinkedListCycle.h"

bool hasCycle(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return false;
  }

  // use a slow and fast pointer to see if they intersect at some point
  ListNode *slow = head;
  ListNode *fast = head->next;

  while (slow != fast) {
    if (fast == nullptr || fast->next == nullptr) return false;

    slow = slow->next;
    fast = fast->next->next;
  }

  return true;
}