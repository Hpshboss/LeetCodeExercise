/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode* ret = malloc(sizeof(struct TreeNode));

    if (numsSize == 0) return NULL;

    ret->val = nums[numsSize/2];

    if (numsSize > 1)
    {
        ret->left = sortedArrayToBST(nums, numsSize >> 1);
        ret->right = sortedArrayToBST(nums + (numsSize >> 1) + 1, numsSize & 1 == 1 ? numsSize >> 1 : (numsSize >> 1) - 1);
    }
    else
    {
        ret->left = NULL;
        ret->right = NULL;
    }
    
    return ret;
}
