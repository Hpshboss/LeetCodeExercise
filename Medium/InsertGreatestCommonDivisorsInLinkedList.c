/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head)
{
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* sp = head;

    int tmp = 0;
    int currVal = 0;
    int nextVal = 0;

    while (head->next != NULL)
    {
        currVal = head->val;
        nextVal = head->next->val;
        while (nextVal != 0)
        {
            tmp = nextVal;
            nextVal = currVal % nextVal;
            currVal = tmp;
        }

        struct ListNode* insNode = malloc(sizeof(struct ListNode));
        insNode->val = currVal;
        insNode->next = head->next;
        head->next = insNode;
        head = head->next->next;
    }
    return sp;
}
