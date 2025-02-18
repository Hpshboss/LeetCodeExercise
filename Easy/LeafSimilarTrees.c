/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int* getLeafSeq(struct TreeNode* root, int* returnSize) {
    int* ret;

    if (*returnSize == 0)
        ret = malloc(200 * sizeof(int));
    
    if (root->left != NULL)
    {
        ret = getLeafSeq(root->left, returnSize);
    }
    if (root->right != NULL)
    {
        ret = getLeafSeq(root->right, returnSize);
    }
    if (root->left == NULL && root->right == NULL)
    {
        ret[(*returnSize)++] = root->val;
    }

    return ret;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int* seq1;
    int* seq2;
    int seq1Size = 0;
    int seq2Size = 0;

    seq1 = getLeafSeq(root1, &seq1Size);
    seq2 = getLeafSeq(root2, &seq2Size);

    if (seq1Size != seq2Size)
    {
        free(seq1);
        free(seq2);
        return false;
    }

    for (int i = 0; i < seq1Size; i++)
    {
        if (seq1[i] != seq2[i])
        {
            free(seq1);
            free(seq2);
            return false;
        }
    }

    return true;
}



