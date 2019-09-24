#include "stdafx.h"
#include "MergeTwoSortedLists.h"

#include <queue>
#include <vector>

using namespace std;

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
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

/*
ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == NULL) {
		return l2;
	}
	else if (l2 == NULL) {
		return l1;
	}
	else if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}
*/

/*
struct mycomp
{
	bool operator() (ListNode *a, ListNode *b) const { return a->val > b->val; }
};

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
	priority_queue<ListNode*, vector<ListNode*>, mycomp> pq;

	ListNode *curr = l1;
	while (curr != NULL) {
		pq.push(curr);
		curr = curr->next;
	}

	curr = l2;
	while (curr != NULL) {
		pq.push(curr);
		curr = curr->next;
	}

	if (pq.empty()) {
		return NULL;
	}

	// iterate through the priority queue and create the
	// new linked list.
	ListNode *pHead = pq.top(), *pNode = pHead;
	pq.pop();
	while (!pq.empty()) {
		pNode->next = pq.top();
		pq.pop();
		pNode = pNode->next;
	}

	pNode->next = nullptr;
	return pHead;
}
*/