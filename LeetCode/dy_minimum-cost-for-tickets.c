//https://leetcode-cn.com/problems/minimum-cost-for-tickets/
//唉
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        /**
            此题拥有最优子结构性质:
            要想获得N天的最少钱,那么N-1天也肯定是最少的钱
        */
        int size = days.size();
        int n = days[size-1];
        vector<int> dp(n+1, 0);
        for(int i=0;i<size;i++)
            dp[days[i]] = -1;   //标记旅行的那一天
        for(int i=1;i<=n;i++)   //开始算旅行
        {
            if(dp[i]==0)    //不旅行
                dp[i] = dp[i-1];
            else
            {
                //想象成最后截止那一天再付钱
                dp[i] = dp[i-1] + costs[0];     //买一天
                dp[i] = min(dp[i], dp[max(0, i-7)]+costs[1]);       //买七天
                dp[i] = min(dp[i], dp[max(0, i-30)] + costs[2]);    //买30天
            }
        }
        return dp[n];
        
    }
};