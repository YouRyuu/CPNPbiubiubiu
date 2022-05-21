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
    ListNode* partition(ListNode* head, int x) {
        ListNode *hair = new ListNode;
        hair->next = head;
        ListNode *pre = hair, *node = hair;
        while(node && node->next)
        {
            if(node->next->val < x)
            {
                if(pre==node)
                {
                    pre = pre->next;
                    node = node->next;
                    continue;
                }
                ListNode *v = node->next;
                node->next = v->next;
                v->next = pre->next;
                pre->next = v;
                pre = pre->next;
            }
            else
            {
                node = node->next;
            }
        }
        return hair->next;
    }
};
