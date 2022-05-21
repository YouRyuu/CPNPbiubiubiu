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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ret;
        int len = 0;
        for(ListNode *v=head; v!=nullptr; v=v->next)
            ++len;
        if(len<=k)
        {
            int count = k-len;
            while(head)
            {
                ListNode *next=head->next;
                head->next = nullptr;
                ret.push_back(head);
                head = next;
            }
            while(count)
            {
                ret.push_back(nullptr);
                --count;
            }
        }
        else
        {
            int mod = len%k;            //1
            int prelen = len/k;         //3
            while(head)
            {
            ListNode *node=head;
            for(int i=0; i<prelen-1 && node!=nullptr; ++i)
            {
                node=node->next;
            }
            if(mod)
            {
                node=node->next;
                --mod;
            }
            ListNode *next = node->next;
            node->next=nullptr;
            ret.push_back(head);
            head=next;
            }
        }
        return ret;
    }
};
