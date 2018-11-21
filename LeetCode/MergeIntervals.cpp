#include "stdafx.h"
#include "MergeIntervals.h"
#include "stdlib.h"

int partition(struct Interval* intervals, int left, int right, int pivot, int intervalsSize) {
	struct Interval temp;

	while(left <= right) {
		while(intervals[left].start < pivot) {
			left++;
		}

		while(intervals[right].start > pivot) {
			right--;
		}

		if(left <= right) {
			temp = intervals[left];
			intervals[left] = intervals[right];
			intervals[right] = temp;
			left++;
			right--;
		}
	}

	return left;
}

void quickSort(struct Interval* intervals, int left, int right, int intervalsSize) {
	int pivot, index;

	if(left >= right) {
		return;
	}

	pivot = intervals[(left+right)/2].start;
	index = partition(intervals, left, right, pivot, intervalsSize);
	quickSort(intervals, left, index - 1, intervalsSize);
	quickSort(intervals, index, right, intervalsSize);

	return;
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    struct Interval* merged = NULL;
	int size = 0;
	int i;
    
	quickSort(intervals, 0, intervalsSize-1, intervalsSize);

	merged = (struct Interval*)malloc(sizeof(struct Interval));

	merged[0] = intervals[0];
	size++;

	for(i = 0; i < intervalsSize; i++) {
		if(intervals[i].start >= merged[size-1].start && intervals[i].start <= merged[size-1].end && intervals[i].end >= merged[size-1].end) {
			merged[size-1].end = intervals[i].end;
		}
		else if(intervals[i].end > merged[size-1].end) {
			size++;
			realloc(merged, size*sizeof(struct Interval));
			merged[size-1] = intervals[i];
		}
	}

	*returnSize = size;
    return merged;
}