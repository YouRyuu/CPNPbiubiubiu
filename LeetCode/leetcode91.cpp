class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int size = s.size();
        vector<int> dp(size);
        dp[0] = 1;
        for(int i=1;i<size;++i)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='1' || s[i-1]=='2')
                {
                    if(i>1)
                        dp[i] = dp[i-2];
                    else
                        dp[i] = dp[i-1];
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            if(s[i-1]=='1')
            {
                if(i>1)
                {
                    dp[i] = dp[i-2] + dp[i-1];
                }
                else
                {
                    dp[i] = dp[i-1] + 1;
                }
            }
            else if(s[i-1]=='2')
            {
                if(s[i]>='0' && s[i]<='6')
                {
                    if(i>1)
                    {
                        dp[i] = dp[i-2] + dp[i-1];
                    }
                    else
                    {
                        dp[i] = dp[i-1] + 1;
                    }

                }
                else
                {
                    dp[i] = dp[i-1];
                }
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
        return dp[size-1];
    }
};
