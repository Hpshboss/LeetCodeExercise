/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int cntMatch(struct TreeNode* root, int targetSum, int* path, int pathSize) {
    int curval = root->val;
    long calval = 0;
    int ret = 0;
    
    path[pathSize++] = curval;
    
    for (int i = pathSize - 1; i >= 0; i--)
    {
        calval += path[i];
        if (calval == targetSum)
            ret++;
    }

    if (root->left != NULL)
        ret += cntMatch(root->left, targetSum, path, pathSize);
    
    if (root->right != NULL)
        ret += cntMatch(root->right, targetSum, path, pathSize);

    return ret;
}

int pathSum(struct TreeNode* root, int targetSum) {
    int ret = 0;
    int* path = malloc(1000 * sizeof(int));
    int pathSize = 0;

    if (root == NULL)
        goto out;
    
    ret = cntMatch(root, targetSum, path, pathSize);
    goto out;

out:
    free(path);
    return ret;
}
