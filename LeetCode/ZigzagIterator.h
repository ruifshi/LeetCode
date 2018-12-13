#include <vector>
#include <queue>

using namespace std;

class ZigzagIterator {
public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2);

	int next();

	bool hasNext();

	queue<int> ans;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */