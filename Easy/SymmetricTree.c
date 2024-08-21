/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// int pow(int m, int n) {
//     int ret = 1;
//     for (int i = 0; i < n; i++)
//     {
//         ret *= m;
//     }
//     return ret;
// }
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL & right == NULL) return true;
    if (left == NULL | right == NULL) return false;
    return (left->val == right->val) & isMirror(left->left, right->right) & isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    return isMirror(root->left, root->right);
}
