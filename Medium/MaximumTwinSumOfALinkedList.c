/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode** head, int pos) {
    struct ListNode* prev;
    struct ListNode* current;
    struct ListNode* next;
    prev = NULL;
    current = *head;
    for (int i = 0; i < pos; i++)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = next;
    return prev;
}

int pairSum(struct ListNode* head) {
    int hsize = 0;
    struct ListNode *node = head;
    struct ListNode *rnode;
    int ret = 0;
    int buf = 0;

    for (;node != NULL; node = node->next)
        hsize++;
    
    node =  head;
    
    rnode = reverseList(&node, hsize / 2);


    while (node != NULL)
    {
        buf = node->val + rnode->val;
        ret = buf > ret ? buf : ret;
        node = node->next;
        rnode = rnode->next;
    }

    return ret;
}
