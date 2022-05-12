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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode *> stk1;
        stack<ListNode *> stk2;
        while(l1!=nullptr || l2!=nullptr)
        {
            if(l1!=nullptr)
            {
                stk1.push(l1);
                l1 = l1->next;
            }
            if(l2!=nullptr)
            {
                stk2.push(l2);
                l2 = l2->next;
            }
        }
        ListNode *next = nullptr, *curr;
        int count = 0;
        while(!stk1.empty() && !stk2.empty())
        {
            curr = stk1.top();
            curr->val += stk2.top()->val + count;
            if(curr->val >= 10)
            {
                curr->val = curr->val - 10;
                count = 1;
            }
            else
                count = 0;
            stk1.pop();
            stk2.pop();
            curr->next = next;
            next = curr;
        }
        stack<ListNode *> *p = stk1.empty()?&stk2:&stk1;
        while(!p->empty())
        {
            curr = p->top();
            curr->val += count;
            if(curr->val > 9)
            {
                curr->val -= 10;
                count = 1;
            }
            else
                count = 0;
            p->pop();
            curr->next = next;
            next = curr;
        }
        if(count==1)
        {
            curr = new ListNode(1, next);
        }
        return curr;
    }
};
