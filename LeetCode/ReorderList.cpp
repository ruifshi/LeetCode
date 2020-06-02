#include "stdafx.h"
#include "ReorderList.h"

ListNode* reverseList(ListNode* head) {
  ListNode* curr = head, *prev = nullptr, *next = nullptr;

  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  head = prev;
  
  return head;
}

void Solution::reorderList(ListNode* head) {
  if (head == nullptr || head->next == nullptr)
    return;

  ListNode* slow = head;
  ListNode* fast = slow->next;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  ListNode* h1 = head;
  ListNode* h2 = slow->next;
  slow->next = NULL;

  h2 = reverseList(h2);

  ListNode dummy(-1);
  ListNode *cur = &dummy;
  while (h1 || h2) {
    if (h1) {
      cur->next = h1;
      h1 = h1->next;
      cur = cur->next;
    }

    if (h2) {
      cur->next = h2;
      h2 = h2->next;
      cur = cur->next;
    }
  }

  head = dummy.next;
}