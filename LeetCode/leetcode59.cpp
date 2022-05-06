class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int maxV = n * n;
        int curr = 1;
        vector<vector<int>> ret(n, vector<int>(n, 0));
        vector<vector<int>> f{{0,1}, {1,0}, {0,-1}, {-1,0}};
        int row = 0, col = 0;
        int fIndex = 0;
        while(curr <= maxV)
        {
            ret[row][col] = curr;
            ++curr;
            int nextRow = row + f[fIndex][0], nextCol = col + f[fIndex][1];
            if(nextRow<0 || nextRow>=n || nextCol<0 || nextCol>=n || ret[nextRow][nextCol]!=0)
            {
                fIndex = (fIndex + 1)%4;
            }
            row = row + f[fIndex][0], col = col + f[fIndex][1];
        }
        return ret;
    }
};
