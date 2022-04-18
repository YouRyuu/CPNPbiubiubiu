class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; ++i)
        {
            for(int j=1; j<i; ++j)
            {
                dp[i] = max(dp[i], max(j*(i-j), (i-j)*dp[j]));
            }
        }
        return dp[n];
    }
};
