typedef struct {
    int* nums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* ret = malloc(sizeof(NumArray));
    ret->nums = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) ret->nums[i] = nums[i];
    return ret;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sum = 0;
    for (int i = left; i <= right; i++)
    {
        sum += obj->nums[i];
    }
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj->nums);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
