/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* node = head;
    struct ListNode* olist = calloc(1, sizeof(struct ListNode));
    struct ListNode* elist = calloc(1, sizeof(struct ListNode));
    struct ListNode* osp = olist;
    struct ListNode* esp = elist;

    if (head == NULL)
        return NULL;
    
    if (head->next == NULL)
    {
        olist->val = node->val;
        return osp;
    }

    for (int i = 1;; i++)
    {
        if (i % 2)
        {
            olist->val = node->val;

            if (node->next != NULL)
                node = node->next;
            else
                break;

            if (node->next != NULL)
            {
                olist->next = calloc(1, sizeof(struct ListNode));
                olist = olist->next;
            }
        }
        else
        {
            elist->val = node->val;

            if (node->next != NULL)
                node = node->next;
            else
                break;
            
            if (node->next != NULL)
            {
                elist->next = calloc(1, sizeof(struct ListNode));
                elist = elist->next;
            }
        }
    }

    olist->next = esp;

    return osp;
}
