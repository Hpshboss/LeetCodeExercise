/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define LOWERBOUND -10000

int countSmallerNodes(struct TreeNode* root, int mval) {
    int ret = 0;

    if (root->val >= mval)
    {
        mval = root -> val;
        ret++;
    }
    
    if (root->left != NULL)
        ret += countSmallerNodes(root->left, mval);

    if (root->right != NULL)
        ret += countSmallerNodes(root->right, mval);
    
    return ret;
}

int goodNodes(struct TreeNode* root){
    int ret = 0;
    ret = countSmallerNodes(root, LOWERBOUND);

    return ret;
}
