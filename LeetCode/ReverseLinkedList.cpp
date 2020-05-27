#include "stdafx.h"
#include "ReverseLinkedList.h"

ListNode* Solution::reverseList(ListNode* head) {
	ListNode *current = head, *prev = nullptr, *next = nullptr;

	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;

	return head;

 /*
	if (head == nullptr || head->next == nullptr) {
		return head;
	}

	ListNode* rest = reverseList(head->next);
	head->next->next = head;

	head->next = nullptr;

	return rest;
	*/
}