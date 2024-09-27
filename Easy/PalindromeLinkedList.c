/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* snode = head;
    struct ListNode* fnode = head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = NULL;
    struct ListNode* next = NULL;
    struct ListNode* startnode = NULL;
    struct ListNode* endnode = NULL;

    while (fnode != NULL)
    {
        if (fnode->next == NULL) break;
        snode = snode->next;
        fnode = fnode->next->next;
    }

    curr = snode;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    startnode = head;
    endnode = prev;
    while(startnode != NULL && endnode != NULL)
    {
        if (startnode->val != endnode->val) return false;
        startnode = startnode->next;
        endnode = endnode->next;
    }

    return true;
}
