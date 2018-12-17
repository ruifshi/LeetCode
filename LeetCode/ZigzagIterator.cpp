#include "stdafx.h"
#include "ZigzagIterator.h"

// O(size of largest input vector)
ZigzagIterator::ZigzagIterator(vector<int>& v1, vector<int>& v2) {
	int size = v1.size() > v2.size() ? v1.size() : v2.size();
	int v1Size = v1.size();
	int v2Size = v2.size();

	for (int i = 0; i < size; i++) {
		if (i < v1Size) {
			ans.push(v1[i]);
		}

		if (i < v2Size) {
			ans.push(v2[i]);
		}
	}

	return;
}

int ZigzagIterator::next() {
	if (!ans.empty()) {
		int val = ans.front();
		ans.pop();
		return val;
	}
	
	return 0;
}

bool ZigzagIterator::hasNext() {
	return !ans.empty();
}