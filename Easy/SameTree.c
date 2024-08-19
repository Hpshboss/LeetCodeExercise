/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL & q == NULL) return true;
    if (p == NULL ^ q == NULL) return false;

    bool ret = true;
    if (p->val == q->val)
    {
        ret &= isSameTree(p->left, q->left);
        ret &= isSameTree(p->right, q->right);
    }
    else
    {
        ret &= false;
    }
    return ret;
}
