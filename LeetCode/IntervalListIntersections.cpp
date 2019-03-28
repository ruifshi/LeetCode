#include "stdafx.h"
#include "IntervalListIntersections.h"

#include <algorithm>

//Merge the intervals to find the intersections
//O(A + B)
vector<Interval> Solution::intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
	vector<Interval> ans;
	int i = 0, j = 0;

	while (i < A.size() && j < B.size()) {
		// Let's check if A[i] intersects B[j].
		// lo - the startpoint of the intersection
		// hi - the endpoint of the intersection
		int lo = max(A[i].start, B[j].start);
		int hi = min(A[i].end, B[j].end);

		if (lo <= hi) {
			Interval in(lo, hi);
			ans.push_back(in);
		}

		if (A[i].end < B[j].end) {
			i++;
		}
		else {
			j++;
		}
	}

	return ans;
}