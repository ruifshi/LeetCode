#include "stdafx.h"
#include "SwapNodesInPairs.h"

ListNode* Solution::swapPairs(ListNode* head) {

  ListNode dummy;
  dummy.next = head;

  ListNode *prevNode = &dummy;

  while ((head != nullptr) && (head->next != nullptr)) {

    // Nodes to be swapped
    ListNode *firstNode = head;
    ListNode *secondNode = head->next;

    // Swapping
    prevNode->next = secondNode;
    firstNode->next = secondNode->next;
    secondNode->next = firstNode;

    // Reinitializing the head and prevNode for next swap
    prevNode = firstNode;
    head = firstNode->next; // jump
  }

  // Return the new head node.
  return dummy.next;
}