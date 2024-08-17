void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* merges = malloc(nums1Size * sizeof(int));
    int i = 0;
    int j = 0;
    while ((i < m) | (j < n))
    {
        printf("%d:%d\n", i, j);
        if (i == m) { merges[i+j] = nums2[j]; j++; continue; }
        if (j == n) { merges[i+j] = nums1[i]; i++; continue; }

        if (nums1[i] < nums2[j])
        {
            merges[i+j] = nums1[i]; i++;
        }
        else if (nums1[i] > nums2[j])
        {
            merges[i+j] = nums2[j]; j++;
        }
        else
        {
            merges[i+j] = nums1[i]; i++;
            merges[i+j] = nums2[j]; j++;
        }
    }
    for (int x = 0; x < nums1Size; x++)
    {
        nums1[x] = merges[x];
    }
    free(merges);
    return;
}
