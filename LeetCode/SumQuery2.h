struct NumArray{
    int *nums;
    int *sum;
    int numsSize;
};

NumArray* numArrayCreate2(int* nums, int numsSize);

void numArrayUpdate(NumArray* obj, int i, int val);

int numArraySumRange2(NumArray* obj, int i, int j);

void numArrayFree2(NumArray* obj);