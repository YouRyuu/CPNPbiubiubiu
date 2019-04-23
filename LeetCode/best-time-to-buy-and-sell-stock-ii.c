//我
int maxProfit(int* prices, int pricesSize) {
        int sum = 0;
    int profit = 0;
    int distance;
    for(int i=1;i<pricesSize;i++)
    {
        distance = prices[i] - prices[i-1];
        if(profit+distance > profit)
        {
            profit = profit + distance;
        }
        else
        {
            sum += profit;
            profit = 0;
        }
    }
    sum+=profit;
    return sum;
}

//别人:双百
int maxProfit(int* prices, int pricesSize) {
    
     int res = 0, n = pricesSize;
        for (int i = 0; i < n - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
}