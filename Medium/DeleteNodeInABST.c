/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int _findMinNode(struct TreeNode* root) {
    if (root->left != NULL)
    {
        return _findMinNode(root->left);
    }
    return root->val;
}

int _findMaxNode(struct TreeNode* root) {
    if (root->right != NULL)
    {
        return _findMaxNode(root->right);
    }
    return root->val;
}

struct TreeNode* _deleteNode(struct TreeNode* root, int key) {
    struct TreeNode* node = calloc(1, sizeof(struct TreeNode));

    // printf("root->val: %d; key: %d\n", root->val, key);

    if (root->val == key)
    {
        if (root->right != NULL)
        {
            key = _findMinNode(root->right);
            node->val = key;
            node->right = _deleteNode(root->right, key);
            node->left = root->left;
        }
        else if (root->left != NULL)
        {
            key = _findMaxNode(root->left);
            node->val = key;
            node->left = _deleteNode(root->left, key);
        }
        else 
        {
            free(node);
            node = NULL;
        }
    }
    else
    {
        node->val = root->val;
        if (root->right != NULL)
        {
            node->right = _deleteNode(root->right, key);
        }

        if (root->left != NULL)
        {
            node->left = _deleteNode(root->left, key);
        }
    }
    return node;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return NULL;

    return _deleteNode(root, key);
}
