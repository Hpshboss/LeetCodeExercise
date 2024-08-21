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

int* getNFloor(struct TreeNode* root, int n) {
    int powval = pow(2, n);
    int* vals = malloc(powval * sizeof(int));
    int* valtmps = malloc(powval * sizeof(int) / 2);

    if (n == 0)
    {
        if (root == NULL)
        {
            // printf("Insert:-101\n");
            vals[0] = -101;
            return vals;
        }
        else
        {
            // printf("Insert: %d\n", root->val);
            vals[0] = root->val;
            return vals;
        }
    }

    struct TreeNode* tmptreeNode;
    int halfpowval = powval / 2;
    valtmps = getNFloor(root != NULL ? root->left : tmptreeNode, n - 1);
    for (int i = 0; i < halfpowval; i++)
    {
        vals[i] = valtmps[i];
    }
    valtmps = getNFloor(root != NULL ? root->right : tmptreeNode, n - 1);
    for (int i = 0; i < halfpowval; i++)
    {
        vals[i+halfpowval] = valtmps[i];
    }
    free(valtmps);
    return vals;
}

bool isSymmetric(struct TreeNode* root) {
    bool ret = true;
    int powval = 1;
    for (int layer = 1; layer < 20; layer++)
    {
        powval = pow(2, layer);
        int* test = malloc(powval * sizeof(int));

        // printf("%d floor\n", layer);
        test = getNFloor(root, layer);
        // printf("ccc\n");
        for (int i = 0; i < powval; i++)
        {
            if (test[i] != -101) break;
            if (i == powval - 1) return ret;
        }
        for (int i = 0; i < powval / 2; i++)
        {
            // printf("aaa\n");
            if (test[i] != test[powval-i-1])
            {
                // printf("bbb\n");
                return ret = false;
            } 
        }
        free(test);
    }
    return ret;
}
