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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* ret = malloc(100 * sizeof(int));
    int* rettmp = malloc(100 * sizeof(int));
    
    if (root == NULL) return ret;
    
    if (root->left != NULL) { rettmp = inorderTraversal(root->left, returnSize); }
    for (int i = 0; i < *returnSize; i++)
    {
        ret[i] = rettmp[i];
    }
    
    ret[*returnSize] = root->val;
    int ridx = *returnSize + 1;

    *returnSize = 0;
    if (root->right != NULL) { rettmp = inorderTraversal(root->right, returnSize); }
    for (int i = ridx; i < *returnSize + ridx; i++)
    {
        ret[i] = rettmp[i-ridx];
    }
    *returnSize += ridx;
    
    free(rettmp);
    return ret;
}
