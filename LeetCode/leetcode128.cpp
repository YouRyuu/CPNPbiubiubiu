class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len==0)  return 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(len);
        dp[0] = 1;
        for(int i=1; i<len; ++i)
        {
            if(nums[i]==nums[i-1])
                dp[i] = dp[i-1];
            else if(nums[i]==nums[i-1] + 1)
                dp[i] = dp[i-1] + 1;
            else
                dp[i] = 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
