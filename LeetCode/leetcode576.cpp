class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int MOD = 1'000'000'007;
        vector<vector<int>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m, vector<int>(n, 0)));
        dp[0][startRow][startColumn] = 1;
        int ret = 0;
        for(int i=0; i<maxMove; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                for(int k=0; k<n; ++k)
                {
                    int count = dp[i][j][k];
                    if(count>0)
                    {
                        for(auto d:dir)
                        {
                            int j1 = j+d[0], k1 = k+d[1];
                            if(j1>=0 && j1<m && k1>=0 && k1<n)
                            {
                                dp[i+1][j1][k1] = (dp[i+1][j1][k1] + count)%MOD;
                            }
                            else
                            {
                                ret = (ret + count)%MOD;
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};
