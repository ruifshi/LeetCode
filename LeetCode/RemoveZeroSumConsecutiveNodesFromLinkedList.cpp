#include "stdafx.h"
#include "RemoveZeroSumConsecutiveNodesFromLinkedList.h"

#include <unordered_map>

using namespace std;

// use a hash map to keep track of the last occurance of a prefix sums (sum of prev nodes)
// iterate through the list and skip to last occurance of current prefix sums
ListNode* Solution::removeZeroSumSublists(ListNode* head) {
  ListNode dummy(0);
  dummy.next = head;
  int prefix = 0;
  unordered_map<int, ListNode*> seen;
  for (ListNode* i = &dummy; i; i = i->next) {
    prefix += i->val;
    seen[prefix] = i;
  }
  prefix = 0;
  for (ListNode* i = &dummy; i; i = i->next) {
    prefix += i->val;
    i->next = seen[prefix]->next;
  }
  return dummy.next;
}