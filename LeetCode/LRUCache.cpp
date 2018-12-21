#include "stdafx.h"
#include "LRUCache.h"

LRUCache::LRUCache(int capacity) {
	cacheSize = capacity;
	head = NULL;
}

int LRUCache::get(int key) {
	if (table.find(key) != table.end()) {
		node *n = table[key];

		// if the node touched is already the head, then
		// don't need to do anything. Otherwise, we need
		// to move the touched element to the front
		if (n != head) {
			// remove the current node from the list and
			// add it to the front of the list
			if (n->prev != NULL) {
				n->prev->next = n->next;
			}
			if (n->next != NULL) {
				n->next->prev = n->prev;
			}
			n->prev = NULL;
			n->next = head;
			head->prev = n;
			head = n;
		}

		return table[key]->val;
	}

	return -1;
}

void LRUCache::put(int key, int value) {
	// if it's the first element inserted,
	// create the head
	if (head == NULL) {
		head = new node(value, key);
		table[key] = head;
		return;
	}

	// If this key already exists, then we 
	// modify the value and move the element to the
	// front of the list.
	node *n = head;
	if (table.find(key) != table.end()) {
		// remove the current node from the list and
		// add it to the front of the list
		table[key]->val = value;
		n = table[key];

		if (n != head) {
			if (n->prev != NULL) {
				n->prev->next = n->next;
			}
			if (n->next != NULL) {
				n->next->prev = n->prev;
			}
			n->prev = NULL;
			n->next = head;
			head->prev = n;
			head = n;
		}

		return;
	}

	// New key, add a new node to the beginning of the list
	n = new node(value, key);
	n->prev = NULL;
	n->next = head;
	head->prev = n;
	head = n;
	table[key] = n;

	// If cache size is reached, then we need to delete 
	// the last element in the list
	if (table.size() > cacheSize) {
		// iterate until we find the last element and
		// remove it from the list
		while (n->next != NULL) {
			n = n->next;
		}
		n->prev->next = NULL;
		table.erase(n->key);
		free(n);
	}

	return;
}

/* constant time solution
class LRUCache {
public:
	LRUCache(int capacity) : _capacity(capacity) {}

	int get(int key) {
		auto it = cache.find(key);
		if (it == cache.end()) return -1;
		touch(it);
		return it->second.first;
	}

	void set(int key, int value) {
		auto it = cache.find(key);
		if (it != cache.end()) touch(it);
		else {
			if (cache.size() == _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
			used.push_front(key);
		}
		cache[key] = { value, used.begin() };
	}

private:
	void touch(unordered_map<int, PII>::iterator it) {
		int key = it->first;
		used.erase(it->second.second);
		used.push_front(key);
		it->second.second = used.begin();
	}

	unordered_map<int, pair<int, list<int>::iterator>> cache;
	list<int> used;
	int _capacity;
};
*/