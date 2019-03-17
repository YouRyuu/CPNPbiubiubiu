/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p,*q;
    p = head;
    while(p!=NULL)
    {
        if(p->next!=NULL)
        {
            if(p->val == p->next->val)
            {
                p->next = p->next->next;
            }
            else
            p = p->next;
        }
        else break;
    }
    return head;
}