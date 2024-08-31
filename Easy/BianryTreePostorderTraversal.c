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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* ret = malloc(100 * sizeof(int)); int* startP = ret;
    int* tmp = malloc(100 * sizeof(int));

    if (root == NULL)
    {
        free(ret);
        return NULL;
    }

    tmp = postorderTraversal(root->left, returnSize);
    if (tmp != NULL)
    {
        for (int i = 0; i < *returnSize; i++) ret[i] = tmp[i];
        ret += *returnSize;
    }
    int lsize = *returnSize; *returnSize = 0;

    tmp = postorderTraversal(root->right, returnSize);
    if (tmp != NULL)
    {
        for (int i = 0; i < *returnSize; i++) ret[i] = tmp[i];
        ret += *returnSize;
    }

    *ret = root->val;
    *returnSize += (lsize + 1);

    return startP;
}
