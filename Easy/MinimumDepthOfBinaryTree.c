/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;

    int ret = 1;
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);

    if (lh == 0 || rh == 0)
    {
        ret += lh == 0 ? rh : lh;
    }
    else
    {
        ret += lh < rh ? lh : rh;
    }
    return ret;
}
