struct NumArray{
    int *sum;
    int numsSize;
} ;

NumArray* numArrayCreate(int* nums, int numsSize);

int numArraySumRange(NumArray* obj, int i, int j);

void numArrayFree(NumArray* obj);