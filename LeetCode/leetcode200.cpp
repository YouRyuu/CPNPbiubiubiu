class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '0';
        if(i-1>=0 && grid[i-1][j]=='1') dfs(grid, i-1, j);
        if(i+1<grid.size() && grid[i+1][j]=='1') dfs(grid, i+1, j);
        if(j-1>=0 && grid[i][j-1]=='1') dfs(grid, i, j-1);
        if(j+1<grid[0].size() && grid[i][j+1]=='1') dfs(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j]=='1')
                {
                    ++ret;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }
};
