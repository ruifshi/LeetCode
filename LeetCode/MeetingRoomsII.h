#include <vector>

using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
	int minMeetingRooms(vector<Interval>& intervals);
};