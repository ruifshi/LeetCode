#include "stdafx.h"
#include "MovingAverageFromDataStream.h"

MovingAverage::MovingAverage(int size) {
	maxSize = size;
	sum = 0;
	return;
}

// O(1)
double MovingAverage::next(int val) {
	sum += val;
	q.push(val);

	if (q.size() > maxSize) {
		int popVal = q.front();
		q.pop();
		sum -= popVal;
	}

	return (double)sum / q.size();
}