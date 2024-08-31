/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define isNullOrNext(node, num) if(node != NULL) { node = node->next; num++; }

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* nodeA = headA;
    struct ListNode* nodeB = headB;

    int numA = 0, numB = 0;
    while (nodeA != NULL || nodeB != NULL)
    {
        isNullOrNext(nodeA, numA);
        isNullOrNext(nodeB, numB);
    }

    nodeA = headA;
    nodeB = headB;
    int minNum = 0;
    int dropNum = 0;
    if (numA < numB)
    {
        minNum = numA;
        dropNum = numB - numA;
        for (int i = 0; i < dropNum; i++) nodeB = nodeB->next;
    }
    else
    {
        minNum = numB;
        dropNum = numA - numB;
        for (int i = 0; i < dropNum; i++) nodeA = nodeA->next;
    }

    for (int i = 0; i < minNum; i++)
    {
        if (nodeA == nodeB) return nodeA;
        nodeA = nodeA->next;
        nodeB = nodeB->next;
    }
    return NULL;
}
