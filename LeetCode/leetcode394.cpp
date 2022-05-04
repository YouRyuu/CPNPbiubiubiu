class Solution {
public:
    bool isDigit(char c)
    {
        if(c>='0' && c<='9')
            return true;
        return false;
    }
    string decodeString(string s) {
        string ret;
        int len = s.size();
        stack<int> dig;
        stack<string> stk;
        int index = 0;
        while(index<len)
        {
            if(isDigit(s[index]))       //是数字，一直找到不是数字的那个字符，然后数字入栈
            {
                string v;
                v.push_back(s[index++]);
                while(isDigit(s[index]))
                {
                    v.push_back(s[index++]);
                }
                dig.push(stoi(v));
            }
            else if(s[index]=='[')
            {
                stk.push(string(1, s[index++]));
            }
            else if(s[index]==']')
            {
                int times = dig.top();      //获取循环次数
                dig.pop();
                vector<string> vs;
                while(stk.top()!="[")       //获取循环的字母
                {
                    vs.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                reverse(vs.begin(), vs.end());
                string temp1;
                for(int i=0; i<vs.size(); ++i)
                {
                    temp1 += vs[i];
                }
                string temp;
                for(int i=0; i<times; ++i)
                {
                    temp += temp1;
                }
                stk.push(temp);
                ++index;
            }
            else
            {
                stk.push(string(1, s[index]));
                ++index;
            }
        }
        while(!stk.empty())
        {
            ret.insert(0, stk.top());
            stk.pop();
        }
        return ret;
    }
};

