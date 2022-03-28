class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;
        for(int i=2; i<=n; ++i)
        {
            for(int j=1;j<i;++j)
            {
                int temp = max(dp[j] * (i-j), j*(i-j));
                if(temp > dp[i])
                    dp[i] = temp;
            }
        }
        return dp[n];
    }
};
