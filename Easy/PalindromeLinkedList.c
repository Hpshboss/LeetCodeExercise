/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* node = head;
    int len = 0;

    while(node != NULL)
    {
        len++;
        node = node->next;
    }

    int* vals = malloc(len * sizeof(int));

    node = head;
    for (int i = 0; i < len; i++)
    {
        vals[i] = node->val;
        node = node->next;
    }

    for (int i = 0; i < len >> 1; i++)
    {
        if (vals[i] != vals[len-i-1]) return false;
    }
    return true;
}
