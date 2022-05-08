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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        ListNode *slow = head, *fast = head;
        while(fast!=nullptr)
        {
            fast = fast->next;
            if(fast!=nullptr && fast->next!=nullptr)
            {
                fast = fast->next;
                slow = slow->next;
            }
            else
            {
                if(fast!=nullptr && fast->next==nullptr)
                    fast = fast->next;
                ListNode *next = slow->next;
                slow->next = nullptr;
                slow = next;
            }
        }
        while(slow!=nullptr)
        {
            stk.push(slow);
            slow = slow->next;
        }
        slow = head;
        while(!stk.empty())
        {
            ListNode *next = slow->next;
            ListNode *v = stk.top();
            stk.pop();
            v->next = slow->next;
            slow->next = v;
            slow = next;
        }
    }
};
