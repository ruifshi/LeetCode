#include "stdafx.h"
#include "MergeKSortedLists.h"

#include <queue>

struct mycomp
{
    bool operator() (ListNode *a, ListNode *b) const { return a->val > b->val; }
};

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
	priority_queue<ListNode*, vector<ListNode*>, mycomp> pq;
	int k = lists.size();
	
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