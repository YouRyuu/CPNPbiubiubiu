class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i=2;i<n+1;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                dp[i] = max(dp[i], dp[j]*(i-j));
                dp[i] = max(dp[i], j*(i-j));
            }
        }
        return dp[n];
    }
};