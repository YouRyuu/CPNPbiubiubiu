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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *p1=l1, *p2=l2, *p;
        
        int jingwei=0;
        int temp=0;
        for(;p1!=nullptr;p1=p1->next)
            jingwei++;
        for(;p2!=nullptr;p2=p2->next)
            temp++;
        if(jingwei<temp)
        {
            p=l2;
            p1=l2;
            p2=l1;
        }
        else
        {
            p=l1;
            p1=l1;
            p2=l2;
        }
        //p1永远指向长的那个
        jingwei=0, temp=0;

        for(;p1!=nullptr;p1=p1->next)
        {
            if(p2!=nullptr)
            {
                temp = p1->val + p2->val + jingwei;
                if(temp>=10)
                {
                    p1->val=temp-10;
                    jingwei=1;
                }
                else
                {
                    p1->val = temp;
                    jingwei = 0;
                }
                p2=p2->next;
            }
            else
            {
                temp = p1->val + jingwei;
                if(temp>=10)
                {
                    p1->val = temp -10;
                    jingwei = 1;
                }
                else
                {
                    p1->val=temp;
                    jingwei = 0;
                }
            }
            if(p1->next==nullptr && jingwei)//最长了还存在进位
            {
                p1->next=new ListNode(1);
                break;
            }
        }
        return p;
    }
};
