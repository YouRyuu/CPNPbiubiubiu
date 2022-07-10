class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2)
            return s.size();
        unordered_map<char, int> m;  
        int ret = 0;
        int len = s.size();
        int L = 0, R = 0;
        while(R<len)
        {
            auto item = m.find(s[R]);
            if(item==m.end())
            {
                m[s[R]] = R;
                ++R;
            }
            else
            {
                if(item->second<L)
                {
                    m[s[R]] = R;
                }
                else
                {
                    ret = max(ret, R-L);
                    L = m[s[R]] + 1;
                    m[s[R]] = R;
                }
                
                ++R;
            }
        }
        ret = max(ret, R-L);
        return ret;
    }
};
