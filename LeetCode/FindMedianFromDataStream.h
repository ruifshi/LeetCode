#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
	priority_queue<int> lo;                              // max heap
	priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
	MedianFinder();

	void addNum(int num);

	double findMedian();
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */