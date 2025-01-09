/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    int** ret = malloc(2 * sizeof(int*));
    int mSize = nums1Size > nums2Size ? nums1Size : nums2Size;
    int idx1 = 0;
    int idx2 = 0;

    ret[0] = malloc(mSize * sizeof(int));
    ret[1] = malloc(mSize * sizeof(int));
    *returnColumnSizes = malloc(2 * sizeof(int));

    *returnSize = 2;
    (*returnColumnSizes)[0] = 0;
    (*returnColumnSizes)[1] = 0;

    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    while (idx1 < nums1Size && idx2 < nums2Size)
    {
        // printf("nums1[%d]=%d; nums2[%d]=%d\n", idx1, nums1[idx1], idx2, nums2[idx2]);
        if (idx1 > 0)
            if (nums1[idx1] == nums1[idx1-1])
            {
                idx1++;
                continue;
            }
        if (idx2 > 0)
            if (nums2[idx2] == nums2[idx2-1])
            {
                idx2++;
                continue;
            }
        
        if (nums1[idx1] < nums2[idx2])
            ret[0][returnColumnSizes[0][0]++] = nums1[idx1++];
        else if (nums1[idx1] > nums2[idx2])
            ret[1][returnColumnSizes[0][1]++] = nums2[idx2++];
        else
            idx1++, idx2++;
    }

    if (idx1 == nums1Size)
        while (idx2 < nums2Size)
            if (idx2 > 0)
                if (nums2[idx2] != nums2[idx2-1])
                    ret[1][returnColumnSizes[0][1]++] = nums2[idx2++];
                else
                    idx2++;
            else
                ret[1][returnColumnSizes[0][1]++] = nums2[idx2++];

    if (idx2 == nums2Size)
        while (idx1 < nums1Size)
            if (idx1 > 0)
                if (nums1[idx1] != nums1[idx1-1])
                    ret[0][returnColumnSizes[0][0]++] = nums1[idx1++];
                else
                    idx1++;
            else
                ret[0][returnColumnSizes[0][0]++] = nums1[idx1++];

    return ret;
}
