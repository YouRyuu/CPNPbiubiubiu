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
        ListNode *slow = head, *fast = head;
        while(fast!=NULL)
        {
            fast = fast->next;
            if(fast==NULL)
                return NULL;
            slow = slow->next;
            fast = fast->next;
            if(slow == fast)
            {
                ListNode *ptr = head;
                while(slow!=ptr)
                {
                    slow = slow->next;
                    ptr = ptr->next;
                }
                return ptr;
            }
        }
        return NULL;
    }
};
