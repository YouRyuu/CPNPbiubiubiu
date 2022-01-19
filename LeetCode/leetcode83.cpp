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
        if(head==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast;
        for(fast=slow->next;fast!=nullptr;)
        {
            if(fast->val==slow->val)
            {
                fast = fast->next;
            }
            else
            {
                slow->next = fast;
                slow = slow->next;
                fast = slow->next;
            }
        }
        slow->next=fast;
        return head;

    }
};
