class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> tmp;
        ret.push_back({1});
        for(int i=1;i<numRows;++i)
        {
            for(int j=0;j<i+1;++j)
            {
                if(j==0 || j==i)
                {
                    tmp.push_back({1});
                }
                else
                {
                    tmp.push_back({ret[i-1][j-1] + ret[i-1][j]});
                }
            }
            ret.push_back(tmp);
            tmp.clear();
        }
        return ret;

    }
};
