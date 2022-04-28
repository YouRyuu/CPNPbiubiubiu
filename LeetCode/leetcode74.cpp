class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = col-1;
        while(left<row && right>=0)
        {
            if(matrix[left][right]==target)
                return true;
            else if(matrix[left][right] < target)
                ++left;
            else
                --right;
        }
        return false;
    }
};
