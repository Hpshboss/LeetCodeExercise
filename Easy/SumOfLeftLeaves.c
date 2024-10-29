/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define LDIRECT 0x00
#define RDIRECT 0x01

int delveIntoTree(struct TreeNode* root, int direct) {
    int ret = 0;

    if (root->left == NULL && root->right == NULL)
        if (direct == LDIRECT)
            return ret = root->val;
        else
            return ret;
    
    if (root->left != NULL)
        ret += delveIntoTree(root->left, LDIRECT);

    if (root->right != NULL)
        ret += delveIntoTree(root->right, RDIRECT);

    return ret;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int ret = 0;

    if (root->left != NULL)
        ret += delveIntoTree(root->left, LDIRECT);

    if (root->right != NULL)
        ret += delveIntoTree(root->right, RDIRECT);

    return ret;
}
