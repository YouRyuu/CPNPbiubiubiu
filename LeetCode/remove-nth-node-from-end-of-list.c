/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
   struct ListNode*p, *q;
    p = head;
    q = head;
    int count = 0;
    while(p!=NULL&&count!=n)
    {
        p = p->next;
        count++;
        if(p==NULL) return head->next;
    }
    while(p->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->next!=NULL)
        q->next = q->next->next;
    return head;
}