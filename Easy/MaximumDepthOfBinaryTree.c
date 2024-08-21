/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int ret = 1;
    if (root->right != NULL | root->left != NULL)
    {
        int ldepth = maxDepth(root->left);
        int rdepth = maxDepth(root->right);
        ret += (ldepth > rdepth ? ldepth : rdepth);
    }
    return ret;
}
