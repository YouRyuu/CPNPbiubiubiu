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
    ListNode *reverse(ListNode *end, ListNode *node)
    {
        ListNode *pre = end;
        while(node!=end)
        {
            ListNode *next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }
        return pre;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *hair = new ListNode;
        hair->next = head;
        int index = 0;
        ListNode *node = hair;
        ListNode *LNode, *RNode;
        while(node!=nullptr)
        {
            ++index;
            if(left==index)
            {
                LNode = node;
            }
            if(right==index-1)
            {
                RNode = node->next;
                break;
            }
            node = node->next;
        }
        LNode->next = reverse(RNode, LNode->next);
        return hair->next;

    }
};
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *hair = new ListNode;
        hair->next = head;
        ListNode *pre = hair;
        for(int i=0; i<left-1; ++i)
        {
            pre = pre->next;
        }
        ListNode *curr = pre->next;
        for(int i=0; i<right-left; ++i)
        {
            ListNode *next = curr->next;
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;

        }
        return hair->next;
    }
};
