class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size+1);
        dp[0] = 0, dp[1] = nums[0];
        if(size==1) return dp[1];
        for(int i=2;i<=size;++i)
        {
            dp[i] = max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        return dp[size];

    }
};
