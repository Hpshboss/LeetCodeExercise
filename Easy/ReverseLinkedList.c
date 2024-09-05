/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    
    struct ListNode* ret = malloc(sizeof(struct ListNode));
    struct ListNode* sp = ret;
    struct ListNode** arr = malloc(5000*sizeof(struct ListNode*));

    int i = 0;
    for (i = 0; head != NULL; i++)
    {
        arr[i] = head;
        head = head->next;
    }
    
    for (i--;i >= 0; i--)
    {
        ret->val = arr[i]->val;
        ret->next = i != 0 ? arr[i-1] : NULL;
        ret = ret->next;
    }
    
    free(arr);
    return sp;
}
