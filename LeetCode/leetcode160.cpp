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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> temp;
        ListNode *p1=headA,*p2=headB;
        for(;p1!=NULL;p1=p1->next)
        {
            temp.insert(p1);
        }
        for(;p2!=NULL;p2=p2->next)
        {
            if(temp.find(p2)!=temp.end())
            {
                return p2;
            }
        }
        //if(p1==p2) return headA;
        return NULL;
    }
};
