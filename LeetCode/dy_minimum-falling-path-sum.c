//https://leetcode-cn.com/problems/minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        //dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]) + A[i][j]
        int length = A.size();
        vector<vector<int>> dp(length, vector<int>(length, 0));
        for(int i=0;i<length;i++)
        {
            for(int j=0;j<length;j++)
            {
                if(i==0)
                {
                    dp[i][j] = A[i][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + A[i][j];
                    if(j>=1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1]+A[i][j]);
                    }
                    if(j+1<length)
                    {
                        dp[i][j] = min(dp[i][j], dp[i-1][j+1]+A[i][j]);
                    }
                }
            }
        }
        int res = dp[length-1][0];
        for(int i=1;i<length;i++)
            res = min(res, dp[length-1][i]);
        return res;
    }
};