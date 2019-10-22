#include "stdafx.h"
#include "EmployeeFreeTime.h"

#include <queue>

vector<Interval*> Solution::employeeFreeTime(vector<vector<Interval*>> schedule) {
	vector<Interval*> ans;
	struct cmp {
		bool operator()(Interval* a, Interval* b) {
			return a->start > b->start;
		}
	};
	//earlier start time has top priority
	priority_queue<Interval*, vector<Interval*>, cmp> pq;
	//insert all employee times into the priority_queue
	for (auto employee : schedule) {
		for (auto t : employee) {
			pq.push(t);
		}
	}
	Interval* temp = pq.top();
	pq.pop();
	while (!pq.empty()) {
		auto t = pq.top();
		if (temp->end < t->start) { // No intersection
			ans.push_back(new Interval(temp->end, t->start));
			temp = pq.top();
			pq.pop();
		}
		else { // there is an intersection
			temp = temp->end < t->end ? t : temp;
			pq.pop();
		}
	}

	return ans;
}