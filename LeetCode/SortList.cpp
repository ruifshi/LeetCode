#include "stdafx.h"
#include "SortList.h"

ListNode* merge(ListNode* l1, ListNode* l2) {
  // maintain an unchanging reference to node ahead of the return node.
  ListNode prehead(-1);

  ListNode *prev = &prehead;
  while (l1 != NULL && l2 != NULL) {
    if (l1->val <= l2->val) {
      prev->next = l1;
      l1 = l1->next;
    }
    else {
      prev->next = l2;
      l2 = l2->next;
    }
    prev = prev->next;
  }

  // exactly one of l1 and l2 can be non-null at this point, so connect
  // the non-null list to the end of the merged list.
  prev->next = l1 == NULL ? l2 : l1;

  return prehead.next;
}

ListNode* Solution::sortList(ListNode* head) {
  if (head == NULL || head->next == NULL)
    return head;

  ListNode* slow = head;
  ListNode* fast = head->next;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  //divide the list into two parts 
  fast = slow->next;
  slow->next = NULL;

  return merge(sortList(head), sortList(fast));
}