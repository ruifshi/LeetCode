#include "stdafx.h"
#include "stdlib.h"

#include "SumQuery.h"

NumArray* numArrayCreate(int* nums, int numsSize) {
    struct NumArray *array;
    int i;

	array = (struct NumArray*)malloc(sizeof(NumArray)); 
	array->sum = (int*)malloc((numsSize+1)*sizeof(int));

	// Indices of the sum array means the sum of the first x
	// elements. So sum[0] = 0 means sum of first 0 elements is 0.
	// sum[1] means sum of first 1 elements
	array->sum[0] = 0;

	for(i = 0; i < numsSize; i++) {
		array->sum[i+1] = array->sum[i] + nums[i];
	}

	return array;
}

int numArraySumRange(NumArray* obj, int i, int j) {
	int sum = 0;
	if(obj ==  NULL) {
		return sum;
	}

	// j + 1 since 0 index and you want the sum of the 
	// first j elements. Minus i since you want to exclude the
	// sum of previous elements including 0
	sum = obj->sum[j+1] - obj->sum[i];

	return sum;
}

void numArrayFree(NumArray* obj) {
	free(obj->sum);
	free(obj);

	return;
}