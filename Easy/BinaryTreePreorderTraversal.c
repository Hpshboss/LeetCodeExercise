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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* ret = malloc(100 * sizeof(struct TreeNode));
    int* tmp = malloc(100 * sizeof(struct TreeNode));
    int* startret = ret;
    if (root == NULL)
    {
        free(ret);
        return NULL;
    }

    *ret = root->val;
    ret += 1;
    tmp = preorderTraversal(root->left, returnSize);
    if (tmp != NULL) 
    {
        for (int i = 0; i < *returnSize; i++) ret[i] = tmp[i];
        ret += *returnSize;
    }
    
    int lsize = *returnSize;
    *returnSize = 0;
    tmp = preorderTraversal(root->right, returnSize);
    for (int i = 0; i < *returnSize; i++) ret[i] = tmp[i];
    *returnSize = *returnSize + lsize + 1;

    return startret;
}
