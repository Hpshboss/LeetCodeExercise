/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* findStartingRoot(struct TreeNode* r, struct TreeNode* p, struct TreeNode* q, int* ispq) {
    int isl = 0;
    int isr = 0;
    struct TreeNode* ret = NULL;
    struct TreeNode* lret = NULL;
    struct TreeNode* rret = NULL;

    if (r->val == p->val || r->val == q->val)
        *ispq = 1;

    if (r->left != NULL)
        lret = findStartingRoot(r->left, p, q, &isl);

    if (r->right != NULL)
        rret = findStartingRoot(r->right, p, q, &isr);

    if (lret != NULL)
        ret = lret;
    else if (rret != NULL)
        ret = rret;
    else
        ret = NULL;
    
    if (isl == 1 && isr == 1)
        ret = r;
    else if ((isl == 1 || isr == 1) && *ispq == 1)
        ret = r;
    else if (isl == 1 || isr == 1)
        *ispq = 1;

    return ret;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* ret;
    int ispq = 0;

    ret = findStartingRoot(root, p, q, &ispq);
    return ret;
}
