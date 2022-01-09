class Solution {
public:
int count = 0;
    void bfs(vector<int> &nums, int index, int target, int sum)
    {
        if(index>=nums.size())
        {
            if(sum==target)
                ++count;
        }
        else
        {
            bfs(nums, index+1, target, sum-nums[index]);
            bfs(nums, index+1, target, sum+nums[index]);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        bfs(nums, 0, target, 0);
        return count;
        }
};
class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int len = nums.size();
        for(int i=0; i<len; ++i)
            sum += nums[i];
        if(sum < target || (sum - target)%2!=0)    return 0;
        int neg = (sum - target)/2;     //在nums中找到和为neg的数量
        vector<int> dp(neg+1);
        dp[0] = 1;
        for(auto num : nums)
        {
            for(int i=neg; i>=num; --i)
            {
                dp[i] = dp[i] + dp[i - num];
            }
        }
        return dp[neg];
        }
};

