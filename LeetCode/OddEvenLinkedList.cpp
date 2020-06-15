#include "stdafx.h"
#include "OddEvenLinkedList.h"

ListNode* oddEvenList(ListNode* head) {
  if (!head) return nullptr;

  ListNode* odd = head, *even = head->next, *evenHead = even;

  while (even && even->next) {
    odd->next = even->next;
    odd = odd->next;

    even->next = odd->next;
    even = even->next;
  }

  odd->next = evenHead;
  return head;
}