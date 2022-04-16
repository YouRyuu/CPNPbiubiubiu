class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row==0)  return 0;
        int col = matrix[0].size();
        int left = 0, right = col-1;
        while(left < row && right >= 0)
        {
            if(target>=matrix[left][0] && target <= matrix[left][col-1])
            {
                for(int i=0; i<col; ++i)
                {
                    if(matrix[left][i]==target)
                        return true;
                }
            }
            ++left;
        }
        return false;
    }
};
