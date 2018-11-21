#include "stdafx.h"
#include "stdlib.h"

#include "SumQuery2.h"

NumArray* numArrayCreate2(int* nums, int numsSize) {
    NumArray *array;
    int i;

	array = (struct NumArray*)malloc(sizeof(NumArray)); 
	array->sum = (int*)malloc((numsSize+1)*sizeof(int));
    array->nums = (int*)malloc((numsSize)*sizeof(int));
    array->numsSize = numsSize;

	array->sum[0] = 0;

	for(i = 0; i < numsSize; i++) {
		array->sum[i+1] = array->sum[i] + nums[i];
        array->nums[i] = nums[i];
	}

	return array;
}

void numArrayUpdate(NumArray* obj, int i, int val) {
    obj->nums[i] = val;
    
	for(i = 0; i < obj->numsSize; i++) {
		obj->sum[i+1] = obj->sum[i] + obj->nums[i];
	}
    
    return;
}

int numArraySumRange2(NumArray* obj, int i, int j) {
	int sum = 0;
	if(obj ==  NULL) {
		return sum;
	}

	sum = obj->sum[j+1] - obj->sum[i];

	return sum;
}

void numArrayFree2(NumArray* obj) {
	free(obj->sum);
    free(obj->nums);
	free(obj);

	return;
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */