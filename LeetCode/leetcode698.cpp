//暴力回溯:
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto &num : nums)
            sum += num;
        if(sum%k!=0)    return false;
        sum = sum / k;
        vector<int> bullet(k, 0);
        return dfs(nums, bullet, sum, 0);
    }

    bool dfs(vector<int> &nums, vector<int> &bullet, int sum, int index)
    {
        if(index >= nums.size())    return true;
        for(int i=0; i<bullet.size(); ++i)
        {
            if(bullet[i] + nums[index] > sum)
                continue;
            else
            {
                bullet[i] += nums[index];
            }
            if(dfs(nums, bullet, sum, index+1))
                return true;
            bullet[i] -= nums[index];
            if(bullet[i]==0)
                break;
        }
        return false;
    }
};
