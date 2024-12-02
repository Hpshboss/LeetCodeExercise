/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void accumulate(struct TreeNode* root, int* table) {
    if (root == NULL)
        return;
    
    table[root->val + 100000] += 1;

    accumulate(root->left, table);
    accumulate(root->right, table);

    return;
}

int* findMode(struct TreeNode* root, int* returnSize) {
    int* ret = malloc(10000 * sizeof(int));
    int* table = calloc(200001, sizeof(int));
    int minlimit = 1;

    *returnSize = 0;

    accumulate(root, table);

    for (int i = 0; i < 200001; i++)
    {
        if (table[i] > minlimit)
        {
            *returnSize = 0;
            ret[(*returnSize)++] = i - 100000;
            minlimit = table[i];
        }
        else if (table[i] == minlimit)
            ret[(*returnSize)++] = i - 100000;
    }

    free(table);

    return ret;
}
