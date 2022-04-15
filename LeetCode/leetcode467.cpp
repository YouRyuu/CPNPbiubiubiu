class Solution {
public:
    bool check(char a, char b)
    {
        if(a=='z')  return b=='a';
        return a+1==b;
    }

    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int len = p.size();
        int k = 0;
        for(int i=0; i<len; ++i)
        {
            if(i>0 && check(p[i-1], p[i]))
                ++k;
            else
                k = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        int sum = 0;
        for(int i=0; i<26; ++i)
        {
            sum += dp[i];
        }
        return sum;
    }
};
