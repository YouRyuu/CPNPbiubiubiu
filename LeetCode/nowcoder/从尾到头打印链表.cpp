class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> temp;
        vector<int> ret;
        while(head!=NULL)
        {
            temp.push_back(head->val);
            head = head->next;
        }
        while(!temp.empty())
        {
            ret.push_back(temp[temp.size()-1]);
            temp.pop_back();
        }
        return ret;
    }
};
//https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking