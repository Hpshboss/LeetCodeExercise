/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return targetSum - root->val == 0 ? true : false;

    bool ret = false;
    if (root->left != NULL) ret |= hasPathSum(root->left, targetSum - root->val);
    if (root->right != NULL) ret |= hasPathSum(root->right, targetSum - root->val);
    return ret;
}
