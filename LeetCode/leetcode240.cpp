class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0; i<row; ++i)
        {
            int left = 0, right = col-1;
            while(left<=right)
            {
                int mid = (left + right)/2;
                if(matrix[i][mid]==target)
                    return true;
                if(matrix[i][mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                --y;
            }
            else {
                ++x;
            }
        }
        return false;
    }
};
