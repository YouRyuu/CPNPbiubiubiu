class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size==1) return nums[0];
        if(size==2) return max(nums[0], nums[1]);
        return max(robRange(nums, 0, size-2), robRange(nums, 1, size-1));


    }

    int robRange(vector<int>& nums, int start, int end)
    {
        int size = end-start+1;
        vector<int> dp(size+1);
        dp[0] = 0, dp[1] = nums[start];
        for(int i=2;i<size+1;++i)
        {
            dp[i] = max(dp[i-2]+nums[i-1+start], dp[i-1]);
        }
        return dp[size];      
    }   
};
