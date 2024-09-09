/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    int x = 0, y = 0;
    int direction = 0; // 0: +x; 1: -y; 2: -x; 3: +y;

    int** ret = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) ret[i] = malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) ret[i][j] = -1;
    }

    *returnSize = m;
    *returnColumnSizes = malloc(m * sizeof(int));
    for (int i = 0; i < *returnSize; i++) (*returnColumnSizes)[i] = n;

    while (head != NULL)
    {
        ret[y][x] = head->val;
        head = head->next;

        x += direction % 2 == 0 ? (1 - direction) : 0;
        y += direction % 2 == 1 ? (direction - 2) : 0;

        if (x == n || x == -1 || y == m || y == -1)
        {
            x -= direction % 2 == 0 ? (1 - direction) : 0;
            y -= direction % 2 == 1 ? (direction - 2) : 0;
            direction = (direction + 3) % 4;
            x += direction % 2 == 0 ? (1 - direction) : 0;
            y += direction % 2 == 1 ? (direction - 2) : 0;
        }
        else if (ret[y][x] != -1)
        {
            x -= direction % 2 == 0 ? (1 - direction) : 0;
            y -= direction % 2 == 1 ? (direction - 2) : 0;
            direction = (direction + 3) % 4;
            x += direction % 2 == 0 ? (1 - direction) : 0;
            y += direction % 2 == 1 ? (direction - 2) : 0;
        }
    }
    return ret;
}
