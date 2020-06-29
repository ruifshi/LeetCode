#include "stdafx.h"
#include "MinStack.h"'

/*
  vector<int> a;
  vector<int> min;
*/

MinStack::MinStack() {
	min.push_back(INT_MAX);
}

// keep track of the minimum for each index in the vector
void MinStack::push(int x) {
	a.push_back(x);
	if (x < min.back()) {
		min.push_back(x);
	}
	else {
		min.push_back(min.back());
	}
}

void MinStack::pop() {
	a.pop_back();
	min.pop_back();
}

int MinStack::top() {
	return a.back();
}

int MinStack::getMin() {
	return min.back();
}