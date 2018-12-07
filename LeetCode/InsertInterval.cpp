#include "stdafx.h"
#include "InsertInterval.h"

vector<Interval> Solution::insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> ans;

	if(intervals.size() == 0) {
		ans.push_back(newInterval);
		return ans;
	}

    int index = 0;
    while(index < intervals.size() && intervals[index].end < newInterval.start){
        ans.push_back(intervals[index]);
		index++;
    }
    while(index < intervals.size() && intervals[index].start <= newInterval.end){
        newInterval.start = min(newInterval.start, intervals[index].start);
        newInterval.end = max(newInterval.end, intervals[index].end);
        index++;
    }
    ans.push_back(newInterval);
    while(index < intervals.size()){
        ans.push_back(intervals[index]);
		index++;
    }

    return ans;
}