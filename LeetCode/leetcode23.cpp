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
    ListNode *merge2Lists(ListNode *node1, ListNode *node2)
    {
        if(!node1 || !node2)
            return node1==nullptr?node2:node1;
        ListNode *head = new ListNode;
        ListNode *node = head;
        ListNode *l1 = node1, *l2 = node2;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                node->next = l1;
                l1 = l1->next;
            }
            else
            {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if(!l1)
            node->next = l2;
        if(!l2)
            node->next = l1;
        return head->next;
    }

    ListNode* merge(vector<ListNode*>& lists, int L, int R)
    {
        if(L==R)
            return lists[L];
        if(L>R)
            return nullptr;
        int mid = (L + R)/2;
        return merge2Lists(merge(lists, L, mid), merge(lists, mid+1, R));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        return merge(lists, 0, len-1);
    }
};
