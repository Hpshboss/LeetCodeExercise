/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ret = malloc(nums1Size * sizeof(int));
    int base = 0;
    *returnSize = nums1Size;

    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j])
            {
                base = j;
                break;
            }
        }

        for (int j = base; j < nums2Size; j++)
        {
            if (nums1[i] < nums2[j])
            {
                ret[i] = nums2[j];
                break;
            }
            if (j == nums2Size -1)
                ret[i] = -1;
        }
    }

    return ret;
}
