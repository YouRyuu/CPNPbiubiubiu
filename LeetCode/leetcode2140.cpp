class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int len = questions.size();
        vector<long long> dp(len+1);
        for(int i=len-1; i>=0; --i)
        {
            dp[i] = max(dp[i+1], questions[i][0] + dp[min(len, i+questions[i][1]+1)]);
        }
        return dp[0];
    }
};
