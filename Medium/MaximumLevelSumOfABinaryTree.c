/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void _maxLevelSum(struct TreeNode* node, int level, int** calvals, int* returnSize) {
    if (level == *returnSize)
        calvals[level] = calloc(1, sizeof(int));
    
    *calvals[level] += node->val;
    (*returnSize) = level + 1 > (*returnSize) ? level + 1 : (*returnSize);
    
    if (node->left != NULL)
    {
        _maxLevelSum(node->left, level+1, calvals, returnSize);
    }
    if (node->right != NULL)
    {
        _maxLevelSum(node->right, level+1, calvals, returnSize);
    }

    return;
}

int maxLevelSum(struct TreeNode* root) {
    int** calvals = malloc(10000 * sizeof(int*));   // malloc first pointer, sub will malloc in sub function
    int calsize = 0;
    int ret = 0;
    int calmaxval = INT_MIN;

    _maxLevelSum(root, 0, calvals, &calsize);

    for (int i = 0; i < calsize; i++)
    {
        if (*calvals[i] > calmaxval)
        {
            calmaxval = *calvals[i];
            ret = i + 1;
        }
    }

    return ret;
}
