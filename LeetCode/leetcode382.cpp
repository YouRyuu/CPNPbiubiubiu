class Solution {
public:
    ListNode *node;
    Solution(ListNode* head) {
        node = head;
    }
    
    int getRandom() {
        int i=1, ret = 0;
        for(ListNode *item=node; item!=nullptr; item=item->next)
        {
            if(rand()%i==0)
                ret = item->val;
            ++i;
        }
        return ret;
    }
};
