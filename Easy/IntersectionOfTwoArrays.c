/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int tmpSize = nums1Size > nums2Size ? nums1Size : nums2Size;
    int* ret = malloc(tmpSize * sizeof(int));

    *returnSize = 0;

    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j])
            {
                for (int k = 0; k <= *returnSize; k++)
                {
                    if (k == *returnSize)
                    {
                        ret[*returnSize] = nums1[i];
                        *returnSize += 1;
                        break;
                    }
                    if (ret[k] == nums1[i]) break;
                }
            }
        }
    }
    return ret;
}
