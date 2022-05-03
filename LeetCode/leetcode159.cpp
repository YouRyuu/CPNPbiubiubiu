class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.size();
        if(len <= 2)
            return len;
        int L=0, R=0;
        int index = 0;
        int maxLen = 2;
        char CL = s[L], CR = '-';
        for(;R<len; ++R)
        {
            if(s[R]==s[L] && CR=='-')
                continue;
            if(CR=='-')
            {
                CR = s[R];
                index = R;
                continue;
            }
            if(s[R]==CL || s[R]==CR)
            {
                if(s[index]!=s[R])
                    index = R;
            }
            if(s[R]!=CL && s[R]!=CR)
            {
                maxLen = max(maxLen, R-L);
                L = index;
                index = R;
                CL = s[L];
                CR = s[R];
            }
        }  
        if(s[R-1]==CL || s[R-1]==CR)
            maxLen = max(maxLen, R-L);
        return maxLen;
    }
};
