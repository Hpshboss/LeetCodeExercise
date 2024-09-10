#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

int quickSort(int* nums, int left, int right) {
    // printf("left: %d; right: %d\n", left, right);
    if (right - left < 1) return 0;
    int idxi = left, idxj = left-1;
    int pivot = nums[right];
    // printf("check\n");
    for (idxi = left; idxi <= right; idxi++)
    {
        // printf("For: idxi: %d; idxj: %d\n", idxi, idxj);
        if (nums[idxi] > pivot) continue;
        
        if (nums[idxi] <= pivot)
        {
            idxj++;
            // printf("Forif: idxi: %d; idxj: %d\n", idxi, idxj);
            if (nums[idxi] == nums[idxj]) continue;
            if (nums[idxi] < nums[idxj]) SWAP(nums[idxi], nums[idxj], int);
        }
    }

    if (pivot > nums[idxj])
    {
        SWAP(nums[idxj], pivot, int);
    }
    // printf("[%d, %d, %d, %d]\n", nums[0], nums[1], nums[2], nums[3]);

    quickSort(nums, left, idxj-1);
    quickSort(nums, idxj+1, right);

    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    quickSort(nums, 0, numsSize - 1);

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i-1]) return true;
    }
    return false;
}
