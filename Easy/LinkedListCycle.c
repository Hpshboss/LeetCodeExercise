/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return false;
    
    struct ListNode* oneStep = head;
    struct ListNode* twoStep = head->next;

    while (1)
    {
        if (oneStep == twoStep) return true;
        
        if (twoStep->next == NULL) return false;
        if (twoStep->next->next == NULL) return false;

        oneStep = oneStep->next;
        twoStep = twoStep->next->next;
    }
    return false;
}
