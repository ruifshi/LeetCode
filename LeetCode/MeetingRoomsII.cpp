#include "stdafx.h"
#include "MeetingRoomsII.h"

#include <queue>

/* o(nlogn)
The heap stores all overlapping events. The heap's head is the event that has earliest end/finish time.
When a new event comes, we greedily choose the event X that finished the earliest. If the new event does not overlap with X, then the new event can re-use X's room, or simply extend X's event to the new event's end time.
If the new event overlaps with X, then it must overlaps with all other events in the heap. So a new room must be created.
The reason for correctness is the invariant: heap size is always the minimum number of rooms we need so far.
*/
int Solution::minMeetingRooms(vector<Interval>& intervals) {
	int n = intervals.size();
	if (n == 0) {
		return 0;
	}

	// sort according to end times
	sort(intervals.begin(), intervals.end(), [](const Interval& l, const Interval& r) { return l.start < r.start; });

	//int = type, vector<int> = container, greater<int> = smallest element on top
	priority_queue<int, vector<int>, greater<int>> q;

	q.push(intervals[0].end);

	// iterate through the vector. If a start time is grater than the smallest end time in the 
	// queue, then that means we have an open room as there is no overlap.
	for (int i = 1; i < intervals.size(); ++i) {
		// see if we can re-use a room
		if (intervals[i].start >= q.top()) {
			q.pop();
		}

		q.push(intervals[i].end);
	}

	return q.size();
}