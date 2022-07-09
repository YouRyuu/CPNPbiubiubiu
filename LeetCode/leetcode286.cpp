class Solution {
public:
    const int empty = 2147483647;
    const int door = 0;
    const int wall = -1;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size();
        int col = rooms[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(rooms[i][j]==door)
                {
                    q.push({i, j});
                }
            }
        }
        while(!q.empty())
        {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int r = cr + dir[i][0];
                int c = cc + dir[i][1];
                if (r < 0 || c < 0 || r >= row || c >= col || rooms[r][c]!=empty)
                    continue;
                rooms[r][c] = rooms[cr][cc] + 1;
                q.push({r,c});
            }
        }
    }
};
