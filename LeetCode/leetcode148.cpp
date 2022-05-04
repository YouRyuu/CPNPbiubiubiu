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
    ListNode *merge(ListNode *head, ListNode *tail)
    {
        if(head==nullptr)
            return head;
        if(head->next==tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode *slow=head, *fast=head;
        while(fast!=tail)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast!=tail)
                fast = fast->next;
        }
        ListNode *mid = slow;
        ListNode *left = merge(head, mid);
        ListNode *right = merge(mid, tail);
        ListNode *sorted = merge2List(left, right);
        return sorted;
    }

    ListNode *merge2List(ListNode *node1, ListNode *node2)
    {
        //合并两个有序链表.返回合并后的头节点
        ListNode *head = new ListNode;
        ListNode *temp = head, *n1 = node1, *n2 = node2;
        while(n1 && n2)
        {
            if(n1->val < n2->val)
            {
                temp->next = n1;
                n1 = n1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = n2;
                n2 = n2->next;
                temp = temp->next;
            }
        }
        if(n1)
            temp->next = n1;
        else if(n2)
            temp->next = n2;
        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        return merge(head, nullptr);
        
    }
};
