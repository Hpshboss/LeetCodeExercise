/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return head;

    struct ListNode* listNode = head;

    while (listNode->next != NULL)
    {
        if (listNode->val == listNode->next->val)
        {
            listNode->next = listNode->next->next;
        }
        else
        {
            listNode = listNode->next;
        }
    }
    return head;
}
