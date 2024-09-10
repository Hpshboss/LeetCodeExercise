/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 **/

bool containsDuplicate(int* nums, int numsSize) {
    struct TreeNode* head = malloc(sizeof(struct TreeNode));
    struct TreeNode* sp = head;

    head->val = nums[0]; head->left = NULL; head->right = NULL;
    for (int i = 1; i < numsSize; i++)
    {
        head = sp;
        while (head != NULL)
        {
            if (head->val == nums[i]) return true;
            if (head->val > nums[i])
            {
                if (head->left == NULL)
                {
                    struct TreeNode* node = malloc(sizeof(struct TreeNode));
                    node->val = nums[i]; node->left = NULL; node->right = NULL;
                    head->left = node;
                    break;
                }
                else
                {
                    head = head->left;
                }
            }
            else 
            {
                if (head->right == NULL)
                {
                    struct TreeNode* node = malloc(sizeof(struct TreeNode));
                    node->val = nums[i]; node->left = NULL; node->right = NULL;
                    head->right = node;
                    break;
                }
                else
                {
                    head = head->right;
                }
            }
        }
    }
    return false;
}
