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
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int val = 1;
        int left = 0, right = n-1, top = 0, buttom = n-1;
        while(left <= right && top<=buttom)
        {
            for(int col = left; col<=right; ++col)
                ret[top][col] = val++;
            for(int row = top+1; row<=buttom; ++row)
                ret[row][right] = val++;
            //if(left < right && top<buttom)
            //{
                for(int col = right-1; col>left; --col)
                    ret[buttom][col] = val++;
                for(int row = buttom; row>top;--row)
                    ret[row][left] = val++;
           // }
            
            ++left;
            ++top;
            --right;
            --buttom;
        }
        return ret;
    }
};
