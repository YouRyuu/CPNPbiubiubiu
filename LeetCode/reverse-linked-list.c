/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p = head;
    struct ListNode *cur=NULL;
    while(p!=NULL)
    {
        struct ListNode *temp = p->next;
        p->next = cur;
        cur = p;
        p = temp;
    }
    return cur;
}


//second:
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL||head->next==NULL)
        return head;
    struct ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}