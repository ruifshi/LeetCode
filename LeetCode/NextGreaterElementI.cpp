#include "stdafx.h"
#include "NextGreaterElementI.h"

#include <map>

// O(n^2)
vector<int> Solution::nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
	vector<int> ans(findNums.size(), -1);

	if(findNums.size() < 1 || nums.size() < 1) {
		return ans;
	}

	map<int, int> nums_index;

	// keep track of the index for each number to be found
	for(int i = 0; i < nums.size(); i++) {
		nums_index[nums[i]] = i;
	}

	// loop through the findnums. We already know the index where the number
	// resides so look through the remainder of the array to see if a greater
	// number exists.
	for(int i = 0; i < findNums.size(); i++) {
		for(int j = nums_index[findNums[i]]; j < nums.size(); j++) {
			if(findNums[i] < nums[j]) {
				ans[i] = nums[j];
				break;
			}
		}
	}

	return ans;
}

/* //use stack to keep track of indicies of decreasing subsequences
// as soon as we see a value bigger than the one of the stack,
// pop all values that are smaller
vector<int> nextGreaterElements(vector<int>& nums) {
  int n = nums.size();
  vector<int> next(n, -1);
  stack<int> s; // index stack
  for (int i = 0; i < n * 2; i++) {
    int num = nums[i % n];
    while (!s.empty() && nums[s.top()] < num) {
      next[s.top()] = num;
      s.pop();
    }
    if (i < n) s.push(i);
  }
  return next;
}
*/