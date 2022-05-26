class Solution {
public:

    int max1(vector<int>& prices, int start, int end)
    {
        //[start, end]交易一次的最大收益
        int minv = 1e7, maxv = 0;
        for(int i=start; i<=end; ++i)
        {
            maxv = max(maxv, prices[i]-minv);
            minv = min(minv, prices[i]);
        }
        return maxv;
    }

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int ret = 0;
        for(int i=0; i<len; ++i)
        {
            int v1 = max1(prices, 0,i);
            int v2 = max1(prices, i+1, len-1);
            ret = max(ret, v1+v2);
        }
        return ret;
    }
};
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(2, vector<int>(3)));
        dp[0][0][0] = 0;
        dp[0][0][1] = INT_MIN+1000000;
        dp[0][0][2] = dp[0][1][1] = dp[0][1][2] = INT_MIN;
        dp[0][1][0] = -prices[0];
        for(int i=1; i<len; ++i)
        {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][0]+prices[i]);
            dp[i][0][2] = max(dp[i-1][0][2], dp[i-1][1][1] + prices[i]);
            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][0]-prices[i]);
            dp[i][1][1] = max(dp[i-1][0][1]-prices[i], dp[i-1][1][1]);
            dp[i][1][2] = INT_MIN;
        }
        return max(0,max(dp[len-1][0][1], dp[len-1][0][2]));
    }
};

