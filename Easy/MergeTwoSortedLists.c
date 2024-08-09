/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode listHead;
    struct ListNode* listAfterHead;
    listAfterHead = &listHead;

    for (int i = 0; i < 100; i++)
    {
        printf("loop start");
        if (list1 == NULL)
        {
            listAfterHead->next = list2;
            break;
        }
        if (list2 == NULL)
        {
            listAfterHead->next = list1;
            break;
        }
        
        printf("%d:%d\n", list1->val, list2->val);
        if (list1->val < list2->val)
        {
            listAfterHead->next = list1;
            list1 = list1->next;
        }
        else
        {
            listAfterHead->next = list2;
            list2 = list2->next;
        }
        listAfterHead = listAfterHead->next;
    }
    return listHead.next;
}
