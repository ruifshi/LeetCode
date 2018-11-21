struct Interval {
	int start;
	int end;
 };

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize);