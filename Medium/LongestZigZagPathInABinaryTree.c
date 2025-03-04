/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define PATHLEN 50000

int countLongest(struct TreeNode* root, int* path, int pathSize) {
    int ret = 0;
    int tmp = 0;
    if (root->left == NULL & root->right == NULL)
    {
        for (int i = 0; i < pathSize; i++)
        {
            tmp++;
            if (path[i] == path[i+1])
            {
                ret = tmp > ret ? tmp : ret;
                tmp = 0;
            }
        }
        ret = tmp > ret ? tmp : ret;
    }

    if (root->left != NULL)
    {
        path[pathSize] = -1;
        tmp = countLongest(root->left, path, pathSize+1);
    }

    ret = tmp > ret ? tmp : ret;

    if (root->right != NULL)
    {
        path[pathSize] = 1;
        tmp = countLongest(root->right, path, pathSize+1);
    }

    ret = tmp > ret ? tmp : ret;

    return ret;
}

int longestZigZag(struct TreeNode* root) {
    int ret = 0;
    int* path = calloc(PATHLEN, sizeof(int));

    ret = countLongest(root, path, 0);

    return ret;
}
