/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int is_add = 0;
    int result = 0;
    struct ListNode *p=NULL;
    struct ListNode *curr, *tail;
    while(l1!=NULL && l2!=NULL)
    {
        result = l1->val + l2->val + is_add;
        is_add = 0;
        if(result>=10)
        {
            is_add = 1;
            result =result -10;
        }
        if (p == NULL) {
            p = (struct ListNode *) malloc(sizeof(struct ListNode));
            p->val = result;
            p->next = NULL;
            curr = p;
             l1 = l1->next;
        l2 = l2->next;
            continue;
        }
        tail = (struct ListNode *) malloc(sizeof(struct ListNode));
        tail->val = result;
        tail->next = NULL;
        curr->next = tail;
        curr = curr->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1!=NULL)
    {
        tail = (struct ListNode *) malloc(sizeof(struct ListNode));
        result =  l1->val + is_add;
        if(result>=10)
        {
            is_add = 1;
            result = result -result;
        }
        else
            is_add = 0;
        tail->val = result;
        tail->next = NULL;
        curr->next = tail;
        curr = curr->next;
        l1 = l1->next;
    }
    while(l2!=NULL)
    {
        tail = (struct ListNode *) malloc(sizeof(struct ListNode));
        result =  l2->val + is_add;
        if(result>=10)
        {
            is_add = 1;
            result = result -result;
        }
        else
            is_add = 0;
        tail->val = result;
        tail->next = NULL;
        curr->next = tail;
        curr = curr->next;
        l2 = l2->next;
    
    }
    if(is_add)
    {
        tail = (struct ListNode *) malloc(sizeof(struct ListNode));
        tail->val = is_add;
        tail->next = NULL;
        curr->next = tail;
        curr = curr->next;
}
    return p;
}