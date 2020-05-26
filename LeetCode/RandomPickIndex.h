#pragma once
#include <vector>
#include <unordered_map>

using namespace std;

class Solution2 {
public:
	unordered_map<int, vector<int>> table;
	Solution2(vector<int>& nums);

	int pick(int target);
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */