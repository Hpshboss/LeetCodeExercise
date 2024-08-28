/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;
    
    struct ListNode** listNode = malloc(10000 * sizeof(struct ListNode*));

    for (int i = 0; i < 10000; i++)
    {
        listNode[i] = head;
        if (head->next != NULL)
        {
            head = head->next;
        }
        else
        {
            return false;
        }
        for (int j = 0; j < i; j++)
        {
            if (listNode[j] == listNode[i])
            {
                return true;
            }
        }
    }
    
    return false;
}
