class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        stack<int> stk;
        int ret = 0;
        stk.push(-1);
        for(int i=0; i<len; ++i)
        {
            if(s[i]=='(')       //遇到左括号时压栈
            {
                stk.push(i);
            }
            else        //遇到右括号时，找到离它最近的左括号开始匹配
            {
                stk.pop();
                if(stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    ret = max(ret, i-stk.top());
                }
            }
        }
        return ret;
    }
};
