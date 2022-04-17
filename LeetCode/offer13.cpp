class Solution {
public:
    int count = 0;
    int dir[4][2] = {-1,0,1,0,0,-1,0,1};
    int movingCount(int m, int n, int k) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                dp[i][j] = i/10 + i % 10 + j/10+j%10;
            }
        }
        dfs(dp, 0, 0, k);
        return count;
    }
    void dfs(vector<vector<int>> &maps, int i, int j, int k)
    {
        if(i>=maps.size() || i<0 || j>=maps[0].size() || j<0)
            return;
        if(maps[i][j] > k)
            return;
        if(maps[i][j] <= k) 
            ++count;
        maps[i][j] =  k+1;
        for(int n=0; n<4;++n)
        {
            dfs(maps, i+dir[n][0], j+dir[n][1], k);
        }
    }
};
