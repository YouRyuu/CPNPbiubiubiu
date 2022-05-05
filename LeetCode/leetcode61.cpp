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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0)
            return head;
        int len = 0;
        ListNode *node = head;
        while(node!=nullptr)
        {
            ++len;
            node = node->next;
        }
        k = k % len;
        if(k==0)
            return head;
        ListNode *slow = head, *fast = head;
        while(k>0)
        {
            --k;
            fast = fast->next;
        }
        while(fast->next!=nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return newHead;
    }
};
