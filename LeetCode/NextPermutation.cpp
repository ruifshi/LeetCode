#include "stdafx.h"
#include "NextPermutation.h"

/*
The following algorithm generates the next permutation lexicographically after a given permutation.It changes the given permutation in - place.

1. Find the largest index k such that a[k] < a[k + 1].If no such index exists, the permutation is the last permutation.
2. Find the largest index l greater than k such that a[k] < a[l].
3. Swap the value of a[k] with that of a[l].
4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
*/
void Solution::nextPermutation(vector<int>& nums) {
	int n = nums.size(), k, l;
	for (k = n - 2; k >= 0; k--) {
		if (nums[k] < nums[k + 1]) {
			break;
		}
	}
	if (k < 0) {
		reverse(nums.begin(), nums.end());
	}
	else {
		for (l = n - 1; l > k; l--) {
			if (nums[l] > nums[k]) {
				break;
			}
		}
		swap(nums[k], nums[l]);
		reverse(nums.begin() + k + 1, nums.end());
	}
}

/*
// Generating permutation using Heap Algorithm
void heapPermutation(int a[], int size, int n)
{
	// if size becomes 1 then prints the obtained
	// permutation
	if (size == 1)
	{
		printArr(a, n);
		return;
	}

	for (int i=0; i<size; i++)
	{
		heapPermutation(a,size-1,n);

		// if size is odd, swap first and last
		// element
		if (size%2==1)
			swap(a[0], a[size-1]);

		// If size is even, swap ith and last
		// element
		else
			swap(a[i], a[size-1]);
	}
}
*/