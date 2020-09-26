#include "stdafx.h"
#include "PartitionList.h"

ListNode* Solution::partition(ListNode* head, int x) {
  ListNode left(0), right(0);
  ListNode *l = &left, *r = &right;

  while (head) {
    int val = head->val;
    // add to left side
    if (val < x) {
      l->next = head;
      l = l->next;
    }
    // add to right side
    else {
      r->next = head;
      r = r->next;
    }

    head = head->next;
  }

  //connect the 2 sides
  l->next = right.next;
  r->next = nullptr;

  return left.next;
}