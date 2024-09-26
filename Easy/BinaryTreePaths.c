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
#define ARROW "->"

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    char** ret = malloc(100 * sizeof(char*));
    if (root->right == NULL && root->left == NULL)
    {
        *returnSize += 1;
        ret[0] = calloc(5, sizeof(char));
        sprintf(ret[0], "%d", root->val);
        return ret;
    }

    if (root->left != NULL)
    {
        char** leftret = binaryTreePaths(root->left, returnSize);
        for (int i = 0; i < *returnSize; i++) 
        {
            ret[i] = calloc(100, sizeof(char));
            sprintf(ret[i], "%d%s%s", root->val, ARROW, leftret[i]);
        }
    }
    
    if (root->right != NULL)
    {
        int retsp = *returnSize;
        char** rightret = binaryTreePaths(root->right, returnSize);
        *returnSize = *returnSize + retsp;
        for (int i = retsp; i < *returnSize; i++) 
        {
            ret[i] = calloc(100, sizeof(char));
            sprintf(ret[i], "%d%s%s", root->val, ARROW, rightret[i - retsp]);
        }
    }
    
    return ret;
}
