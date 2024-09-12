/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int digTree(struct TreeNode* node, int end, int level)
{
    if (level == end)
    {
        if (node != NULL)
            return 1;
        else
            return 0;
    }
    level += 1;
    return digTree(node->left, end, level) + digTree(node->right, end, level);
}

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;

    int ret = 0;
    int level = 0;
    struct TreeNode* node = root;

    while (node != NULL)
    {
        level++;
        node = node->left;
    }

    for (int i = 0; i < level-1; i++) ret += pow(2, i);

    ret += digTree(root, level, 1);

    return ret;
}
