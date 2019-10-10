#include "stdafx.h"
#include "CopyListWithRandomPointer.h"


// recursively construct the new linked list
// the map keeps the mapping of old node to new node, this is needed for the random pointer so we know what to point to in newly created structure
Node* Solution::copyRandomList(Node* head) {
	if (!head) 
		return NULL;

	if (hmap.find(head) != hmap.end())
		return hmap[head];

	Node* node = new Node(head->val, NULL, NULL);
	hmap[head] = node;
	node->next = copyRandomList(head->next);
	node->random = copyRandomList(head->random);
	return node;
}

// Alternative solution: https://www.youtube.com/watch?v=EHpS2TBfWQg