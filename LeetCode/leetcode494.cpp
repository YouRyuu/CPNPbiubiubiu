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
