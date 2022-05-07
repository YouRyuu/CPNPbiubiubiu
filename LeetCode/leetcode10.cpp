class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        vector<vector<int>> dp(lens+1, vector<int>(lenp+1, 0));
        dp[0][0] = 1;

        for (int j = 2; j <= lenp; ++j) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        for(int i=1; i<=lens; ++i)
        {
            for(int j=1; j<=lenp; ++j)
            {
                
                if(p[j-1]=='*')
                {
                    dp[i][j] |= dp[i][j-2];
                    if(s[i-1]==p[j-2] || p[j-2]=='.')
                    {
                        dp[i][j] |= dp[i-1][j];
                    }
                }
                else
                {
                    if(s[i-1]==p[j-1] || p[j-1]=='.')
                    dp[i][j] = dp[i-1][j-1];
                }
                }
            }
        return dp[lens][lenp];
    }
};
