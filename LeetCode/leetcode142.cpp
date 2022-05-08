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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, ListNode*> m;
        ListNode *hair = new ListNode;
        hair->next = head;
        ListNode *node = hair;
        while(node!=NULL && node->next!=NULL)
        {
            if(m.count(node->next)==0)
            {
                m[node->next] = node;
                node = node->next;
            }
            else
            {
                ListNode *v = m[node->next];
                return v->next;
            }
        }
        return NULL;
    }
};
