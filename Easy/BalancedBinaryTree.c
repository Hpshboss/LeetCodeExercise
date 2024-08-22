/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxHeightOfTree(struct TreeNode* root) {
    if (root == NULL) return 0;

    int ret = 1;
    int lheight = maxHeightOfTree(root->left);
    int rheight = maxHeightOfTree(root->right);

    if (lheight < 0 || rheight < 0)
    {
        return -1;
    }

    if (abs(lheight - rheight) > 1)
    {
        return -1;
    }
    else
    {
        ret += lheight > rheight ? lheight : rheight;
        return ret;
    }
}
bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    
    int ret = maxHeightOfTree(root);
    return ret > 0 ? true : false;
}
