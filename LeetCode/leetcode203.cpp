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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return nullptr;
        ListNode *p = head;
        head = digui(p, val);
        return head;

    }

    ListNode* digui(ListNode* node, int val)
    {
        if(node==nullptr) return nullptr;
        node->next = digui(node->next, val);
        if(node->val==val)
            return node->next;
        return node;
    }

};
