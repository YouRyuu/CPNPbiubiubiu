class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* node = new ListNode(0, head);
        ListNode* node1, *node2, *temp=node;
        while(temp->next!=nullptr && temp->next->next!=nullptr)
        {
            node1 = temp->next;
            node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return node->next;
    }
};
