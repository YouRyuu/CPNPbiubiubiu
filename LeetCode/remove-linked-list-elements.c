struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL) return NULL;
    struct ListNode *p = head;
    struct ListNode *q = p->next;
    while(q!=NULL)
    {
        if(q->val==val)
        {
            p->next = q->next;
            q = q->next;
            continue;
        }
        q = q->next;
        p = p->next;
    }
    if(head->val==val)
    {
        head=head->next;
    }
    return head;
}