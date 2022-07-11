class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c : s)
        {
            if(c=='(' || c=='{' || c=='[')
                stk.push(c);
            else
            {
                if(stk.empty())
                    return false;
                char top = stk.top();
                int ret = 0;
                switch(c)
                {
                    case ')':
                        ret = top=='('?1:0;
                        break;
                    case '}':
                        ret = top=='{'?1:0;
                        break;
                    case ']':
                        ret = top=='['?1:0;
                        break;
                    default:
                        break;
                }
                if(!ret)
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
