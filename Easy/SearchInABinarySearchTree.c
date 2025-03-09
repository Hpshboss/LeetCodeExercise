/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (val > root->val)
        if (root->right != NULL)
            return searchBST(root->right, val);

    if (val < root->val)
        if (root->left != NULL)
            return searchBST(root->left, val);
            
    if (val == root->val)
        return root;
    
    return NULL;
}
