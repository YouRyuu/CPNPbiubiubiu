class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        //ListNode *start = new ListNode();
        //start->next = head;
        ListNode *node = head->next;
        while(node!=nullptr)
        {
            for(ListNode *temp = head; temp!=node; temp=temp->next)
            {
                if(node->val < temp->val)
                {
                    int v = temp->val;
                    temp->val = node->val;
                    node->val = v;
                }
            }
            node=node->next;
        }        
        return head;
    }
};

