class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        for(int i=row-2;i>=0;--i)
        {
            for(int j=0;j<triangle[i].size();++j)
            {
                int val = min(triangle[i+1][j], triangle[i+1][j+1]);
                triangle[i][j] += val;
            }
        }
        int ret = INT_MAX;
        for(int val:triangle[0])
        {
            ret=ret<val?ret:val;
        }
        return ret;

    }
};
