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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> temp;
        int size;
        ListNode *p=head;
        for(;p!=nullptr;p=p->next)
        {
            temp.push(p);
        }
        p=head;
        while(p!=nullptr)
        {
            if(p->val!=(temp.top())->val)
            {
                return false;
            }
            temp.pop();
            p=p->next;
        }
        return true;

    }
};


//快慢指针
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode pre = null;
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null){
            ListNode temp = slow.next;
            if(pre != null) {
                slow.next = pre;
            }
            pre = slow;
            fast = fast.next.next;
            slow = temp;
        }
        if(fast != null) slow = slow.next;
        while(slow != null){
            if(slow.val != pre.val) return false;
            slow = slow.next;
            pre = pre.next;
        }
        return true;
    }
}
