#include "stdafx.h"
#include "ReverseLinkedListII.h"

ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
	if (head == nullptr || m == n) {
		return head;
	}

	ListNode *dummy = new ListNode();
	ListNode *begin = dummy;

	dummy->next = head;

	int start = m;

	// begin is the node right before start of reversal
	while (--start) {	// 1 based
		begin = begin->next;
	}

	ListNode* tail = begin->next;

	// detach node at begin next
	// point begin next to node after tail, bubble node after tail to front
	// iterate tail next since old one is moved to front
	// point node moved to front to old node at front
	while (m++ < n) {
		ListNode *tmp = begin->next;
		begin->next = tail->next;
		tail->next = tail->next->next;
		begin->next->next = tmp;
	}

	return dummy->next;
}