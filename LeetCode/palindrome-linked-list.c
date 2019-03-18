//my:
//Runtime: 28 ms, faster than 11.79% of C online submissions for Palindrome Linked List.
//Memory Usage: 12.2 MB, less than 20.46% of C online submissions for Palindrome Linked List.

bool isPalindrome(struct ListNode* head) {
    struct ListNode* fast;
    struct ListNode* slow;
    struct ListNode* start = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(head==NULL || head->next==NULL) return true;
    start->val = head->val;
    start->next = NULL;
    struct ListNode* q = start;
    struct ListNode *p;
    int count = 0;
    fast = head;
    slow = head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = slow->val;
        p->next = q;
        q = p;
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }
    if(fast == NULL) slow = slow;
    else slow = slow->next;
    while(p!=start)
    {
        if(p->val==slow->val)
        {
            p = p->next;
            slow = slow->next;
        }
        else
            return false;
    }
    return true;
}