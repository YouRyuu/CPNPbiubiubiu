class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i=1;i<size;++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][0] - fee + prices[i], dp[i-1][1]);
        }
        return dp[size-1][1];
    }

    

};
