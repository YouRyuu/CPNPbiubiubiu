//最小路径和https://leetcode-cn.com/problems/minimum-path-sum/
//递推公式:dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];

#define min(a,b) ((a)<(b)?(a):(b))

int minPathSum(int** grid, int gridSize, int* gridColSize){
    //f[m,n] = min(f[m,n-1]+g[m,n], f[m-1][n]+g[m,n])
    int dp[gridSize][*gridColSize];
    for(int i=0;i<gridSize;i++)
    {
        for(int j=0;j<*gridColSize;j++)
        {
            if(i==0)
            {
                if(j==0)
                    dp[i][j] = grid[i][j];
                else
                    dp[i][j] = dp[i][j-1] + grid[i][j];
            }
            else if(j==0)
            {
                if(i==0)
                    dp[i][j] = grid[i][j];
                else
                    dp[i][j] = dp[i-1][j] + grid[i][j];
            }
            else
                dp[i][j] = min(dp[i-1][j]+grid[i][j], dp[i][j-1]+grid[i][j]);
        }
    }
    return dp[gridSize-1][*gridColSize-1];
}

//更好的方法
int minPathSum(int** grid, int gridRowSize, int *gridColSizes) {
    int n = gridColSizes[0], p[n], i, j;
    p[0] = 0;
    for (i = 0; i < gridRowSize; ++i) {
        p[0] = grid[i][0] + p[0];
        for (j = 1; j < n; ++j) {
            if (i == 0) {
                p[j] = grid[i][j] + p[j - 1];
            } else {
                p[j] = grid[i][j] + MIN(p[j - 1], p[j]);
            }
        }
    }
    return p[n - 1];
        
}