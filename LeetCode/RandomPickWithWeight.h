#pragma once
#include <vector>

using namespace std;

class Solution {
private:
	vector<int> prefixSums;
public:
	Solution(vector<int>& w);

	int pickIndex();
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */