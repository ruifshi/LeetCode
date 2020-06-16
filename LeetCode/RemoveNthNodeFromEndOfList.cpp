#include "stdafx.h"
#include "RemoveNthNodeFromEndOfList.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode dummy; // needed in case we're removing the first node
  dummy.next = head;
  ListNode* start = &dummy, *end = &dummy;

  n++;  // since dummy

  // make sure pointers are n distance apart
  while (n--) {
    end = end->next;
  }

  while (end != nullptr) {
    start = start->next;
    end = end->next;
  }

  start->next = start->next->next;

  return dummy.next;
}