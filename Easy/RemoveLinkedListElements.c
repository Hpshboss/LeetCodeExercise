/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* prev = malloc(sizeof(struct ListNode));
    struct ListNode* prev_sp = malloc(sizeof(struct ListNode));

    prev->next = head;
    prev_sp = prev;
    
    while (head)
    {
        if (head->val == val) 
        {
            prev->next = head->next;
            head = head->next;
        }
        else
        {
            prev = head;
            head = head->next;
        }
    }
    return prev_sp->next;
}
