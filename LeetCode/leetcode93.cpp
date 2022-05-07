class Solution {
public:
    vector<string> ret;
    vector<int> v;
    void bt(string &s, int count, int start)
    {
        if(count == 4)
        {
            if(start==s.size())
            {
                string s;
                for(int i=0; i<4; ++i)
                {
                    s += to_string(v[i]);
                    if(i!=3)
                        s.push_back('.');
                }
                ret.push_back(s);
            }
            return;
        }
        if(start==s.size())
            return;
        if(s[start]=='0')
        {
            v[count] = 0;
            bt(s, count+1, start+1);
        }
        int addr = 0;
        for(int end=start;end<s.size(); ++end)
        {
            addr = addr * 10 + (s[end]-'0');
            if(addr>0 && addr<256)
            {
                v[count]=addr;
                bt(s, count+1, end+1);
            }
            else
                break;
        }
    }


    vector<string> restoreIpAddresses(string s) {
        v.resize(4);
        bt(s, 0, 0);
        return ret;
    }
};
