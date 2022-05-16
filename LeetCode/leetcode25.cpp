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

    pair<ListNode*, ListNode*> reverse(ListNode *head, ListNode *tail)
    {
        ListNode *pre = tail->next;
        ListNode *p = head;
        while(pre!=tail)
        {
            ListNode *next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return {tail, head};        //返回新的头和尾
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *hair = new ListNode;
        hair->next = head;
        ListNode *pre = hair;
        while(head)
        {
            ListNode *tail = pre;
            for(int i=0; i<k; ++i)
            {
                tail = tail->next;
                if(!tail)
                    return hair->next;
            }
            ListNode *next = tail->next;
            pair<ListNode*, ListNode*> ret = reverse(head, tail);
            head = ret.first;
            tail = ret.second;
            pre->next = head;
            tail->next = next;
            pre = tail;
            head = next;
        }
        return hair->next;
    }
};
