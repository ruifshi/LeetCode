#include "stdafx.h"
#include "NestedListWeightSum.h"

int dfs(const vector<NestedInteger>& nestedList, int depth) {
	int size = nestedList.size();
	int sum = 0;

	for (int i = 0; i < size; i++) {
		if (nestedList[i].isInteger()) {
			sum += nestedList[i].getInteger() * depth;
		}
		else {
			sum += dfs(nestedList[i].getList(), depth + 1);
		}
	}

	return sum;
}

int Solution::depthSum(vector<NestedInteger>& nestedList) {
	return dfs(nestedList, 1);
}