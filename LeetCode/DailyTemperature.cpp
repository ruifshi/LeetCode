#include "stdafx.h"
#include "DailyTemperature.h"

#include <stack>

//the local min is always on the top of the stack since we pop
//as soon as we see a value greater than the top
vector<int> Solution::dailyTemperatures(vector<int>& T) {
	if (T.size() == 1) {
		return { 0 };
	}

	int N = T.size();
	vector<int> res(N);
	stack<int> st;
	for (int i = 0; i < N; i++) {
		while (!st.empty() && T[st.top()] < T[i]) {
			res[st.top()] = i - st.top();
			st.pop();
		}
		st.push(i);
	}
	return res;
}