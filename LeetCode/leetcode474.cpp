class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //按字符串长度排序
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(auto &str:strs)
        {
            int sum0 = 0, sum1=0;
            for(int i=0; i<str.size(); ++i)
            {
                if(str[i]=='0') sum0+=1;
                else sum1+=1;
            }
            for(int i=m; i>=sum0; --i)
            {
                for(int j=n; j>=sum1; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i-sum0][j-sum1]+1);
                }
            }
        }
        return dp[m][n];
    }
};
