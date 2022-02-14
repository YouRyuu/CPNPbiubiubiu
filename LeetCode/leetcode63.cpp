class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for(int i=0;i<row;++i)
        {
            if(obstacleGrid[i][0]==1)
            {
                break;
            }
            dp[i][0] = 1;
        }
        for(int i=0;i<col;++i)
        {
            if(obstacleGrid[0][i]==1)
            {
                break;
            }
            dp[0][i] = 1;
        }
        for(int i=1;i<row;++i)
        {
            for(int j=1;j<col;++j)
            {
                dp[i][j] = obstacleGrid[i][j]==1?0:dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[row-1][col-1];

    }
};
