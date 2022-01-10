class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p1, *p2;
        p1=head;
        p2=nullptr;
        while(p1!=nullptr)
        {
            ListNode *temp = p1->next;
            if(p2!=nullptr)
            {
                p1->next = p2;
            }
            p2 = p1;
            if(p1==head)
                p1->next=nullptr;
            p1 = temp;
        }
        return p2;
    }
};
