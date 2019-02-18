#include "stdafx.h"
#include "FlattenNestedListIterator.h"

bool NestedInteger::isInteger() const {
	return true;
};

// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
int NestedInteger::getInteger() const {
	return 1;
}

// Return the nested list that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger hold
const vector<NestedInteger> & NestedInteger::getList() const {
	return {};
}

// put integers, and lists on the stack
NestedIterator::NestedIterator(vector<NestedInteger> &nestedList) {
	int size = nestedList.size();
	for (int i = size - 1; i >= 0; --i) {
		nodes.push(nestedList[i]);
	}
}

int NestedIterator::next() {
	int result = nodes.top().getInteger();
	nodes.pop();
	return result;
}

// everytime this is called, if it's already an integer, then return.
// If it's a list, then get the list and push all the integers to the stack
// until there are no more lists
bool NestedIterator::hasNext() {
	while (!nodes.empty()) {
		NestedInteger curr = nodes.top();
		if (curr.isInteger()) {
			return true;
		}

		nodes.pop();
		const vector<NestedInteger>& adjs = curr.getList();
		int size = adjs.size();
		for (int i = size - 1; i >= 0; --i) {
			nodes.push(adjs[i]);
		}
	}

	return false;
}