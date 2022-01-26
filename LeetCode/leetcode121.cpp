class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int size = prices.size();
        int minp = INT_MAX;
        for(int i=0;i<size;++i)
        {
            if(prices[i] - minp > ret)
                ret = prices[i] - minp;
            else if(prices[i] < minp)
                minp = prices[i];
        }   
        return ret;
    }
};
