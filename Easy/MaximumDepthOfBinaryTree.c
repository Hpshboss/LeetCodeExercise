/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int ret = 0;
    int lcnt = 0;
    int rcnt = 0;

    if (root == NULL)
        return 0;
    
    if  (root->left != NULL)
        lcnt = maxDepth(root->left);
    
    if (root->right != NULL)
        rcnt = maxDepth(root->right);
    
    ret = lcnt > rcnt ? lcnt : rcnt;
    ret++;

    return ret;
}
