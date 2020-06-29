#include "stdafx.h"
#include "AddTwoNumbersII.h"

#include <stack>

using namespace std;

ListNode* Solution::addTwoNumbers2(ListNode* l1, ListNode* l2) {
  stack<int> stk1, stk2;

  while (l1) {
    stk1.push(l1->val);
    l1 = l1->next;
  }

  while (l2) {
    stk2.push(l2->val);
    l2 = l2->next;
  }

  ListNode *prev = nullptr, *curr = nullptr;
  int carry = 0;

  while (!stk1.empty() || !stk2.empty() || carry) {
    int sum = 0;
    if (!stk1.empty()) {
      sum += stk1.top();
      stk1.pop();
    }

    if (!stk2.empty()) {
      sum += stk2.top();
      stk2.pop();
    }

    sum += carry;
    curr = new ListNode(sum % 10);
    carry = sum / 10;
    curr->next = prev;
    prev = curr;
  }

  return prev;
}

/*
ListNode* reverseList(ListNode* head) {
  ListNode *current = head, *prev = nullptr, *next = nullptr;

  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head = prev;

  return head;
}

ListNode* Solution::addTwoNumbers2(ListNode* l1, ListNode* l2) {
  l1 = reverseList(l1);
  l2 = reverseList(l2);

  //treat NULL pointers as 0s
  ListNode preHead(0), *p = &preHead;
  int extra = 0;
  while (l1 || l2 || extra) {
    int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
    extra = sum / 10;
    p->next = new ListNode(sum % 10);
    p = p->next;
    l1 = l1 ? l1->next : l1;
    l2 = l2 ? l2->next : l2;
  }
  return reverseList(preHead.next);
}
*/