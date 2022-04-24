class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n);
        dp[0] = "1";
        for(int i=1; i<n; ++i)
        {
            char preValue = dp[i-1][0];
            int count = 1;
            string v;
            int j=1;
            for(; j<dp[i-1].size();++j)
            {
                if(dp[i-1][j] == preValue)
                {
                    ++count;
                    
                }
                else
                {
                    v = v + to_string(count);
                    v.push_back(preValue);
                    preValue = dp[i-1][j];
                    count = 1;
                }
                
            }
            v = v + to_string(count);
            v.push_back(preValue);
            dp[i] = v;
        }
        return dp[n-1];
    }
};
