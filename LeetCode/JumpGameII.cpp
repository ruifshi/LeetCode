#include "stdafx.h"
#include "JumpGameII.h"

#include <algorithm>

/*
This problem has a nice BFS structure.Let's illustrate it using the example nums = [2, 3, 1, 1, 4] 
in the problem statement. We are initially at position 0. Then we can move at most nums[0] steps from it. 
So, after one move, we may reach nums[1] = 3 or nums[2] = 1. So these nodes are reachable in 1 move. 
From these nodes, we can further move to nums[3] = 1 and nums[4] = 4. Now you can see that the target nums[4] = 4 is reachable in 2 moves.

Putting these into codes, we keep two pointers start and end that record the current range of the starting nodes.
Each time after we make a move, update start to be end + 1 and end to be the farthest index that can be reached in 1 move from the current[start, end].
*/
int Solution::jump(vector<int>& nums) {
	int n = nums.size(), step = 0, start = 0, end = 0;
	while (end < n - 1) {
		step++;
		int maxend = end + 1;
		for (int i = start; i <= end; i++) {
			if (i + nums[i] >= n - 1) return step;
			maxend = max(maxend, i + nums[i]);
		}
		start = end + 1;
		end = maxend;
	}
	return step;
}