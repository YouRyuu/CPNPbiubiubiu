//暴力法太垃圾了,略过...想到的第一个方法.擦..

//答案 4ms
int maxProfit(int* prices, int pricesSize) {
    int minprice = 0x7FFFFFFF;
    int profit = 0;
    for(int i=0;i<pricesSize;i++)
    {
        if(prices[i] < minprice)
            minprice = prices[i];
        else if(prices[i] - minprice > profit)
            profit = prices[i] - minprice;
    }
    return profit;
}
