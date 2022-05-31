class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(1001));
        int ret = 0;
        for(int k=1; k<len; ++k)
        {
            for(int j=0; j<k; ++j)
            {
                int d = nums[k] - nums[j] + 500;
                dp[k][d] = dp[j][d] + 1;
                ret = max(dp[k][d], ret);
            }
        }
        return ret + 1;
    }
};
