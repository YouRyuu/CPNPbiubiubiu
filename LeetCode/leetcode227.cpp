class Solution {
public:
    bool isDigit(char c)
    {
        if(c!='+' && c!='-' && c!='*' && c!='/')
            return true;
        return false;
    }

    int calculate(string s) {
        vector<int> stk;
        char preSig = '+';
        int len = s.size();
        int num = 0;
        for(int i=0; i<len; ++i)
        {
            if(isDigit(s[i]))
            {
                num = num * 10 + int(s[i]-'0');
            }
            if(!isDigit(s[i]) && s[i]!=' ' || i==len-1)
            {
                if(preSig=='+')
                    stk.push_back(num);
                else if(preSig=='-')
                    stk.push_back(-num);
                else if(preSig=='*')
                    stk.back() *= num;
                else
                    stk.back() /= num;
                num = 0;
                preSig = s[i];
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
