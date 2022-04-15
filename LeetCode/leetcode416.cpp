class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); ++i)
            sum += nums[i];
        if(sum % 2 != 0)  return false;
        sum = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1));
        if(nums[0] <= sum)
            dp[0][nums[0]] = true;
        for(int i=1; i<nums.size(); ++i)
        {
            for(int j=0; j<=sum; ++j)
            {
                dp[i][j] = dp[i-1][j];       //不选择nums[j]
                if(nums[i] == j)
                    dp[i][j] = true;
                if(j > nums[i])
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[nums.size()-1][sum];
    }
};
