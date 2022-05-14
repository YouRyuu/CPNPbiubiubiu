class Solution {
public:
    int dfs(string s, int L, int R, int k)
    {
        vector<int> count(26,0);
        for(int i=L; i<=R; ++i)
            ++count[s[i]-'a'];
        char split = 0;
        for(int i=0; i<26; ++i)
        {
            if(count[i]>0 && count[i]<k)
            {
                split = i+'a';
                break;
            }
        }
        if(split==0)
            return R-L+1;
        int ret = 0;
        int i=L;
        while(i<=R)
        {
            while(i<=R && s[i]==split)
                ++i;
            if(i>R)
                break;
            int start = i;
            while(i<=R && s[i]!=split)
                ++i;
            int length = dfs(s, start, i-1, k);
            ret = max(ret, length);
        }
        return ret;
    }

    int longestSubstring(string s, int k) {
        return dfs(s, 0, s.size()-1, k);
    }
};
