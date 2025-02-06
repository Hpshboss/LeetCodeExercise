/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* ret = calloc(1, sizeof(struct ListNode));
    struct ListNode* retsp = ret;
    struct ListNode* node = head;
    int* vals = malloc(5000 * sizeof(int));
    int idx = 0;

    if (head == NULL)
    {
        free(vals);
        return NULL;
    }

    while (node != NULL)
    {
        vals[idx++] = node->val;
        node = node->next;
    }

    while (idx > 1)
    {
        ret->val = vals[--idx];
        ret->next = calloc(1, sizeof(struct ListNode));
        ret = ret->next;
    }
    ret->val = vals[0];

    ret = retsp;

    free(vals);
    return ret;
}
