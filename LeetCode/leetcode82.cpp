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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *hair = new ListNode(200);
        hair->next = head;
        ListNode *pre = hair, *slow = hair, *fast = head;
        while(fast!=nullptr)
        {
            if(slow->val==fast->val)
            {
                fast = fast->next;
            }
            else
            {
                pre->next = fast;
                slow = fast;
                fast = fast->next;
                if(fast!=nullptr && slow->val != fast->val)
                    pre = slow;
            }
        }
        if(slow->next!=nullptr && slow->val==slow->next->val)
            pre->next=nullptr;
        return hair->next;
    }
};
