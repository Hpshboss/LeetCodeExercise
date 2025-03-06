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
void __rightSideView(struct TreeNode* root, int layer, int* views, int* viewsSize) {
    views[layer] = root->val;

    if (layer == *viewsSize)
        (*viewsSize)++;
    
    if (root->left != NULL)
        __rightSideView(root->left, layer+1, views, viewsSize);
    
    if (root->right != NULL)
        __rightSideView(root->right, layer+1, views, viewsSize);
    
    return;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* views = malloc(100 * sizeof(int));
    int viewSize = 0;

    if (root == NULL)
        goto out;
        
    __rightSideView(root, 0, views, &viewSize);

out:
    *returnSize = viewSize;
    return views;
}
