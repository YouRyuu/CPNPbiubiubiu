class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int len = preorder.size();
        stack<int> stk;
        int pre = INT_MIN;
        for(int i=0; i<len; ++i)
        {
            if(preorder[i] < pre)
                return false;
            while(!stk.empty() && preorder[i] > stk.top())
            {
                pre = stk.top();
                stk.pop();
            }
            stk.push(preorder[i]);
        }
        return true;
    }
};

