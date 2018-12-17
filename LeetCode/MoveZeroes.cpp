#include "stdafx.h"
#include "MoveZeroes.h"

// O(n)
void Solution::moveZeroes(vector<int>& nums) {
    int j = 0, i; 
    for(i = 0; i < nums.size(); i++) 
    { 
        if (abs(nums[i]) > 0)  
        { 
            int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
            j++; // increment count non zero integers. i-j is the number of 0s current found.
				 // keep bubling the non zero integers to the front
        } 
    } 

    return;
}