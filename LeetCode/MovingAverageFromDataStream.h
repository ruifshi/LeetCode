#include <queue>

using namespace std;

class MovingAverage {
public:
	/** Initialize your data structure here. */
	MovingAverage(int size);
	double next(int val);

	queue<int> q;
	int maxSize;
	int sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */