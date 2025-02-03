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

    if (head == NULL || head->next == NULL)
        return NULL;

    while (true)
    {
        size++;
        if (node->next != NULL)
            node = node->next;
        else
            break;
    }
    
    node = head;
    for (int i = 0; i < size - 1; i++)
    {
        if (i == (size >> 1) - 1)
        {
            node->next = node->next->next;
            continue;
        }
        node = node->next;
    }

    return head;
}
