/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        dfs(ret, head);
        return ret;
    }

    void dfs(vector<int> &ret, ListNode *node)
    {
        if(node==NULL)
            return;
        dfs(ret, node->next);
        ret.push_back(node->val);
    }
};
