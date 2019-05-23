//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n<2) return 0;
        int ret = 0;
        int mins = prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]<mins)
                mins=prices[i];
            else if(prices[i]-mins-fee > 0)
            {
                ret += prices[i]-mins-fee;
                mins=prices[i]-fee;
            }
        }
        return ret;
    }
};