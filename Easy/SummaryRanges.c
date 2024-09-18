/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void intToChars(char* s, long val) // Reverse Chars from Integer
{
    // printf("val: %d\n", val);
    char* tmp = malloc(15 * sizeof(char));
    bool neg = val < 0 ? true : false;
    val = val > 0 ? val : -val;
    int idx = 0;
    if (val == 0) 
    {
        tmp[idx] = (char) 48;
        idx++;
    }
    while(val != 0)
    {
        tmp[idx] = (char) ((val % 10) + 48);
        idx++;
        val = val / 10;
    }
    if (neg == true)
    {
        tmp[idx] = '-';
        idx++;
    }
    tmp[idx] = '\0';
    // printf("tmp: %s\n", tmp);
    for (int i = 0; i < 15; i++) s[i] = '\0';
    int tmpLen = strlen(tmp);
    for (int i = 0; i < tmpLen; i++)
    {
        s[i] = tmp[tmpLen - i-1];
    }

    return;
}

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    int i = 0, j = 0;
    int idx = 0;
    char* arrow = "->";
    char** ret = malloc(20 * sizeof(char*));
    *returnSize = 0;
    if (numsSize == 0) return ret;
    if (numsSize == 1)
    {
        (*returnSize)++;
        char* single = malloc(15 * sizeof(char));
        intToChars(single, (long)nums[i]);
        ret[0] = malloc((strlen(single) + 1) * sizeof(char));
        for (int p = 0; p < strlen(single) + 1; p++) ret[0][p] = single[p];

        free(single);
        return ret;
    }

    j++;
    bool islast = false;
    while (islast == false)
    {
        if (j == numsSize)
        {
            j--;
            islast = true;
        }
        printf("i, j = %d, %d\n", i, j);
        if ((long)nums[j] - (long)nums[j-1] > (long)1 || islast == true)
        {
            (*returnSize)++;
            if (islast == true) j++;
            if (j - i == 1)
            {
                char* single = malloc(15 * sizeof(char));
                intToChars(single, (long)nums[i]);
                ret[idx] = malloc((strlen(single) + 1) * sizeof(char));
                for (int p = 0; p < strlen(single) + 1; p++) ret[idx][p] = single[p];

                free(single);
                idx++;
                i = j;
            }
            else
            {
                char* from = malloc(15 * sizeof(char));
                char* to = malloc(15 * sizeof(char));

                intToChars(from, (long)nums[i]);
                intToChars(to, (long)nums[j-1]);

                ret[idx] = malloc((strlen(from) + strlen(to) + 3) * sizeof(char));
                int p = 0;
                for (; p < strlen(from); p++) ret[idx][p] = from[p];
                for (; p < strlen(from) + 2; p++) ret[idx][p] = arrow[p-strlen(from)];
                for (; p < strlen(from) + strlen(to) + 3; p++) ret[idx][p] = to[p-strlen(from)-2];

                free(from);
                free(to);
                idx++;
                i = j;
            }
        }
        j++;
    }
    
    printf("size: %d\n", *returnSize);
    return ret;
}



