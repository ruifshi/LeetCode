#include "stdafx.h"
#include "MergeKSortedLists.h"

#include <queue>

/*
ListNode* mergeList(ListNode* l1, ListNode* l2) {
	ListNode dummy(-1);
	ListNode* p = &dummy;

	while (l1 && l2) {
		if (l1->val < l2->val) {
			p->next = l1;
			l1 = l1->next;
		}
		else {
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}

	p->next = l1 ? l1 : l2;

	return dummy.next;
}

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) return nullptr;

		if (lists.size() == 1) return lists[0];

		ListNode* list = mergeList(lists[0], lists[1]);

		if (lists.size() == 2) return list;

		for (int i = 2; i < lists.size(); i++) {
			list = mergeList(list, lists[i]);
		}

		return list;
	}
};
*/

struct mycomp
{
    bool operator() (ListNode *a, ListNode *b) const { return a->val > b->val; }
};

//O(lists.size() * element is each list)
ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
	priority_queue<ListNode*, vector<ListNode*>, mycomp> pq;
	int k = lists.size();
	
	// put each node in a priority queue where the smallest
	// val is in the front.
	for(int i = 0; i < k; i++) {
		ListNode *curr = lists[i];
		while(curr != NULL) {
			pq.push(curr);
			curr = curr->next;
		}
	}

    if (pq.empty()) {
		return NULL;
	}

	// iterate through the priority queue and create the
	// new linked list.
    ListNode *pHead = pq.top(), *pNode = pHead;
    pq.pop();
	while(!pq.empty()) {
        pNode->next = pq.top();
        pq.pop();
        pNode = pNode->next;
	}

    pNode->next = nullptr;
    return pHead;
}