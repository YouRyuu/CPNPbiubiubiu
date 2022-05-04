class Solution {
public:
    bool checkValidString(string s) {
        stack<int> kohc;
        stack<int> xkhc;
        int len = s.size();
        int index = 0;
        while(index < len)
        {
            if(s[index]=='*')
            {
                xkhc.push(index);
                ++index;
            }
            else if(s[index]=='(')
            {
                kohc.push(index);
                ++index;
            }
            else        //遇到 )
            {
                if(!kohc.empty())
                {
                    kohc.pop();
                }
                else
                {
                    if(xkhc.empty())
                        return false;
                    else
                        xkhc.pop();
                }
                ++index;
            }
        }
        while(!kohc.empty() && !xkhc.empty())
        {
            int koindex = kohc.top();
            kohc.pop();
            int xkindex = xkhc.top();
            xkhc.pop();
            if(koindex > xkindex)
                return false;
        }
        return kohc.empty();
    }
};
