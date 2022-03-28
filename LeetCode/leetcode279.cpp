class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; ++i)
        {
            int temp = INT_MAX;
            for(int j=1;j*j<=i; ++j)
            {
                temp = min(temp, dp[i-j*j]);
            }
            dp[i] = temp + 1;
        }
        return dp[n];
    }
};
