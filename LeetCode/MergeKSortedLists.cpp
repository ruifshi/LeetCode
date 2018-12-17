#include "stdafx.h"
#include "MergeKSortedLists.h"

#include <queue>

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