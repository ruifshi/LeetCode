#include "stdafx.h"
#include "SortTransformedArray.h"

// O(n)
vector<int> Solution::sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    vector<int> ans;

    if(nums.size() == 0) {
        return ans;
    }

    int i = 0, j = nums.size()-1, q1, q2;

	// If a is positive, then that means the ends of the 
	// array are the biggest values. The elements toward the
	// middle are smaller so add to beginning
    if(a > 0) {
        while(i <= j) {
            q1 = quad(nums[i], a, b, c);
            q2 = quad(nums[j], a, b, c);
            if(q1 > q2) {
                ans.insert(ans.begin(),q1);
                i++;
            }
            else {
                ans.insert(ans.begin(),q2);
                j--;
            }
        }
    }
	// If a is negative, then that means the ends of the 
	// array are the smallest values. The elements toward the
	// middle are bigger so add to end
    else {
        while(i <= j) {
            q1 = quad(nums[i], a, b, c);
            q2 = quad(nums[j], a, b, c);
            if(q1 < q2) {
                ans.push_back(q1);
                i++;
            }
            else {
                ans.push_back(q2);
                j--;
            }
        }
    }

    return ans;
}

int Solution::quad(int x, int a, int b, int c) {
	return a*x*x+b*x+c;
}