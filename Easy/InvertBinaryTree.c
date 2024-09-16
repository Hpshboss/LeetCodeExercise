/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return root;

    struct TreeNode* tmpNode = malloc(sizeof(struct TreeNode));
    
    tmpNode = root->left;
    root->left = root->right;
    root->right = tmpNode;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}
