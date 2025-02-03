/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    int size = 0;
    struct ListNode* ret = malloc(sizeof(struct ListNode));
    struct ListNode* retsp = ret;
    struct ListNode* node = head;

    while (true)
    {
        size++;
        if (node->next != NULL)
            node = node->next;
        else
            break;
    }

    node = head;
    for (int i = 0; i < size; i++)
    {
        printf("jjjj\n");
        if (i == (size >> 1))
            continue;
        
        ret->val = node->val;
        ret->next = malloc(sizeof(struct ListNode));
        ret = ret->next;
        node = node->next;
    }
    ret = retsp;

    return ret;
}
