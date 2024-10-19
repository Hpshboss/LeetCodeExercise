/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int retlen = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* ret = malloc(retlen * sizeof(int));

    int idx1 = 0;
    int idx2 = 0;

    *returnSize = 0;

    qsort(nums1, nums1Size, sizeof(int), cmpfunc);
    qsort(nums2, nums2Size, sizeof(int), cmpfunc);

    while (idx1 < nums1Size && idx2 < nums2Size)
    {
        if (nums1[idx1] > nums2[idx2]) idx2++;
        else if (nums1[idx1] < nums2[idx2]) idx1++;
        else if (nums1[idx1] == nums2[idx2])
        {
            ret[*returnSize] = nums1[idx1];
            idx1++;
            idx2++;
            *returnSize += 1;
        }
    }

    return ret;
}
