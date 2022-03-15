class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxValue = 0;
        int len = accounts.size();
        for(int i=0; i<len; ++i)
        {
            int length = accounts[i].size();
            int sum = 0;
            for(int j=0; j<length; ++j)
            {
                sum += accounts[i][j];
            }
            if(sum > maxValue)
                maxValue = sum;
        }
        return maxValue;
    }
};
