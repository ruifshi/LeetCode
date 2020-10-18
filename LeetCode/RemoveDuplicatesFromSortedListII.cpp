#include "stdafx.h"
#include "RemoveDuplicatesFromSortedListII.h"

ListNode* Solution::deleteDuplicates2(ListNode* head) {
  //recursively reconstruct list with no dups

  if (head == nullptr)
    return nullptr;

  bool dup = false;

  // forward pointers to last duplicate
  while (head->next != nullptr && head->val == head->next->val) {
    dup = true;
    head->next = head->next->next;
  }

  head->next = deleteDuplicates2(head->next);

  // if dup is found, then attach to next value since we're deleting
  return dup ? head->next : head;
}