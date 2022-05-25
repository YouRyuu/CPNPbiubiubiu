class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n,vector<double>(n)));
        vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
        for(int p=0; p<=k; ++p)
        {
            for(int i=0; i<n; ++i)
            {
                for(int j=0; j<n; ++j)
                {
                    if(p==0)
                        dp[p][i][j] = 1;
                    else
                    {
                        for(auto dir : dirs)
                        {
                            int di = i+dir[0], dj = j+dir[1];
                            if(di>=0 && di<n && dj>=0 && dj<n)
                            {
                                dp[p][i][j] += dp[p-1][di][dj]/8;
                            }
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};
