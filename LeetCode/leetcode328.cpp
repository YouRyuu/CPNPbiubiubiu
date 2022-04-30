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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *head1 = head, *head2 = head->next;
        ListNode *node1 = head1, *node2 = head2;
        while(node1 && node2 && node2->next)
        {
            node1->next = node2->next;
            node2->next = node1->next->next;
            node1 = node1->next;
            node2 = node2->next;
        }
        node1->next = head2;
        return head1;
    }
};
