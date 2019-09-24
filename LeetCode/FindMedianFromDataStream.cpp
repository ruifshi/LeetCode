#include "stdafx.h"
#include "FindMedianFromDataStream.h"

//Log(N) for insertions each time
/*
Adding number 41
MaxHeap lo: [41]           // MaxHeap stores the largest value at the top (index 0)
MinHeap hi: []             // MinHeap stores the smallest value at the top (index 0)
Median is 41
=======================
Adding number 35
MaxHeap lo: [35]
MinHeap hi: [41]
Median is 38
=======================
Adding number 62
MaxHeap lo: [41, 35]
MinHeap hi: [62]
Median is 41
=======================
Adding number 4
MaxHeap lo: [35, 4]
MinHeap hi: [41, 62]
Median is 38
=======================
Adding number 97
MaxHeap lo: [41, 35, 4]
MinHeap hi: [62, 97]
Median is 41
=======================
Adding number 108
MaxHeap lo: [41, 35, 4]
MinHeap hi: [62, 97, 108]
Median is 51.5
*/
MedianFinder::MedianFinder() {

}

void MedianFinder::addNum(int num) {
	lo.push(num);                                    // Add to max heap

	hi.push(lo.top());                               // balancing step
	lo.pop();

	if (lo.size() < hi.size()) {                     // maintain size property
		lo.push(hi.top());
		hi.pop();
	}
}

double MedianFinder::findMedian() {
	return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5;
}

/* always sorts before finding median
class MedianFinder {
	vector<double> store;

public:
	// Adds a number into the data structure.
	void addNum(int num)
	{
		store.push_back(num);
	}

	// Returns the median of current data stream
	double findMedian()
	{
		sort(store.begin(), store.end());

		int n = store.size();
		return (n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5);
	}
};
*/

/* use insertion sort to sort on entry
class MedianFinder {
	vector<int> store; // resize-able container

public:
	// Adds a number into the data structure.
	void addNum(int num)
	{
		if (store.empty())
			store.push_back(num);
		else
			store.insert(lower_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
	}

	// Returns the median of current data stream
	double findMedian()
	{
		int n = store.size();
		return n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5;
	}
};
*/