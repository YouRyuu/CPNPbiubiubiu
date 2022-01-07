/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode *p1=head, *p2=head->next;
        // int count=1;
        // int size=1;
        // for(;p2!=nullptr;p2=p2->next)
        // {
        //     size++;     //求出链表的长度
        // }
        // if(size==n)
        // {
        //     head=head->next;
        // }
        // else
        // {
        //     size = size-n;
        // for(;count<size;count++)
        // {
        //     p1 = p1->next;
        // }
        // p1->next=p1->next->next;
        // }
        
        // return head;
        ListNode* p = new ListNode(0, head);
        ListNode *slow=p, *fast=p;
        for(int i=0;i<n+1;i++)
            fast=fast->next;
        while(fast!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return p->next;

    }
};
