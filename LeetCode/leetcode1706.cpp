class Solution {
public:
    vector<int> ret;
    void dfs(vector<vector<int>> &grid, int startrow, int startcol, int nowrow, int nowcol)
    {
        if(nowcol<0 || nowcol>=grid[0].size())
            return;
        if((nowcol==0 && grid[nowrow][nowcol]==-1) || (nowcol==grid[0].size()-1 && grid[nowrow][nowcol]==1))
            return;
        if(nowcol<grid[0].size()-1 && grid[nowrow][nowcol]==1 && grid[nowrow][nowcol+1]==-1)
            return;
        if(nowcol>0 && grid[nowrow][nowcol]==-1 && grid[nowrow][nowcol-1]==1)
            return;
        if(nowrow==grid.size()-1)
        {
            if(grid[nowrow][nowcol]==1)
                ret[startcol] = nowcol+1;
            else
                ret[startcol] = nowcol-1;
            return;
        }
        if(grid[nowrow][nowcol] == -1)
            dfs(grid, startrow, startcol, nowrow+1, nowcol-1);
        else
            dfs(grid, startrow, startcol, nowrow+1, nowcol+1);
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        ret.resize(n);
        for(int i=0; i<n; ++i)
            ret[i] = -1;
        for(int i=0; i<n; ++i)
            dfs(grid, 0, i, 0, i);
        return ret;
    }
};
