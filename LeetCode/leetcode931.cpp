class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i=size-2;i>=0;--i)
        {
            for(int j=0;j<size;++j)
            {
                int val = matrix[i+1][j];
                if(j>0)
                {
                    val = min(val, matrix[i+1][j-1]);
                }
                if(j<size-1)
                {
                    val = min(val, matrix[i+1][j+1]);
                }
                matrix[i][j] += val;
            }
        }
        int ret = INT_MAX;
        for(int val:matrix[0])
        {
            ret=ret<val?ret:val;
        }
        return ret;
        

    }
};
