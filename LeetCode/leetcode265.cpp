class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<vector<int>> dp(n+1, vector<int>(k));
        int pre1=0, pre2=0;
        for(int i=1; i<=n; ++i)
        {
            int tmp1=2e9, tmp2=2e9;
            for(int j=0; j<k; ++j)
            {
                if(dp[i-1][j]!=pre1)
                    dp[i][j] = costs[i-1][j] + pre1;
                else
                    dp[i][j] = costs[i-1][j] + pre2;
                if(dp[i][j] < tmp1)
                {
                    tmp2 = tmp1;
                    tmp1 = dp[i][j];
                }
                else if(dp[i][j] < tmp2)
                    tmp2 = dp[i][j];
            }
            pre1 = tmp1, pre2 = tmp2;
        }
        
        return *min_element(dp[n].begin(), dp[n].end());
    }
};
