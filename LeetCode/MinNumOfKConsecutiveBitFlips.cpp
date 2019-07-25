#include "stdafx.h"
#include "MinNumOfKConsecutiveBitFlips.h"

/*
In the beginning, we know that each 0 should be flipped at least once, so we want to start first flip at the position of the first 0. For example, our input is 1011, K=2
So we start flip at position 1, increment counter, but instead of flipping the subarray, we flip our variable so we now look for 1 instead of 0. We also mark the end of 
current flip in temporary array, at the position 1+2=3. Now move to the position 2, compare with 'flip' variable and start another flip, increment counter, flip variable 
(back to 0), the end position is 4, it matches the end of input array so no need to store it. At the position 3 we have the end marker, so we flip variable again to 1, 
compare with current element and see we need to start another flip which would end outside of the array so we return -1. If we do the same steps for A=1010 and K=2, we 
do the same until position 3, where we don't need to start another flip so we end the loop and return counter which would be 2.
*/
int Solution::minKBitFlips(vector<int>& A, int K) {
	vector<int> hint(A.size(), 0);
	int ans = 0, flip = 0;

	for (int i = 0; i < A.size(); i++) {
		flip ^= hint[i];
		if (A[i] == flip) {
			ans++;
			if (i + K > A.size()) {
				return -1;
			}
			flip ^= 1;
			if (i + K < A.size()) {
				hint[i + K] ^= 1;
			}
		}
	}

	return ans;
}